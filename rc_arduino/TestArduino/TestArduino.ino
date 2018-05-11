

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
char a;
void loop(){
  if(Serial.available()){
    a=Serial.read();
    switch(a){
      case 'a':
        Serial.print("{0001,0001,0001,0001,0001,0001,0001,0001}");
        digitalWrite(8,HIGH);
        delay(100);
        digitalWrite(8,LOW);
        break;
      case 'b':
        Serial.print(1);
        digitalWrite(10,HIGH);
        delay(100);
        digitalWrite(10,LOW);
        break;
      case 'c':
        Serial.print(1);
        break;
      case 'd':
        Serial.print(1);
        break;
      case 'e':
        Serial.print(1);
        break;
      case 'f':
        Serial.print(1);
        break;
      case 'g':
        Serial.print(1);
        break;
      case 'h':
        Serial.print(1);
        break;
      case 'i':
        Serial.print(1);
        break;
      default:
        Serial.print(2);
        break;
        
    }
    Serial.flush();
  }
  
}
