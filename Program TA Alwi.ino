#include <ArduinoJson.h>
#include <WiFi.h>

#include "esp_camera.h"
#include "soc/soc.h"           // Brownout error fix
#include "soc/rtc_cntl_reg.h"  // Brownout error fix
#define CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
#define FLASH_LED_PIN 4
#define ON HIGH
#define OFF LOW
bool flashState = LOW;
bool sendPhoto = false;
bool capturePhotoWithFlash = false;
  
#include <UniversalTelegramBot.h>
/*const char* ssid = "Lukman74";  // SSID WiFi network
const char* pass = "08agustus2000";  // Password  WiFi network
String BOTtoken = "5996667065:AAHFh_sSip18Pd9WTNEtFOt98rlcYkPzif8";
String CHAT_ID = "1348194951";*/

const char* ssid = "Han5657";  // SSID WiFi network
const char* pass = "aug343";  // Password  WiFi network
String BOTtoken = "6359227626:AAGXVy_8DOiGU1PUXHJV_tMkYgflfSAA690";
String CHAT_ID = "1172817906";

int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

#include <WiFiClientSecure.h>
WiFiClientSecure clientTCP;
UniversalTelegramBot bot(BOTtoken, clientTCP);

#define pir  12 
bool pir_state = 0;

int count = 0; 

unsigned long previousMillis = 0;    // Waktu sebelumnya
unsigned long interval = 1000;      // Interval waktu dalam milidetik (10 detik)

#include <EEPROM.h>

#include <WiFiUdp.h>
#include <NTPClient.h>
WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 25200;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds );

int jam1 = 12;
int jam2 = 18;
int jam3 = 22;
int menit = 0;
int detik = 5;

void configInitCamera(){
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;  //0-63 lower number means higher quality
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SXGA;
    config.jpeg_quality = 12;  //0-63 lower number means higher quality
    config.fb_count = 1;
  }
  
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(1000);
    ESP.restart();
  }

  // Drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_SVGA);  // UXGA|SXGA|XGA|SVGA|VGA|CIF|QVGA|HQVGA|QQVGA
}

void LEDFlash_State (bool ledState) {
  digitalWrite(FLASH_LED_PIN, ledState);
}

void handleNewMessages(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);
    
    String from_name = bot.messages[i].from_name;
    if (text == "/start") {
      String welcome = "Welcome , " + from_name + "\n";
      welcome += "Silahkan akses menu berikut : \n";
      welcome += "/photo : mengambil foto\n";
      welcome += "/piron : mengaktifkan sensor \n";
      welcome += "/piroff : mematikan sensor \n";
      welcome += "/pelanggaran : mengirimkan jumlah pelanggaran yang terjadi \n";
      welcome += "/reset : menghapus data jumlah pelanggaran \n";
      bot.sendMessage(CHAT_ID, welcome, "");
    }
    if (text == "/piron"){
      pir_state = 1;
      bot.sendMessage(CHAT_ID, "PIR Sensor sudah aktif, Saat terjadi gerakan anda akan dikirimkan foto", "");
    }

    if (text == "/piroff"){
      pir_state = 0;
      bot.sendMessage(CHAT_ID, "PIR sensor sudah mati, Anda tidak akan menerima pemberitahuan lagi saat terjadi gerakan", "");
    }
    if (text == "/photo") {
      sendPhoto = true;
      capturePhotoWithFlash = true;
      Serial.println("New photo request");
    }
    if (text == "/pelanggaran"){
      String message = "Jumlah pelanggaran : " + String(count);
      bot.sendMessage(CHAT_ID, message, "");
    }
    if (text == "/reset"){
      count = 0;
      EEPROM.write(0, count);
      EEPROM.commit();
      bot.sendMessage(CHAT_ID, "jumlah pelanggaran berhasil direset", "");
    }       
  }
}

