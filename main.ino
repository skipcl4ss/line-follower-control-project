// Variables used in measuring distance
long duration;
int distance;
// Ultrasonic sensor pins
#define trigger 6
#define echo 5
// IR sensors pins
#define irLeft 9
#define irRight 7
// H-bridge pins
// Right motor
#define rightEnable 10
int rightForward = 8;
int rightBackward = 13;
// Left motor
#define leftEnable 11
int leftForward = 4;
int leftBackward = 12;

// Defining whether the pins are inputs or outputs
void setup()
{
    // Ultrasonic sensor
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    // IR sensors
    pinMode(irRight, INPUT);
    pinMode(irLeft, INPUT);
    // H-bridge pins
    // Enable pins for speed
    pinMode(rightEnable, OUTPUT);
    pinMode(leftEnable, OUTPUT);
    // Input pins for direction
    pinMode(rightForward,OUTPUT);
    pinMode(rightBackward,OUTPUT);
    pinMode(leftForward,OUTPUT);
    pinMode(leftBackward,OUTPUT);
}

void loop()
{
    // Save the distance that the ultrasonic calculates in a variable
    distance = getDistance();
    // If there is an obstacle close nearby, the car avoids it
    if (distance <= 15)
    {
        // The values of the delays are a rough estimate and are bound to change when useing the car on the track
        // Stop for a second
        stop();
        delay(1000);
        // The car redirects itself left and moves for 675 milliseconds
        moveLeft();
        delay(250);
        moveForward();
        delay(675);
        // The car redirects itself right and moves for 675 milliseconds
        // The delay value should be roughly double that of moving left, to face forward again
        moveRight();
        delay(400);
        moveForward();
        delay(675);
    }
    // If there are no obstacles, it follows the line
    // When the left sensor sees black, the car goes left
    else if (seesBlack(irLeft) && !seesBlack(irRight))
    {
        moveLeft();
    }
    // When the right sensor sees black, the car goes right
    else if (!seesBlack(irLeft) && seesBlack(irRight))
    {
        moveRight();
    }
    // If both sensors see the same color, the car goes forward
    else {
        moveForward();
    }
}
/**
 * @brief The function just returns the value read by the sensor, I just used it to make the code more readable
 * @param sensor: The pin number of the sensor
 * @return digitalRead(sensor), HIGH if the sensor sees black, LOW if it sees white
*/
int seesBlack(int sensor)
{
    return digitalRead(sensor);
}
/**
 * @brief calculate the distance by calculating the time it takes for the sound wave to travel back and forth, divide it by two, and multiply it by the speed of sound
 * @return distance in front of the car in centimeters
*/
int getDistance()
{
    // Clears the trigger pin condition
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    // Sets the trigger pin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    // Reads the echo pin, returns the sound wave travel time in microseconds
    duration = pulseIn(echo, HIGH);
    // Calculating the distance
    // 0.034 is the speed of sound in cm per microsecond, divided by 2 because the sound wave travels back and forth
    distance = duration * 0.034 / 2;
    return distance;
}
/**
 * @brief makes the car stop by setting both the direction and the enable pins to 0 for a certain amount of time
 * @param delayTime: the time in milliseconds that the car stops for
*/
void stop()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
  analogWrite(rightEnable, 0);
  analogWrite(leftEnable, 0);
}
// @brief makes the car move forward by setting the forward pins to 1 and the enable pins to slightly different speeds to compensate for physical errors
void moveForward()
{
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
    analogWrite(rightEnable, 50);
    analogWrite(leftEnable, 51);
}
// @brief makes the car move right by setting the right motor forward and the left one backward, with different speeds to make the car follow the line smoothly
void moveRight()
{
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, HIGH);
    analogWrite(rightEnable, 55);
    analogWrite(leftEnable, 65);
}
// @brief makes the car move left by setting the left motor forward and the right one backward, with different speeds to make the car follow the line smoothly
void moveLeft()
{
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
    analogWrite(rightEnable, 65);
    analogWrite(leftEnable, 55);
}
