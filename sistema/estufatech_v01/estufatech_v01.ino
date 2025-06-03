#include <Servo.h>

int leitura=0;
Servo aba_sol;
void setup()
{
  aba_sol.attach(11, 500, 2500);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  leitura = (analogRead(A0)-6);
  Serial.println(leitura);
  if(leitura>=673){
    aba_sol.write(45);
  }else{
    aba_sol.write(0);
  }
  delay(3000);
}