float leftstate=LOW;
float rightstate=LOW;
void setup() {
  for (int i =2; i <= 5; i++) { 
    pinMode(i, OUTPUT); 
  }
  
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  attachInterrupt(6, leftblink, CHANGE);
  attachInterrupt(7, rightblink, CHANGE);
  Serial.begin(9600);
}

void loop() {
  //analogWrite(3, 255);
  leftstate = digitalRead(6);
  digitalWrite(5, leftstate);
  rightstate = digitalRead(7);
  digitalWrite(3, rightstate);
  delay(10);
}
void leftblink()
{
  digitalWrite(5,HIGH);
  delay(500);
  Serial.println('sss');
  leftstate +=1;
  digitalWrite(5,LOW);
}
void rightblink()
{
  digitalWrite(3,HIGH);
  delay(500);
  Serial.println('sss');
  leftstate +=1;
  digitalWrite(3,LOW);
}
