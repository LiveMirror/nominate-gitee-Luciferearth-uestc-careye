#ifndef __CONTROL_H
#define __CONTROL_H
#include<Arduino.h>
#include "interface.h"
class SMotor{
public:
static void PWM_PIN_Write(int pin,int time){
    digitalWrite(pin,HIGH);
    //delayMicroseconds(100);
  }
  static void init_motor(){
    pinMode(C1_D0,OUTPUT);
    pinMode(C1_D1,OUTPUT);
    pinMode(C2_D0,OUTPUT);
    pinMode(C2_D1,OUTPUT);
    pinMode(C3_D0,OUTPUT);
    pinMode(C3_D1,OUTPUT);
  }

  
  static void motor_c1_stop(){
    digitalWrite(C1_D0,LOW);
    digitalWrite(C1_D1,LOW);
  }
  static void motor_c2_stop(){
    digitalWrite(C2_D0,LOW);
    digitalWrite(C2_D1,LOW);
  }
  static void motor_c3_stop(){
    digitalWrite(C3_D0,LOW);
    digitalWrite(C3_D1,LOW);
  }
  static void motor_stop(){
    digitalWrite(C1_D0,LOW);
    digitalWrite(C2_D0,LOW);
    digitalWrite(C3_D0,LOW);
    digitalWrite(C1_D1,LOW);
    digitalWrite(C2_D1,LOW);
    digitalWrite(C3_D1,LOW);
  }
  static void motor_c1_n(int time){
    PWM_PIN_Write(C1_D0,time);
    digitalWrite(C1_D1,LOW);
  }
  static void motor_c1_s(int time){
    digitalWrite(C1_D0,LOW);
    PWM_PIN_Write(C1_D1,time);
  }
  static void motor_c2_n(int time){
    digitalWrite(C2_D0,LOW);
    PWM_PIN_Write(C2_D1,time);
  }
  static void motor_c2_s(int time){
    PWM_PIN_Write(C2_D0,time);
    digitalWrite(C2_D1,LOW);
  }
  static void motor_c3_s(int time){
    PWM_PIN_Write(C3_D0,time);
    digitalWrite(C3_D1,LOW);
  }
  static void motor_c3_n(int time){
    digitalWrite(C3_D0,LOW);
    PWM_PIN_Write(C3_D1,time);
  }
  static void motor_go_forword(){
    motor_stop();
    motor_c1_n(100);
    motor_c2_s(100);
  }
  static void motor_go_backword(){
    motor_stop();
    motor_c1_s(100);
    motor_c2_n(100);
  }
};
#endif


