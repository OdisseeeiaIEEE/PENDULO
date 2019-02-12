const int set1 = 2;
const int set2 = 3;

void setup()
{
  Serial.begin(115200);

  pinMode(set1, OUTPUT);
  pinMode(set2, OUTPUT);
}

void loop()
{
  digitalWrite(set1, HIGH);
  digitalWrite(set2, LOW);

  delay(1000);

  digitalWrite(set1, LOW);
  digitalWrite(set2, HIGH);

  delay(1000);
  
  /*
  Serial.println("set1");
  for(int i = 0; i < 255; i += 50)
  {
    pwm(i, true);
    delay(200); 

    Serial.println(i);
  }

  delay(2000);

  Serial.println("desligar");
  deligar();
  delay(1000);


  Serial.println("set2");
  for(int i = 0; i < 255; i += 50)
  {
    pwm(i, false);
    delay(200);

    Serial.println(i);
  }

  delay(2000);

  Serial.println("desligar");
  deligar();
  delay(1000);
  */
}

void pwm(int pwm, boolean sentido)
{
  if(sentido)
  {
    analogWrite(set1, pwm);
    digitalWrite(set2, LOW); 
  }
  else if(!sentido)
  {
    digitalWrite(set1, LOW);
    //analogWrite(set2, pwm);
    digitalWrite(set2, HIGH);
  }
}


void deligar()
{
  digitalWrite(set1, LOW);
  digitalWrite(set2, LOW);
}
