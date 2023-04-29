# line-follower-control-project
A team project that we made last semester for the Control Components course where we used an Arduino Nano to make a line-following car that also avoids an obstacle in the track.

## Car Characteristics 
The car has:
* 3 wheels
* 3 sensors
    * 2 IR sensors
    * 1 Ultrasonic
* Arduino Nano
* H-bridge
* Breadboard
* 2 DC motors
* 3 cells of voltage 3.7V

## Moving Mechanism
#### Line Follower
The car has two IR sensors in the front of the car, one on the left and the other on right. Those two sensors are adjusted to read digital input, where 0 indicates white and 1 indicates black. Therefore, there are 4 possible outcomes (2<sup>2</sup>).
Left \ Right| White | Black
:---: | :---: | :---:
White | Forward | Right
Black | Left | Forward

The car moves forward automatically, when one of the sensors detect the black line, it gives a signal to the microcontroller (Arduino); to rotate left or right. And when the ultrasonic sensor detects an obstacle, it gives a signal to the microcontroller (Arduino); to avoid it by turning around the obstacle. the wheels are 2 connected to the motor
for leading the car, 1 back wheel for supporting the veichle.

## The Arduino type: 
Arduino nano microcontroller.

## License

This project is licensed under the terms of the [MIT license](https://opensource.org/licenses/MIT).
