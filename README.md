# Digital Fabrication: Memory Game & Speed Game

*University of Oulu, Principles of Digital Fabrication course project, 2021*


## Introduction and explanation of the project

![First sketch to final prototype](https://github.com/VilleKylmamaa/DigitalFabrication-MemoryGame/blob/main/Progress%20Images/3.5.%20-%20First%20Sketch%20to%20Finished%20Prototype.png?raw=true)

We set out to make a game with 4 LEDs, 4 buttons, a display and a buzzer using Arduino Uno microcontroller. Originally the project also included a servo motor to make the LCD change angle, but this idea was scrapped since it was not part of the main functionality and due to the scope of the rest of the project.

The original idea was to a speed game similar to the one in the old Finnish game show “Speden Spelit”. We then decided to make a memory game instead. However, since the project had the all the required electronics for both games, eventually the project made a full circle and the original speed game idea was also programmed.

The user decides which game to play in the start menu where the leftmost button should be pressed for Memory Game and the rightmost button for Speed Game.

In Memory Game the player must repeat a randomly generated sequence displayed by the LEDs with the buttons. The sequence grows by one after each round and the whole sequence is displayed from the start after each round. The sequence is displayed always at the same calm speed and the player can take as much time as they want between the inputs. The game continues until the player gets the sequence wrong and the score is the number of rounds the player wins by getting the sequence right.

In Speed Game the player also must repeat a randomly generated sequence displayed by the LEDs with the buttons. However, the sequence grows all the time, and the speed slightly accelerates after each time it grows. The player is constantly repeating the sequence as it grows until the player makes a mistake and the game is over. The score is the total amount of correct inputs given.

To make the game more enjoyable and easier to follow, there is an LCD and a piezo buzzer in the system. The LCD shows the highest score ever reached when the game starts, the current score when the game is being played, prompts the user to choose one of the games in the start menu, tells when the game is over and if a new high score was set.

The piezo buzzer makes a different sound for each LED when the LED is lit. The buzzer is programmed to play a certain frequency and for the LEDs the frequencies are set up as C4, E4, G4 and C5 notes from left to right. That’s a C major chord! When a new game is beginning it plays a quickly rising sound and a quickly falling sound when the game is lost. Not to mention it plays amazing easter egg songs activated by holding one of the buttons down in the start menu. The sound design in this game is totally out of this world.

All that was quite a bit of embedded C and C++ based Arduino language programming!

The button system was 3D printed to make buttons that look more interesting and are easier to press than the very small actual electronic component buttons that are under the system. The casing was laser cut from 2 mm thick plywood.

The project advanced weekly and we accomplished an awesome prototype!


### Videos

Memory Game with the high score fanfare: https://www.youtube.com/watch?v=84gJxdbrVfw&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=1&ab_channel=VilleKylm%C3%A4maa

Speed Game: https://www.youtube.com/watch?v=mnNzNzYEoZY&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=2&ab_channel=VilleKylm%C3%A4maa


### Easter eggs

Here are the music easter eggs Ville programmed for the piezo buzzer. I’m holding the buzzer for better audio.

Megalovania by Toby Fox: https://www.youtube.com/watch?v=YPllY2mjIPw&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=3&ab_channel=VilleKylm%C3%A4maa

Astronomia by Tony Igy and Vicetone, also known as Coffin Dance: https://www.youtube.com/watch?v=EJ6rxVDyQ3Y&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=4&ab_channel=VilleKylm%C3%A4maa

Master of Puppets by Metallica, Kirk Hammet’s solo: https://www.youtube.com/watch?v=3PkglK9Oo-k&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=5&ab_channel=VilleKylm%C3%A4maa

Never Gonna Give You Up by Rick Astley: https://www.youtube.com/watch?v=SF4I14ke4gY&list=PLaXh4aINZpK3UAFl0ipgvpciPTIYi-pv6&index=6&ab_channel=VilleKylm%C3%A4maa


## Lessons learned

**Skills**: Arduino embedded programming, electronics design, 2D design and operating a laser cutter, 3D design and operating a 3D printer.

**Better work distribution would’ve been important**. Ville did majority of the work by doing all the electronics design, all the programming, a bunch of laser cutting, all the reports, attending TA sessions and holding both midterm and final presentations. Lasse made the 3D printed button system and together with Ville the heroic final stretch of putting everything together. Johannes and Tommy made the first iteration of the laser cut casing.

Although, things such as programming are hard to divide. Sometimes what one programmer can do in a month, two can do in two months.

**Laser cutting is fast and 3D printing is slow**. Almost no matter what you design, the laser cutter is going to cut it in the matter of few minutes. You can make a change and quickly cut a new piece. 3D printing on the other hand is very slow. Our button system didn’t have that much material and it still had to be done overnight and then one of the pieces still had to sit in some solution and be fetched later.

**Making the casing and the button system should’ve started earlier**. There was no reason to wait so long before starting the design for them and making the first iteration. It could’ve been started basically as soon as we knew the size of our LCD, LEDs and buttons. This made our final stretch of putting it all together require heroic effort because we were running out of time. Because of this we also learned too late that we should have made a microcircuit instead of soldering multiple cables together, and since we didn’t have enough time to make a microcircuit we ended up having to include the breadboard which we were supposed to discard inside the casing.

**Initiative is important and it’s good to ask questions as early as possible**.


<br>

# Development Blog

### Monday 15/03:

The course starts and the group is formed. The members are Ville Kylmämaa, Lasse Rapo, Tommy Meriläinen and Johannes Lampela. Ville got the basic idea of a speed game based on the old Finnish game show “Speden Spelit”.

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

#### First sketch
![First sketch](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/28.3%20-%20First%20Sketch.png)

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

![First Arduino build](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/4.4.%20-%20First%20Arduino%20Build.jpg)

Ville transferred the code from the simulation to the Arduino. Unfortunately, the code doesn’t work quite as well on the Arduino. The game sometimes registers a failed input even though the input was assuredly correct. Why this happens on the Arduino and not in the simulation, is left to be determined.

<br>


## Week 14

 
### Goals of the week:

* Debug why the game doesn’t work quite as well on the Arduino as in the simulation.
* Figure out how to connect the LCD to the circuit and how to program it.
* Further improve the code.
* Start designing the laser cutting in Inkscape

### Wednesday 07/04:

Ville fixed the button issue.

The issue was that while the buttons in the Tinkercad simulation give you a signal that goes perfectly from 0 to 1 and vice versa, electronic components in the real world often can’t provide a perfect signal. The real buttons give a signal that when pressed down or released, the signal would sometimes quickly oscillate  multiple times between 0 and 1  during the transition.

![Button bounce graph](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/7.4%20-%20Button%20Bounce.jpeg)

Image source: https://embedds.com/software-debouncing-of-buttons/

This leads to multiple inputs with a single press of a button which leads to an unenjoyable game that is lost because of an extra input. A single press should always give exactly one input. The issue was easy enough to take into account in the code.

![Button debounce timer code](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/7.4%20-%20Button%20Fix.png)

The solution was to use a debounce timer that resets if button bouncing happens during the transition and only lets the game check whether the input was correct or not after the debounce timer has exceeded the debounce delay, which was set to 50 milliseconds.

### Friday 09/04:

Two of the LEDs, red and transparent, were overly bright. Bright enough to leave a spot in your vision after looking at them, making the game uncomfortable to play.

Ville made the two LEDs less bright by changing the connections to PWM (Pulse-Width Modulation) pins on the Arduino and using analogWrite() instead of digitalWrite(). After a call to analogWrite(), a PWM pin will generate a steady rectangular wave of the specified duty cycle. Choosing a lower duty cycle makes the connected LED less bright. 

### Saturday 10/04:

Ville attempted to connect and program the LCD display through an I2C adapter. The attempt was unsuccessful. The LCD mostly doesn’t display anything except when the brightness/contrast screw on the back of the I2C is turned, the LCD produces glitches such as black boxes or random lines.

![Glitching LCD display](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/10.4.%20-%20LCD%20glitch.jpg)

All the connections should be correct. From I2C to Arduino Uno: GND to GND, VCC to 5V, SDA to A4, SCL to A5. The I2C address is 0x27 confirmed through a test. It’s trying to run just a basic hello world program, tested with multiple libraries available for the I2C. Is the LCD or the I2C faulty?

Ville ran a diagnostic test program for LCD and I2C from an Arduino library called hd44780: https://www.arduino.cc/reference/en/libraries/hd44780/

![LCD diagnostics](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/10.4.%20-%20LCD%20Diagnostics.png)

The diagnostics program reports that I2C seems to be working and the connections are right, but the LCD is stuck in BUSY status and is therefore marked as not working.

Later, Ville noticed the LCD is running hot and especially one of the black circles on the back of the LCD is hot enough to be painful to touch. There is likely a short circuit but it’s not clear where.

### Sunday 11/04:

Ville connected the buzzer to the circuit and programmed it to beep when the game displays the sequence or the player presses a button. The frequency of the beep for each LED is of course different. The frequencies were set up as C4, E4, G4, C5, i.e. the C major chord, for a delightful musical experience.

The beeps really add to the game, making the sequence easier to remember and more fun to repeat.

<br>


## Week 14


### Goals of the week:
* Switch the LCD and get it working
* Start designing the casing, laser cut it next week if possible

### Wednesday 14/04:

In the TA session this week we determined that the LCD was probably faulty. Ville fetched a new LCD from Fablab and it works mostly without issues. Curiously, the LCD only works properly when connected to 3.5V even though the manufacturer says that it should be connected to 5V on the Arduino. Connected to 5V the LCD doesn’t work, displaying just black boxes.

Additionally, the new LCD has RGB background lighting which can be animated with code!

### Friday 16/04:

Ville fetched more jumper cables from Fablab to make all connections possible at the same time. 4 buttons, 4 LEDs, an LCD and a buzzer is quite a lot.

![Memory Game video](https://github.com/VilleKylmamaa/DigitalFabrication-MemoryGame/blob/main/Progress%20Images/16.4.%20-%20Memory%20Game%20Video%20Compressed.gif?raw=true)

The game works well. You can play as fast as you can and the game won’t take double inputs. The feedback from the buzzer makes the game more fun and helps you memorize the sequence. The LCD let’s you know how long the current sequence is and how many inputs you have given so far for the current sequence. Not to mention the totally amazing RGB animation!

### Sunday 18/04:

We started designing the casing with Inkscape as a team. The box will be laser cut.

![Inkscape design started](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/18.4%20-%20Inkscape%20Design%20Started.png)

There are a couple of challenges regarding the casing.

1. The breadboard should be above the Arduino to make the box less deep. How will we securely attach a panel to the middle and make sure that all the wires can get from the Arduino to the breadboard?

2. How could we make the LCD angle change with a servo?


<br>


## Week 16

### Goals of the week:
* Design the casing and the button system
* Laser cut the casing and 3D print the button system

Laser cutting the casing was postponed because everyone was busy and we realized that the button caps should also be designed before laser cutting so that we know the size of the hole required for the button caps. Lasse started designing the 3D model for the button caps.

Ville attended the weekly TA session to ask some questions about the casing design. It was confirmed that making the LCD change angle with a servo would be optional given the scope of the rest of the project and because it’s not part of the main functionality.

Ville also figured out that you can program music with the piezo buzzer by finding the frequencies of the notes:

![Piezo buzzer music programming](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/23.4.%20-%20Piezo%20Buzzer%20Music%20Programming.png)

The limitation is that the piezo buzzer can only play one note at a time. Thus, it can’t play chords. The music can’t be used during the game but perhaps it could be a reward for reaching a high score or some sort of an easter egg.

Tommy and Johannes will laser cut the casing next week and Lasse will 3D print the caps for the buttons.


<br>


## Week 17

### Goals of the week:
* Design the casing and the button system
* Laser cut the casing and 3D print the button system

### Button design:

The button system was expanded from this design by username “jeplans” on Thingiverse: https://www.thingiverse.com/thing:1909644

Link to Lasse’s Tinkercad design: https://www.tinkercad.com/things/fN4gwttubXP-memory-game-buttons

![3D button design](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/27.4.%20-%203D%20Button%20System.png)

The design 3D printed, Teerenpeli drink underlay for scale:

![Button design 3D printed](https://github.com/VilleKylmamaa/DigitalFabrication-MemoryGame/blob/main/Progress%20Images/30.4.%20-%20Button%20System%203D%20Printed.jpg?raw=true)

This button system was designed for the shorter buttons so we switched our tall buttons for smaller ones at the Fablab. Every piece was printed with white plastic to save time with the 3D printing.

### Casing:

The casing was laser cut from plywood:

![Button design 3D printed](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/27.4.%20-%20Laser%20Cut%20Casing.jpg)

Unfortunately, the hole for the USB on the side and the holes for the LEDs on the top were forgotten.

Ville added the extra holes to the design later.

### Speed Game:

The original idea for this project was to make a speed game but we decided to make a memory game instead. Well, the project has all the prerequisites for a speed game as well. It’s possible to have both!

Ville programmed the speed game from “Speden Spelit” to the system. It was easy enough given that the code for an increasing sequence, debouncing buttons, checking if the input was correct or wrong, etc., had already been implemented for Memory Game.

It was somewhat challenging figuring out how to let the user give inputs while the sequence is growing faster and faster, and getting displayed on the LEDs. The Arduino delay()-function couldn’t be used because it would pause the ability to give inputs. Instead, a solution using the millis()-function to calculate how much time had passed since the sequence last grew was used to make the game work properly.

The sequence starts by growing after each 1000 milliseconds and gets 15 milliseconds faster after each time the sequence gets longer. The acceleration drops to 5 milliseconds faster after sequence length of 40 to ease the acceleration curve.

Now that there are two games in the system, the player chooses which game to play after the turning the device on and after each game. The choice is made by clicking either the leftmost button for Memory Game or rightmost button for Speed Game, as prompted by the LCD and the two LEDs.

Not to mention the high score system Ville added. Separate high scores for both games, of course. The high score is saved to the memory with the Arduino EEPROM library so that the high scores is saved even when the Arduino is turned off. After reaching a new high score, the game congratulates the player with a delightful tune, the chorus from Never Gonna Give You Up by Rick Astley, programmed to the piezo buzzer.

![Speed Game](https://github.com/VilleKylmamaa/DigitalFabrication-MemoryGame/blob/main/Progress%20Images/2.5.%20-%20Speed%20Game%20Video%20Compressed.gif?raw=true)

Ville also programmed easter egg songs to the piezo buzzer. The easter eggs are activated by holding one of the buttons down for two seconds in the start menu. Each of the 4 buttons has a different song.

### The final stretch

Ville and Lasse went to Fablab to finish the project. What was left was just putting it all together.

It wasn’t easy. Arduino Uno has just 3 GND pins and because we didn’t want to have the breadboard inside the box we needed 10 cables to go to GND. We thought it would be as simple as soldering some cables together, but the assistant at the Fablab told us that soldering so many cables together would be a doomed idea and we would need to produce a microcircuit for the task. We didn’t have the time for producing a microcircuit so we decided to leave the breadboard inside instead.

The top of the box needed multiple iterations to get it right. There was a part on the side of the LCD that wasn’t considered before. Although the LCD fit through the hole, this extra part would make screwing the LCD impossible. The hole for the button system needed to be bigger. The breadboard was very difficult to fit in because we shouldn’t have needed it.

Here’s a picture of the underside of the button system, where pins of the buttons are soldered:

![Buttons soldered](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/3.5.%20-%20Buttons%20Soldered.jpg)

After heroic effort of 5 hours in the Fablab, everything fit inside the box and everything that needed soldering was soldered. Note all the extra casing tops:

![A complete casing and 5 extra casing tops](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/3.5.%20-%20All%20Done.jpg)
 
Later, Ville also painted the buttons to the same colour as the corresponding LEDs.

We did it! We have a fully functional Memory Game and Speed Game inside this lovely little box.

This is the conclusion of this development blog. Here is the finished product:

![Finished prototype](https://raw.githubusercontent.com/VilleKylmamaa/DigitalFabrication-MemoryGame/main/Progress%20Images/3.5.%20-%20Finished%20Prototype.jpg)

Videos are found in the introduction section at the start.



<br>
