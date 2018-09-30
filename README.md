# Arduino-Gesture-Controller
controlling pc, laptops or any other device through hand gesture with the help of arduino
 With This project you can control the VLC player, you can increase the volume, play pause the video etc.
 
 More features will be added soon.
 You can also customize this project and change the controlling action

# Circuit Diagram
<h1 align="center">
<img src="/.source/circuitDaigram.png"/>

</h1>



# ScreenShot
<h1 align="center">
<img src="/.source/diagram.png"/>

</h1>

<h1 align="center">
<img src="/.source/working.png"/>

</h1>


# How to Use

1. change the COM4 in the code the COM port that your arduino uses
2. Burn the code into the Arduino
3. Open Command prompt and type the follwoing commands

To install pyserial module so you can communicate at the serial port using python
```java
pip install pyserial

```
To install pyautogui module

```java

pip install pyautogui

```
 4. Run the python code
 
 
# Gestures 

1. If both hands are at a distance of 40 cm  to 50 cm : Play or Pause the Video

2. If only left hand is placed at a distance of 40cm to 50cm : Rewind the video

3.  If left hand is at distance of 17 cm to 27 cm :lock mode
    
4. In Lock mode if distance is less tha 10 cm : volume decrease

5. In lock mode if distance is grater than 20 cm : volume increase

     
 
# NOTE 

1. Before running the python code you must close the arduino software or any other software that is using that COM port
