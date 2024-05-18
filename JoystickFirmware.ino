#include "UUID.h"

const int joystickPins[] = {A0, A1, A2, A3};  // Joystick analog pins
const int analogInputPins[] = {A4, A5, A6, A7};  // Other analog input pins
const int digitalInputPins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
                                38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};  // Digital input pins
const int digitalOutputPins[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6};  // Digital output pins

UUID uuid;
void setup() {
  // Declare the Joystick Analog Inputs as Inputs
  pinMode(joystickPins[0], INPUT); pinMode(joystickPins[1], INPUT);
  pinMode(joystickPins[2], INPUT); pinMode(joystickPins[3], INPUT);
  // Declare the Analog Inputs as Inputs
  pinMode(analogInputPins[0], INPUT); pinMode(analogInputPins[1], INPUT); 
  pinMode(analogInputPins[2], INPUT); pinMode(analogInputPins[3], INPUT);
  // Declare the Digital Inputs as Inputs
  pinMode( digitalInputPins[0], INPUT); pinMode( digitalInputPins[1], INPUT);
  pinMode( digitalInputPins[2], INPUT); pinMode( digitalInputPins[3], INPUT);
  pinMode( digitalInputPins[4], INPUT); pinMode( digitalInputPins[5], INPUT);
  pinMode( digitalInputPins[6], INPUT); pinMode( digitalInputPins[7], INPUT);
  pinMode( digitalInputPins[8], INPUT); pinMode( digitalInputPins[9], INPUT);
  pinMode(digitalInputPins[10], INPUT); pinMode(digitalInputPins[11], INPUT);
  pinMode(digitalInputPins[12], INPUT); pinMode(digitalInputPins[13], INPUT);
  pinMode(digitalInputPins[14], INPUT); pinMode(digitalInputPins[15], INPUT);

  pinMode(digitalInputPins[16], INPUT); pinMode(digitalInputPins[17], INPUT);
  pinMode(digitalInputPins[18], INPUT); pinMode(digitalInputPins[19], INPUT);
  pinMode(digitalInputPins[20], INPUT); pinMode(digitalInputPins[21], INPUT);
  pinMode(digitalInputPins[22], INPUT); pinMode(digitalInputPins[23], INPUT);
  pinMode(digitalInputPins[24], INPUT); pinMode(digitalInputPins[25], INPUT);
  pinMode(digitalInputPins[26], INPUT); pinMode(digitalInputPins[27], INPUT);
  pinMode(digitalInputPins[28], INPUT); pinMode(digitalInputPins[29], INPUT);
  pinMode(digitalInputPins[30], INPUT); pinMode(digitalInputPins[31], INPUT);
  // Declare the Digital Outputs as Outputs
  pinMode( digitalOutputPins[0], OUTPUT); pinMode( digitalOutputPins[1], OUTPUT);
  pinMode( digitalOutputPins[2], OUTPUT); pinMode( digitalOutputPins[3], OUTPUT);
  pinMode( digitalOutputPins[4], OUTPUT); pinMode( digitalOutputPins[5], OUTPUT);
  pinMode( digitalOutputPins[6], OUTPUT); pinMode( digitalOutputPins[7], OUTPUT);
  pinMode( digitalOutputPins[8], OUTPUT); pinMode( digitalOutputPins[9], OUTPUT);
  pinMode(digitalOutputPins[10], OUTPUT); pinMode(digitalOutputPins[11], OUTPUT);
  pinMode(digitalOutputPins[12], OUTPUT); pinMode(digitalOutputPins[13], OUTPUT);
  pinMode(digitalOutputPins[14], OUTPUT); pinMode(digitalOutputPins[15], OUTPUT);
  // Begin Serial Output with 9600 bits per second, uses a value that can be interpreted by the Arduino Serial Monitor as well as the GUI Program
  Serial.begin(9600);
  // Wait for the Program (or Arduino Serial Monitor) to connect before starting the loop
  while (!Serial) {}
}
// Create 4 Float values to hold the x and y values of Joysticks 1 and 2
String joystickValues[4];
// Create 4 Float values to hold the values of the Analog Inputs
String analogValues[4];
// Create 4 Integer values to hold the values of the Digital Inputs
String digitalValues[32];
// Create 1 Character value to hold the value of the user input from the GUI telling the program which LED to turn on
char userInput;
bool connectionReady = false; // Variable to check whether Serial communications have been established properly; 

