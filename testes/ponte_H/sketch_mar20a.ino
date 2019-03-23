const int set1 = 4;
const int set2 = 3;

const int pwm = 5;

const int POT = A8;
int pot = 0;

void setup ()
{
  Serial.begin(115200);
  
  pinMode(set1, OUTPUT);
  pinMode(set2, OUTPUT);
  pinMode(pwm, OUTPUT);

  digitalWrite(pwm, HIGH);
}

void loop ()
{
  pot = analogRead(POT);
  //Serial.println(pot);
  
  if (pot > 600)
  {
    //digitalWrite(set1, HIGH);
    int val = map(pot, 600, 750, 10, 255);
    val = constrain(val, 0, 255);
    Serial.println(val);
    
    analogWrite(set1, val);
    
    digitalWrite(set2, LOW);

    Serial.println("set1");
  }
  else if (pot < 300)
  {
    digitalWrite(set1, LOW);

    int val = map(pot, 0, 300, 255, 10);
    val = constrain(val, 0, 255);
    analogWrite(set2, val);
    //digitalWrite(set2, HIGH); 

    Serial.println("set2");
  }
  else
  {
    digitalWrite(set1, LOW);
    digitalWrite(set2, LOW);

    Serial.println("desligado");
  }
}
