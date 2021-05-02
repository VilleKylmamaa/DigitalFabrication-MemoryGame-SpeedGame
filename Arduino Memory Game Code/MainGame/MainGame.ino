#include <Wire.h>
#include "DFRobot_RGBLCD.h"
#include <EEPROM.h>

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

// Arrays to make for loops easier to write and understand
// The order of LEDs and buttons is from left to right
const byte ledArray[] = {green, red, transparent, orange};
const byte buttonArray[] = {buttonGreen, buttonRed, buttonTransparent, buttonOrange};

// LCD
// The model is DFR0464
// Manufacturer's guide: https://wiki.dfrobot.com/Gravity__I2C_16x2_Arduino_LCD_with_RGB_Backlight_Display_SKU__DFR0464
DFRobot_RGBLCD lcd(16,2);  // 16 characters and 2 lines
int r, g, b;
int lcdTime = 0;

const byte buzzer = 3;
int sequence[400];
int sequenceLength = 0;
int inputCount = 0;
byte correctInput = 0;
byte buttonPressed = 0;
bool buttonDown = false;
bool waitUserInput = false;
bool waitGameChoice = true;
bool memoryGame = false;
bool speedGame = false;
bool firstGameChoiceLoop = true;
int score = 0;
int memoryHighScore = 0;
int speedHighScore = 0;

/* 
 * Button debouncing is used to counter noise in the button signals
 * Reference: https://www.arduino.cc/en/pmwiki.php?n=Tutorial/Debounce
 * The following variables are unsigned longs because the time, measured in
 * milliseconds, will quickly become a bigger number than can be stored in an int.
 */
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

// Timers for Speed Game
unsigned long currentTime = 0;
unsigned long previousTime = 0;

// Notes for button presses and music
const float A_2_sharp = 116.54;
const float B_2 = 123.47;
const float C_3 = 130.81;
const float C_3_sharp = 138.59;
const float D_3 = 146.83;
const float E_3 = 164.81;
const float F_3 = 174.61;
const float F_3_sharp = 185.00;
const float G_3 = 196.00;
const float G_3_sharp = 207.65;
const float A_3 = 220.00;
const float C_4 = 261.63;
const float C_4_sharp = 277.18;
const float D_4 = 293.66;
const float D_4_sharp = 311.13;
const float E_4 = 329.63;
const float F_4 = 349.23;
const float F_4_sharp = 369.99;
const float G_4 = 392.00;
const float G_4_sharp = 415.30;
const float A_4 = 440.00;
const float A_4_sharp = 466.16;
const float B_4 = 493.88;
const float C_5 = 523.25;
const float C_5_sharp = 554.37;
const float D_5 = 587.33;
const float D_5_sharp = 622.25;
const float E_5 = 659.25;
const float F_5 = 698.46;
const float F_5_sharp = 739.99;
const float G_5 = 783.99;
const float G_5_sharp = 830.61;
const float A_5 = 880.00;
const float A_5_sharp = 932.33;
const float B_5 = 987.77;
const float C_6_sharp = 1108.73;
const float D_6 = 1174.66;
const float D_6_sharp = 1244.51;
const float E_6 = 1318.51;
const float F_6 = 1396.91;
const float F_6_sharp = 1479.98;
const float G_6 = 1567.98;
const float G_6_sharp = 1661.22;

unsigned long musicTimerGreen = 0;
unsigned long musicTimerRed = 0;
unsigned long musicTimerTransparent = 0;
unsigned long musicTimerOrange = 0;
unsigned long musicActivationDelay = 2000;  // Time a button must be held to activate music

/*
 * Plays the given note for the given duration
 * and sets the given delay after the note is played
 */
void playNote(float note, float noteDuration, float delayDuration) {
    tone(buzzer, note);
    delay(noteDuration);
    noTone(buzzer);
    delay(delayDuration);
}

/* 
 * Makes a beep for the chosen LED and turns it on
 * The beep for each LED is in different frequency
 */ 
