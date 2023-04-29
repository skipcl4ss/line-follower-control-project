# line-follower-control-project
A team project that we made last semester for the Control Components course where we used an Arduino Nano to make a line-following car that also avoids an obstacle in the track.
- - - -
## Car Characteristics 
The car has:
* 3 Wheels
* 3 Sensors
    * 2 IR Sensors
    * 1 Ultrasonic sensor
* Arduino Nano
* H-Bridge
* Breadboard
* 2 DC Motors
* 3 Battery Cells (3.7V)
* Steering wheel

## Moving Mechanism
The two DC motors are attached in the front side of the care, and the steering wheel is at the back.
#### Line Follower
The car has two IR sensors in the front of the car, one on the left and the other on right. Those two sensors are adjusted to read digital input, where 0 indicates white and 1 indicates black. Therefore, there are 4 possible outcomes (2<sup>2</sup>).
Left \ Right| White | Black
:---: | :---: | :---:
White | Forward | Right
Black | Left | Forward
#### Obstacle Avoidance
Due to lack of time, and since that the track had only one obstacle, we had to make the car avoid that obstacle with a hard-coded mechanism.When the ultrasonic sees an obstacle in range of 15 centimeters, the car turns left, turns right, and then adjusts itself to face forward and look at the track line.

## The Arduino type
Arduino Nano microcontroller, with Arduino C++ as the programming language used.
- - - -
## Code
**work in progress**
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
