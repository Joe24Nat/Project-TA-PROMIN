#define WIFI_SSID "Farhan24"
#define WIFI_PASSWORD "Farka24721"

#include <WiFi.h> 
#include <WiFiUdp.h>
#include <NTPClient.h>
WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 25200;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds );

byte sda = 5;
byte rst = 13;
#include<KRrfid.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

#include <EEPROM.h>

#include "CTBot.h"
CTBot myBot;
#define BOT_TOKEN "5716285837:AAE54ot9trVZcLu1fVrI23kUgHniT0iOt84"
int groupID = -684708263;

int hari,jam1,menit1,jam2,menit2,jam3,menit3,nilai;
int hour1,minute1,hour2,minute2,hour3,minute3,hour4,minute4,hour5,minute5,hour6,minute6,hour7,minute7,hour8,minute8,hour9,minute9,hour10,minute10,hour11,minute11,hour12,minute12;
int hour13,minute13,hour14,minute14,hour15,minute15,hour16,minute16,hour17,minute17,hour18,minute18,hour19,minute19,hour20,minute20,hour21,minute21,hour22,minute22;
int hour23,minute23,hour24,minute24,hour25,minute25,hour26,minute26,hour27,minute27,hour28,minute28,hour29,minute29,hour30,minute30;
int hour31,minute31,hour32,minute32,hour33,minute33,hour34,minute34,hour35,minute35,hour36,minute36,hour37,minute37,hour38,minute38,hour39,minute39,hour40,minute40;
int hour41,minute41,hour42,minute42,hour43,minute43,hour44,minute44,hour45,minute45,hour46,minute46,hour47,minute47,hour48,minute48,hour49,minute49,hour50,minute50;
int hour51,minute51,hour52,minute52,hour53,minute53,hour54,minute54,hour55,minute55,hour56,minute56,hour57,minute57,hour58,minute58,hour59,minute59,hour60,minute60;
int day1,day2,day3,day4,day5,day6,day7,day8,day9,day10,day11,day12,day13,day14,day15,day16,day17,day18,day19,day20;
int tl,a,z,b;

String arrData[8];
int jamA = 6;
int jamB = 18;
int offline,ketinggalan;
int pinrelay1 = 14, pinrelay2 = 27, ledbiru = 16, ledmerah = 17, ledkuning = 25, buzzer = 26;

