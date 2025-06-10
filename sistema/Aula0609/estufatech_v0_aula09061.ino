#include <Servo.h>
int vml = 5, azl = 6, vrd = 3;
int leitura=0;
Servo aba_sol;
Servo regua_agua;
void setup()
{
  aba_sol.attach(11, 500, 2500);
  regua_agua.attach(10, 500, 2500);
  pinMode(vml, OUTPUT);
  pinMode(azl, OUTPUT);
  pinMode(vrd, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  leitura = analogRead(A0);
  Serial.println(leitura);
  if(leitura<350){
    aba_sol.write(0);
    digitalWrite(azl, HIGH);
    digitalWrite(vml, LOW);
    digitalWrite(vrd, LOW);
    //Motor dever estar em 45 graus irrigar
  }else if(leitura<600){
    aba_sol.write(50);
    digitalWrite(azl, LOW);
    digitalWrite(vml, LOW);
    digitalWrite(vrd, HIGH);
    //Motor dever ficar em 20 graus humidecer
  }else{
    aba_sol.write(90);
    digitalWrite(azl, LOW);
    digitalWrite(vml, HIGH);
    digitalWrite(vrd, LOW);]
    //Motor deve esta a 0 graus sem agua para evitar estufa.
  }
  delay(3000);
}