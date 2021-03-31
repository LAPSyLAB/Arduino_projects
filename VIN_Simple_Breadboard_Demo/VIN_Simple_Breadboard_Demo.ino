/*
  Analog input, analog output, serial output

  Reads an analog input pins, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also reads and writes other pins and prints the results to the Serial Monitor.

  The circuit:
  - LDR, Thermistor, potentiometer connected to analog pins 0,1,2.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected to digital pin 2 (GND means LED ON)
  - Key connected to digitaln pin 3 (GND means key pressed)

*/
// These constants won't change. They're used to give names to the pins used:
const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A2;  // Analog input pin that the potentiometer is attached to

const int analogOutPin = 9; // Analog output pin that the Buzzer or LED is attached to

const int LEDOutPin = 2; // Digital output pin that the LED is attached to
const int KeyInpPin = 3; // Digital output pin that the Key is attached to

int ValueA0 = 0;        // value read from the pot
int ValueA1 = 0;        // value read from the pot
int ValueA2 = 0;        // value read from the pot
int outputValue = 0;    // value output to the PWM (analog out)
int KeyValue = 0;       // value of Key input pin

void setup() {

  pinMode(LEDOutPin, OUTPUT); 
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  ValueA0 = analogRead(analogInPin0);

  // read the analog in value:
  ValueA1 = analogRead(analogInPin1);

    // read the analog in value:
  ValueA2 = analogRead(analogInPin2);

// map it to the range of the analog out:
  outputValue = map(ValueA0, 650, 1000, 100, 255);
  
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);
  tone(analogOutPin, 4*outputValue);

  // read key input value
  KeyValue = digitalRead(KeyInpPin);
  digitalWrite(LEDOutPin,KeyValue);

  
  // print the results to the Serial Monitor:
  Serial.print("A0 = ");
  Serial.print(ValueA0);
  Serial.print("\tA1 = ");
  Serial.print(ValueA1);
  Serial.print("\tA2 = ");
  Serial.print(ValueA2);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\t Key = ");
  Serial.println(KeyValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(200);
}
