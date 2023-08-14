//sensor 1
const int ldrPin1 = A0; // Pin analog untuk membaca data dari sensor LDR
const int ledPin1 = 9; // Pin digital untuk mengontrol LED
//sensor 2
const int ldrPin2 = A1; // Pin analog untuk membaca data dari sensor LDR
const int ledPin2 = 10; // Pin digital untuk mengontrol LED
//sensor 3
const int ldrPin3 = A2; // Pin analog untuk membaca data dari sensor LDR
const int ledPin3 = 11; // Pin digital untuk mengontrol LED

//sensor 1 variabel
int ldrValue1; // Variabel untuk menyimpan nilai bacaan sensor LDR
int ledBrightness1; // Variabel untuk menyimpan tingkat kecerahan LED
//sensor 2 variabel
int ldrValue2; // Variabel untuk menyimpan nilai bacaan sensor LDR
int ledBrightness2; // Variabel untuk menyimpan tingkat kecerahan LED
//sensor 3 variabel
int ldrValue3; // Variabel untuk menyimpan nilai bacaan sensor LDR
int ledBrightness3; // Variabel untuk menyimpan tingkat kecerahan LED

void setup() {
  pinMode(ledPin1, OUTPUT); // Mengatur pin LED sebagai OUTPUT
  pinMode(ledPin2, OUTPUT); // Mengatur pin LED sebagai OUTPUT
  pinMode(ledPin3, OUTPUT); // Mengatur pin LED sebagai OUTPUT
  Serial.begin(9600); // Inisialisasi komunikasi serial untuk pemantauan

  // Mengatur rentang tingkat kecerahan LED sensor1
  ledBrightness1 = map(analogRead(ldrPin1), 0, 1023, 255, 0);
  analogWrite(ledPin1, ledBrightness1); // Mengatur kecerahan awal LED
  // Mengatur rentang tingkat kecerahan LED sensor2
  ledBrightness2 = map(analogRead(ldrPin2), 0, 1023, 255, 0);
  analogWrite(ledPin2, ledBrightness2); // Mengatur kecerahan awal LED
  // Mengatur rentang tingkat kecerahan LED sensor3
  ledBrightness3 = map(analogRead(ldrPin3), 0, 1023, 255, 0);
  analogWrite(ledPin3, ledBrightness3); // Mengatur kecerahan awal LED
}

void loop() {
  ldr_1();
  ldr_2();
  ldr_3();  
}

void ldr_1()
{
  // Membaca nilai dari sensor LDR
  ldrValue1 = analogRead(ldrPin1);

  // Mengubah rentang nilai bacaan sensor LDR menjadi rentang kecerahan LED
  ledBrightness1 = map(ldrValue1, 0, 1023, 255, 0);
  analogWrite(ledPin1, ledBrightness1); // Mengatur tingkat kecerahan LED

  // Mencetak nilai bacaan LDR dan kecerahan LED ke Serial Monitor
  Serial.print("LDR Value1: ");
  Serial.print(ldrValue1);
  Serial.print(", LED Brightness1: ");
  Serial.println(ledBrightness1);

  delay(500); // Menunda selama 500ms sebelum membaca ulang sensor LDR  
}

void ldr_2()
{
  // Membaca nilai dari sensor LDR
  ldrValue2 = analogRead(ldrPin2);

  // Mengubah rentang nilai bacaan sensor LDR menjadi rentang kecerahan LED
  ledBrightness2 = map(ldrValue2, 0, 1023, 255, 0);
  analogWrite(ledPin2, ledBrightness2); // Mengatur tingkat kecerahan LED

  // Mencetak nilai bacaan LDR dan kecerahan LED ke Serial Monitor
  Serial.print("LDR Value2: ");
  Serial.print(ldrValue2);
  Serial.print(", LED Brightness2: ");
  Serial.println(ledBrightness2);

  delay(500); // Menunda selama 500ms sebelum membaca ulang sensor LDR  
}

void ldr_3()
{
  // Membaca nilai dari sensor LDR
  ldrValue3 = analogRead(ldrPin3);

  // Mengubah rentang nilai bacaan sensor LDR menjadi rentang kecerahan LED
  ledBrightness3 = map(ldrValue3, 0, 1023, 255, 0);
  analogWrite(ledPin3, ledBrightness3); // Mengatur tingkat kecerahan LED

  // Mencetak nilai bacaan LDR dan kecerahan LED ke Serial Monitor
  Serial.print("LDR Value3: ");
  Serial.print(ldrValue3);
  Serial.print(", LED Brightness3: ");
  Serial.println(ledBrightness3);

  delay(500); // Menunda selama 500ms sebelum membaca ulang sensor LDR  
}