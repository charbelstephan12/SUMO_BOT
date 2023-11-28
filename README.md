## Arduino Sumo Bot 🤖

### Overview 📖

Embark on an electrifying journey into the world of robotics with our Arduino Sumo Bot—a pulsating project ⚡️ born from the depths of a university course 🎓. Tailored for riveting Sumo battles, this bot seamlessly weaves together the threads of Arduino programming 💻, sophisticated sensor integration 📡, and laser-focused motor control 🕹️.

### Key Features ✨

* **Arduino-Powered:** Driven by an Arduino microcontroller 🧠, offering a malleable and programmable canvas for robotics enthusiasts.

* **Sensor Integration:** Armed with infrared sensors, our Sumo Bot deftly senses Sumo ring edges 📏 and strategically tracks its adversary.

* **Motor Control:** Revel in precise control over motors ⚙️, enabling nimble movements crucial for outmaneuvering opponents in Sumo battles 🔥🔥🔥.

### Getting Started 🚀

1. **Hardware Setup:** Dive into detailed instructions for assembling the necessary components.

2. **Codebase:** Immerse yourself in the Arduino code directing the Sumo Bot's evasive maneuvers and tactical decision-making.

3. **Documentation:** Uncover the mysteries with a comprehensive guide, unveiling the project's structure, functionality, and customization options.

### Competition Rules 🏆

**Hardware**

* Maximum of two motors for movement ⚙️
* Any sensors allowed
* No height or weight limit
* Recommended chassis: Teacher's recommendation or the closest alternative chassis
* Budget: Around $50 💵💵💵

**Ring Size**

* 0.6 meters in surface

**Out of Bounds**

* A robot is considered out of the ring if any part of its body touches the ground outside of the ring

**Winning Condition**

* First robot to force the opponent robot out of the ring wins the match

### Scoring 🏆🏆🏆

**Full Win:** 2 points for forcing the opponent robot out of the ring 🏆🏆

**Early Win:** 1 point 🏆 for kicking the opponent robot out of the ring within the first 30 seconds. The match resumes.

### Safety 🛡️🛡️🛡️

* **Safe Design:** All robots must be designed and operated in a safe manner.

* **No Weapons:** Robots must not be equipped with any weapons or other devices that could harm other robots or spectators 🚫🚫🚫.

### Code Structure 🏗️

The code is organized into distinct functions, each tailored to specific tasks:

• **microsecondsToCentimeters():** Converts the duration measured by the ultrasonic sensor in microseconds to centimeters 📏.

• **ultra():** Measures the distance using the ultrasonic sensor and stores the value in the centimeters variable 📊.

• **backward():** Sets the motor pins to control the robot's movement in reverse 🔙🔙🔙.

• **forward():** Sets the motor pins to control the robot's movement forward ➡️➡️➡️.

• **search():** Sets the motor pins to control the robot's movement in a slow, scanning manner 🔎🔎🔎.

• **attack():** Sets the motor pins to control the robot's movement at full speed towards the detected object 🚀🚀🚀.

• **detection():** Combines ultra() and attack/search operations, measuring the distance and triggering either attack() or search() based on the distance value 📈📈📈.

### Key Concepts 💡

The code incorporates several key concepts that govern the robot's behavior:

• **Sensor Fusion 🤝🤝🤝:** The code effectively utilizes both ultrasonic and IR sensors for ligne detection and enemy identification, enabling comprehensive environmental awareness.

• **Distance-based Behavior 📏📏📏:** The robot's behavior is dynamically adjusted based on the distance measured by the ultrasonic sensor, transitioning between lign avoidance and attack modes based on proximity to objects.

• **Enemy Detection and Attack ⚔️⚔️⚔️:** The proactive scanning and attacking behavior using the ultrasonic sensor demonstrate the robot's ability to detect and engage opponents.

### Usage 🚀

To use this code for your sumo robot, follow these steps:

1. **Connect the sensors and motors:** Connect the ultrasonic sensor 📡, IR sensors 👁️‍🗨️, and DC motors ⚙️⚙️ to the Arduino Uno microcontroller 🧠 according to the wiring diagram.

2. **Upload the code:** Upload the code to the Arduino Uno microcontroller 🧠 using the Arduino IDE 💻.

3. **Place the robot in the sumo arena:** Place the robot 🤖 in the sumo arena ⭕️ and power it on 🔌.

4. **Observe the robot's behavior 👀👀👀:** The robot 🤖
