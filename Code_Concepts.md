<h3><b>Overall Objective:</b></h3>
The code aims to control the movement of a robot equipped with ultrasonic sensors, IR sensors, and DC motors. The robot's behavior is governed by two primary actions:

1. **Obstacle Avoidance:** When the IR sensors detect an obstacle in front or behind the robot, it triggers a backward or forward movement, respectively, to evade the obstacle.

2. **Enemy Detection and Attack:** The ultrasonic sensor continuously scans for nearby objects. If an object is detected within a certain distance threshold, the robot switches to attack mode, driving towards the object with full power.

**Code Structure:**

The code is organized into several functions, each handling a specific task:

1. `microsecondsToCentimeters()`: Converts the duration measured by the ultrasonic sensor in microseconds to centimeters.

2. `ultra()`: Measures the distance using the ultrasonic sensor and stores the value in the `centimeters` variable.

3. `backward()`: Sets the motor pins to control the robot's movement in reverse.

4. `forward()`: Sets the motor pins to control the robot's movement forward.

5. `search()`: Sets the motor pins to control the robot's movement in a slow, scanning manner.

6. `attack()`: Sets the motor pins to control the robot's movement at full speed towards the detected object.

7. `detection()`: Combines `ultra()` and attack/search operations: it measures the distance and triggers either `attack()` or `search()` based on the distance value.

8. `setup()`: Initializes the pin modes for motors, sensors, and encoders.

9. `loop()`: Continuously reads the sensor values and triggers the appropriate actions based on the detected conditions.

**Key Concepts:**

- Sensor fusion: The code utilizes both ultrasonic and IR sensors for obstacle detection and enemy identification.

- Distance-based behavior: The robot's behavior is dynamically adjusted based on the distance measured by the ultrasonic sensor.

- Object avoidance: The robot implements obstacle avoidance mechanisms to prevent collisions.

- Enemy detection and attack: The robot actively searches for nearby objects and attacks them upon detection.
