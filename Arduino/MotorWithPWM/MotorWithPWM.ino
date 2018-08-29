#include <Motor.h>

//motor 1ww
int enA = 3;
int in1 = 4;
int in2 = 5;

//motor 2
int enB = 6;
int in3 = 7;
int in4 = 8;

//Motor(int in1, int in2, int in3, int in4, int enA, int enB)
Motor motor(in1, in2, in3, in4, enA, enB);


void Main(int duration){
  Serial.println("\n");
  Serial.println("Main");
  
  motor.backward();

  motor.analogBoth(169,255,25);
  motor.analogBothCD(255,255,duration);
  motor.analogBoth(255,60,25);

  motor.stopMotors();
  Serial.println("Complete"); 
}


void setup() {
  motor.usePin(enA);
  motor.usePin(enB);
  motor.usePin(in1);
  motor.usePin(in2);
  motor.usePin(in3);
  motor.usePin(in4);

  //Use Serial Monitor
  Serial.begin(9600);
}

void loop() {
  motor.stopMotors();
  delay(2000);
  Main(5000);
}
