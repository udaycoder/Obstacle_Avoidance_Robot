long duration;
int distance;
int prevdist;
int count;
int turn;
int front;

void setup() {
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(8,OUTPUT); //TRIG
   pinMode(9,INPUT);  //ECHO
   Serial.begin(9600);
   count=0;
   turn=0;
   front=0;
}

void loop() {
  digitalWrite(8,LOW);
  delayMicroseconds(2);

  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(8,LOW);
  
  duration=pulseIn(9,HIGH);

  distance=(duration*0.034)/2;
  Serial.println(distance);
  if(distance<30){
    if(turn>=200)
  {
    Serial.println("opposite direcn");
    for(int i=0;i<100;i++){
     digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(20);
    }
  turn=0;
  front=0;
  prevdist=distance;
  }
  else{
    Serial.println("Turning");
     digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(10);
  turn++;
  front=0;
  prevdist=distance;
  }
  }
  else{
    if(front>=200 && (abs(distance-prevdist)==0 || distance>=3000)){
      for(int i=0;i<60;i++){
      Serial.println("Backing");
     digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(20);
      }
  turn=0;
  front=0;
  prevdist=distance;
    }
    else{
    Serial.println("Forward");
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  turn=0;
  front++;
  prevdist=distance;
    }
  }
}
