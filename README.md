### Future engineers

### TEAM ROBOCRV

Our project consists of the manufacture of an automated land vehicle, which navigates in an environment marked by colored obstacles, taking different paths depending on the characteristics and properties of said obstacles. We use a technology based on Arduino (C++), which has programming composed of the ultrasonic sensor module that sends and receives ultrasonic pulses at a set distance, which when detecting an object will activate a color sensor that defines the color of the object, indicating to the vehicle's movement system where to go. Depending on the color, it will move to the right, left or backwards to be able to avoid the obstacle in the best way, clockwise or counterclockwise depending on the requirement of the round.

___

The code is created on a laptop under **Windows 10 and/or GNU-Linux** operating system, the software used is **Arduino IDE version 1.8.18** loaded to an **Arduino Mega** board, through a data transmission cable. This board is powered by 2 3.7 volt lithium batteries.

The device also has another battery holder with two 3.7-volt lithium batteries, which powers the motor controller and provides the necessary energy to perform tasks with excellent speed.

___

Coding has different routines for:

-Perform movement, using a servomotor that has the ability to be located in any position within its range of action, and from there, execute a direction.

-Detection of obstacles, using ultrasonic sensors that determine their proximity, sending a signal to the plate that will activate the color sensor.

-Color identification using a color sensor. Depending on the identified color, it will go, if it is Red on the right side, if it is Green on the left side, if it is Black, it will define it as a wall and avoid it, clockwise or counterclockwise depending on the requirement of the challenge.

-Stop when you identify the Magenta color and park in the area designed for this purpose.

___

The vehicle is made in an original way using various equipment from many sources to be able to create a robot with a completely own design both physically and computerically.

In this repository you can find:

-Elements that make up the robot (plate, sensors, mobility components and structure)

-Photos of the robot (angles of the robot, the assembly process and recorded tests)

-Instructions given to the robot and what it should do (flowcharts and protocodes)

-Code used and its updates (commits)

-Wiring diagram made in [**Wokwi**](https://wokwi.com/) (Arduino project simulator)

___

This vehicle owes its mobility to a 5-volt DC motor connected to two rear wheels for traction, linked through a single axle. A front axle controlled by a servomotor (micro servo gg sg90), which using levers can rotate the axle to the left or right depending on the degrees it has. The DC motor and the servomotor work with 5 volts. The engine generates a Torque of 1.9 Nm, which, considering the weight of the vehicle, which is 1100 grams, made it necessary to add a counterweight at the rear for greater grip and to avoid “jumps” or skidding.

The sensors work with 5 volts, the board on the other hand uses two 3.7 volt batteries and a voltage amplifier was also connected so that the controller would receive more energy and thus be able to generate greater force to the DC motor

For this robot, no 3D printer was used to make the parts, everything was completely a matter of collecting various parts for assembly based on our needs.
