
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor


const int trigger2 = 4; //Trigger pin of 2nd Sesnor
const int echo2 = 5;//Echo pin of 2nd Sesnor

long time_taken;
int dist,distL,distR;

 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

/*###Function to calculate distance###*/
int calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50 && dist<60)
dist = 50;

return dist;
}


void loop(){


distL= calculate_distance(trigger1,echo1);
distR= calculate_distance(trigger1,echo1);


// if both hands are at distance  40 play or pause the video
if ((distL >40 && distR>40) && (distL <50 && distR<50)) //Detect both hands
{
  Serial.println("Play/Pause");
delay (500);
}


// only left hand
if ((distL >40 && distL<50) && (distR ==50)) //Detect Left Hand
{
  Serial.println("Rewind");
  delay (500);

}


// only right hand

if ((distR >40 && distR<50) && (distL ==50)) //Detect Right Hand
{
  
  Serial.println("Forward"); 

  delay (500);

}


//  left hand still

if (distL>=13 && distL<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<10) //Hand pushed in 
      {
        Serial.println ("Vup");
        delay (300);
        
        }
      if (distL>20) //Hand pulled out
      {
        Serial.println ("Vdown");
      delay (300);
      }
    }
  }
}





}