void setup() 
{
  Serial.begin(115200);
  rfidBegin();
  
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("KELAS PSI 210");
  lcd.setCursor(1,1);
  lcd.print("TEKNIK ELEKTRO");

  pinMode(ledbiru, OUTPUT);
  pinMode(ledmerah, OUTPUT);
  pinMode(ledkuning, OUTPUT);
  pinMode(pinrelay1, OUTPUT);
  digitalWrite(pinrelay1, HIGH);
  pinMode(pinrelay2, OUTPUT);
  digitalWrite(pinrelay2, LOW);
  pinMode(buzzer, OUTPUT);  
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledbiru, LOW);
    offline = 1;
    bacarfid();
    delay (500);
    Serial.print (".");
  }

  Serial.println("Starting TelegramBot...");

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);

	// set the telegram bot token
	myBot.setTelegramToken(BOT_TOKEN);

	// check if all things are ok
	if (myBot.testConnection())
  {  
		Serial.println("\ntestConnection OK");
    digitalWrite(ledbiru, HIGH);
    offline = 0;
    myBot.sendMessage(groupID,"Selamat Datang di Sistem Kunci Terjadwal Ruang Kelas 210 Teknik Elektro.\nSilahkan kirim Menu untuk melihat tampilan perintah yang tersedia.");
  }      
    else
  {  
		Serial.println("\ntestConnection NOK");
  }  

  EEPROM.begin(140);
  hour1 = EEPROM.read(0);
  minute1 = EEPROM.read(1);
  hour2 = EEPROM.read(2);
  minute2 = EEPROM.read(3);
  hour3 = EEPROM.read(4);
  minute3 = EEPROM.read(5);
  hour4 = EEPROM.read(6);
  minute4 = EEPROM.read(7);
  hour5 = EEPROM.read(8);
  minute5 = EEPROM.read(9);
  hour6 = EEPROM.read(10);
  minute6 = EEPROM.read(11);
  hour7 = EEPROM.read(12);
  minute7 = EEPROM.read(13);
  hour8 = EEPROM.read(14);
  minute8 = EEPROM.read(15);
  hour9 = EEPROM.read(16);
  minute9 = EEPROM.read(17);
  hour10 = EEPROM.read(18);
  minute10 = EEPROM.read(19);
  hour11 = EEPROM.read(20);
  minute11 = EEPROM.read(21);
  hour12 = EEPROM.read(22);
  minute12 = EEPROM.read(23);
  hour13 = EEPROM.read(24);
  minute13 = EEPROM.read(25);
  hour14 = EEPROM.read(26);
  minute14 = EEPROM.read(27);
  hour15 = EEPROM.read(28);
  minute15 = EEPROM.read(29);
  hour16 = EEPROM.read(30);
  minute16 = EEPROM.read(31);
  hour17 = EEPROM.read(32);
  minute17 = EEPROM.read(33);
  hour18 = EEPROM.read(34);
  minute18 = EEPROM.read(35);
  hour19 = EEPROM.read(36);
  minute19 = EEPROM.read(37);
  hour20 = EEPROM.read(38);
  minute20 = EEPROM.read(39);
  hour21 = EEPROM.read(40);
  minute21 = EEPROM.read(41);
  hour22 = EEPROM.read(42);
  minute22 = EEPROM.read(43);
  hour23 = EEPROM.read(44);
  minute23 = EEPROM.read(45);
  hour24 = EEPROM.read(46);
  minute24 = EEPROM.read(47);
  hour25 = EEPROM.read(48);
  minute25 = EEPROM.read(49);
  hour26 = EEPROM.read(50);
  minute26 = EEPROM.read(51);
  hour27 = EEPROM.read(52);
  minute27 = EEPROM.read(53);
  hour28 = EEPROM.read(54);
  minute28 = EEPROM.read(55);
  hour29 = EEPROM.read(56);
  minute29 = EEPROM.read(57);
  hour30 = EEPROM.read(58);
  minute30 = EEPROM.read(59);
  hour31 = EEPROM.read(60);
  minute31 = EEPROM.read(61);
  hour32 = EEPROM.read(62);
  minute32 = EEPROM.read(63);
  hour33 = EEPROM.read(64);
  minute33 = EEPROM.read(65);
  hour34 = EEPROM.read(66);
  minute34 = EEPROM.read(67);
  hour35 = EEPROM.read(68);
  minute35 = EEPROM.read(69);
  hour36 = EEPROM.read(70);
  minute36 = EEPROM.read(71);
  hour37 = EEPROM.read(72);
  minute37 = EEPROM.read(73);
  hour38 = EEPROM.read(74);
  minute38 = EEPROM.read(75);
  hour39 = EEPROM.read(76);
  minute39 = EEPROM.read(77);
  hour40 = EEPROM.read(78);
  minute40 = EEPROM.read(79);
  hour41 = EEPROM.read(80);
  minute41 = EEPROM.read(81);
  hour42 = EEPROM.read(82);
  minute42 = EEPROM.read(83);
  hour43 = EEPROM.read(84);
  minute43 = EEPROM.read(85);
  hour44 = EEPROM.read(86);
  minute44 = EEPROM.read(87);
  hour45 = EEPROM.read(88);
  minute45 = EEPROM.read(89);
  hour46 = EEPROM.read(90);
  minute46 = EEPROM.read(91);
  hour47 = EEPROM.read(92);
  minute47 = EEPROM.read(93);
  hour48 = EEPROM.read(94);
  minute48 = EEPROM.read(95);
  hour49 = EEPROM.read(96);
  minute49 = EEPROM.read(97);
  hour50 = EEPROM.read(98);
  minute50 = EEPROM.read(99);
  hour51 = EEPROM.read(100);
  minute51 = EEPROM.read(101);
  hour52 = EEPROM.read(102);
  minute52 = EEPROM.read(103);
  hour53 = EEPROM.read(104);
  minute53 = EEPROM.read(105);
  hour54 = EEPROM.read(106);
  minute54 = EEPROM.read(107);
  hour55 = EEPROM.read(108);
  minute55 = EEPROM.read(109);
  hour56 = EEPROM.read(110);
  minute56 = EEPROM.read(111);
  hour57 = EEPROM.read(112);
  minute57 = EEPROM.read(113);
  hour58 = EEPROM.read(114);
  minute58 = EEPROM.read(115);
  hour59 = EEPROM.read(116);
  minute59 = EEPROM.read(117);
  hour60 = EEPROM.read(118);
  minute60 = EEPROM.read(119);
  day1 = EEPROM.read(120);
  day2 = EEPROM.read(121);
  day3 = EEPROM.read(122);
  day4 = EEPROM.read(123);
  day5 = EEPROM.read(124);
  day6 = EEPROM.read(125);
  day7 = EEPROM.read(126);
  day8 = EEPROM.read(127);
  day9 = EEPROM.read(128);
  day10 = EEPROM.read(129);
  day11 = EEPROM.read(130);
  day12 = EEPROM.read(131);
  day13 = EEPROM.read(132);
  day14 = EEPROM.read(133);
  day15 = EEPROM.read(134);
  day16 = EEPROM.read(135);
  day17 = EEPROM.read(136);
  day18 = EEPROM.read(137);
  day19 = EEPROM.read(138);
  day20 = EEPROM.read(139);  
  delay(100); 
    
  timeClient.begin();
}

void loop() {
  waktu();
  bacarfid();
  tele();  
}

void bacarfid()
{
  getTAG();              
    if(TAG == "11051181" && offline == 1 || TAG == "11051181" && ketinggalan == 1 && a !=1) 
    {                  
      digitalWrite(pinrelay1,LOW);
      digitalWrite(ledmerah,HIGH);    
      digitalWrite(pinrelay2,HIGH);
      digitalWrite(ledkuning,HIGH);
      myBot.sendMessage(groupID,"Pintu diakses menggunakan kartu kelas");                
      delay(5000);
      digitalWrite(pinrelay1,HIGH);
      digitalWrite(ledmerah,LOW);    
      digitalWrite(pinrelay2,LOW);
      digitalWrite(ledkuning,LOW);
    }
    if(TAG == "912219129")
    {        
      digitalWrite(pinrelay1,LOW);
      digitalWrite(ledmerah,HIGH);    
      digitalWrite(pinrelay2,HIGH);
      digitalWrite(ledkuning,HIGH);
      myBot.sendMessage(groupID,"Pintu diakses menggunakan MasterCard");            
      delay(5000);    
      digitalWrite(pinrelay1,HIGH);
      digitalWrite(ledmerah,LOW);    
      digitalWrite(pinrelay2,LOW);
      digitalWrite(ledkuning,LOW);
    }    
  TAG = "";    
}

