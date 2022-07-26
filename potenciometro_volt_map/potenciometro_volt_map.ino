void setup() {
  //Inicializar el pin digital LED_BUILTIN como salida
  Serial.begin(9600);
}
//La funcion bucle se ejecuta una y otra vez para siempre

void loop() {
  //Leer la entrada en el pin analogico 0
  int sensorValue = analogRead(A0);
  //Convertir la elctura analogica (que va de 0 a 1023) en una tension (0-5V)
  int val = map(sensorValue,0,1023,0,255);
  //Imprimir el valor leido
  Serial.println(val);
}
