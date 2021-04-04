
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
bool inputGiven = false;
bool waitUserInput = false;


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
    delay(500);
}


void loop() {
    if (!waitUserInput) {
      // Add a new random LED value to the sequence
      sequence[sequenceLength] = random(0, 4);
      sequenceLength++;

      // Display the sequence to the player
      for (int i = 0; i < sequenceLength; i++) {
        digitalWrite(ledArray[sequence[i]], HIGH);
        delay(500);
        digitalWrite(ledArray[sequence[i]], LOW);
        delay(200);
      }
      
      Serial.print("\n\nSequence length: ");
      Serial.print(sequenceLength);
      waitUserInput = true;

    } else {
        // Get the current correct LED value in the sequence
        correctInput = sequence[inputCount];

        // Check if any button has been pressed
        for (int i = 0; i < 4; i++) {
          if (digitalRead(buttonArray[i]) == LOW) {
            buttonPressed = i;
            inputGiven = true;
          }
        }

        // If the user has pressed a button and released it
        if (inputGiven && digitalRead(buttonArray[buttonPressed]) == HIGH) {
          inputGiven = false;
          // If correct
          if (buttonPressed == correctInput) {
            Serial.print("\nCorrect :D");
            inputCount++;
            if (inputCount == sequenceLength) {
                inputCount = 0;
              waitUserInput = false;
                delay(500);
            }
          // If wrong
          } else {
            Serial.print("\nYou lose :(");
            sequenceLength = 0;
            inputCount = 0;
            waitUserInput = false;
            
            delay(1000);
            Serial.print("\n\n\nNew game :3\n");
            delay(1000);
          }
        }
    }
}
