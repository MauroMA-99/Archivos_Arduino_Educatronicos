#include <WiFi.h>
// Con el ESP8266: #include <ESP8266WiFi.h>

IPAddress ip(192,168,2,50);
IPAddress dns(8,8,8,8);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(9600);
  WiFi.begin("MAUROMONTOYA","04021999"); //se habilitará el modo estación
  WiFi.config(ip,dns,gateway,subnet);
  
  while(WiFi.status() != WL_CONNECTED){ 

    delay(200);
    Serial.print(".");
  }
  
  Serial.println(WiFi.localIP()); //Imprimo el IP del esp32
}

void loop() {

}
