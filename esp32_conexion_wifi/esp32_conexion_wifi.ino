#include <WiFi.h> // Con el ESP8266: #include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void setup(){
  
  setup_wifi();
  client.setServer("44.204.191.227",1883);
}

void loop(){

  if(!client.connected()){

    reconnect();
  }

  client.publish("canal","1");
  delay(3000);
}

// Funciones creadas

void reconnect(){

  if(client.connect("ESP32")){
    Serial.println("Conexión exitosa");
  }
}

void setup_wifi(){

  Serial.begin(9600);
  WiFi.begin("Educatronicos","Edu12345"); //se habilitará el modo estación

  // Mientras el ESP32 no se conecte al AP:
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  
  //Serial.println(WiFi.localIP()); //Imprimo el IP del esp32
}
