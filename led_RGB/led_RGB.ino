int PinPot1 = A0;
int PinPot2 = A1;
int PinPot3 = A2;
int PinLed_R = 6;
int PinLed_G = 10;
int PinLed_B = 11;

void setup()
{
  pinMode(PinLed_R, OUTPUT);
  pinMode(PinLed_G, OUTPUT);
  pinMode(PinLed_B, OUTPUT);
}

void loop()
{
  int potValue;
  int ledValue;
  potValue = analogRead(PinPot1);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(PinLed_R, ledValue);

  potValue = analogRead(PinPot2);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(PinLed_G, ledValue);
  
  potValue = analogRead(PinPot3);
  ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(PinLed_B, ledValue);
 }