void lightUpLed(byte led) {
    // For a delightful musical experience, the frequencies are set up as C major chord
    if (led == 10) {
      playNote(C_4, 25, 0);
    } else if (led == 11) {
      playNote(E_4, 25, 0);
    } else if (led == 12) {
      playNote(G_4, 25, 0);
    } else {
      playNote(C_5, 25, 0);
    }
    
    // Use analogWrite() if the LED is red or transparent, which must be connected to PWM pins
    // Red and transparent are otherwise overly bright
    // Change analogWrite(led, x) value x to control brightness
    if (led == red || led == transparent) {
      analogWrite(led, 15);
    } else {
      digitalWrite(led, HIGH);
    }
}

/*
 * Light up all LEDs quickly one after another twice and play their notes
 */
void lightAllLeds() {
    for (int i = 0; i < 4; i++) {
      lightUpLed(ledArray[i]);
      delay(50);
      digitalWrite(ledArray[i], LOW);
    }
}

/*
 * Changes LCD background colour over time
 * RGB values range between 0 and 255
 * abs(sin()) is used to keep the coefficient between 0 and 1
 */
void lcdAnimation() {
  r = (abs(sin(3.14*lcdTime/180)))*255;
  g = (abs(sin(3.14*(lcdTime+60)/180)))*255;
  b = (abs(sin(3.14*(lcdTime+120)/180)))*255;
  lcd.setRGB(r, g, b);
  lcdTime++;
  delay(50);
}

/*
 * Play a tune rising in frequency to indicate that a new game is starting
 */
void newGameTune() {
  for (int i = 0; i < 50; i++) {
    playNote(100 + i*5, 10, 0);
  }
}

/*
 * Play a tune lowering in frequency to indicate that the game was lost
 */
void gameOverTune() {
  for (int i = 0; i < 100; i++) {
    playNote(C_4 - i*5, 15, 0);
  }
}

/*
 * Play a delightful tune if a new high score is set
 * It's the chorus from Never Gonna Give You Up by Rick Astley
 */
