const int POT = A0;
int ledPIN = 16;
void setup()
{
  Serial.begin(115200);
  pinMode (ledPIN, OUTPUT);
}

void loop()
{
  float pot = analogRead(POT);
  if (pot > 512){
  digitalWrite(ledPIN, HIGH);
  delay (100);
  //digitalWrite(ledPIN, LOW);
 //delay (100);
  }
  else {
    digitalWrite(ledPIN, LOW);
    delay(100);
  }
  Serial.println(pot);
 // delay(100);
}
