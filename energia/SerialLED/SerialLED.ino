/*
  SerialLED
  Roberto Cadena Vega
  21/11/13

  This sketch reads information from the serial port and makes the LED glow
  with the brightness specified. The incoming information from serial must
  be packages of characters between "0" y "255".

  Electric Circuit:
  There are no additional requirements to the MSP430 Launchpad.
*/

// Global Variables
const int led = GREEN_LED;
int data;

// Setup (only runs once)
void setup(){
  Serial.begin(9600);   // Initializes the serial port
  pinMode(led, OUTPUT); // Initializes the LED pin as an output
  Serial.println(":)"); // Sends out a ready message through the serial port
}

// Loop (runs continuously)
void loop(){
  if(Serial.available() > 0){       // Checks if the serial port has new data
    data = Serial.parseInt();       // Reads the port and outputs an Int
    data = constrain(data, 0, 255); // If the data is over 255 set it to 255
    analogWrite(led, data);         // Writes the data to the LED pin
    Serial.println(":)");           // Sends out a ready message
  }
}