void highScoreTune() {
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(F_5, 400, 25);
  playNote(F_5, 400, 25);
  playNote(D_5_sharp, 600, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(D_5_sharp, 400, 25);
  playNote(D_5_sharp, 400, 25);
  playNote(C_5_sharp, 400, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 225, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(C_5_sharp, 325, 75);
  playNote(D_5_sharp, 225, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(G_4_sharp, 600, 25);
  playNote(G_4_sharp, 225, 25);
  playNote(D_5_sharp, 500, 25);
  playNote(C_5_sharp, 1000, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(G_4_sharp, 100, 25);
  
  playNote(F_5, 400, 25);
  playNote(F_5, 400, 25);
  playNote(D_5_sharp, 600, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);

  playNote(G_5_sharp, 400, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 325, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 400, 25);

  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(G_4_sharp, 100, 25);

  playNote(C_5_sharp, 400, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(C_5, 400, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(G_4_sharp, 600, 50);
  
  playNote(G_4_sharp, 225, 25);
  playNote(D_5_sharp, 500, 25);
  playNote(C_5_sharp, 1000, 25);
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
  
  lcd.init();
  lcd.clear();
}


// Game loop
void loop() {
  // The player chooses which game to play
  while (waitGameChoice) {
    lcdAnimation();
    
    if (firstGameChoiceLoop) {
      firstGameChoiceLoop = false;
      lcd.clear();
      lcd.print("Left for Memory");
      lcd.setCursor(0, 1);
      lcd.print("Right for Speed");
      
      lightAllLeds();
      digitalWrite(green, HIGH);
      digitalWrite(orange, HIGH);
    }
    
    // Check if any button has been pressed down
    if (!buttonDown) {
      for (int i = 0; i < 4; i++) {
        // digitalRead() returning LOW means the button is pressed down
        // because the buttons are set as INPUT_PULLUP
        if (digitalRead(buttonArray[i]) == LOW) {
          // Light the corresponding LED
          buttonPressed = buttonArray[i];
          buttonDown = true;

          // Set timers for secret music easter eggs
          if (buttonArray[i] == buttonGreen) {
            musicTimerGreen = millis();
          } else if (buttonArray[i] == buttonRed) {
            musicTimerRed = millis();
          } else if (buttonArray[i] == buttonTransparent) {
            musicTimerTransparent = millis();
          } else if (buttonArray[i] == buttonOrange) {
            musicTimerOrange = millis();
          }
        }
      }
    }

    if (buttonDown) {
      
      // Secret music easter eggs are activated by holding a button for 2 seconds
      if (digitalRead(buttonGreen) == LOW) {
        if ((millis() - musicTimerGreen) > musicActivationDelay) {
          playMegalovania();
          musicTimerGreen = 0;
          buttonDown = false;
          firstGameChoiceLoop = true;
          continue;
        }
      }
      if (digitalRead(buttonRed) == LOW) {
        if ((millis() - musicTimerRed) > musicActivationDelay) {
          playCoffinDance();
          musicTimerRed = 0;
          digitalWrite(red, HIGH);
          buttonDown = false;
          firstGameChoiceLoop = true;
          continue;
        }
      }
      if (digitalRead(buttonTransparent) == LOW) {
        if ((millis() - musicTimerTransparent) > musicActivationDelay) {
          playMasterOfPuppets();
          musicTimerTransparent = 0;
          buttonDown = false;
          firstGameChoiceLoop = true;
          continue;
        }
      }
      if (digitalRead(buttonOrange) == LOW) {
        if ((millis() - musicTimerOrange) > musicActivationDelay) {
          playNeverGonnaGiveYouUp();
          musicTimerOrange = 0;
          buttonDown = false;
          firstGameChoiceLoop = true;
          continue;
        }
      }
      
      // If the button is still down or there is noise after its release, Reset the debouncing timer
      if (digitalRead(buttonPressed) == LOW) { 
        lastDebounceTime = millis();
      }

      // This if statement passes if the button that was pressed
      // has returned HIGH for longer than the debounce delay
      if ((millis() - lastDebounceTime) > debounceDelay) {
        buttonDown = false;
        
        if (buttonPressed == buttonGreen) { // Leftmost button for Memory Game
          memoryGame = true;
          waitGameChoice = false;
          digitalWrite(green, LOW);
          digitalWrite(orange, LOW);
  
          lcd.clear();
          lcd.print("New memory game");
          lcd.setCursor(0, 1);
          lcd.print("High score: ");
          memoryHighScore = EEPROM.read(0); // Memory Game high score is in memory place 0
          lcd.print(memoryHighScore);
          
          lightAllLeds();
          newGameTune();
          delay(700);
        
          lcd.clear();
          lcd.print("Sequence: 1");
          lcd.setCursor(2, 1);
          lcd.print("Inputs: 0");
          delay(1000);
          
        } else if (buttonPressed == buttonOrange) { // Rightmost button for Speed Game
          speedGame = true;
          waitGameChoice = false;
          digitalWrite(green, LOW);
          digitalWrite(orange, LOW);
  
          lcd.clear();
          lcd.print("New speed game");
          lcd.setCursor(0, 1);
          lcd.print("High score: ");
          speedHighScore = EEPROM.read(1); // Speed Game high score is in memory place 1
          lcd.print(speedHighScore);
          
          lightAllLeds();
          newGameTune();
          delay(700);
      
          lcd.clear();
          lcd.print("Score: 0");
          delay(1000);
        }
      }
    }
  }
  
  lcdAnimation();
  

  /**************
  * MEMORY GAME *
  **************/
 
  if (memoryGame) {
    // Sequence grows and its displayed through the LEDs
    if (!waitUserInput) {
    // Add a new random LED value to the sequence
    sequence[sequenceLength] = random(0, 4);
    sequenceLength++;
    
    lcd.setCursor(10, 0);
    lcd.print(sequenceLength);

    // Display the sequence to the player
    for (int i = 0; i < sequenceLength; i++) {
      lightUpLed(ledArray[sequence[i]]);
      delay(300);
      digitalWrite(ledArray[sequence[i]], LOW);
      delay(100);
    }
    waitUserInput = true;

    // Player inputs the sequence
    } else if (waitUserInput) {
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

            // Set timers for secret music easter eggs
            if (buttonArray[i] == buttonGreen) {
              musicTimerGreen = millis();
            } else if (buttonArray[i] == buttonRed) {
              musicTimerRed = millis();
            } else if (buttonArray[i] == buttonTransparent) {
              musicTimerTransparent = millis();
            } else if (buttonArray[i] == buttonOrange) {
              musicTimerOrange = millis();
            }
          }
        }
      }

      if (buttonDown) {
             
        // If the button is still down or there is noise after its release, Reset the debouncing timer
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
            inputCount++;
            lcd.setCursor(10, 1);
            // When the inputs get over 10 and a new sequence starts, the last character (e.g. 0 from 10)
            // would be left there because numbers < 10 have only one character
            if (inputCount < 10) {
              lcd.print(inputCount);
              lcd.setCursor(11, 1);
              // Space is used to clear just a single character, it's faster than clearing the whole LCD
              lcd.print(" ");
            } else {
              lcd.print(inputCount);
            }
            // If that was the last input of the sequence, proceed to next sequence
            if (inputCount == sequenceLength) {
              inputCount = 0;
              waitUserInput = false;
              delay(500);
              lcd.setCursor(10, 1);
              lcd.print(inputCount);
              lcd.setCursor(11, 1);
              lcd.print(" ");
            }

          // If the input was wrong, the game is over and a new game starts after some delay
          } else {
            lcd.clear();
            lcd.print("Game Over");
            lcd.setCursor(0, 1);
            lcd.print("Score: ");
            score = sequenceLength - 1;
            lcd.print(score);
            gameOverTune();
            delay(2000);

            // Check if the score was a new high score
            if (score > memoryHighScore) {
              EEPROM.write(0, score);
              lcd.clear();
              lcd.print("NEW HIGH SCORE");
              lcd.setCursor(0, 1);
              lcd.print("Score: ");
              lcd.print(score);
              highScoreTune();
              delay(2000);    
            }
            
            sequenceLength = 0;
            inputCount = 0;
            waitUserInput = false;
            memoryGame = false;
            waitGameChoice = true;
            firstGameChoiceLoop = true;
          }
        }
      }
    }
  }


  /*************
  * SPEED GAME *
  *************/
  
  else if (speedGame) {
    currentTime = millis();

    if (sequenceLength <= 40) {
      if (currentTime - previousTime >= 1000 - sequenceLength * 15) {
        digitalWrite(ledArray[sequence[sequenceLength - 1]], LOW);
        sequence[sequenceLength] = random(0, 4);
        lightUpLed(ledArray[sequence[sequenceLength]]);
        sequenceLength++;
        previousTime = currentTime;
      }
      
    // After 40 inputs, when the speed is one input per 400 ms, the game starts speeding up slower
    } else if (sequenceLength <= 119) {
      if (currentTime - previousTime >= 605 - sequenceLength * 5) {
        digitalWrite(ledArray[sequence[sequenceLength - 1]], LOW);
        sequence[sequenceLength] = random(0, 4);
        lightUpLed(ledArray[sequence[sequenceLength]]);
        sequenceLength++;
        previousTime = currentTime;
      }
      
    } else {
      // After 119 inputs the game reaches its maximum speed
      if (currentTime - previousTime >= 10) {
        digitalWrite(ledArray[sequence[sequenceLength - 1]], LOW);
        sequence[sequenceLength] = random(0, 4);
        lightUpLed(ledArray[sequence[sequenceLength]]);
        sequenceLength++;
        previousTime = currentTime;
      }
    }

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
      // If the button is still down or there is noise after its release, Reset the debouncing timer
      if (digitalRead(buttonArray[buttonPressed]) == LOW) { 
        lastDebounceTime = millis();
      }

      // This if statement passes if the button that was pressed
      // has returned HIGH for longer than the debounce delay
      if ((millis() - lastDebounceTime) > debounceDelay) {
        buttonDown = false;
        
        // Input was correct
        if (buttonPressed == correctInput) {
          inputCount++;
          lcd.setCursor(7, 0);
          lcd.print(inputCount);

        // If the input was wrong, the game is over and a new game starts after some delay
        } else {
          lcd.clear();
          lcd.print("Game Over");
          lcd.setCursor(0, 1);
          lcd.print("Score: ");
          lcd.print(inputCount);
          gameOverTune();
          delay(2000);

          // Check if the score was a new high score
          if (inputCount > speedHighScore) {
            EEPROM.write(1, inputCount);
            lcd.clear();
            lcd.print("NEW HIGH SCORE");
            lcd.setCursor(0, 1);
            lcd.print("Score: ");
            lcd.print(inputCount);
            highScoreTune();
            delay(2000);    
          }
          
          sequenceLength = 0;
          inputCount = 0;
          waitUserInput = false;
          speedGame = false;
          waitGameChoice = true;
          firstGameChoiceLoop = true;
        }
      }
    }
  }
}
