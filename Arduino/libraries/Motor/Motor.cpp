#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int in1, int in2, int enA) {
	pin1 = in1;
	pin2 = in2;
	enablePinA = enA;
}

Motor::Motor(int in1, int in2, int in3, int in4, int enA, int enB) {
	pin1 = in1;
	pin2 = in2;
	pin3 = in3;
	pin4 = in4;
	enablePinA = enA;
	enablePinB = enB;
}

void Motor::accel(int pin, int startSignal, int endSignal, int delayTime) {
	// printOut("\tAccel");
	for (int i = startSignal; i < endSignal; i++) {
		printOut(i);
		analogWrite(pin, i);
		delay(delayTime);
	}
}
void Motor::accel(int pin, int startSignal, int endSignal) {
	accel(pin, startSignal, endSignal, 200);
}

void Motor::decel(int pin, int startSignal, int endSignal, int delayTime) {
	// printOut("\tDecel");
	for (int i = startSignal; i > endSignal; i--) {
		// printOut("\t Analog:" + i);
		analogWrite(pin, i);
		delay(delayTime);
	}
}
void Motor::decel(int pin, int startSignal, int endSignal) {
	decel(pin, startSignal, endSignal, 200);
}

void Motor::analog(int pin, int startSignal, int endSignal, int delayTime) {
	if (startSignal > endSignal)
		decel(pin, startSignal, endSignal, delayTime);
	else if (startSignal < endSignal)
		accel(pin, startSignal, endSignal, delayTime);
	else if (startSignal == endSignal) {
		// printOut("\t Analog: Constant = " + startSignal);
		// printOut(startSignal);
		analogWrite(pin, startSignal);
		delay(delayTime);
	}
}
void Motor::analog(int pin, int startSignal, int endSignal) {
	analog(pin, startSignal, endSignal, 200);
}

void Motor::analogCD(int pin, int startSignal, int endSignal, int delayTime) { //CD means it will count down the signal if the analog signal is changing
	if (startSignal > endSignal)
		decel(pin, startSignal, endSignal, delayTime);
	else if (startSignal < endSignal)
		accel(pin, startSignal, endSignal, delayTime);
	else if (startSignal == endSignal) {
		// printOut("\t Analog: Constant = " + startSignal);
		printOut(startSignal);
		analogWrite(pin, startSignal);
		for (int i = delayTime; i >= 0; i--) {
			Serial.println("\t" + i);
			delay(1);
		}
	}
}
void Motor::analogCD(int pin, int startSignal, int endSignal) {
	analogCD(pin, startSignal, endSignal, 200);
}

void Motor::motor1Forward() {
	printOut("Motor 1 Forward");
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
}
void Motor::motor2Forward() {
	printOut("Motor 2 Forward");
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, LOW);
}
void Motor::motor1Backward() {
	printOut("Motor 1 Backward");
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
}
void Motor::motor2Backward() {
	printOut("Motor 2 Backward");
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, HIGH);
}
void Motor::motor1Stop() {
	printOut("Motor 1 Stop");
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
}
void Motor::motor2Stop() {
	printOut("Motor 2 Stop");
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
}

void Motor::forward() {
	motor1Forward();
	motor2Forward();
}
void Motor::backward() {
	motor1Backward();
	motor2Backward();
}
void Motor::stopMotors() {
	motor1Stop();
	motor2Stop();
}
void Motor::analogBoth(int startValue, int endValue, int delayTime) {
	analog(enablePinA, startValue, endValue, delayTime);
	analog(enablePinB, startValue, endValue, delayTime);
}
void Motor::analogBoth(int startValue, int endValue) {
	analogBoth(startValue, endValue, 200);
}

void Motor::analogBothCD(int startValue, int endValue, int delayTime) {
	analogCD(enablePinA, startValue, endValue, delayTime);
	analogCD(enablePinB, startValue, endValue, delayTime);
}
void Motor::analogBothCD(int startValue, int endValue) {
	analogBothCD(startValue, endValue, 200);
}

void Motor::usePin(int pin) {
	pinMode(pin, OUTPUT);
}

// void Motor::printOut(char out[]) {
// 	Serial.println(out);
// }
void Motor::printOut(String out) {
	Serial.println("\t" + out);
}
void Motor::printOut(int out) {
	Serial.println(String(out));
}