void tele()
{
  TBMessage group;
	if (CTBotMessageText == myBot.getNewMessage(group)) 
  {
    int index = 0;
    arrData[0] = "";
    arrData[1] = "";
    arrData[2] = "";
    arrData[3] = "";
    arrData[4] = "";
    arrData[5] = "";
    arrData[6] = "";
    arrData[7] = "";
    
    for (int i=0; i<group.text.length(); i++)
    {
      char delimiter = '#';
      if (group.text[i] != delimiter)        
        {
          arrData[index] += group.text[i];
        }
      else
        {
          index = index + 1;
          delay(10);
        }                                     
    }

    if (index)
    {
      hari = arrData[0].toInt();
      jam1 = arrData[1].toInt();     
      menit1 = arrData[2].toInt();
      jam2 = arrData[3].toInt();
      menit2 = arrData[4].toInt();
      jam3 = arrData[5].toInt();
      menit3 = arrData[6].toInt();
      nilai = arrData[7].toInt();
      
      Serial.println("Atur jadwal....");
      myBot.sendMessage(groupID, "Jadwal berhasil diinputkan");            
    }
    
		if (group.text.equalsIgnoreCase("menu"))   
    {
      myBot.sendMessage(groupID, "Silahkan kirim : \n1. Jadwal = Menginputkan jadwal \n2. Cek = Menampilkan jadwal yang telah disimpan \n3. Reset = Menghapus jadwal yang telah disimpan \n4. Telat = Akses masuk bagi yang terlambat \n5. Buka = Untuk membuka pintu \n6. Tinggal = Akses masuk jika ada sesuatu yang tertinggal diruang kelas");      
    }
    if (group.text.equalsIgnoreCase("jadwal"))
    {
      myBot.sendMessage(groupID, "Silahkan masukkan hari, jam & menit \nFormat : Hari = kode angka 1-6 artinya senin-sabtu#Jam Masuk#Menit Masuk#Jam Keterlambatan#Menit Keterlambatan#Jam Keluar#Menit Keluar# Kode Slot Jadwal <berupa angka dari skala 1-20>");
    }
    if (group.text.equalsIgnoreCase("cek"))
    {
      myBot.sendMessage(groupID, String() +"Jadwal 1 : \nHari = "+day1+"\nJam masuk = "+ hour1 +":"+ minute1 +"\nJam keterlambatan = "+ hour2 +":"+ minute2 + "\nJam keluar = "+ hour3 +":"+minute3+"\nJadwal 2 : \nHari = "+day2+"\nJam masuk = "+ hour4 +":"+ minute4 +"\nJam keterlambatan = "+ hour5 +":"+ minute5 + "\nJam keluar = "+ hour6 +":"+minute6+"\nJadwal 3 : \nHari = "+day3+"\nJam masuk = "+ hour7 +":"+ minute7 +"\nJam keterlambatan = "+ hour8 +":"+ minute8 + "\nJam keluar = "+ hour9 +":"+minute9+"\nJadwal 4 : \nHari = "+day4+"\nJam masuk = "+ hour10 +":"+ minute10 +"\nJam keterlambatan = "+ hour11 +":"+ minute11 + "\nJam keluar = "+ hour12 +":"+minute12+"\nJadwal 5 : \nHari = "+day5+"\nJam masuk = "+ hour13 +":"+ minute13 +"\nJam keterlambatan = "+ hour14 +":"+ minute14 + "\nJam keluar = "+ hour15 +":"+minute15+"\nJadwal 6 : \nHari = "+day6+"\nJam masuk = "+ hour16 +":"+ minute16 +"\nJam keterlambatan = "+ hour17 +":"+ minute17 + "\nJam keluar = "+ hour18 +":"+minute18+"\nJadwal 7 : \nHari = "+day7+"\nJam masuk = "+ hour19 +":"+ minute19 +"\nJam keterlambatan = "+ hour20 +":"+ minute20 + "\nJam keluar = "+ hour21 +":"+minute21+"\nJadwal 8 : \nHari = "+day8+"\nJam masuk = "+ hour22 +":"+ minute22 +"\nJam keterlambatan = "+ hour23 +":"+ minute23 + "\nJam keluar = "+ hour24 +":"+minute24+"\nJadwal 9 : \nHari = "+day9+"\nJam masuk = "+ hour25 +":"+ minute25 +"\nJam keterlambatan = "+ hour26 +":"+ minute26 + "\nJam keluar = "+ hour27 +":"+minute27+"\nJadwal 10 : \nHari = "+day10+"\nJam masuk = "+ hour28 +":"+ minute28 +"\nJam keterlambatan = "+ hour29 +":"+ minute29 + "\nJam keluar = "+ hour30 +":"+minute30+"\nJadwal 11 : \nHari = "+day11+"\nJam masuk = "+ hour31 +":"+ minute31 +"\nJam keterlambatan = "+ hour32 +":"+ minute32 + "\nJam keluar = "+ hour33 +":"+minute33+"\nJadwal 12 : \nHari = "+day12+"\nJam masuk = "+ hour34 +":"+ minute34 +"\nJam keterlambatan = "+ hour35 +":"+ minute35 + "\nJam keluar = "+ hour36 +":"+minute36+"\nJadwal 13 : \nHari = "+day13+"\nJam masuk = "+ hour37 +":"+ minute37 +"\nJam keterlambatan = "+ hour38 +":"+ minute38 + "\nJam keluar = "+ hour39 +":"+minute39+"\nJadwal 14 : \nHari = "+day14+"\nJam masuk = "+ hour40 +":"+ minute40 +"\nJam keterlambatan = "+ hour41 +":"+ minute41 + "\nJam keluar = "+ hour42 +":"+minute42+"\nJadwal 15 : \nHari = "+day15+"\nJam masuk = "+ hour43 +":"+ minute43 +"\nJam keterlambatan = "+ hour44 +":"+ minute44 + "\nJam keluar = "+ hour45 +":"+minute45+"\nJadwal 16 : \nHari = "+day16+"\nJam masuk = "+ hour46 +":"+ minute46 +"\nJam keterlambatan = "+ hour47 +":"+ minute47 + "\nJam keluar = "+ hour48 +":"+minute48+"\nJadwal 17 : \nHari = "+day17+"\nJam masuk = "+ hour49 +":"+ minute49 +"\nJam keterlambatan = "+ hour50 +":"+ minute50 + "\nJam keluar = "+ hour51 +":"+minute51+"\nJadwal 18 : \nHari = "+day18+"\nJam masuk = "+ hour52 +":"+ minute52 +"\nJam keterlambatan = "+ hour53 +":"+ minute53 + "\nJam keluar = "+ hour54 +":"+minute54+"\nJadwal 19 : \nHari = "+day19+"\nJam masuk = "+ hour55 +":"+ minute55 +"\nJam keterlambatan = "+ hour56 +":"+ minute56 + "\nJam keluar = "+ hour57 +":"+minute57+"\nJadwal 20 : \nHari = "+day20+"\nJam masuk = "+ hour58 +":"+ minute58 +"\nJam keterlambatan = "+ hour59 +":"+ minute59 + "\nJam keluar = "+ hour60 +":"+minute60);    
    }
    if (group.text.equalsIgnoreCase("telat") && z==1)   
    {
      digitalWrite(pinrelay1,LOW);
      digitalWrite(ledmerah,HIGH);    
      digitalWrite(pinrelay2,HIGH);
      digitalWrite(ledkuning,HIGH);
      myBot.sendMessage(groupID,"Akses berhasil, Anda terlambat");
      delay(5000);
      digitalWrite(pinrelay1,HIGH);
      digitalWrite(ledmerah,LOW);    
      digitalWrite(pinrelay2,LOW);
      digitalWrite(ledkuning,LOW);               
    }
    if (group.text.equalsIgnoreCase("buka") && b==1)
    {
      digitalWrite(pinrelay2, HIGH);
      digitalWrite(ledkuning, HIGH);
      myBot.sendMessage(groupID,"Silahkan masuk");
      delay(5000);
      digitalWrite(pinrelay2, LOW);
      digitalWrite(ledkuning, LOW);      
    }
    if (group.text.equalsIgnoreCase("tinggal") && tl==1 && a!=1)
    {
      myBot.sendMessage(groupID,"Silahkan scan kartu kelas");
      ketinggalan = 1;                  
    }
    if (group.text.equalsIgnoreCase("reset"))
    {
      hour1 = 0; minute1 = 0; hour2 = 0; minute2 = 0; hour3 = 0; minute3 = 0;
      hour4 = 0; minute4 = 0; hour5 = 0; minute5 = 0; hour6 = 0; minute6 = 0;
      hour7 = 0; minute7 = 0; hour8 = 0; minute8 = 0; hour9 = 0; minute9 = 0;
      hour10 = 0; minute10 = 0; hour11 = 0; minute11 = 0; hour12 = 0; minute12 = 0;
      hour13 = 0; minute13 = 0; hour14 = 0; minute14 = 0; hour15 = 0; minute15 = 0;
      hour16 = 0; minute16 = 0; hour17 = 0; minute17 = 0; hour18 = 0; minute18 = 0;
      hour19 = 0; minute19 = 0; hour20 = 0; minute20 = 0; hour21 = 0; minute21 = 0;
      hour22 = 0; minute22 = 0; hour23 = 0; minute23 = 0; hour24 = 0; minute24 = 0;
      hour25 = 0; minute25 = 0; hour26 = 0; minute26 = 0; hour27 = 0; minute27 = 0;
      hour28 = 0; minute28 = 0; hour29 = 0; minute29 = 0; hour30 = 0; minute30 = 0;
      hour31 = 0; minute31 = 0; hour32 = 0; minute32 = 0; hour33 = 0; minute33 = 0;
      hour34 = 0; minute34 = 0; hour35 = 0; minute35 = 0; hour36 = 0; minute36 = 0;
      hour37 = 0; minute37 = 0; hour38 = 0; minute38 = 0; hour39 = 0; minute39 = 0;
      hour40 = 0; minute40 = 0; hour41 = 0; minute41 = 0; hour42 = 0; minute42 = 0;
      hour43 = 0; minute43 = 0; hour44 = 0; minute44 = 0; hour45 = 0; minute45 = 0;
      hour46 = 0; minute46 = 0; hour47 = 0; minute47 = 0; hour48 = 0; minute48 = 0;
      hour49 = 0; minute49 = 0; hour50 = 0; minute50 = 0; hour51 = 0; minute51 = 0;
      hour52 = 0; minute52 = 0; hour53 = 0; minute53 = 0; hour54 = 0; minute54 = 0;
      hour55 = 0; minute55 = 0; hour56 = 0; minute56 = 0; hour57 = 0; minute57 = 0;
      hour58 = 0; minute58 = 0; hour59 = 0; minute59 = 0; hour60 = 0; minute60 = 0; 
      nilai=0; day1=0; day2=0; day3=0; day4=0; day5=0; day6=0; day7=0; day8=0; day9=0; day10=0;
      day11=0; day12=0; day13=0; day14=0; day15=0; day16=0; day17=0; day18=0; day19=0; day20=0;
      
      EEPROM.write(0, hour1); 
      EEPROM.write(1, minute1); 
      EEPROM.write(2, hour2); 
      EEPROM.write(3, minute2);
      EEPROM.write(4, hour3);
      EEPROM.write(5, minute3);
      EEPROM.write(6, hour4);
      EEPROM.write(7, minute4);
      EEPROM.write(8, hour5);
      EEPROM.write(9, minute5);
      EEPROM.write(10, hour6);
      EEPROM.write(11, minute6);
      EEPROM.write(12, hour7);
      EEPROM.write(13, minute7);
      EEPROM.write(14, hour8);
      EEPROM.write(15, minute8);
      EEPROM.write(16, hour9);
      EEPROM.write(17, minute9);
      EEPROM.write(18, hour10);
      EEPROM.write(19, minute10);
      EEPROM.write(20, hour11);
      EEPROM.write(21, minute11);
      EEPROM.write(22, hour12);
      EEPROM.write(23, minute12);
      EEPROM.write(24, hour13);
      EEPROM.write(25, minute13);
      EEPROM.write(26, hour14);
      EEPROM.write(27, minute14);
      EEPROM.write(28, hour15);
      EEPROM.write(29, minute15);      
      EEPROM.write(30, hour16);
      EEPROM.write(31, minute16);
      EEPROM.write(32, hour17);
      EEPROM.write(33, minute17);
      EEPROM.write(34, hour18);
      EEPROM.write(35, minute18);
      EEPROM.write(36, hour19);
      EEPROM.write(37, minute19);
      EEPROM.write(38, hour20);
      EEPROM.write(39, minute20);
      EEPROM.write(40, hour21);
      EEPROM.write(41, minute21);
      EEPROM.write(42, hour22);
      EEPROM.write(43, minute22);
      EEPROM.write(44, hour23);
      EEPROM.write(45, minute23);    
      EEPROM.write(46, hour24);
      EEPROM.write(47, minute24);
      EEPROM.write(48, hour25);
      EEPROM.write(49, minute25);
      EEPROM.write(50, hour26);
      EEPROM.write(51, minute26);
      EEPROM.write(52, hour27);
      EEPROM.write(53, minute27);
      EEPROM.write(54, hour28);
      EEPROM.write(55, minute28);
      EEPROM.write(56, hour29);
      EEPROM.write(57, minute29);
      EEPROM.write(58, hour30);
      EEPROM.write(59, minute30);
      EEPROM.write(60, hour31); 
      EEPROM.write(61, minute31); 
      EEPROM.write(62, hour32); 
      EEPROM.write(63, minute32);
      EEPROM.write(64, hour33);
      EEPROM.write(65, minute33);
      EEPROM.write(66, hour34);
      EEPROM.write(67, minute34);
      EEPROM.write(68, hour35);
      EEPROM.write(69, minute35);
      EEPROM.write(70, hour36);
      EEPROM.write(71, minute36);
      EEPROM.write(72, hour37);
      EEPROM.write(73, minute37);
      EEPROM.write(74, hour38);
      EEPROM.write(75, minute38);
      EEPROM.write(76, hour39);
      EEPROM.write(77, minute39);
      EEPROM.write(78, hour40);
      EEPROM.write(79, minute40);
      EEPROM.write(80, hour41);
      EEPROM.write(81, minute41);
      EEPROM.write(82, hour42);
      EEPROM.write(83, minute42);
      EEPROM.write(84, hour43);
      EEPROM.write(85, minute43);
      EEPROM.write(86, hour44);
      EEPROM.write(87, minute44);
      EEPROM.write(88, hour45);
      EEPROM.write(89, minute45);      
      EEPROM.write(90, hour46);
      EEPROM.write(91, minute46);
      EEPROM.write(92, hour47);
      EEPROM.write(93, minute47);
      EEPROM.write(94, hour48);
      EEPROM.write(95, minute48);
      EEPROM.write(96, hour49);
      EEPROM.write(97, minute49);
      EEPROM.write(98, hour50);
      EEPROM.write(99, minute50);
      EEPROM.write(100, hour51);
      EEPROM.write(101, minute51);
      EEPROM.write(102, hour52);
      EEPROM.write(103, minute52);
      EEPROM.write(104, hour53);
      EEPROM.write(105, minute53);    
      EEPROM.write(106, hour54);
      EEPROM.write(107, minute54);
      EEPROM.write(108, hour55);
      EEPROM.write(109, minute55);
      EEPROM.write(110, hour56);
      EEPROM.write(111, minute56);
      EEPROM.write(112, hour57);
      EEPROM.write(113, minute57);
      EEPROM.write(114, hour58);
      EEPROM.write(115, minute58);
      EEPROM.write(116, hour59);
      EEPROM.write(117, minute59);
      EEPROM.write(118, hour60);
      EEPROM.write(119, minute60);
      EEPROM.write(120, day1);
      EEPROM.write(121, day2);
      EEPROM.write(122, day3);
      EEPROM.write(123, day4);
      EEPROM.write(124, day5);
      EEPROM.write(125, day6);    
      EEPROM.write(126, day7);
      EEPROM.write(127, day8);
      EEPROM.write(128, day9);
      EEPROM.write(129, day10);
      EEPROM.write(130, day11);
      EEPROM.write(131, day12);
      EEPROM.write(132, day13);
      EEPROM.write(133, day14);
      EEPROM.write(134, day15);
      EEPROM.write(135, day16);
      EEPROM.write(136, day17);
      EEPROM.write(137, day18);
      EEPROM.write(138, day19);
      EEPROM.write(139, day20);      
      EEPROM.commit();
      myBot.sendMessage(groupID, "Jadwal berhasil direset");
    }

    if(nilai == 1)
    {
      day1=hari; hour1=jam1; hour2=jam2; minute1=menit1; minute2=menit2; hour3=jam3; minute3=menit3;     
      EEPROM.write(0, hour1);
      EEPROM.write(1, minute1);
      EEPROM.write(2, hour2);
      EEPROM.write(3, minute2);
      EEPROM.write(4, hour3);
      EEPROM.write(5, minute3);
      EEPROM.write(120, day1);
      EEPROM.commit();      
    }
    else if(nilai == 2)
    {
      day2=hari; hour4=jam1; hour5=jam2; minute4=menit1; minute5=menit2; hour6=jam3; minute6=menit3;   
      EEPROM.write(6, hour4);
      EEPROM.write(7, minute4);
      EEPROM.write(8, hour5);
      EEPROM.write(9, minute5);
      EEPROM.write(10, hour6);
      EEPROM.write(11, minute6);
      EEPROM.write(121, day2);
      EEPROM.commit();      
    }
    else if(nilai == 3)
    {
      day3=hari; hour7=jam1; hour8=jam2; minute7=menit1; minute8=menit2; hour9=jam3; minute9=menit3;
      EEPROM.write(12, hour7);
      EEPROM.write(13, minute7);
      EEPROM.write(14, hour8);
      EEPROM.write(15, minute8);
      EEPROM.write(16, hour9);
      EEPROM.write(17, minute9);      
      EEPROM.write(122, day3);
      EEPROM.commit();                  
    }
    else if(nilai == 4)
    {
      day4=hari; hour10=jam1; hour11=jam2; minute10=menit1; minute11=menit2; hour12=jam3; minute12=menit3;
      EEPROM.write(18, hour10);
      EEPROM.write(19, minute10);
      EEPROM.write(20, hour11);
      EEPROM.write(21, minute11);
      EEPROM.write(22, hour12);
      EEPROM.write(23, minute12);
      EEPROM.write(123, day4);      
      EEPROM.commit();      
    }
    else if(nilai == 5)
    {
      day5=hari; hour13=jam1; hour14=jam2; minute13=menit1; minute14=menit2; hour15=jam3; minute15=menit3;   
      EEPROM.write(24, hour13);
      EEPROM.write(25, minute13);
      EEPROM.write(26, hour14);
      EEPROM.write(27, minute14);
      EEPROM.write(28, hour15);
      EEPROM.write(29, minute15);
      EEPROM.write(124, day5);
      EEPROM.commit();      
    }
    else if(nilai == 6)
    {
      day6=hari; hour16=jam1; hour17=jam2; minute16=menit1; minute17=menit2; hour18=jam3; minute18=menit3;    
      EEPROM.write(30, hour16);
      EEPROM.write(31, minute16);
      EEPROM.write(32, hour17);
      EEPROM.write(33, minute17);
      EEPROM.write(34, hour18);
      EEPROM.write(35, minute18);
      EEPROM.write(125, day6);
      EEPROM.commit();            
    }
    else if(nilai == 7)
    {
      day7=hari; hour19=jam1; hour20=jam2; minute19=menit1; minute20=menit2; hour21=jam3; minute21=menit3;    
      EEPROM.write(36, hour19);
      EEPROM.write(37, minute19);
      EEPROM.write(38, hour20);
      EEPROM.write(39, minute20);
      EEPROM.write(40, hour21);
      EEPROM.write(41, minute21);
      EEPROM.write(126, day7);
      EEPROM.commit();
    }
    else if(nilai == 8)
    {
      day8=hari; hour22=jam1; hour23=jam2; minute22=menit1; minute23=menit2; hour24=jam3; minute24=menit3;    
      EEPROM.write(42, hour22);
      EEPROM.write(43, minute22);
      EEPROM.write(44, hour23);
      EEPROM.write(45, minute23);
      EEPROM.write(46, hour24);
      EEPROM.write(47, minute24);
      EEPROM.write(127, day8);
      EEPROM.commit();
    }
    else if(nilai == 9)
    {
      day9=hari; hour25=jam1; hour26=jam2; minute25=menit1; minute26=menit2; hour27=jam3; minute27=menit3;    
      EEPROM.write(48, hour25);
      EEPROM.write(49, minute25);
      EEPROM.write(50, hour26);
      EEPROM.write(51, minute26);
      EEPROM.write(52, hour27);
      EEPROM.write(53, minute27);
      EEPROM.write(128, day9);
      EEPROM.commit();      
    }
    else if(nilai == 10)
    {
      day10=hari; hour28=jam1; hour29=jam2; minute28=menit1; minute29=menit2; hour30=jam3; minute30=menit3;    
      EEPROM.write(54, hour28);
      EEPROM.write(55, minute28);
      EEPROM.write(56, hour29);
      EEPROM.write(57, minute29);
      EEPROM.write(58, hour30);
      EEPROM.write(59, minute30);
      EEPROM.write(129, day10);      
      EEPROM.commit();
    }
    else if(nilai == 11)
    {
      day11=hari; hour31=jam1; hour32=jam2; minute31=menit1; minute32=menit2; hour33=jam3; minute33=menit3;    
      EEPROM.write(60, hour31);
      EEPROM.write(61, minute31);
      EEPROM.write(62, hour32);
      EEPROM.write(63, minute32);
      EEPROM.write(64, hour33);
      EEPROM.write(65, minute33);      
      EEPROM.write(130, day11);
      EEPROM.commit();      
    }
    else if(nilai == 12)
    {
      day12=hari; hour34=jam1; hour35=jam2; minute34=menit1; minute35=menit2; hour36=jam3; minute36=menit3;      
      EEPROM.write(66, hour34);
      EEPROM.write(67, minute34);
      EEPROM.write(68, hour35);
      EEPROM.write(69, minute35);
      EEPROM.write(70, hour36);
      EEPROM.write(71, minute36);      
      EEPROM.write(131, day12);
      EEPROM.commit();            
    }
    else if(nilai == 13)
    {
      day13=hari; hour37=jam1; hour38=jam2; minute37=menit1; minute38=menit2; hour39=jam3; minute39=menit3;   
      EEPROM.write(72, hour37);
      EEPROM.write(73, minute37);
      EEPROM.write(74, hour38);
      EEPROM.write(75, minute38);
      EEPROM.write(76, hour39);
      EEPROM.write(77, minute39);
      EEPROM.write(132, day13);
      EEPROM.commit();      
    }
    else if(nilai == 14) 
    {
      day14=hari; hour40=jam1; hour41=jam2; minute40=menit1; minute41=menit2; hour42=jam3; minute42=menit3;    
      EEPROM.write(78, hour40);
      EEPROM.write(79, minute40);
      EEPROM.write(80, hour41);
      EEPROM.write(81, minute41);
      EEPROM.write(82, hour42);
      EEPROM.write(83, minute42);      
      EEPROM.write(133, day14);            
      EEPROM.commit();
    }
    else if(nilai == 15)
    {
      day15=hari; hour43=jam1; hour44=jam2; minute43=menit1; minute44=menit2; hour45=jam3; minute45=menit3;    
      EEPROM.write(84, hour43);
      EEPROM.write(85, minute43);
      EEPROM.write(86, hour44);
      EEPROM.write(87, minute44);
      EEPROM.write(88, hour45);
      EEPROM.write(89, minute45);      
      EEPROM.write(134, day15);
      EEPROM.commit();      
    }
    else if(nilai == 16)
    {
      day16=hari; hour46=jam1; hour47=jam2; minute46=menit1; minute47=menit2; hour48=jam3; minute48=menit3;    
      EEPROM.write(90, hour46);
      EEPROM.write(91, minute46);
      EEPROM.write(92, hour47);
      EEPROM.write(93, minute47);
      EEPROM.write(94, hour48);
      EEPROM.write(95, minute48);
      EEPROM.write(135, day16);
      EEPROM.commit();      
    }
    else if(nilai == 17)
    {
      day17=hari; hour49=jam1; hour50=jam2; minute49=menit1; minute50=menit2; hour51=jam3; minute51=menit3;   
      EEPROM.write(96, hour49);
      EEPROM.write(97, minute49);
      EEPROM.write(98, hour50);
      EEPROM.write(99, minute50);
      EEPROM.write(100, hour51);
      EEPROM.write(101, minute51);
      EEPROM.write(136, day17);
      EEPROM.commit();      
    }
    else if(nilai == 18)
    {
      day18=hari; hour52=jam1; hour53=jam2; minute52=menit1; minute53=menit2; hour54=jam3; minute54=menit3;   
      EEPROM.write(102, hour52);
      EEPROM.write(103, minute52);
      EEPROM.write(104, hour53);
      EEPROM.write(105, minute53);
      EEPROM.write(106, hour54);
      EEPROM.write(107, minute54);      
      EEPROM.write(137, day18);
      EEPROM.commit();      
    }
    else if(nilai == 19)
    {
      day19=hari; hour55=jam1; hour56=jam2; minute55=menit1; minute56=menit2; hour57=jam3; minute57=menit3;    
      EEPROM.write(108, hour55);
      EEPROM.write(109, minute55);
      EEPROM.write(110, hour56);
      EEPROM.write(111, minute56);
      EEPROM.write(112, hour57);
      EEPROM.write(113, minute57);      
      EEPROM.write(138, day19);
      EEPROM.commit();      
    }
    else if(nilai == 20)
    {
      day20=hari; hour58=jam1; hour59=jam2; minute58=menit1; minute59=menit2; hour60=jam3; minute60=menit3;    
      EEPROM.write(114, hour58);
      EEPROM.write(115, minute58);
      EEPROM.write(116, hour59);
      EEPROM.write(117, minute59);
      EEPROM.write(118, hour60);
      EEPROM.write(119, minute60);
      EEPROM.write(139, day20);
      EEPROM.commit();      
    }
		
	}
	// wait 500 milliseconds
	delay(500);
}

