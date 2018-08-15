
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor
long time_taken;
int dist,distL,distR;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigger1, OUTPUT);
pinMode(echo1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void calculateDistance()(int trigger,int echo){

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;  
}

void sendAndTrigger(){

digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
}

