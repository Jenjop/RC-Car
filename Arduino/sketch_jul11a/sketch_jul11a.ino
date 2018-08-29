#include <Motor.h>
int enA = 3;
int in1 = 4;
int in2 = 5;

int enB = 6; 
int in3 = 7;
int in4 = 8;

Motor motor(in1, in2, in3, in4, enA, enB);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

  pinMode(enA,OUTPUT); // Equivalent of pinMode(enA, OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

}

void loop() {
  Serial.println("begin");
  delay(3000);
//  motor.motor1Forward();
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // put your main code here, to run repeatedly:

}
