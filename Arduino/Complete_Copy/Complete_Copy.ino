#include <Motor.h>

//motor 1
int enA = 3;
int in1 = 4;
int in2 = 5;

//motor 2
int enB = 8; 
int in3 = 7;
int in4 = 6;

int pinFB = 9;
int pinRL = 10;
int pinRunning = 11;
int pinTurning = 12;

int signalFB = 0; //Forward - Backward
int signalLR = 0; //Right - Left
int signalRunning = 0; //Running - Stop
int signalTurning = 0; //Turning - Straight

int switchCase = 0;
bool isRunning = false;
int runNumber = -1;
//Motor(int in1, int in2, int in3, int in4, int enA, int enB)
Motor motor(in1, in2, in3, in4, enA, enB);

//Motor 1 -> right side
//Motor 2 -> left side


void enableMotors(){
  enableMotors(255);
}

void enableMotors(int pwm){
  motor.analog(enA,pwm,pwm,255);
  motor.analog(enB,pwm,pwm,255);
}

void turnLeft(){
  motor.motor1Forward();
  motor.motor2Backward(); 
  enableMotors(255);
}

void turnRight(){
  motor.motor2Forward();
  motor.motor1Backward();
  enableMotors(255);
}

void forward(){
  motor.forward();  
  enableMotors(255);
}
void backward(){
  motor.backward();
  enableMotors(255);
}

/*
void Main(int duration){
  Serial.println("\n");
  Serial.println("Main");
//  
//  motor.backward();
//
//  motor.analogBoth(169,255,25);
//  motor.analogBothCD(255,255,duration);
//  motor.analogBoth(255,60,25);
//
//  motor.stopMotors();

  Serial.println("Forward");
  forward();
  delay(duration);
  Serial.println("Stop");
  motor.stopMotors();
  delay(duration);
  Serial.println("Backward");
  backward();
  delay(duration);
  Serial.println("Stop");
  motor.stopMotors();
  delay(duration);
  Serial.println("Left");
  turnLeft();
  delay(duration);
  Serial.println("Right");
  turnRight();
  delay(duration);
  
  Serial.println("Complete"); 
}
*/


void setup() {
  //Use Serial Monitor
  Serial.begin(9600);
  
  motor.usePin(enA); // Equivalent of pinMode(enA, OUTPUT);
  motor.usePin(enB);
  motor.usePin(in1);
  motor.usePin(in2);
  motor.usePin(in3);
  motor.usePin(in4);

  pinMode(pinFB, INPUT);  
  pinMode(pinRL, INPUT);  
  pinMode(pinRunning, INPUT);
  pinMode(pinTurning, INPUT);


//  Main(5000);
  if (digitalRead(pinRunning) == true)
    isRunning = true;
    Serial.println("Setup Complete");

}

void loop() {
//  /* 
  
//  Serial.println("start");
Serial.println("\n");

  signalRunning = digitalRead(pinRunning);
//  Serial.println(1);
  signalFB = digitalRead(pinFB);
//  Serial.println(2);
  signalTurning = digitalRead(pinTurning);
//  Serial.println(3);
  signalLR = digitalRead(pinRL);
//  Serial.println(4);
  delay(1000);
//  Serial.println("Delay Complete");


 //Part 1
 //Stores Variables based on input from pi to be run in part 2
  if (signalRunning == HIGH){ //Should car be running
    if (runNumber == -1) //CHeck if it's the first run
      runNumber = 0;
    if(signalTurning == LOW){ //Should the car be turning
    
      if (signalFB == HIGH){ //Should car be going forward
        switchCase = 1;
//        Serial.println("Forward Command Received");
      }
      else if (signalFB == LOW){ //Should car be going backward
        switchCase = 2;
//        Serial.println("Backward Command Received");
      }
    }
    else if (signalTurning == HIGH){ //Should car be Turning
      
      if (signalLR == HIGH){ //Should car be turning left
        switchCase = 3;
//        Serial.println("Left Command Received");
      }
      else if (signalLR == LOW){ //Should car be turning right
        switchCase = 4;
//        Serial.println("Right Command Received");
      }
    }
    else{
      switchCase = 0; //error
//      Serial.println("Erroneous Command Received");
    }

   //Part 2
   switch(switchCase){ //Uses Stored Variables from Part 1to Transmit Command to Motor Controller
     case 1:
       forward();
       Serial.println("Running Forward");
       break;
        
      case 2:
       backward();
       Serial.println("Running Backward");
       break;
        
      case 3:
       turnLeft();
       Serial.println("Turning Left");
        break;
        
      case 4:
       turnRight();
       Serial.println("Turning Right");
       break;
        
      case 0:
      Serial.println("Error: No Change in Movement");
        break;
    }
  }

  //Part 3 - Bypassed if the car should be running
  while(signalRunning == LOW){ //While car is not running
    if (runNumber == -1){ //Check if it's the first run
      Serial.println("Stopped");
      runNumber = 0;
    }
      
    if (isRunning == true){
      motor.stopMotors();
      Serial.println("Stopped");
      isRunning = false;
    }
    signalRunning = digitalRead(pinRunning); //Recheck Running Status
  }
  isRunning = true;
  
  /*
  //Debugging
  Serial.print("Running ");
  Serial.println(signalRunning);
  Serial.print("Forward ");
  Serial.println(signalFB);
  Serial.print("Left ");
  Serial.println(signalLR);
  */
//  motor.forward();
//motor.motor1Forward();
//enableMotors(); //Send Analog Signal, not needed if jumper is on enA and enB

//  delay(500); //Interval before data is read again
  runNumber++;
}
