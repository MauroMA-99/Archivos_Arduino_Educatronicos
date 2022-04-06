/***********************
* - Transmisión serial de datos entre dos
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
int Sensor = A0;      //Asignamos el puerto analógico A0 para el sensor TMP36.
int ValorSensor = 0;    //Variable para el almacenamiento del valor del sensor.
float Temperatura = 0;    //Variable para almacenar el valor de la temperatura.

int Grados_Cent;      //Variable para grados centígrados.
int Grados_Fahr;      //Variable para grados Fahrenheit.
int Kelv;         //Variable para Kelvin.

int Rojo = 10;        //Asignacion del puerto digital 10 para e lcolor rojo.
int Verde = 9;        //Asignacion del puerto digital 9 para el color verde.
int Amarillo = 8;     //Asignacion del puerto digital 8 para el color amarillo.

unsigned long Tiempo_Tx;

void setup()
{
  Serial.begin(115200);   //Iniciamos el puerto de comunicación a una velocidad de 115200 bps.
  delay(1000);        //Retardo
  //Configuramos los puertos digitales 8, 9 y 10 como salidas.
  pinMode(Rojo,OUTPUT);
  pinMode(Verde,OUTPUT);
  pinMode(Amarillo,OUTPUT);
  //Inicializamos los pines 8, 9 y 10 como nivel lógico 0.
  digitalWrite(Rojo,LOW);
  digitalWrite(Verde,LOW);
  digitalWrite(Amarillo,LOW);
  
  Tiempo_Tx = millis();   //Leemos el tiempo de inicio de programa
}

void loop()
{
  ValorSensor = analogRead(Sensor);     //Leemos el valor del sensor.
  Temperatura = ((ValorSensor*(5000/1024.0))-500)/10;
  
  Grados_Cent = (int)Temperatura;     //Grados Celsius o centígrados.
  Grados_Fahr = (int)(Grados_Cent*1.8)+32;  //Grados Fahrenheit
  Kelv = (int)(Grados_Cent+273.15); //Kelvin
  
  //Transmisión de datos
  if((millis()-Tiempo_Tx)>500)  //Transmision en cada segundo 1seg=1000miiseg
  {
    Serial.print(Grados_Cent);  //Transmision en grados centígrados.
    Serial.print("C");      //Enviamos la unidad
    
    Serial.print(Grados_Fahr);  //Transmision en grados Fahrenheit.
    Serial.print("F");      //Enviamos la unidad
    
    Serial.print(Kelv);     //Transmision en Kelvin.
    Serial.print("K");      //Enviamos la unidad
    Tiempo_Tx = millis();   //Tiempo de actualización     
  }
  
  //Recepcion de datos.
  if(Serial.available()>0)
  {
    int datos = Serial.read();  //Lectura de datos.
    if(datos=='a')        //Temperatura alta
    {
      digitalWrite(Rojo,HIGH);  //Encendemos LED para temperaturas altas.
      digitalWrite(Amarillo,LOW);
      digitalWrite(Verde,LOW);
    }
    if(datos=='b')        //Temperatura baja
    {
      digitalWrite(Rojo,LOW); 
      digitalWrite(Amarillo,HIGH);
      digitalWrite(Verde,LOW);  //Encendemos LED para temperaturas altas.
    }
    if(datos=='n')        //Temperatura normal
    {
      digitalWrite(Rojo,LOW); 
      digitalWrite(Amarillo,LOW);
      digitalWrite(Verde,HIGH); //Encendemos LED para temperaturas normales.
    }  
  } 
}
