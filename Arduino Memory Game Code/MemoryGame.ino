#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// LEDs
const byte green = 12;
const byte red  = 10;
const byte transparent = 11;
const byte orange = 13;

// Buttons
const byte buttonGreen = 6;
const byte buttonRed = 7;
const byte buttonTransparent = 8;
const byte buttonOrange = 9;

const byte ledArray[] = {green, red, transparent, orange};
const byte buttonArray[] = {buttonGreen, buttonRed, buttonTransparent, buttonOrange};

const byte buzzer = 3;
byte sequence[100];
byte sequenceLength = 0;
byte inputCount = 0;
byte correctInput = 0;
byte buttonPressed = 0;
bool buttonDown = false;
bool waitUserInput = false;

/* 
 * Button debouncing is used to counter noise in the button signals
 * Reference: https://www.arduino.cc/en/pmwiki.php?n=Tutorial/Debounce
 * The following variables are unsigned longs because the time, measured in
 * milliseconds, will quickly become a bigger number than can be stored in an int.
 */
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

/* 
 * Function for making a beep for the chosen LED and turning it on
 * The beep for each LED is in different frequency
 */ 
void lightUpLed(byte led) {
  // For a delightful musical experience, the frequencies are set up as C major chord
  if (led == 10) {
    tone(buzzer, 261.63); // note C4
  } else if (led == 11) {
    tone(buzzer, 329.63); // note E4
  } else if (led == 12) {
    tone(buzzer, 392.00); // note G4
  } else {
    tone(buzzer, 525.25); // note C5
  }
  // Play the note for 25 ms before turning it off
  delay(25);
  noTone(buzzer);
  
  // Use analogWrite() if the LED is red or transparent, which must be connected to PWM pins
  // Red and transparent are otherwise overly bright
  // Change analogWrite(led, x) value x to control brightness
  if (led == red || led == transparent) {
    analogWrite(led, 15); 
  } else {
    digitalWrite(led, HIGH); 
  }
}

// Setup is ran once
void setup() {
    // Set inputs and outputs
    pinMode(red, OUTPUT);
    pinMode(transparent, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(orange, OUTPUT);
    pinMode(buttonTransparent, INPUT_PULLUP);
    pinMode(buttonRed, INPUT_PULLUP);
    pinMode(buttonGreen, INPUT_PULLUP);
    pinMode(buttonOrange, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    
    // analogRead(x) is to create a different random seed each game, x must be an empty pin
    randomSeed(analogRead(0));

    Serial.begin(9600);
    delay(1000);
}

// Game loop
void loop() {
    if (!waitUserInput) {
      // Add a new random LED value to the sequence
      sequence[sequenceLength] = random(0, 4);
      sequenceLength++;

      // Display the sequence to the player
      for (int i = 0; i < sequenceLength; i++) {
        lightUpLed(ledArray[sequence[i]]);
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
              // Light the corresponding LED
              lightUpLed(ledArray[i]);
              buttonPressed = i;
              buttonDown = true;
            }
          }
        }

        if (buttonDown) {
          // Reset the debouncing timer if the button is still down or there is noise after its release
          if (digitalRead(buttonArray[buttonPressed]) == LOW) { 
            lastDebounceTime = millis();
          }

          // This if statement passes if the button that was pressed
          // has returned HIGH for longer than the debounce delay
          if ((millis() - lastDebounceTime) > debounceDelay) {
              buttonDown = false;
              digitalWrite(ledArray[buttonPressed], LOW); 

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
