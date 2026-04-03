/*
 * 
 Consider the internal arrangement of the Rotary Encoder pins as below:
 DT (Assume its connected to pull up resistor (state of pin: HIGH))
 CLK (Assume its connected to pull up resistor (state of pin: HIGH))
 
 When turning the knob clockwise, the rotating plate first makes contact with the
 CLK pin hence changing its state from HIGH(1) to LOW(0) but DT pin is still at HIGH
 state. If we read and store original state of CLK pin e.g. HIGH, whenever CLK pin
 keeps changing from HIGH to LOW or LOW to HIGH we can tell that the knob is being turned
 Clockwise. For clockwise CLK pin state changes before DT pin state

 When turning the knob anti-clockwise, the rotating plate first makes contact with the DT pin
 changing its state from HIGH(1) to LOW(0) but CLK pin is still at HIGH state though as the knob
 keeps getting turned, there will reach a point when both the states of DT and CLK pins are
 the same e.g. both at LOW state. Hence to tell that the knob is being turned anti-clockwise, 
 right after the CLK Pin changes its state we can check to see whether its state is equal 
 to DT pin. If they are equal, it means the DT pin had changed its state before the CLK pin 
 and the direction is anti-clockwise.

 Sketch Author: Tumwesigire Rodney Michael
 License: MIT License (https://opensource.org/licenses/MIT)
*/
const int swPin  = 3;
const int dtPin  = 4;
const int clkPin = 5;
int swState, previousClkState;
int counter = 0; 

void setup(){
     Serial.begin(9600);
     pinMode(swPin, INPUT_PULLUP); // DEFAULT pin state at HIGH(1)
     pinMode(dtPin, INPUT);
     pinMode(clkPin, INPUT);
    
     previousClkState = digitalRead(clkPin);
}

void loop(){
     int currentClkState = digitalRead(clkPin);  
      
      // the following below executes whenever CLK state changes from turning the knob
      if (currentClkState != previousClkState){ 
         if (digitalRead(dtPin) == currentClkState){
              counter -= 1;
              Serial.print("\n\nKnob turning Anti-clockwise | counterValue: ");
              Serial.print(counter);
         } 
         else{
              counter += 1;
              Serial.print("\n\nKnob turning Clockwise | counterValue: ");
              Serial.print(counter);
         }
      }
     previousClkState = currentClkState; 

     swState = digitalRead(swPin); // DEFAULT pin state is HIGH(1) when pressed goes LOW(0) 
      if (!swState){ // inverts LOW(0) when pressed to HIGH(1) to execute condition below
         Serial.print("\n\nsw pressed");
         delay(100);
      }  
}
