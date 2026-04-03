# How to use the Rotary Encoder with Arduino
<img src="https://github.com/rodtezla/rotary_encoder_with_arduino/blob/main/rotary_encoder.jpg" alt="rotary encoder image" width="400" height="400">

## Pin connections to Arduino
The rotary encoder has the following pins:
- CLK  :  to any pin on the arduino
- DT   :  to any pin on the arduino
- sw   :  to any pin on the arduino
- '+'  :  to positive 5V
- GND  :  to GND
___

## Mode of operation of rotary encode
Consider the arrangement of CLK and DT as below
- DT
- CLK
> When the knob is turned clockwise, CLK changes state before DT similary when the knob is turned anti-clockwise DT changes
its state before CLK.
> 
> By checking for these two conditions we can tell when the knob is turning clockwise or anti-clockwise.
>
> The sw is the clickable push button swicth that can be used for selecting in projects with displays like OLEDs and LCDs.
> 
> After downloading the code file, check the comment section above the code for further explanation on how DT and CLK
are used to tell knob turning direction.

___

## Arduino IDE
<img src="https://www.circuitbasics.com/wp-content/uploads/2020/05/Arduino-IDE-1-1024x878.png" alt="arduino IDE Image" width="500" height="500">

To run the source code file, Download the zip folder from the repository by clicking the button with ***<> code***
then ensure the arduino IDE is installed on your computer  

if not yet installed => Click here to [Install the Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) 

___
