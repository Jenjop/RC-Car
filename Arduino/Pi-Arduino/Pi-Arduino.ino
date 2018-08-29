
int ledPin = 3;
int piPin = 4;
int piSignal = 0;
int i = 0;
int j = 1;
int k = 2;
int prevSig = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(piPin, INPUT);  
  Serial.begin(9600);

}

void loop() {
  piSignal = digitalRead(piPin);
  if (prevSig != piSignal)
    Serial.println(piSignal);
  
while (piSignal == HIGH){
    if (i !=  k)
      Serial.println("While Loop");
    
    digitalWrite(ledPin, HIGH);
    delay(1000);
//    digitalWrite(ledPin, LOW);
//    delay(1000);  
    i ++;
    k = i;
    piSignal = digitalRead(piPin);
}
if (i != j)
    Serial.println("While Loop Ended");

digitalWrite(ledPin,LOW);  
delay (1000);
j = i;
k++;
prevSig = piSignal;

}
