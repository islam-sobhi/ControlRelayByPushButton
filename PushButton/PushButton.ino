

// constants won't change. They're used here to
// set pin numbers:
const int button1 = 2;              // the number of the pushbutton pin
const int button2 = 3;              // the number of the pushbutton pin
const int relay1 =  11;             // the number of the relay1 pin
const int relay2 =  12;             // the number of the relay2 pin

// variables will change:
int buttonState1 = 0;              // variable for reading the pushbutton1 status
int buttonState2 = 0;              // variable for reading the pushbutton2 status
void setup() {
                                   // initialize the relay pin as an output:
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT_PULLUP); // PULLUP for add 5v to pin without hardware prevent pin from floating between HIGH and LOW 
  pinMode(button2, INPUT_PULLUP); // PULLUP for add 5v to pin without hardware prevent pin from floating between HIGH and LOW 
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(button1);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState1 == LOW) {                      // pin 2 is pressed and connected to GND so it will be LOW
    digitalWrite(relay1, LOW);                    // remove 5v from pin 11 so relay in1 will be 0v and this make relay on
  ///  delay (1000);                                 // wait 1 second
  } else {                                        
    digitalWrite(relay1, HIGH); 
     digitalWrite(relay2, LOW);  // add 5v to arduino pin 11 so relay in1 will be 5v and this make relay off
  }

   // read the state of the pushbutton value:
  buttonState2 = digitalRead(button2);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:
  if (buttonState2 == LOW) {                    // pin 3 is pressed and connected to GND so it will be LOW
    digitalWrite(relay2, LOW);                  // remove 5v from pin 12 so relay in2 will be 0v and this make relay on
   // delay (5000);                               // wait 5 second
  } else {
    digitalWrite(relay2, HIGH);
     digitalWrite(relay1, LOW); // add 5v to arduino pin 12 so relay in2 will be 5v and this make relay off
  }
}