void waktu()
{
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());
  if(timeClient.isTimeSet()) {
    if(timeClient.getHours() >= jamA && timeClient.getHours() <= jamB) 
    { 
      tl=1;      
    }
    else if(timeClient.getHours() > jamB && timeClient.getHours() < jamA) 
    { 
      tl=0;      
    }
if(timeClient.getDay() == day1 && ((timeClient.getHours() >= hour1 && timeClient.getMinutes() >= minute1) && (timeClient.getHours() <= hour2 && timeClient.getMinutes() < minute2)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");            
    }
    else if(timeClient.getDay() == day1 && timeClient.getMinutes() == minute2)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day1 && timeClient.getHours() == hour3 && timeClient.getMinutes() == minute3)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);      
    }
    else if(timeClient.getDay() == day2 && ((timeClient.getHours() >= hour4 && timeClient.getMinutes() >= minute4) && (timeClient.getHours() <= hour5 && timeClient.getMinutes() < minute5)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day2 && timeClient.getMinutes() == minute5)
    {
      z=1;b=0;      
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day2 && timeClient.getHours() == hour6 && timeClient.getMinutes() == minute6)
    {
      a=0;z=0;
      digitalWrite(ledbiru,LOW);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);                  
    }
    else if (timeClient.getDay() == day3 && ((timeClient.getHours() >= hour7 && timeClient.getMinutes() >= minute7) && (timeClient.getHours() <= hour8 && timeClient.getMinutes() < minute8)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");             
    }
    else if(timeClient.getDay() == day3 && timeClient.getMinutes() == minute8)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day3 && timeClient.getHours() == hour9 && timeClient.getMinutes() == minute9)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }    
    else if(timeClient.getDay() == day4 && ((timeClient.getHours() >= hour10 && timeClient.getMinutes() >= minute10) && (timeClient.getHours() <= hour11 && timeClient.getMinutes() < minute11)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");                      
    }
    else if(timeClient.getDay() == day4 && timeClient.getMinutes() == minute11)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day4 && timeClient.getHours() == hour12 && timeClient.getMinutes() == minute12)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }        
    else if(timeClient.getDay() == day5 && ((timeClient.getHours() >= hour13 && timeClient.getMinutes() >= minute13) && (timeClient.getHours() <= hour14 && timeClient.getMinutes() < minute14)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day5 && timeClient.getMinutes() == minute14)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day5 && timeClient.getHours() == hour15 && timeClient.getMinutes() == minute15)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);            
    }    
    else if(timeClient.getDay() == day6 && ((timeClient.getHours() >= hour16 && timeClient.getMinutes() >= minute16) && (timeClient.getHours() <= hour17 && timeClient.getMinutes() < minute17)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");    
    }
    else if(timeClient.getDay() == day6 && timeClient.getMinutes() == minute17)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day6 && timeClient.getHours() == hour18 && timeClient.getMinutes() == minute18)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }        
    else if(timeClient.getDay() == day7 && ((timeClient.getHours() >= hour19 && timeClient.getMinutes() >= minute19) && (timeClient.getHours() <= hour20 && timeClient.getMinutes() < minute20)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");       
    }
    else if(timeClient.getDay() == day7 && timeClient.getMinutes() == minute20)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day7 && timeClient.getHours() == hour21 && timeClient.getMinutes() == minute21)
    {
      a=0;z=0;
      digitalWrite(ledbiru,LOW);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }            
    else if(timeClient.getDay() == day8 && ((timeClient.getHours() >= hour22 && timeClient.getMinutes() >= minute22) && (timeClient.getHours() <= hour23 && timeClient.getMinutes() < minute23)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");       
    }
    else if(timeClient.getDay() == day8 && timeClient.getMinutes() == minute23)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if (timeClient.getDay() == day8 && timeClient.getHours() == hour24 && timeClient.getMinutes() == minute24)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }
    else if (timeClient.getDay() == day9 && ((timeClient.getHours() >= hour25 && timeClient.getMinutes() >= minute25) && (timeClient.getHours() <= hour26 && timeClient.getMinutes() < minute26)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");      
    }
    else if(timeClient.getDay() == day9 && timeClient.getMinutes() == minute26)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day9 && timeClient.getHours() == hour27 && timeClient.getMinutes() == minute27)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);      
    }
    else if(timeClient.getDay() == day10 && ((timeClient.getHours() >= hour28 && timeClient.getMinutes() >= minute28) && (timeClient.getHours() <= hour29 && timeClient.getMinutes() < minute29)))
    { 
      a=1;b=1;     
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day10 && timeClient.getMinutes() == minute29)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day10 && timeClient.getHours() == hour30 && timeClient.getMinutes() == minute30)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }
    else if(timeClient.getDay() == day11 && ((timeClient.getHours() >= hour31 && timeClient.getMinutes() >= minute31) && (timeClient.getHours() <= hour32 && timeClient.getMinutes() < minute32)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");             
    }
    else if(timeClient.getDay() == day11 && timeClient.getMinutes() == minute32)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day11 && timeClient.getHours() == hour33 && timeClient.getMinutes() == minute33)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);      
    }
    else if(timeClient.getDay() == day12 && ((timeClient.getHours() >= hour34 && timeClient.getMinutes() >= minute34) && (timeClient.getHours() <= hour35 && timeClient.getMinutes() < minute35)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day12 && timeClient.getMinutes() == minute35)
    {
      z=1;b=0;      
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day12 && timeClient.getHours() == hour36 && timeClient.getMinutes() == minute36)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);                  
    }
    else if (timeClient.getDay() == day13 && ((timeClient.getHours() >= hour37 && timeClient.getMinutes() >= minute37) && (timeClient.getHours() <= hour38 && timeClient.getMinutes() < minute38)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");            
    }
    else if(timeClient.getDay() == day13 && timeClient.getMinutes() == minute38)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day13 && timeClient.getHours() == hour39 && timeClient.getMinutes() == minute39)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }    
    else if(timeClient.getDay() == day14 && ((timeClient.getHours() >= hour40 && timeClient.getMinutes() >= minute40) && (timeClient.getHours() <= hour41 && timeClient.getMinutes() < minute41)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");                      
    }
    else if(timeClient.getDay() == day14 && timeClient.getMinutes() == minute41)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day14 && timeClient.getHours() == hour42 && timeClient.getMinutes() == minute42)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }        
    else if(timeClient.getDay() == day15 && ((timeClient.getHours() >= hour43 && timeClient.getMinutes() >= minute43) && (timeClient.getHours() <= hour44 && timeClient.getMinutes() < minute44)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day15 && timeClient.getMinutes() == minute44)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day15 && timeClient.getHours() == hour45 && timeClient.getMinutes() == minute45)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);            
    }    
    else if(timeClient.getDay() == day16 && ((timeClient.getHours() >= hour46 && timeClient.getMinutes() >= minute46) && (timeClient.getHours() <= hour47 && timeClient.getMinutes() < minute47)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");      
    }
    else if(timeClient.getDay() == day16 && timeClient.getMinutes() == minute47)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day16 && timeClient.getHours() == hour48 && timeClient.getMinutes() == minute48)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }        
    else if(timeClient.getDay() == day17 && ((timeClient.getHours() >= hour49 && timeClient.getMinutes() >= minute49) && (timeClient.getHours() <= hour50 && timeClient.getMinutes() < minute50)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");      
    }
    else if(timeClient.getDay() == day17 && timeClient.getMinutes() == minute50)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day17 && timeClient.getHours() == hour51 && timeClient.getMinutes() == minute51)
    {
      a=0;z=0;
      digitalWrite(ledbiru,LOW);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }            
    else if(timeClient.getDay() == day18 && ((timeClient.getHours() >= hour52 && timeClient.getMinutes() >= minute52) && (timeClient.getHours() <= hour53 && timeClient.getMinutes() < minute53)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");       
    }
    else if(timeClient.getDay() == day18 && timeClient.getMinutes() == minute53)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if (timeClient.getDay() == day18 && timeClient.getHours() == hour54 && timeClient.getMinutes() == minute54)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }
    else if (timeClient.getDay() == day19 && ((timeClient.getHours() >= hour55 && timeClient.getMinutes() >= minute55) && (timeClient.getHours() <= hour56 && timeClient.getMinutes() < minute56)))
    {
      a=1;b=1;
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan");      
    }
    else if(timeClient.getDay() == day19 && timeClient.getMinutes() == minute56)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day19 && timeClient.getHours() == hour57 && timeClient.getMinutes() == minute57)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);      
    }
    else if(timeClient.getDay() == day20 && ((timeClient.getHours() >= hour58 && timeClient.getMinutes() >= minute58) && (timeClient.getHours() <= hour59 && timeClient.getMinutes() < minute59)))
    { 
      a=1;b=1;     
      digitalWrite(pinrelay1, LOW);
      digitalWrite(ledmerah, HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Ruang sudah");                                      
      lcd.setCursor(1,1);
      lcd.print("dijadwalkan"); 
    }
    else if(timeClient.getDay() == day20 && timeClient.getMinutes() == minute59)
    {
      z=1;b=0;
      digitalWrite(pinrelay1, HIGH);
      digitalWrite(ledmerah, LOW);
    }
    else if(timeClient.getDay() == day20 && timeClient.getHours() == hour60 && timeClient.getMinutes() == minute60)
    {
      a=0;z=0;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("KELAS PSI 210");
      lcd.setCursor(1,1);
      lcd.print("TEKNIK ELEKTRO");
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
    }    
  }

  delay(1000);  
}