String sendPhotoTelegram() {
  const char* myDomain = "api.telegram.org";
  String getAll = "";
  String getBody = "";

   if(capturePhotoWithFlash == true) {
    LEDFlash_State(ON);
  }
  delay(1000);

  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();  
  if(!fb) {
    Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();
    return "Camera capture failed";
  }  
  
  if(capturePhotoWithFlash == true) {
    LEDFlash_State(OFF);
    capturePhotoWithFlash = false;
  }
    
  Serial.println("Connect to " + String(myDomain));


  if (clientTCP.connect(myDomain, 443)) {
    Serial.println("Connection successful");
    
    String head = "--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"chat_id\"; \r\n\r\n" + CHAT_ID + "\r\n--RandomNerdTutorials\r\nContent-Disposition: form-data; name=\"photo\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    String tail = "\r\n--RandomNerdTutorials--\r\n";

    uint16_t imageLen = fb->len;
    uint16_t extraLen = head.length() + tail.length();
    uint16_t totalLen = imageLen + extraLen;
  
    clientTCP.println("POST /bot"+BOTtoken+"/sendPhoto HTTP/1.1");
    clientTCP.println("Host: " + String(myDomain));
    clientTCP.println("Content-Length: " + String(totalLen));
    clientTCP.println("Content-Type: multipart/form-data; boundary=RandomNerdTutorials");
    clientTCP.println();
    clientTCP.print(head);
  
    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    for (size_t n=0;n<fbLen;n=n+1024) {
      if (n+1024<fbLen) {
        clientTCP.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen%1024>0) {
        size_t remainder = fbLen%1024;
        clientTCP.write(fbBuf, remainder);
      }
    }  
    
    clientTCP.print(tail);
    
    esp_camera_fb_return(fb);
    
    int waitTime = 10000;   // timeout 10 seconds
    long startTimer = millis();
    boolean state = false;
    
    while ((startTimer + waitTime) > millis()){
      Serial.print(".");
      delay(100);      
      while (clientTCP.available()) {
        char c = clientTCP.read();
        if (state==true) getBody += String(c);        
        if (c == '\n') {
          if (getAll.length()==0) state=true; 
          getAll = "";
        } 
        else if (c != '\r')
          getAll += String(c);
        startTimer = millis();
      }
      if (getBody.length()>0) break;
    }
    clientTCP.stop();
    Serial.println(getBody);
  }
  else {
    getBody="Connected to api.telegram.org failed.";
    Serial.println("Connected to api.telegram.org failed.");
  }
  return getBody;
}

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  // Init Serial Monitor
  Serial.begin(115200);

  // Set LED Flash as output
  pinMode(FLASH_LED_PIN, OUTPUT);
  pinMode(pir,INPUT);
  digitalWrite(FLASH_LED_PIN, flashState);
  
  // Config and init the camera
  configInitCamera();

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  clientTCP.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  
  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");

  EEPROM.begin(1);
  count = EEPROM.read(0);
  delay(100);
  
  timeClient.begin();     
}

void loop()
{
  String perintah;
  while(Serial.available() > 0){
    delay(10);
    char d = Serial.read();
    perintah += d;
  }
  if (perintah == "photo") {
    sendPhoto = true;
    Serial.println("New photo request");
  }
  
  if (sendPhoto) {
    Serial.println("Preparing photo");
    sendPhotoTelegram(); 
    sendPhoto = false;
  }

  if (pir_state == 1){
    if(digitalRead(pir) == 1){
      Serial.print("Motion Detected, Value = ");
      Serial.println(digitalRead(pir));
      String motion = "Terdeteksi pelanggaran!!\n";
      motion += "Foto akan segera dikirim\n";   
      bot.sendMessage(CHAT_ID, motion, "");
      capturePhotoWithFlash = true;
      sendPhotoTelegram();
    } 
  }  
  
  hitung();
  kirim();
  
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
} 
 
void hitung() 
{

  int pir_state = digitalRead(pir);

  // Periksa apakah ada pergerakan terdeteksi oleh sensor PIR
  if (pir_state == HIGH) {
    // Periksa waktu untuk menghindari bounce pada sensor PIR
    if (millis() - previousMillis > interval) {
      count++;  // Tambah jumlah barang
      Serial.print("Jumlah Barang: ");
      Serial.println(count);
      previousMillis = millis();  // Simpan waktu saat ini
      // Simpan jumlah barang ke EEPROM
      EEPROM.write(0, count);
      EEPROM.commit();
    }
  }
}  

void kirim()
{
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());
  if(timeClient.isTimeSet()) {
    if((timeClient.getHours() == jam1 || timeClient.getHours() == jam2 || timeClient.getHours() == jam3 ) && timeClient.getMinutes() == menit && timeClient.getSeconds() >= detik) 
    { 
      String message = "Jumlah pelanggaran : " + String(count);
      bot.sendMessage(CHAT_ID, message, "");      
    }
  }
  delay(1000);
}
