void setup() {
  //Inicializar el pin digital LED_BUILTIN como salida
  Serial.begin(9600);
}
//La funcion bucle se ejecuta una y otra vez para siempre

void loop() {
  //Leer la entrada enel pin analogico 0
  int sensorValue = analogRead(A0);
  //Imprimir el valor leido
  Serial.println(sensorValue);
  delay(1);//Retardo entre lecturas para la estabilidad
}
