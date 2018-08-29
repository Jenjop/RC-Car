// connect motor controller pins to Arduino digital pins


// DemoTwo up 170
//DemoTwo Noise 230
//DemmoTwo Down


//motor1
int enA = 11;
int in1 = 8;
int in2 = 9;

//motor2
int enB = 5;
int in3 = 3;
int in4 = 2;



//method start
void printOut(String out){
    Serial.println(out);
  }

void printOut(int out){
    Serial.println(out);
  }


 void accel(int pin, int startSignal, int endSignal){
    printOut("Accel");
    for (int i = startSignal; i < endSignal; i++)
     {
       printOut(i);
       analogWrite(pin, i);
        delay(200);
     } 
  }
  void accel(int pin, int startSignal, int endSignal,int delayTime){
    printOut("Accel");
    for (int i = startSignal; i < endSignal; i++)
     {
       printOut(i);
       analogWrite(pin, i);
        delay(delayTime);
     } 
  }

    void decel(int pin, int startSignal, int endSignal){
      printOut("Decel");
    for (int i = startSignal; i > endSignal; i--)
     {
       printOut(i);
       analogWrite(pin, i);
        delay(200);
     } 
  }
  void decel(int pin, int startSignal, int endSignal,int delayTime){
    printOut("Decel");
    for (int i = startSignal; i > endSignal; i--)
     {
       printOut(i);
       analogWrite(pin, i);
        delay(delayTime);
     } 
  }

void analog(int pin, int startSignal, int endSignal){
    if (startSignal > endSignal)
      decel(pin, startSignal,endSignal); 
    else if(startSignal < endSignal)
        accel(pin, startSignal,endSignal);
      else if (startSignal == endSignal){
        printOut(startSignal);
        analogWrite(pin,startSignal);
        delay(200);
      }    
  }

  void analog(int pin,int startSignal, int endSignal, int delayTime){
    if (startSignal > endSignal)
      decel(pin, startSignal,endSignal,delayTime);     
    else if(startSignal < endSignal)
        accel(pin, startSignal,endSignal,delayTime);
      else if (startSignal == endSignal){
        printOut(startSignal);
        analogWrite(pin,startSignal);
        delay(delayTime);
      }    
  }

  void forward1(){
    printOut("Forward");
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);
  }
  void forward2(){
    printOut("Forward");
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW);
  }
  
  void backward1(){
    printOut("Backward");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH); 
  }
  void backward2(){
    printOut("Backward");
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
  }
  
  void stopMotor1(){
    printOut("Stopped");
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW); 
  }
  void stopMotor2(){
    printOut("Stopped");
    digitalWrite(in3, LOW); 
    digitalWrite(in4, LOW); 
  }

//  void backward(){
//  backward1();
//  backward2();
//}
//
//void forward(){
//  forward1();
//  forward2();
//}
//
//void stopMotor(){
//  stopMotor1();
//  stopMotor2();
//}
//
//void analogBoth(int startValue, int endValue, int delayTime){
//  analog(enA,startValue,endValue,delayTime);
//  analog(enB,startValue,endValue,delayTime);
//}
//
//void analogBoth(int startValue, int endValue){
//  analog(enA,startValue,endValue);
//  analog(enB,startValue,endValue);
//}

  //method stop
  





 
  
void demoOne()
{
  Serial.println("demoOne");
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  Serial.println("Analog1");
  analogWrite(enA, 50);
////   turn on motor B
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  // set speed to 200 out of possible range 0~255
//  analogWrite(enB, 200);
  delay(2000);
  // now change motor directions
  Serial.println("FLip");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  Serial.println("off");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
}
void demoTwo()
{
  Serial.println("demoTwo");
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH); 
  // accelerate from zero to maximum speed
  Serial.println("Accel");
  for (int i = 120; i < 256; i++)
  {
    Serial.println(i);
    analogWrite(enA, i);
//    analogWrite(enB, i);
    delay(200);
  } 
  // decelerate from maximum speed to zero
  Serial.println("decel");
  for (int i = 255; i >= 0; --i)
  {
    Serial.println(i);
    analogWrite(enA, i);
//    analogWrite(enB, i);
    delay(200);
  } 
  // now turn off motors
  Serial.println("off");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);  
}

void demoThree()
{
  Serial.println("demoFour");
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);  
  Serial.println("Accel");
  for (int i = 120; i < 256; i++)
  {
    Serial.println(i);
    analogWrite(enA, i);
//    analogWrite(enB, i);
    delay(200);
  } 
  Serial.println("decel");
  for (int i = 255; i >= 0; --i)
  {
    Serial.println(i);
    analogWrite(enA, i);
    delay(200);
  } 
  Serial.println("off");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
}

void demoFour(){
  Serial.println("demoTwo");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  Serial.println("Accel");
  for (int i =  250; i <255 ; i++)
  {
    Serial.println(i);
    analogWrite(enA, i);
    delay(100);
  } 

    for (int i = 255; i >= 100; --i)
  {
    Serial.println(i);
    analogWrite(enA, i);
    delay(100);
  } 

    for (int i = 100; i >= 65; --i)
  {
    Serial.println(i);
    analogWrite(enA, i);
    delay(1000);
  } 

  
  
  Serial.println("decel");
  for (int i = 65; i >= 0; --i)
  {
    Serial.println(i);
    analogWrite(enA, i);
    delay(2000);
  } 
  Serial.println("off");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
}


void mainTest()
{
  printOut("\n");
  printOut("Main"); 
  
 backward();  
  
  analog(169,256,25);
  
  analog(255,255,10000);
  
  analog(256,60,25);
  
  printOut("Off");
  stopMotor();  
}


void backward(){
  backward1();
  backward2();
}

void forward(){
  forward1();
  forward2();
}

void stopMotor(){
  stopMotor1();
  stopMotor2();
}

void analogBoth(int startValue, int endValue, int delayTime){
  analog(enA,startValue,endValue,delayTime);
  analog(enB,startValue,endValue,delayTime);
}

void analogBoth(int startValue, int endValue){
  analog(enA,startValue,endValue);
  analog(enB,startValue,endValue);
}





void runDuration(int duration)
{
  printOut("\n");
  printOut("Main"); 
  
 backward();  
  
  analogBoth(169,255,25);
//  int sv= 169;
//  int ev= 255;
//  int dt= 25;
//  analog(enA,sv,ev,dt);
//  analog(enB,sv,ev,dt);

  analogBoth(255,255,25);
//  int sv1= 255;
//  int ev1= 255;
//  int dt1= 25;
//  analog(enA,sv1,ev1,dt1);
//  analog(enB,sv1,ev1,dt1);
  
  analogBoth(255,60,25);
//  int sv2= 255;
//  int ev2= 60;
//  int dt2= 25;
//  analog(enA,sv2,ev2,dt2);
//  analog(enB,sv2,ev2,dt2);
  
  printOut("Off");
  stopMotor();  
}


void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
stopMotor();
delay(2000);
runDuration(5000);
  
}