void loop() {
  while (connectionReady == false){
    // Set User Input to the Character "0" before every loop to make sure we dont keep an LED on after its no longer pressed down
    Serial.println(uuid);
    userInput = '0';
    // Check if there is any User Input from the GUI by checking if the length of the Serial Input is greater than 0
    if (Serial.available() > 0) {
      userInput = Serial.read(); // If the length of the Serial Input is greater than 0, then read in our User Input
    }
    if (userInput == 'a') {
      connectionReady = true; // Reads when the IDE is read by the Python Program has confirmed
    }
  }
  if (connectionReady == true){
    // Set User Input to the Character "0" before every loop to make sure we dont keep an LED on after its no longer pressed down
    userInput = '0';
    // Check if there is any User Input from the GUI by checking if the length of the Serial Input is greater than 0
    if (Serial.available() > 0) {
      userInput = Serial.read(); // If the length of the Serial Input is greater than 0, then read in our User Input
    }
    // Read the Analog Value of the Joysticks, which are on a range from 0V to 5V with 1024 bits of precision
    joystickValues[0] = analogRead(joystickPins[0]) * (5.0 / 1023.0); joystickValues[1] = analogRead(joystickPins[1]) * (5.0 / 1023.0);
    joystickValues[2] = analogRead(joystickPins[2]) * (5.0 / 1023.0); joystickValues[3] = analogRead(joystickPins[3]) * (5.0 / 1023.0);
    // Read the Analog Value of the Analog Inputs, which are on a range from 0V to 5V with 1024 bits of precision
    analogValues[0] = analogRead(analogInputPins[0]) * (5.0 / 1023.0); analogValues[1] = analogRead(analogInputPins[1]) * (5.0 / 1023.0);
    analogValues[2] = analogRead(analogInputPins[2]) * (5.0 / 1023.0); analogValues[3] = analogRead(analogInputPins[3]) * (5.0 / 1023.0);
    // Read the Digital Value of the Digital Inputs
    digitalValues[0]= digitalRead( digitalInputPins[0]); digitalValues[1]= digitalRead( digitalInputPins[1]); 
    digitalValues[2]= digitalRead( digitalInputPins[2]); digitalValues[3]= digitalRead( digitalInputPins[3]);
    digitalValues[4]= digitalRead( digitalInputPins[4]); digitalValues[5]= digitalRead( digitalInputPins[5]); 
    digitalValues[6]= digitalRead( digitalInputPins[6]); digitalValues[7]= digitalRead( digitalInputPins[7]);
    digitalValues[8]= digitalRead( digitalInputPins[8]); digitalValues[9]= digitalRead( digitalInputPins[9]); 
    digitalValues[10]=digitalRead(digitalInputPins[10]); digitalValues[11]=digitalRead(digitalInputPins[11]);
    digitalValues[12]=digitalRead(digitalInputPins[12]); digitalValues[13]=digitalRead(digitalInputPins[13]); 
    digitalValues[14]=digitalRead(digitalInputPins[14]); digitalValues[15]=digitalRead(digitalInputPins[15]);

    digitalValues[16]=digitalRead(digitalInputPins[16]); digitalValues[17]=digitalRead(digitalInputPins[17]); 
    digitalValues[18]=digitalRead(digitalInputPins[18]); digitalValues[19]=digitalRead(digitalInputPins[19]);
    digitalValues[20]=digitalRead(digitalInputPins[20]); digitalValues[21]=digitalRead(digitalInputPins[21]); 
    digitalValues[22]=digitalRead(digitalInputPins[22]); digitalValues[23]=digitalRead(digitalInputPins[23]);
    digitalValues[24]=digitalRead(digitalInputPins[24]); digitalValues[25]=digitalRead(digitalInputPins[25]); 
    digitalValues[26]=digitalRead(digitalInputPins[26]); digitalValues[27]=digitalRead(digitalInputPins[27]);
    digitalValues[28]=digitalRead(digitalInputPins[28]); digitalValues[29]=digitalRead(digitalInputPins[29]); 
    digitalValues[30]=digitalRead(digitalInputPins[30]); digitalValues[31]=digitalRead(digitalInputPins[31]);

    // React to Incoming Data
    // Check for Application Closed Command
    if (userInput == 'x') { Serial.end(); setup(); };
    // Read the value sent to the Arduino from the GUI and turn on the right Digital Output
    (userInput == '1') ?  digitalWrite(digitalOutputPins[0], HIGH) : digitalWrite(digitalOutputPins[0], LOW);
    (userInput == '2') ?  digitalWrite(digitalOutputPins[1], HIGH) : digitalWrite(digitalOutputPins[1], LOW);
    (userInput == '3') ?  digitalWrite(digitalOutputPins[2], HIGH) : digitalWrite(digitalOutputPins[2], LOW);
    (userInput == '4') ?  digitalWrite(digitalOutputPins[3], HIGH) : digitalWrite(digitalOutputPins[3], LOW);
    (userInput == '5') ?  digitalWrite(digitalOutputPins[4], HIGH) : digitalWrite(digitalOutputPins[4], LOW);
    (userInput == '6') ?  digitalWrite(digitalOutputPins[5], HIGH) : digitalWrite(digitalOutputPins[5], LOW);
    (userInput == '7') ?  digitalWrite(digitalOutputPins[6], HIGH) : digitalWrite(digitalOutputPins[6], LOW);
    (userInput == '8') ?  digitalWrite(digitalOutputPins[7], HIGH) : digitalWrite(digitalOutputPins[7], LOW);
    (userInput == '9') ?  digitalWrite(digitalOutputPins[8], HIGH) : digitalWrite(digitalOutputPins[8], LOW);
    (userInput == 'q') ?  digitalWrite(digitalOutputPins[9], HIGH) : digitalWrite(digitalOutputPins[9], LOW);
    (userInput == 'w') ? digitalWrite(digitalOutputPins[10], HIGH) : digitalWrite(digitalOutputPins[10], LOW);
    (userInput == 'e') ? digitalWrite(digitalOutputPins[11], HIGH) : digitalWrite(digitalOutputPins[11], LOW);
    (userInput == 'r') ? digitalWrite(digitalOutputPins[12], HIGH) : digitalWrite(digitalOutputPins[12], LOW);
    (userInput == 't') ? digitalWrite(digitalOutputPins[13], HIGH) : digitalWrite(digitalOutputPins[13], LOW);
    (userInput == 'y') ? digitalWrite(digitalOutputPins[14], HIGH) : digitalWrite(digitalOutputPins[14], LOW);
    (userInput == 'u') ? digitalWrite(digitalOutputPins[15], HIGH) : digitalWrite(digitalOutputPins[15], LOW);
    // Print the start delimiter for the packet of data
    Serial.println("<");
    // Print X-axis and Y-axis of each Joystick (This number ranges from 0 to 5V)
    Serial.println(joystickValues[0]); Serial.println(joystickValues[1]);
    Serial.println(joystickValues[2]); Serial.println(joystickValues[3]);
    // Print the Analog Input values (This number ranges from 0 to 5V)
    Serial.println(analogValues[0]); Serial.println(analogValues[1]);
    Serial.println(analogValues[2]); Serial.println(analogValues[3]);
    // Print the Digital Input values (Either 0 or 1)
    Serial.println( digitalValues[0]); Serial.println( digitalValues[1]);
    Serial.println( digitalValues[2]); Serial.println( digitalValues[3]);
    Serial.println( digitalValues[4]); Serial.println( digitalValues[5]);
    Serial.println( digitalValues[6]); Serial.println( digitalValues[7]);
    Serial.println( digitalValues[8]); Serial.println( digitalValues[9]);
    Serial.println(digitalValues[10]); Serial.println(digitalValues[11]);
    Serial.println(digitalValues[12]); Serial.println(digitalValues[13]);
    Serial.println(digitalValues[14]); Serial.println(digitalValues[15]);

    Serial.println(digitalValues[16]); Serial.println(digitalValues[17]);
    Serial.println(digitalValues[18]); Serial.println(digitalValues[19]);
    Serial.println(digitalValues[20]); Serial.println(digitalValues[21]);
    Serial.println(digitalValues[22]); Serial.println(digitalValues[23]);
    Serial.println(digitalValues[24]); Serial.println(digitalValues[25]);
    Serial.println(digitalValues[26]); Serial.println(digitalValues[27]);
    Serial.println(digitalValues[28]); Serial.println(digitalValues[29]);
    Serial.println(digitalValues[30]); Serial.println(digitalValues[31]);
    Serial.println(">");
  }
}