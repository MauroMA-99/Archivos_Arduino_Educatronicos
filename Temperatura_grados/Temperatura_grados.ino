/************************
 * Transmisión de temperaturas
 ************************
 *Este programa permite leer la temperatura de un sensor de
 *temperatura TMP36 y enviar por puerto serial temperaturas en grados
 *Celsius, grados Fahrenheit y Kelvin.
 ************************/

 int Sensor_TMP36 = A0;    //Declaramos el puerto analogico A0 para el sensor TMP36.
 int Valor_Analogico = 0; //Declaramos una variable para guardar los datos del sensor.
 float Temperatura = 0.0; //Declaramos una variable para el calculo de temperatura.
 
 //Variables para la conversion de temperatura en las tres escalas.
 float Grados_Cent = 0.0;
 float Grados_Fahr = 0.0;
 float Kelv        = 0.0;
  
 void setup()
 {
   Serial.begin(19200); //Iniciamos el puerto de comunicacion a una velocidad de 19200 bps.
   delay(1000);     //Retardo.
   //Imprimir texto:
   Serial.println("Transmision de Tmperaturas en tres escalas:");
   Serial.println("Escala Celsius, Fahrenheit y Kelvin   ");
 }

 void loop()
 {
   Valor_Analogico = analogRead(Sensor_TMP36);  //Leemos los datos del sensor.
   Temperatura = ((Valor_Analogico*(5000/1024.0))-500)/10; //Calculamos la temperatura
   
   Grados_Cent = Temperatura;       //Grandos centigrados
   Grados_Fahr = (Grados_Cent * 1.8) + 32;  //Grados Fahrenheit
   Kelv        = Grados_Cent + 273.15;    //Kelvin
   
   //Imprimimos las temperaturas en las tres escalas.
   Serial.print("Temperaturas: ");
   Serial.print(Grados_Cent,3);
   Serial.print("'C, ");
   Serial.print(Grados_Fahr,3);
   Serial.print("'F, ");
   Serial.print(Kelv,3);
   Serial.print(" K, ");
   Serial.println();
   delay(1000); //Retardo para transmitir cada segundo.
 }
 
