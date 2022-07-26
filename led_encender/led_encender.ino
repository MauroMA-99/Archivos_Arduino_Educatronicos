void setup() {
  //Inicializar el pin digital LED_BUILTIN como salida
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);

}
//La funcion bucle se ejecuta una y otra vez para siempre

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);//encender el LED (HIGH nivel de Tension)
  Serial.println("LED ON");
  delay(2000);                    //Espera 2 segundo
  digitalWrite(LED_BUILTIN,LOW);//Apaga el LED haciendo la Tension Baja
  Serial.println("LED OFF");
  delay(2000);                  //Espera 2 segundo
  
}
