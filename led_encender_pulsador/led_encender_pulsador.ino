void setup() {
  //Inicializar el pin digital LED_BUILTIN como salida
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}
//La funcion bucle se ejecuta una y otra vez para siempre

void loop() {
  if(Serial.available()>0)
  {
    char letter = Serial.read();
    if(letter == '1'){
    digitalWrite(LED_BUILTIN,HIGH);//Enciende el LED (HIGH es el nivel de tension)
    Serial.println("LED ON");
    delay(1000);}
    else if(letter=='0'){
    digitalWrite(LED_BUILTIN,LOW);//Apaga el LED (haciendo que la tension sea baja)
    delay(1000);//Espera un segundo
    Serial.println("LED OFF");
    }
    }
}
