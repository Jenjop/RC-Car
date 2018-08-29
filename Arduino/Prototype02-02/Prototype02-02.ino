#include <Motor.h>

/*
  ----------------------------
  The entire block (call packet or pdu) always has 5 bytes
  ----------
  [0] inByte0: 0xab -- first byte in the buffer - signature byte
  After the signature byte, the 2nd byte is the command
  [1]inByte1 - Cmd:
   0 - Error
   1 - Start
   2 - Stop
   3 - Run Direction Prefix
   4 - Turn Prefix
   5 - PWM Value Prefix
  [2]inByte2 - Data
  [3]inByte3 - Data
  [4]inByte4 - Ending Signature Byte

*/


//int inByte0 = 0;
//int inByte1Cmd = 0; //Prefix: this byte is a command - tells us what the other 3 bytes are used for
//int inByte2Data = 0; //After Prefix
//int inByte3Data = 0; //After Prefix
//int inByte4Data = 0; //After Prefix
int inByteArray[10]; //Place Read bytes into array
int inByte = 0;
int ipos = 0;
int pwmVal = 0;

//motor 1
int enA = 3;
int in1 = 4;
int in2 = 5;

//motor 2
int enB = 8;
int in3 = 7;
int in4 = 6;

//Comment ! suffix = GPIO Switched out for Serial
//int pinFB = 9;!
//int pinRL = 10;!
//int pinRunning = 11;!
//int pinTurning = 12;!

//int signalFB = 0; //Forward - Backward!
//int signalLR = 0; //Right - Left!
//int signalRunning = 0; //Running - Stop!
//int signalTurning = 0; //Turning - Straight!

//int switchCase = 0;!

//bool isRunning = false;!
int runNumber = -1;
//Motor(int in1, int in2, int in3, int in4, int enA, int enB)
Motor motor(in1, in2, in3, in4, enA, enB);
void enableMotors() {
  enableMotors(255);
}

void enableMotors(int pwm) {
  motor.analog(enA, pwm, pwm, 255);
  motor.analog(enB, pwm, pwm, 255);
}

void turnLeft() {
  motor.motor1Forward();
  motor.motor2Backward();
  enableMotors(255);
}

void turnRight() {
  motor.motor2Forward();
  motor.motor1Backward();
  enableMotors(255);
}

void forward() {
  motor.forward();
  enableMotors(255);
}
void backward() {
  motor.backward();
  enableMotors(255);
}

void setup() {
  //Use Serial Monitor
  Serial.begin(115200);

  motor.usePin(enA); // Equivalent of pinMode(enA, OUTPUT);
  motor.usePin(enB);
  motor.usePin(in1);
  motor.usePin(in2);
  motor.usePin(in3);
  motor.usePin(in4);

  //  pinMode(pinFB, INPUT);!
  //  pinMode(pinRL, INPUT);!
  //  pinMode(pinRunning, INPUT);!
  //  pinMode(pinTurning, INPUT);!


  //  Main(5000);
  //  if (digitalRead(pinRunning) == true)!
  //    isRunning = true;!
  //    Serial.println("Setup Complete");!

}
void loop() {
  ipos = 0;

  while (Serial.available() > 0)
  {
    //reading a byte in the buffer
    inByte = Serial.read();

    //check beginning signature, to start copying the whole command
    if (inByte == 0x80)
    {
      ipos = 0;
      inByteArray[ipos] = inByte;
      Serial.print("Array Header");
      Serial.println(inByte);
    }
    else if (inByte == 0x81) //Break out of loop at ending signature
    {
      ipos++;
      inByteArray[ipos] = inByte;
      Serial.print("Array Footer ");
      Serial.print(ipos);
      Serial.print(" :");
      Serial.println(inByte);
      break;
    }
    else
    {
      ipos++;
      inByteArray[ipos] = inByte;
      Serial.print("Array Inside");
      Serial.println(inByte);
    }
    delay(100);
  }//while end
  switch (inByteArray[1]) {
    case 0x00: //Pass
//      Serial.println("Error");
      break;
    case 0x01: //Start
      Serial.println("Start");
      break;
    case 0x02: //Stop
      Serial.println("Stop");
      break;
    case 0x03: //Run Direction
      Serial.println("Run Direction");
      if (inByteArray[2] == 0x01){
        forward();
      }
      else if (inByteArray[2] == 0x02){
        backward();
      }
      else{
        Serial.print("Error Forward/Backward - Received: ");
        Serial.println(inByteArray[0]);
        Serial.print(" Next: ");
        Serial.println(inByteArray[1]);
        Serial.print(" Next: ")  ;
        Serial.println(inByteArray[2]);
        Serial.print(" Next: ")   ;
        Serial.println(inByteArray[3]);
      }
      break;
    case 0x04: //Turn
      Serial.println("Turn");
      if (inByteArray[2] == 0x01)
        turnLeft();
      else if (inByteArray[2] == 0x02)
        turnRight();
      else{
        Serial.print("Error Left/Right - Received: ");
        Serial.println(inByteArray[0]);
        Serial.print(" Next: ");
        Serial.println(inByteArray[1]);
        Serial.print(" Next: ")  ;
        Serial.println(inByteArray[2]);
        Serial.print(" Next: ")   ;
        Serial.println(inByteArray[3]);
      }
      break;
    case 0x05: //PWM
      Serial.print("PWM: ");
      pwmVal = (int)inByteArray[2];
      Serial.println(pwmVal);
      enableMotors(pwmVal);
      break;
    case 0xEE:
      Serial.println("Test");
      break;
  }
for (int i = 0; i < 10; i++){
    inByteArray[i] = 0x00;
  }


  runNumber++;
}





