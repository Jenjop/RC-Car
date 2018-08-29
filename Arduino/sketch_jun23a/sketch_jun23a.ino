//Preset(

int enA = 5;
int in1 = 2;
int in2 = 3;


void printOut(String out){
    Serial.println(out);
  }

  void printOut(int out){
    Serial.println(out);
  }


 void accel(int startSignal, int endSignal){
    printOut("Accel");
    for (int i = startSignal; i < endSignal; i++)
     {
       printOut(i);
       analogWrite(enA, i);
        delay(200);
     } 
  }
  void accel(int startSignal, int endSignal,int delayTime){
    printOut("Accel");
    for (int i = startSignal; i < endSignal; i++)
     {
       printOut(i);
       analogWrite(enA, i);
        delay(delayTime);
     } 
  }

    void decel(int startSignal, int endSignal){
      printOut("Decel");
    for (int i = startSignal; i > endSignal; i--)
     {
       printOut(i);
       analogWrite(enA, i);
        delay(200);
     } 
  }
  void decel(int startSignal, int endSignal,int delayTime){
    printOut("Decel");
    for (int i = startSignal; i > endSignal; i--)
     {
       printOut(i);
       analogWrite(enA, i);
        delay(delayTime);
     } 
  }

void analog(int startSignal, int endSignal){
    if (startSignal > endSignal)
      decel(startSignal,endSignal); 
    else if(startSignal < endSignal)
        accel(startSignal,endSignal);
      else if (startSignal == endSignal){
        printOut(startSignal);
        analogWrite(enA,startSignal);
        delay(200);
      }    
  }

  void analog(int startSignal, int endSignal, int delayTime){
    if (startSignal > endSignal)
      decel(startSignal,endSignal,delayTime);     
    else if(startSignal < endSignal)
        accel(startSignal,endSignal,delayTime);
      else if (startSignal == endSignal){
        printOut(startSignal);
        analogWrite(enA,startSignal);
        delay(delayTime);
      }    
  }

  void forward(){
    printOut("Forward");
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);
  }
  void backward(){
    printOut("Backward");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH); 
  }
  void stopMotor(){
    printOut("Stopped");
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW); 
  }



// )



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
