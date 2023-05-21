# line-follower-control-project

A team project that we made last semester for the Control Components course where we used an Arduino Nano to make a line-following car that also avoids an obstacle in the track.
- - - -

## Car Characteristics 
The car has:
* 3 Wheels
    * 2 Regular Wheels
    * 1 Steering Wheel
* 3 Sensors
    * 2 IR Sensors
    * 1 Ultrasonic sensor
* 1 Arduino Nano
* 1 H-Bridge
* 1 Breadboard
* 2 DC Motors
* 3 Battery Cells (3.7V)

## Moving Mechanism

The two DC motors are attached in the front side of the care, and the steering wheel is at the back.

### Line Follower

The car has two IR sensors in the front of the car, one on the left and the other on right. Those two sensors are adjusted to read digital input, where 0 indicates white and 1 indicates black. Therefore, there are 4 possible outcomes (2<sup>2</sup>).
Left \ Right| White | Black
:---: | :---: | :---:
White | Forward | Right
Black | Left | Forward

### Obstacle Avoidance

Due to lack of time, and since that the track had only one obstacle, we had to make the car avoid that obstacle with a hard-coded mechanism.When the ultrasonic sees an obstacle in range of 15 centimeters, the car turns left, turns right, and then adjusts itself to face forward and look at the track line.

## The Arduino type

Arduino Nano microcontroller, with Arduino C++ as the programming language used.
- - - -

## Code

***Note that those words in the following context have the same meaning:***  
HIGH, 1, and True mean that max voltage is given to the terminal in question.  
LOW, 0, and False mean that min or no voltage is given to the terminal in question.

### Global Variables

* duration, distance: used in the calculations of the ultrasonic sensor to measure the distance, it represents the time taken by the waves to travel from the ultrasonic sensor transmitter (trigger) to the receiver (echo), and the distance from the sensor to the obstacle in front of it respectively.
* trigger (Digital, Output), echo (Input): the pins which transmit and receive the ultrasonic waves respectively.
* irLeft, irRight (Digital, Input): the input pins for the ir sensor connected to the left and the right sides of the car respectively.
* rightForward, rightBackward, leftForward, leftBackward (Digital, Output): the pins which determine the polarity given for each terminal of each motor respectively. For example, the right motor moves backwards if rightForward is LOW, and rightBackward is HIGH.
* rightEnable, leftEnable (Analog, Output): pins used in the H-Bridge tn determine the speed given for each motor respectively.

### Functions Used

***int seesBlack(int sensor)***  
Returns the reading of the IR sensor, where **1** is black and **0** is white.

***int getDistance()***  
Sends an ultrasonic pulse, calculates *duration* of travel of this pulse in microseconds and multiplies it by a factor to get the distance centimeters. This factor is 0.034 cm/µs (speed of sound) and dividing by two gives us the *distance* half of that travelled back and forth.

***void Stop(int delayTime)***  
Stops the car by giving the terminals of both motors the same voltage of **zero**, and reduces the speed to **zero**.

***void moveForward()***  
Moves the car forward by giving the *Forward* pins a **HIGH** value and *Backward* pins a **LOW** one, and giving both enable pins the same-ish value, you may need to give them slightly different values to compensate for physical errors

***void moveRight()***  
Moves the car right by giving the *Forward* pins a **HIGH** value and *Backward* pins a **LOW** one, but giving the *leftEnable* pin a noticably higher value than that of *rightEnable*. This makes the car drift to the right.

**void moveLeft()**  
Moves the car right by giving the *Forward* pins a **HIGH** value and *Backward* pins a **LOW** one, but giving the *rightEnable* pin a noticably higher value than that of *leftEnable*. This makes the car drift to the left.

### Main Loop

The code takes the return value of ***getDistance()*** and saves it in *distance*.  
If the *distance*:
* is less than or equal than 15cm:  
This means that the is an obstacle. In this case, the car will stop, turn left for a certain time, move forward for a little bit   of time, turn right for a certain time that is longer than that of turning left (the value of the delay is approximately double,   to cancel out the effects of ***moveLeft()*** and in the end move in the right direction), and moves forward again for some time. 
* is more than 15cm and only the left IR sensor ***seesBlack()*** line, the car will ***moveLeft()***.
* is more than 15cm and only the right IR sensor ***seesBlack()*** line, the car will ***moveRight()***.
* is more than 15cm and both sensors see the same color regardless of what it is, the car will ***moveForward()***.

## Project in Action
**work in progress**
- - - -
## License
It is worth noting that even though this is a team project, this repo contains my own version of the code that I edited to increase the readability and that the logic of the code is still the same.
My teammates in the project were:
* [Ahmed Salah](https://github.com/Ahmed-Salah-312) (Team Leader)
* [Youssef Ehab](https://github.com/Youssef231001)
* [Youssef Ashmawy](https://github.com/youssefashmawy)
* [Omar Saleh](https://github.com/MrMariodude)
* [Nour Eldein Karem](https://github.com/NourEl-dein)
* Mohamed Fathy

This project is licensed under the terms of the [MIT license](https://opensource.org/licenses/MIT).
