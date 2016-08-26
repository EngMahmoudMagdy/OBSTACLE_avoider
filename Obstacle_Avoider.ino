#include <NewPing.h>
#define trigger 4
#define echo 3
#define maxdistance 4000
#include <Servo.h>

Servo myservo;
int pos = 0;

 NewPing sensor (trigger,echo,maxdistance );

float distRight, distLeft ;  
int en1=8;
int en2=7;
int in1=5;
int in2=6;
int in3=9;
int in4=10;
int vel = 125; 
int right,left,middle;
int us ; 
float distance ; 
void forward(){
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  analogWrite(in1,0);
  analogWrite(in2,vel);
  analogWrite(in3,0);
  analogWrite(in4,vel);

  
}
void right_move(){
   
digitalWrite (in1,LOW);
digitalWrite (in2,LOW);
digitalWrite (in3,LOW);
analogWrite (in4,vel);
  }
  void steep_right_move()
  {

analogWrite (in1,200);
digitalWrite (in2,LOW);
digitalWrite (in3,LOW);
analogWrite (in4,vel);
  }

void left_move(){
  //digitalWrite (en1,HIGH);
//digitalWrite (en2,LOW);
digitalWrite (in1,LOW);
analogWrite (in2,vel);
digitalWrite (in3,LOW);
digitalWrite (in4, LOW  );
  }
  void steep_left_move(){
 // digitalWrite (en1,HIGH);
//digitalWrite (en2,LOW);
digitalWrite (in1,LOW);
analogWrite (in2,vel);
analogWrite (in3,vel);
digitalWrite (in4,LOW   );
  }
  void stop_move(){
  digitalWrite(en1,LOW);
  digitalWrite(en2,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  
void setup() {
///MOTORS
pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

myservo.attach(2);
myservo.write(90);

}

void loop() {
  us = sensor.ping();
  distance = us / US_ROUNDTRIP_CM ; 
  if (distance >10)
  {
    forward();
       myservo.write(90);
    }
else {
     stop_move();
     myservo.write(50);
     us = sensor.ping();
  distRight = us / US_ROUNDTRIP_CM ; 
    delay(700);
     myservo.write(120);
     us = sensor.ping();
  distLeft = us / US_ROUNDTRIP_CM ; 
     delay(700);
     if(distRight > distLeft )
     {
      right_move();
      delay(200);
      }
      else {
        left_move();
      delay(200);
        }
     
}


}
