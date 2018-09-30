
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor
const int trigger2 = 4; //Trigger pin of 2nd Sesnor
const int echo2 = 5;//Echo pin of 2nd Sesnor


long time_taken;
int dist,distL,distR;
float r;
unsigned long temp=0;
int temp1=0;
int l=0;


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
distR= calculate_distance(trigger2,echo2);

 // Serial.println(distL);



 
  if(distR<=35 && distR>=15) // once if we placed our hands in front of the right sensor in the range between 15 to 35cm this condition becomes true.
  { 
      delay(300);
      distR= calculate_distance(trigger2,echo2);
     
    if(distR<=35 && distR>=15) // this condition will true if we place our hand in front of the right sensor for more then 300 milli seconds. 
    {
     temp=distR;                         // store the current position of our hand in the variable temp. 
     while(distR<=50 || distR==0)    // this loop will run untill we removes our hand in front of the right sensor.
     {
       
       distR= calculate_distance(trigger2,echo2);              // call this function continuously to get the live data. 
       if((temp+6)<distR)                // this condition becomes true if we moves our hand away from the right sensor (**but in front of it ). here " temp+6 " is for calibration.
       {
       Serial.println("down");               // send "down" serially.
       }
       else if((temp-6)>distR)           // this condition becomes true if we moves our hand closer to the right sensor.
       {
        Serial.println("up");                // send "up" serially.
       }
     }
    }
    else                                     // this condition becomes true, if we only swipe in front of the right sensor . 
    {
      Serial.println("next");                // send "next" serially.
    }
  }






  else {

          distL= calculate_distance(trigger1,echo1);

  if(distL<=35 && distL>=15)   // once if we placed our hands in front of the left sensor in the range between 15 to 35cm this condition becomes true.
  { 
  
    temp=millis();                           
  
    while(millis()<=(temp+300))             
    {
      distR= calculate_distance(trigger2,echo2);
      distL= calculate_distance(trigger1,echo1);

       if(distR<=35 && distR>=15)  // if our hand detects in the right sensor before 300 milli seconds this condition becomes true. ( usually it happens if we swipe our hand from left to right sensor )
       {
         Serial.println("change");         // send "change" serially.
         l=1;                              // store 1 in variable l. ( it avoids the program to enter into the upcoming if condition )
         break;                            // break the loop.
       }
    }
    
    if(l==0)                               // this condition will become true, only if we swipe our hand in front of left sensor.
    {
    Serial.println("previous");            // send "previous" serially.
    while(distL<=35 && distL>=15) // this loop will rotate untill we removes our hand infront of the left sensor. this will avoid not to enter this if condition again.
      distR= calculate_distance(trigger2,echo2);
      distL= calculate_distance(trigger1,echo1);
    }
    l=0;                                  // make l=0 for the next round.
   }
   
  }

  


}
