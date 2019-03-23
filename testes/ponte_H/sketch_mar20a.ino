const int set1 = 4;
const int set2 = 3;
const int pwm = 5;

const int POT = 8;

void setup ()
{
  Serial.begin(115200);
  
  pinMode(set1, OUTPUT);
  pinMode(set2, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void loop ()
{
  int pot = analogRead(POT);
  Serial.println(pot);
  
  if (pot > 600)
  {
    digitalWrite(set1, HIGH);
    digitalWrite(set2, LOW);

    //analogWrite(pwm, 120);
    digitalWrite(pwm, HIGH);
  }
  else if (pot < 400)
  {
    digitalWrite(set1, LOW);
    digitalWrite(set2, HIGH); 

    //analogWrite(pwm, 120);
    digitalWrite(pwm, HIGH);
  }
  else
  {
    digitalWrite(set1, LOW);
    digitalWrite(set2, LOW);

    digitalWrite(pwm, LOW);
  }
}
