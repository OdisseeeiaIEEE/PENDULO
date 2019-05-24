/*
#include "CNC_CAS_IEEE_UFJF.h"

const int stepsPerRevolution = 200; //1.8 graus por passo
const int p1 = 8;
const int p2 = 9;
const int p3 = 10;
const int p4 = 11;
Stepper_CNC myStepper(stepsPerRevolution, p1, p2, p3, p4);
                                        //D0,D1,D2,D3

int n = 0;

void setup ()
{
  myStepper.setSpeed(160);
  Serial.begin(115200);
}

void loop ()
{
  n++;
  myStepper.step(n);
  delay(10);
}
*/

#include "CNC_CAS_IEEE_UFJF.h"

const int stepsPerRevolution = 200; //1.8 graus por passo
const int p1 = 8;
const int p2 = 9;
const int p3 = 10;
const int p4 = 11;
Stepper_CNC myStepper(stepsPerRevolution, p1, p2, p3, p4);
                                        //D0,D1,D2,D3

int n = 0;

const int POT = A0;

//variáveis globais
int pot = 0;
int pot_max = 0;

void setup ()
{
  myStepper.setSpeed(160);
  Serial.begin(115200);
}

void loop ()
{
  pot = analogRead(POT);

  if(pot > pot_max) // correção do valor máx do potenciometro
    pot_max = pot;
  
  if (pot > 600)
  {
    n++;
    myStepper.step(n);
    
    Serial.print(" _|_ set1");
  }
  else if (pot < 300)
  {
    n--;
    myStepper.step(-n);
    
    Serial.print(" _|_ set1");
  }
  else
  {
    Serial.print("desligado");
  }

  print_dev();
}

void print_dev()
{
  Serial.print(" _|_ pot: ");
  Serial.println(pot);
}
