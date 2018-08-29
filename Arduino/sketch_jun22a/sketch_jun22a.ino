void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("Moving");
//  digitalWrite(2,HIGH);
//  digitalWrite(3,LOW);
//  delay(3000);
//  digitalWrite(2,LOW);
//  delay(250);
//  Serial.println("Delay1");
//  Serial.println("Stopped");
//  digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
//  delay(3000);
//  Serial.println("Delay2");
//  digitalWrite(3,LOW);
//  delay(250);
Serial.println("10");
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
analogWrite(5,10);

delay(4000);

Serial.println("REST");
digitalWrite(3,LOW);

delay(4000);

Serial.println("50");
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
analogWrite(5,50);

delay(4000);

Serial.println("REST");
digitalWrite(3,LOW);

delay(4000);

Serial.println("100");
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
analogWrite(5,100);

delay(4000);

Serial.println("REST");
digitalWrite(3,LOW);

delay(4000);

Serial.println("200");
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
analogWrite(5,200);

delay(4000);

Serial.println("REST");
digitalWrite(3,LOW);

delay(4000);

}
