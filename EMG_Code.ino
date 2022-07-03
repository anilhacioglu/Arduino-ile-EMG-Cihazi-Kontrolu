
int buzzerPin = 12; //BUZZER için gerekli port girişi

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);   //LED için 1. gerekli port girişi
  pinMode(9, OUTPUT);   //LED için 2. gerekli port girişi
  pinMode(10, OUTPUT);   //LED için 3. gerekli port girişi
    
}


// Cihazın girdiği döngü
void loop() {
   int sensorValue = analogRead(A0);  // ANALOG0 dan EMG sensör verileri alınıyor.
  Serial.println(sensorValue);    // EMG Sensör verileri port ekranına yazdırılıyor.
      
      if (sensorValue < 50)  // Sensör alınan değer 50'a kadar ise ilk led yanar
      {
          digitalWrite(8, LOW);    // LED Kapatma
          digitalWrite(9, LOW);    // LED Kapatma
          digitalWrite(10, HIGH);   // LED Açma
          noTone(buzzerPin);    //BUZZER Kapatma
      }
      else if (sensorValue < 100) // Sensör alınan değer 50'ı geçer ise ilk iki led yanar
      {
          digitalWrite(8, LOW);    // LED Kapatma
          digitalWrite(10, HIGH);    // LED Kapatma
          digitalWrite(9, HIGH);   // LED Açma
          tone(buzzerPin,330);    //BUZZER Açma
      }
      
      else // Sensör alınan değer 100'ı geçer ise tüm ledler yanar
      {
          digitalWrite(10, HIGH);    // LED Kapatma
          digitalWrite(9, HIGH);    // LED Kapatma
          digitalWrite(8, HIGH);    // LED Açma
          tone(buzzerPin,440);    //BUZZER Açma
      }
      
      
  delay(100);   // Sensör verileri daha stabil olması için gecikme kullanılıyor. Gecikme (100 = 0.1 Saniye)
