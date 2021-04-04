# DigitalFabrication-MemoryGame
University of Oulu, Principles of Digital Fabrication course project

![Original idea drawing](https://raw.githubusercontent.com/ville-kylmamaa/DigitalFabrication-MemoryGame/main/Original%20Idea%20Drawing.png)

Memory Game is a game where you have to remember and correctly input a sequence that grows each time the player gets it right.

The game includes 4 buttons, 4 LEDs and a liquid-crystal display, which are connected to an Arduino Uno unit through a breadboard. The game logic is programmed to the Arduino microcontroller.

The sequence is displayed through the LEDs lighting up, after which the player has to input the same sequence with the corresponding buttons. If the input is correct the game will generate another sequence which is one digit longer than the previous one. The screen displays the score which is the current sequence length. The screen rises certain number of degrees when the game is turned on and goes back down when the game is turned off.

First, we were inspired by the old Finnish game show ”Speden spelit” and were going to make a similar speed game with four buttons as seen on the show. Later on, we thought that a memory game would be more fun and decided to go with the memory game idea instead!
