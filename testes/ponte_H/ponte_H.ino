/*
  Code de teste feito para ser usado com aquela ponte H vermelha com dissipador
  23/03/2019
*/

//pinagem
const int set1 = 4;
const int set2 = 3;

const int POT = A0;

//variáveis globais
int pot = 0;
int pot_max = 0;

void setup ()
{
  Serial.begin(115200);
  
  pinMode(set1, OUTPUT);
  pinMode(set2, OUTPUT);
}

void loop ()
{
  pot = analogRead(POT);

  if(pot > pot_max) // correção do valor máx do potenciometro
    pot_max = pot;
  
  if (pot > 600)
  {
    //digitalWrite(set1, HIGH);

    //fazer controle de vel
    int val = map(pot, 600, pot_max, 10, 255);
    val = constrain(val, 0, 255); 
    analogWrite(set1, val);
    Serial.print("val: ");
    Serial.print(val); 
    
    digitalWrite(set2, LOW);
  
    Serial.print(" _|_ set1");
  }
  else if (pot < 300)
  {
    digitalWrite(set1, LOW);

    //fazer controle de vel
    int val = map(pot, 0, 300, 255, 10);
    val = constrain(val, 0, 255);
    analogWrite(set2, val);

    Serial.print("val: "); 
    Serial.print(val); 
    Serial.print(" _|_ set2");
  }
  else
  {
    digitalWrite(set1, LOW);
    digitalWrite(set2, LOW);

    Serial.print("desligado");
  }

  print_dev();
}

void print_dev()
{
  Serial.print(" _|_ pot: ");
  Serial.println(pot);
}

