#include <WiFi.h>
// Con el ESP8266: #include <ESP8266WiFi.h>

void setup(){
  Serial.begin(9600);
  WiFi.begin("Educatronicos","Edu12345"); //se habilitará el modo estación

  // Mientras el ESP32 no se conecte al AP:
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  
  Serial.println(WiFi.localIP()); //Imprimo el IP del esp32
}

void loop() {

}
