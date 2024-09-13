Proyek jemuran otomatis dengan menggunakan sensor LDR (Light Dependent Resistor) dan Blynk adalah sebuah sistem yang dapat menggerakkan jemuran secara otomatis berdasarkan intensitas cahaya matahari dan dapat dipantau serta dikontrol melalui aplikasi Blynk pada smartphone. Sistem ini membantu dalam mengeringkan pakaian dan melindunginya dari hujan secara otomatis tanpa intervensi manual.

Komponen yang Dibutuhkan
Microcontroller: Arduino atau NodeMCU (ESP8266/ESP32) dengan koneksi WiFi.
Sensor LDR: Untuk mendeteksi intensitas cahaya matahari.
Relay Module: Untuk mengontrol motor yang menggerakkan jemuran.
Motor DC atau Motor Servo: Untuk menggerakkan jemuran ke dalam atau keluar.
Modul WiFi: Jika menggunakan Arduino, diperlukan modul WiFi seperti ESP8266; jika menggunakan NodeMCU/ESP32, sudah terdapat WiFi bawaan.
Aplikasi Blynk: Untuk monitoring dan kontrol sistem secara jarak jauh.
Baterai/Adaptor: Untuk suplai daya ke microcontroller dan motor.
Kabel, Resistor, dan Breadboard: Untuk pengkabelan dan rangkaian.
Cara Kerja Sistem
Sensor LDR mendeteksi intensitas cahaya. Jika cahaya matahari cukup terang, maka jemuran akan tetap berada di luar.
Jika intensitas cahaya turun di bawah ambang batas tertentu (menandakan hari mendung atau hujan), maka microcontroller akan mengaktifkan relay untuk menggerakkan motor yang menarik jemuran ke dalam.
Sistem juga akan terhubung ke aplikasi Blynk melalui WiFi, memungkinkan pengguna untuk memantau status jemuran dan mengontrol secara manual jika diperlukan.
Skema Rangkaian
Hubungkan LDR ke microcontroller (misalnya, Arduino atau NodeMCU) pada salah satu pin analog (misalnya, A0) dan ground (GND). Tambahkan resistor pull-down untuk mengatur sensitivitas.
Sambungkan Relay Module ke pin digital microcontroller (misalnya, D2) untuk mengontrol motor.
Hubungkan motor DC atau servo ke relay.
Pasangkan modul WiFi (jika menggunakan Arduino) atau gunakan NodeMCU/ESP32 untuk menghubungkan ke jaringan WiFi.
Instal aplikasi Blynk dan buat project baru, tambahkan widget yang sesuai (misalnya, indikator untuk cahaya dan tombol untuk mengontrol relay).
