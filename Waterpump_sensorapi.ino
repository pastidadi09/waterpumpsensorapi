const int sensorPin = A1; // Pin analog untuk sensor MQ-2
const int relayPin = 8;   // Pin digital untuk mengendalikan relay

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  // Ubah nilai pembacaan sensor menjadi suhu dalam derajat Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100;
  
  Serial.print("Suhu saat ini: ");
  Serial.print(tempC);
  Serial.println("°C");
  
  // Jika suhu melebihi nilai tertentu, aktifkan relay
  if (tempC > 400) { // Ganti 50 dengan nilai suhu ambang yang diinginkan
    digitalWrite(relayPin, HIGH); // Aktifkan relay
    Serial.println("Tidak ada api terdeteksi. Relay mati.");
  } else {
    digitalWrite(relayPin, LOW); // Matikan relay
    Serial.println("Api terdeteksi! Relay aktif.");
    
  }
  
  delay(1000); // Tunggu 1 detik sebelum membaca sensor lagi
}
