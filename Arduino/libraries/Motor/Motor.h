#ifndef Motor_h //Wrap Header File
#define Motor_h //Wrap Header File

#include "Arduino.h"

class Motor
{
    public:
        Motor(int in1, int in2, int enA);
        Motor(int in1, int in2, int in3, int in4, int enA, int enB);
        // void printOut(char out[]);
         void printOut(String out);
        void printOut(int out);
        void accel(int pin, int startSignal, int endSignal);
        void accel(int pin, int startSignal, int endSignal, int delayTime);
        void decel(int pin, int startSignal, int endSignal);
        void decel(int pin, int startSignal, int endSignal, int delayTime);
        void analog(int pin, int startSignal, int endSignal);
        void analog(int pin, int startSignal, int endSignal, int delayTime);    
        void analogCD(int pin, int startSignal, int endSignal);
        void analogCD(int pin, int startSignal, int endSignal, int delayTime);
        void motor1Forward();
        void motor2Forward();
        void motor1Backward();
        void motor2Backward();
        void motor1Stop();
        void motor2Stop();
        void forward();
        void backward();
        void stopMotors();
        void analogBoth(int startSignal, int endSignal);
        void analogBoth(int startSignal, int endSignal, int delayTime);
        void analogBothCD(int startSignal, int endSignal);
        void analogBothCD(int startSignal, int endSignal, int delayTime);
        void usePin(int pin);
    private:
        int enablePinA;
        int enablePinB;
        int pin1;
        int pin2;
        int pin3;
        int pin4;


};


#endif //Wrap Header File