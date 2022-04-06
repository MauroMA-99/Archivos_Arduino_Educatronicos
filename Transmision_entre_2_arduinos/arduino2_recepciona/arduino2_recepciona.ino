/***********************
*- Transmisión serial de datos entre dos
*         tarjetas Arduino
************************
Este ejemplo permite una transmisión serial de datos entre
dos tarjetas Arduino.
-La tarjeta 1 realizará el cálculo de temperatura en las tres 
escalas (Celsius, Fahrenheit, Kelvin) y el encendido de LED
para temperaturas normales, bajas y altas.
-En la tarjeta 2 se presentarán las temperaturas en las tres
escalas en una pantalla LCD. El rango de temperatura normal es
de 20 a 25 °C.
***********************/
#include <LiquidCrystal.h>          //Incluimos librería LCD

LiquidCrystal lcd(12,11,5,4,3,2);     //Inicializamos la librería LCD con sus respectivos puertos de configuración.

char datos[13];               //Variable array para capturar datos de llegada
int posicion = 0;             //Variable de posiciónpara datos de llegada.

char *resultado = NULL;           //Variable de segmentación de datos string de llegada.
char separador[] = "CFK";         //Variable separadora de datos (Celsius, Fahrenheit, Kelvin).
int valores[] = {0,0,0};          //Variable de tipo array para almacenar datos segmentados {Celsius, Fahrenheit, Kelvin}
int Grados_Cent;              //Variable para grados centígrados
int Grados_Fahr;              //Variable para grados Fahrenheit
int Kelv;                 //Variable para Kelvin

unsigned long Tiempo_LCD;         //Variable de tiempo para impresión de texto en pantalla LCD.
unsigned long Tiempo_Tx;          //Variable de tiempo para transmisión de datos.

void setup()
{
  lcd.begin(16,2);              //Inicializamos pantalla LCD de 16x2.
  Serial.begin(115200);           //Inicializamos el puerto de comunicación a una velocidad de 115200bps.
  delay(1000);                //Retardo.
  Tiempo_LCD = millis();          //Leemos tiempo de inicio de programa para pantalla LCD.
  Tiempo_Tx = millis();           //Leemos tiempo de inicio de programa para Tx.
}

void loop()
{
  boolean segmentacion;           //Variable para segmentación de datos después de la recepcion de datos.
  
  //Recepción de datos
  while(Serial.available()>0)
  {//Mientras haya datos en el buffer ejecuta la función
    delay(5);   //Ponemos un pequeño retardo para mejorar la recepción de datos
    datos[posicion] = Serial.read();  //Leemos un carácter del string "cadena" de la "posición", luego lee el siguiente carácter con "posición++"
    posicion++; //Aumentamos la variable en 1 para ir leyendo los datos de llegada uno a uno
    segmentacion = true;  //Después de la recepción de datos, aprobamos (true) para introducir la segmentación de datos
  }
  posicion = 0; //Encerramos el contador de posición para empezar de nuevo en la próxima recepción de datos.
  
  //Segmentación de datos.
  if(segmentacion == true)
  {
    int index = 0;
    resultado = strtok(datos, separador); //Separamos los datos correspondientes a C, F y K.
    while((resultado != NULL)&&(index<3))
    {
      valores[index++] = atoi(resultado); //Almacenamos los datos segmentados en el array y los transformamos de string a entero.
      resultado = strtok(NULL, separador);  //Anulamos los resultados para una próxima segmentación.  
    }
    segmentacion = false; //Despues de la segmentación, lo desaprobamos (false) hasta nuevos datos de recepción.  
  }
  
  Grados_Cent = valores[0]; //Leemos los datos correspondientes a grados Celsius en la posición 0 del array.
  Grados_Fahr = valores[1]; //Leemos los datos correspondientes a grados Fahrenheit en la posición 1 del array.
  Kelv = valores[2];  //Leemos los datos correspondientes a Kelvin en la posición 2 del array.
  
  //Impresión en la pantalla LCD
  if((millis()-Tiempo_LCD)>500)
  {
    lcd.clear();  //Limpiamos la pantalla antes de presentar los nuevos datos.
    lcd.setCursor(0,1); //Fijamos el cursor de la pantalla en columna 0, fila 1.
    lcd.print(Grados_Cent); //Imprimimos temperatura en grados Celsius.
    lcd.print("C"); //Imprimimos la unidad.
    lcd.setCursor(6,1); //Fijamos el cursor de la pantalla en columna 6, fila 1
    lcd.print(Grados_Fahr); //Imprimimos temperatura en grados Fahrenheit.
    lcd.print("F"); //Imprimimos la unidad.
    lcd.setCursor(12,1);  //Fijamos el cursor de la pantalla en columna 12, fila 1
    lcd.print(Kelv);  //Imprimimos temperatura en Kelvin
    lcd.print("K"); //Imprimimos la unidad
    Tiempo_LCD = millis();  //Tiempo de actualización
  }
  
  //Transmisión de datos
  if((millis()-Tiempo_Tx)>500)
  {
    if((Grados_Cent>=20)&&(Grados_Cent<=25))
    {
      lcd.setCursor(0,0); //Fijamos el cursor de la pantalla en columna 0, fila 0
      lcd.print("TEMPERATURA NORM");  //Imprimimos comentario
      Serial.print("n");  //Enviamos el carácter n para temperaturas normales.  
    }
    else if (Grados_Cent<20)
    {
      lcd.setCursor(0,0); //Fijamos el cursor de la pantalla en columna 0, fila 0
      lcd.print("TEMPERATURA BAJA");  //Imprimimos comentario
      Serial.print("b");  //Enviamos el carácter b para temperaturas bajas
    }
    else
    {
      lcd.setCursor(0,0); //Fijamos el cursor de la pantalla en columna 0, fila 0.
      lcd.print("TEMPERATURA ALTA");  //Imprimimos comentario
      Serial.print("a");  //Enviamos el carácter a para temepraturas altas
    }
    Tiempo_Tx = millis();  
  }  
}
