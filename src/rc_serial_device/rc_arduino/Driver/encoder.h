#include<Arduino.h>
#include "interface.h"
#include "config.h"
int temp_cs[3][2]={
  0};
int temp_ct[3][2]={
  0};
double velicity[3]={
  0};

class SEncoder{
public:
  static void init_encoder(){
    pinMode(C1_VCC_C,OUTPUT);
    pinMode(C1_GND_C,OUTPUT);
    pinMode(C1_A,INPUT);
    pinMode(C1_B,INPUT);
    digitalWrite(C1_VCC_C,HIGH);
    digitalWrite(C1_GND_C,LOW);

    pinMode(C2_VCC_C,OUTPUT);
    pinMode(C2_GND_C,OUTPUT);
    pinMode(C2_A,INPUT);
    pinMode(C2_B,INPUT);
    digitalWrite(C2_VCC_C,HIGH);
    digitalWrite(C2_GND_C,LOW);

    pinMode(C3_VCC_C,OUTPUT);
    pinMode(C3_GND_C,OUTPUT);
    pinMode(C3_A,INPUT);
    pinMode(C3_B,INPUT);
    digitalWrite(C3_VCC_C,HIGH);
    digitalWrite(C3_GND_C,LOW);
  }

  //Encoder_C1
  static int get_encode_c1_A(){
    return digitalRead(C1_A);
  }
  static int get_encode_c1_B(){
    return digitalRead(C1_B);
  }

  //Encoder_C1
  static int get_encode_c2_A(){
    return digitalRead(C2_A);
  }
  static int get_encode_c2_B(){
    return digitalRead(C2_B);
  }

  //Encoder_C1
  static int get_encode_c3_A(){
    return digitalRead(C3_A);
  }
  static int get_encode_c3_B(){
    return digitalRead(C3_B);
  }
};

void encoder(){
  for(int i=0;i<TIMER_C;i++){
    int c1_a=SEncoder::get_encode_c1_A();
    int c1_b=SEncoder::get_encode_c1_B();
    int c2_a=SEncoder::get_encode_c2_A();
    int c2_b=SEncoder::get_encode_c2_B();
    int c3_a=SEncoder::get_encode_c3_A();
    int c3_b=SEncoder::get_encode_c3_B();
    temp_cs[0][0]=c1_a;
    temp_cs[0][1]=c1_b;
    temp_cs[1][0]=c2_a;
    temp_cs[1][1]=c2_b;
    temp_cs[2][0]=c3_a;
    temp_cs[2][1]=c3_b;
    for(int i=0;i<3;i++){
      for(int j=0;j<2;j++){
        if(temp_cs[i][j]!=temp_ct[i][j]){
          if(j==0){
            velicity[i]+=1;
          }
          if(j==1){
            velicity[i]-=1;
          }
        }
      }
    }
    temp_ct[0][0]=c1_a;
    temp_ct[0][1]=c1_b;
    temp_ct[1][0]=c2_a;
    temp_ct[1][1]=c2_b;
    temp_ct[2][0]=c3_a;
    temp_ct[2][1]=c3_b;
    //delay(10);
  }
  
  
}




