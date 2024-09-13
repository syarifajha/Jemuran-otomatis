#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6mTFgrNr2"
#define BLYNK_TEMPLATE_NAME "Smartjemuran"
#define BLYNK_AUTH_TOKEN "sk-O0mjmta29zveCWoV1ojJNl7SJrjGo"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#define VIRTUAL_PIN V0

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Student_UMPO";
char pass[] = "";

// Definisikan pin
const int ldrPin = A0;        // Pin untuk LDR
const int rainSensorPin = D1; // Pin untuk sensor hujan
const int servoPin = D5;      // Pin untuk servo motor

// Variabel untuk pembacaan sensor
int ldrValue = 0;
int rainValue = 0;

// Inisialisasi servo
Servo myServo;

// Variabel untuk menyimpan status jemuran
bool deviceOn = false;

void setup() {
  // Mulai komunikasi serial
  Serial.begin(115200);
  Serial.println("Memulai koneksi ke WiFi...");
  
  Blynk.begin(auth, ssid, pass);
  
  // Inisialisasi pin
  pinMode(ldrPin, INPUT);
  pinMode(rainSensorPin, INPUT);

  // Mengattach servo ke pin yang ditentukan
  myServo.attach(servoPin);
  
  // Mengatur posisi awal servo (tutup jemuran)
  myServo.write(0);
}

void loop() {
  Blynk.run();
  
  // Baca nilai dari LDR
  ldrValue = analogRead(ldrPin);
  // Baca nilai dari sensor hujan
  rainValue = digitalRead(rainSensorPin);

  // Debugging output
  Serial.print("Intensitas Cahaya: ");
  Serial.println(ldrValue);
  Serial.print("Status Sensor Hujan: ");
  Serial.println(rainValue);

  // Kirim nilai intensitas cahaya ke gauge di Blynk
  Blynk.virtualWrite(V1, ldrValue);

  // Logika kontrol jemuran
  if (rainValue == LOW) { // Sensor hujan mendeteksi air
    Blynk.virtualWrite(VIRTUAL_PIN, LOW); // Mematikan tombol di aplikasi Blynk
    Serial.println("Hujan terdeteksi! Menutup jemuran.");
    myServo.write(0); // Tutup jemuran
  } else if (ldrValue > 300) { // Jika nilai LDR tinggi (cahaya terang)
    Serial.println("Cahaya tinggi terdeteksi! Membuka jemuran.");
    myServo.write(180); // Buka jemuran
  } else {
    Serial.println("Cahaya rendah terdeteksi! Menutup jemuran.");
    myServo.write(0); // Tutup jemuran
  }

  // Tunggu 2 detik sebelum pengulangan
  delay(2000);
}

// Fungsi ini dipanggil ketika tombol Blynk ditekan
BLYNK_WRITE(VIRTUAL_PIN) {
  int pinValue = param.asInt();
  
  if (pinValue == 1) {
    deviceOn = true;
    myServo.write(5); // Buka jemuran
    Serial.println("Device turned on via Blynk.");
  } else {
    deviceOn = false;
    myServo.write(0); // Tutup jemuran
    Serial.println("Device turned off via Blynk.");
  }
}
