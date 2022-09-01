
#define pulso1 9 //defino el pin por el cual saldra la señal de disparo
#define rebote1 8 //defino el pin que recepcionara  el rebote de la señal

float distancia1;
float tiempo1;

int resolucion=255;

void setup()
{
  Serial.begin(9600); 
  pinMode(pulso1,OUTPUT);
  pinMode(rebote1,INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(pulso1,LOW);
  delayMicroseconds(5);
  digitalWrite(pulso1,HIGH);
  delayMicroseconds(10); //Generamos el pulso
  digitalWrite(pulso1,LOW);
  
  tiempo1=pulseIn(rebote1,HIGH);//Tomamos el tiempo
  
  //distancia=(velocidad_sonido)x(tiempo)
  //distancia=(343m/s)x(tiempo1/2)
  //distancia=(1cm/29.2us)x(tiempo1/2)
  distancia1=tiempo1/(29.2*2); //calculamos la distancia
  
  float voltajemedido=resolucion*5/255.0;
  
  if(distancia1>3 && distancia1<200)
  {
    resolucion=255;
    analogWrite(10,resolucion); //analogRead->0-1023/ analogWrite->0-255
  }
  else{
    
    analogWrite(10,resolucion); //analogRead->0-1023/ analogWrite->0-255
    resolucion=resolucion-15;
    
    if(resolucion<=0){
      resolucion=0;
    }
  }
  
  Serial.print("El voltaje medido es: ");
  Serial.println(voltajemedido);
  
  Serial.print("Distancia 1: ");
  Serial.print(distancia1);
  Serial.println(" cm");
  Serial.println();
  delay(500);
}
