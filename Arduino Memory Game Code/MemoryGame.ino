
// Initialize variables
const byte blue  = 10;
const byte red = 11;
const byte green = 12;
const byte orange = 13;

const byte buttonBlue = 6;
const byte buttonRed = 7;
const byte buttonGreen = 8;
const byte buttonOrange = 9;

const byte ledArray[] = {10, 11, 12, 13};
const byte buttonArray[] = {6, 7, 8, 9};

byte sequence[100];
byte sequenceLength = 0;
byte inputCount = 0;
byte correctInput = 0;
byte buttonPressed = 0;
bool buttonDown = false;
bool waitUserInput = false;

// Button debouncing is used to counter noise in the button signals
// Reference: https://www.arduino.cc/en/pmwiki.php?n=Tutorial/Debounce
// The following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
    // Set inputs and outputs
    pinMode(blue, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(orange, OUTPUT);
    pinMode(buttonBlue, INPUT_PULLUP);
    pinMode(buttonRed, INPUT_PULLUP);
    pinMode(buttonGreen, INPUT_PULLUP);
    pinMode(buttonOrange, INPUT_PULLUP);

    // analogRead(x) is to create a different random seed each game, x must be an empty pin
    randomSeed(analogRead(0));
  
    Serial.begin(9600);
    delay(1000);
}


void loop() {
    if (!waitUserInput) {
      // Add a new random LED value to the sequence
      sequence[sequenceLength] = random(0, 4);
      sequenceLength++;

      // Display the sequence to the player
      for (int i = 0; i < sequenceLength; i++) {
        digitalWrite(ledArray[sequence[i]], HIGH);
        delay(400);
        digitalWrite(ledArray[sequence[i]], LOW);
        delay(100);
      }
      
      Serial.print("\n\nSequence length: ");
      Serial.print(sequenceLength);
      waitUserInput = true;

    } else {
        // Get the current correct LED value in the sequence
        correctInput = sequence[inputCount];

        // Check if any button has been pressed down
        if (!buttonDown) {
          for (int i = 0; i < 4; i++) {
            // digitalRead() returning LOW means the button is pressed down
            // because the buttons are set as INPUT_PULLUP
            if (digitalRead(buttonArray[i]) == LOW) {
              buttonPressed = i;
              buttonDown = true;
            }
          }
        }

        if (buttonDown) {
          // If the button is still down or there is noise after its release
          if (digitalRead(buttonArray[buttonPressed]) == LOW) {
            // reset the debouncing timer
            lastDebounceTime = millis();
          }

          // This if statement passes if the button that was pressed
          // has returned HIGH for longer than the debounce delay
          if ((millis() - lastDebounceTime) > debounceDelay) {
              buttonDown = false;

            // If the input was correct, proceed to next input
            if (buttonPressed == correctInput) {
              Serial.print("\nCorrect :D");
              inputCount++;
              // If that was the last input of the sequence, proceed to next sequence
              if (inputCount == sequenceLength) {
                inputCount = 0;
                waitUserInput = false;
                delay(500);
              }

            // If the input was wrong, the game is over and a new game starts after some delay
            } else {
              Serial.print("\nYou lose :(");
              sequenceLength = 0;
              inputCount = 0;
              waitUserInput = false;
              
              delay(1000);
              Serial.print("\n\n\n-- New game --");
              delay(1000);
            }
          }
        }
    }
}
