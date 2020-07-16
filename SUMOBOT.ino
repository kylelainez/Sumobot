#include <NewPing.h>

NewPing sonar1(A0,A1,100);
NewPing sonar2(A2,A3,100);

//Motor Pins
int ena = 9;
int in1 = 4;
int in2 = 5;
int enb = 10;
int in3 = 6;
int in4 = 7;

//Assigning Values
int s1value=0;
int s2value=0;
int ir1=0;
int ir2=0;
int enemy=0;

void setup()
{
  pinMode(A4, INPUT);//IR LEFT
  pinMode(A5, INPUT);//IR RIGHT
  //Motor Pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void stop()
{
  analogWrite(ena,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(enb,0);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void accelerateSlow()
{
  analogWrite(ena,150);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,150);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void acclerateLeft()
{
  analogWrite(ena,250);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,150);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void accelerateRight()
{
  analogWrite(ena,150);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,250);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void accelerateFast(){
  analogWrite(ena,250);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,250);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void left()
{
  analogWrite(ena,75);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,150);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void right()
{
  analogWrite(ena,100);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb,75);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void reverse()
{
  analogWrite(ena,150);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enb,150);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void turnLeft()
{
  analogWrite(ena,150);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enb,150);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void checkFloor()
{
  ir1=digitalRead(A4);
  ir2=digitalRead(A5);
  if((ir1==LOW)&&(ir2==LOW)){
    accelerateSlow();
  }
   if((ir1==LOW)&&(ir2==HIGH)){
    left();
    delay(250);
  }
   if((ir1==HIGH)&&(ir2==LOW)){
    right();
    delay(250);
  }
  if((ir1==HIGH)&&(ir2==HIGH)){
    stop();
    delay(250);
    reverse();
    delay(250);
    turnLeft();
    delay(250);
    accelerateSlow();
  }
}

void sonar()
{
  s1value=sonar1.ping_cm();
  s2value=sonar2.ping_cm();
  delay(50);

  if ((s1value>0)||(s2value>0)){
    enemy = 1;
  }
  if (enemy==1){
    if ((s1value>0)&&(s2value==0)){
    acclerateLeft();
    delay(100);
  }
  if ((s1value==0)&&(s2value>0)){
    accelerateRight();
    delay(100);
  }
  if ((s1value>0)&&(s2value>0)){
    accelerateFast();
    delay(100);
  }
  }
  if (enemy==0){
    checkFloor();
    delay (250)
  }
}
void loop() {
  sonar();
}
