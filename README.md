# Memory Game

*University of Oulu, Principles of Digital Fabrication course project, 2021*

## Introduction

Memory Game is a game where you have to remember and correctly input a sequence that grows each time the player gets it right.

The game includes 4 buttons, 4 LEDs and a liquid-crystal display, which are connected to an Arduino Uno unit through a breadboard. The game logic is programmed to the Arduino microcontroller.

The sequence is displayed through the LEDs lighting up, after which the player has to input the same sequence with the corresponding buttons. If the input is correct the game will generate another sequence which is one digit longer than the previous one. The screen displays the score which is the current sequence length. The screen rises certain number of degrees when the game is turned on and goes back down when the game is turned off.

First, we were inspired by the old Finnish game show ”Speden spelit” and were going to make a similar speed game with four buttons as seen on the show. Later on, we thought that a memory game would be more fun and decided to go with this memory game idea instead!

<br>

## Work in Progress, Weekly Report

### Monday 15/03:

Group is formed, members being Ville Kylmämaa, Lasse Rapo, Tommy Meriläinen, Johannes Lampela. Ville got the basic idea of a speed game based on the old Finnish game show “Speden Spelit”.

### Thursday 18/03:

Idea is originally registered as Speed Game.

<br>

## Week 12

### Goals of the week:

* Attend lectures.
* Decide which project idea to carry out.
* Finish introductory report.
* Consider the system requirements and different stages of the project to prepare for the coming weeks.
 
### Wednesday 24/03:

We got feedback on our project idea in the project ideas meeting. We decided to change the idea of the game to be a memory game instead of a speed game. Project was renamed to Memory Game.

### Sunday 28/03:

A meeting was held with the team. We started sketching the first prototype and finished the introductory report. We considered the system requirements and different stages of the project.

#### First drawn prototype
![First drawn prototype](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/28.3%20-%20Original%20Idea%20Drawing.png)

After a week of attending all the lectures we figured that the programming portion of the game would be the main part and perhaps the most difficult part of the project, as we discussed with Georgi and Iván in the project ideas meeting on Wednesday. 3D printing or laser cutting the casing for the game might also be challenging as not one of us has experience with these processes.

<br>

## Week 13
 
### Goals of the week:

* Start designing the circuit.
* Start designing the game code.
 
### Tuesday 30/03:

We attended TA session to clarify issues we were unsure about:

* The requirement of a moving part in the project would be satisfied by the moving display, and a servo should be enough to move it.
* The preferable way to build the casing would be to use laser cutting for which we can design with Inkscape.
* For power we could use either 9V batteries, coin/button cells or lipo batteries.
* For bigger buttons we could either order them or 3D print caps to the smaller buttons.
 
### Thursday 01/04:

Ville fetched the electronic components:

![Electronic components box](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/1.4.%20-%20Electronic%20Components.jpg)

The buttons are indeed small, banana for scale:

![Buttons with a banana for scale](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/1.4.%20-%20Buttons%20with%20a%20Banana.jpg)

Out of the 4 extra buttons we got one was accidentally different and should be switched later. Ville chose the higher version of the button so that 3D printing and inserting a cap for it would be easier.

### Saturday 03/04:

Ville started designing the circuit on Tinkercad:

![First Tinkercad circuit simulation](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/3.4.%20-%20Tinkercad%20Circuit%20Design.png)

Keeping the circuit simple with just 4 LEDs and 4 buttons was enough to start programming the game logic in the Tinkercad simulation. Curiously, you can use buttons without a resistor between the button and GND by connecting them just to GND and the desired pin, and setting them as INPUT_PULLUP in the Arduino code.

Ville also programmed a preliminary working game logic for the simulation.

### Sunday 04/04:

Ville replicated the simulation circuit on an actual breadboard and Arduino Uno:

![Original idea drawing](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/4.4.%20-%20First%20Arduino%20Build.jpg)

Ville transferred the code from the simulation to the Arduino. Unfortunately, the code doesn’t work quite as well on the Arduino. The game sometimes registers a failed input even though the input was assuredly correct. Why this happens on the Arduino and not in the simulation, is left to be determined.

<br>

## Week 14
 
### Goals of the week:

* Debug why the game doesn’t work quite as well on the Arduino as in the simulation.
* Figure out how to connect the LCD to the circuit and how to program it.
* Further improve the code.
* Start designing the laser cutting in Inkscape



<br>
