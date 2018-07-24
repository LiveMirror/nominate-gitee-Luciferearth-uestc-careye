#include "control.h"
#include "encoder.h"
#include <MsTimer2.h>
int c1=0;
char commond='\0';
void dEncoder(){
    if(SEncoder::get_encode_c1_A()==SEncoder::get_encode_c1_B()){
        c1++;
    }else{
        c1--;
    }
    Serial.println(c1,DEC);
}
void setup(){
  Serial.begin(9600);
  SMotor::init_motor();
  SEncoder::init_encoder();
  MsTimer2::set(TIMER_T, encoder);
  MsTimer2::start();
  attachInterrupt(0,dEncoder,CHANGE);
}
void loop(){
  if(Serial.available()){
    commond=(char)Serial.read();
    switch((int)commond){
      case (int)'a':
          SMotor::motor_c1_s(1);
          break;
      case (int)'b':
          SMotor::motor_c1_n(1);
          break;
      case (int)'c':
      SMotor::motor_c2_s(1);
      break;
      case (int)'d':
      SMotor::motor_c2_n(1);
      break;
      case (int)'e':
      SMotor::motor_c3_s(1);
      break;
      case (int)'f':
      SMotor::motor_c3_n(1);
      break;
      case (int)'g':
      
      SMotor::motor_go_forword();
      break;
      case (int)'h':
      SMotor::motor_go_backword();
      break;
      case (int)'i':
      SMotor::motor_c1_s(1);
      SMotor::motor_c2_s(1);
      SMotor::motor_c3_s(1);
      break;
      case (int)'j':
      SMotor::motor_c1_n(1);
      SMotor::motor_c2_n(1);
      SMotor::motor_c3_n(1);
      break;
    default:
      SMotor::motor_stop();
      break;
    }
    Serial.flush();
    /*
    if((velicity[0]!=0)||velicity[1]!=0||velicity[2]!=0){
     Serial.print("{");
     Serial.print(velicity[0]);
     Serial.print(",");
     Serial.print(velicity[1]);
     Serial.print(",");
     Serial.print(velicity[2]);
     Serial.print("}");
     }*/
    for(int i=0;i<3;i+=1){
      velicity[i]=0;
    }
    delay(50);
    commond='\0';
  }
  SMotor::motor_stop();
  commond='\0';
}








