## Proyecto Futuros Ingenieros
### REXBOT

### Team RoboCRV
 
Nuestro proyecto consiste en la fabricación de un vehículo terrestre automatizado, que navega en un entorno señalizado por obstáculos de colores, tomando diferentes caminos en función  de las características y propiedades de dichos obstáculos. Utilizamos una tecnología basada en **Arduino (C++)**, que posee una programación compuesta por sensores ultrasónicos que envían y reciben pulsos a una distancia preestablecida en el código, los cuales al detectar la proximidad de un objeto, envían una señal a la placa **Arduino**, que indicará al sistema de movimiento del vehículo hacia donde dirigirse, en sentido horario o antihorario, según lo preestablecido. Por otro lado, también cuenta con un sensor de visión o cámara  **Huskylens (Gravity)** para detectar los obstáculos de colores, y evadirlos cuando sea necesario. Dependiendo del color, se desplazará por la derecha o la izquierda del obstáculo, según lo requerido. 
  
El código fue creado en un equipo portátil bajo sistema operativo **Windows 10 y/o GNU-Linux**. El software utilizado es **Arduino IDE versión 1.8.18**, cargado a una placa **Arduino  Mega**, a través de un cable de transmisión de datos. Esta placa está abastecida por 2 baterías de litio de 3.7 voltios.

El dispositivo también cuenta con otro portapilas de dos baterías de litio de 3.7 voltios, que alimenta el controlador del motor y proporciona la energía necesaria para poder realizar las tareas con una velocidad óptima. 

La codificación tiene diferentes rutinas para:

- Realizar movimiento, utilizando un servomotor que tiene la capacidad de ubicarse en cualquier posición dentro de su rango de acción, y desde allí, ejecutar una dirección.

- Detección de obstáculos, mediante sensores ultrasónicos que determinan la proximidad de los mismos, enviando una señal a la placa que activará el sensor de color.

- Identificación de color utilizando un sensor de color. Según el color identificado se dirigirá, si es Rojo por el lado derecho, si es Verde por el lado izquierdo, si es Negro, la definirá como pared y la esquivará, en sentido horario o antihorario según el requerimiento del desafío.  

- Detenerse al identificar el color Magenta y aparcar en la zona diseñada para tal fin.

El vehículo está hecho de forma original usando diversos equipos de muchas fuentes para poder realizar un robot con un diseño completamente propio en Hardware y Software.

En este repositorio se pueden encontrar:

- Elementos que conforman el robot (placa, sensores, componentes de movilidad y estructura)

- Fotos de el robot  (ángulos del robot, el proceso de ensamblado y pruebas grabadas)

- Instrucciones dadas al robot y lo que debería hacer (diagramas de flujo y protocódigos) 

- Código utilizado y sus actualizaciones (commits)

- Diagrama de cableado realizada en **Wokwi** (simulador de proyectos de Arduino)

Este vehículo debe su movilidad a un motor DC, conectado a dos ruedas traseras para la tracción, unidas a través de un solo eje. Un eje delantero controlado por un servomotor **(micro servo mg90)**, el cual mediante palancas puede girar el eje hacia la izquierda o derecha en función de los grados que tenga. El motor DC y el servomotor trabajan con **5 voltios**. El peso total del vehículo es de **1100 gramos**.

El **sensor ultrasónico** trabaja con **5 voltios**, el **sensor visual** (cámara) con **3,3 voltios**, la placa **Arduino Mega**, por otro lado utiliza **dos baterías de 3.7 voltios** y el **servomotor 5V**.

Para este robot no se utilizó impresión 3D para realizar las piezas.Se hizo recolección de diversas piezas para su ensamblaje en función de nuestras necesidades.

##### Materiales: 

###### Parte electrónica:

- Placa **Arduino Mega**

- Elevador DC-DC step up **XL6009** 5V a 32V 

- Jumpers

- Cables de red

- 6 Pilas de litio de 3.7 voltios

- 2 porta pilas

- Borneras

- Cámara **Huskylens (Gravity)**

- 2 Sensores ultrasónicos **Hc-SR04**
###### Sistema de tracción:

- Motor DC

- Caja de engranajes para motor DC

- Bujes para ruedas de goma

- 4 ruedas de goma

- Controlador de motores (driver **L298**)

- 1 Servo (Servo motor **Mg995R o Mg996R**)

- Barra de acero para buje de parte delantera

- Laminas de Acrilico de 5mm y 3 mm

- Espaciadores de teflón industrial

- Espaciadores de metal con rosca para tornillos

- Cable de cobre rígido

- Tuercas y tornillos
###### Gestión de movilidad:

Este vehículo debe su movilidad a un motor DC, conectado a dos ruedas traseras para la tracción, unidas a través de un solo eje, y dos ruedas delanteras conectadas al sistema de dirección.

**Sistema de dirección:** dirección delantera a través de un servomotor (servomotor **mg995r**) que consta de tres pines, positivo, negativo y datos que va a la placa **Arduino Mega** al pin 3, para controlar sus giros mediante grados, con un sistema de palanca que cada vez que gira el servo entre 0 y 180 grados, a la izquierda o derecha, empuja el eje principal hacia la izquierda o hacia la derecha respectivamente.  

Este sistema de dirección cuenta con una palanca que va fija desde el brazo del servomotor hasta el eje de una de las ruedas, que conecta con la otra. Utilizamos ruedas de goma para que tenga mayor adherencia a la pista.
###### Gestión de energía:

**Conexión eléctrica del sistema de tracción trasera:** constituido por dos pilas de 3.7 voltios conectadas en serie para dar 7.4 V, conectadas a su vez al elevador de voltaje (**XL6009**) para dar 10 V sostenidos al driver **L298**, en su entrada de 12 voltios, para proporcionar mayor eficiencia al motor DC. Este va conectado de sus pines n1 y n2 a la placa **Arduino Mega** en sus pines 8 y 7, para cambiar polaridad de energía que defina el giro de las ruedas, si avanza o retrocede. Del **L298** van conectados a las salidas del motor DC de 5V.

La placa microcontroladora está alimentada mediante dos baterías **18650** 3.7 V en serie conectadas al puerto de 12 voltios corriente directa.
###### Sistema de Sensores:

El carro cuenta con dos sensores ultrasónicos (**HCSR04**) que consta de 4 pines, positivo, negativo, trigger y echo, que van conectados a la placa **Arduino Mega** para dar la función de detección de paredes. Este funciona a través de ondas ultrasónicas que son emitidas y recibidas por el mismo, detectando la proximidad de un objeto, enviando una señal lógica a la placa  para ejecutar una acción. Además utiliza un sensor de visión o cámara, **Huskylens (Gravity)** para detectar los obstáculos de colores, que consta de cuatro pines positivo, negativo, Tx (transmisión de datos) y Rx (recepción de datos) que van conectados a la placa **Arduino Mega** a los pines 10 y 12(Rx y Tx).

###### Detallado del archivo CAD:

- Base Inferior de Rexbot (chasis): tiene la parte frontal ovalada en forma de parachoques para evitar golpes durante las pruebas, que afecten al sensor ultrasónico que está ubicado en el centro de la zona frontal. 

- El chasis está constituido por una pieza de acrílico de 5 mm, material que nos permite la dureza para  garantizar la rigidez torsional y el anclaje de piezas, y la resiliencia al momento de impactos. Sus dimensiones son de 26cm de largo y 19cm de Ancho.

- En el chasis tenemos dos espacios simétricos a cada lado, para colocar las ruedas, con la capacidad suficiente para brindar el campo de movimiento necesario dentro del mismo. En su intermedio, dos pestañas semiredondeadas paralelas, que se utilizan para colocar la base de las ruedas y el sistema de dirección, que va en el centro de estas pestañas, luego en la parte central estará colocado el controlador de motores(**L298N**). En la parte posterior del chasis estará colocada una base para fijar la caja reductora del motor DC y dos soportes del eje de tracción trasera, a ambos lados se encuentran los espacios donde se ubican las ruedas traseras.

- Las ruedas son de goma, en número de cuatro, con medidas de 6,6 cm de diámetro y 3,5 cm de grosor.

 - Base Superior: de 26 cm de largo y 19 cm de ancho, en la parte frontal y central de esta base, se ubica el soporte de la cámara **Huskylens**. Seguidamente se ubica un porta baterías de **2x18650** para alimentar la placa microprocesadora **Arduino Mega** que está ubicada en la parte central de esta base, seguidamente de un segundo porta baterías **4x18650**.
#
#
#

## Future Engineers Project
### REXBOT

### Team RoboCRV

Our project involves the manufacture of an automated land vehicle that navigates in an environment marked by colored obstacles, taking different paths based on the characteristics and properties of said obstacles. We use a technology based on **Arduino (C++)**, which has a programming composed of ultrasonic sensors that send and receive pulses at a distance preset in the code, which, upon detecting the proximity of an object, send a signal to the **Arduino** board, which will indicate to the vehicle's movement system where to go, clockwise or counterclockwise, as preset. On the other hand, it also has a vision sensor or **Huskylens (Gravity)** camera to detect colored obstacles, and avoid them when necessary. Depending on the color, it will move to the right or left of the obstacle, as required. 

The code was created on a laptop under **Windows 10 and/or GNU-Linux** operating system. The software used is **Arduino IDE version 1.8.18**, loaded onto an **Arduino Mega** board, through a data transmission cable. This board is supplied by 2 3.7 volt lithium batteries. 

The device also has another battery holder for two 3.7 volt lithium batteries, which feeds the motor controller and provides the energy needed to perform tasks at optimal speed. 

The coding has different routines for: 

- Performing movement, using a servo motor that has the ability to be located in any position within its range of action, and from there, execute a direction. 

- Obstacle detection, using ultrasonic sensors that determine their proximity, sending a signal to the board that will activate the color sensor. 

- Color identification using a color sensor. Depending on the color identified, it will go to the right side if it is Red, to the left if it is Green, and if it is Black, it will define it as a wall and avoid it, clockwise or counterclockwise according to the challenge requirements. 

- Stop when identifying the Magenta color and park in the area designed for that purpose. 

The vehicle is made in an original way using various equipment from many sources to be able to make a robot with a completely unique design in Hardware and Software. 

In this repository you can find: 

- Elements that make up the robot (board, sensors, mobility components and structure) 
- Photos of the robot (robot angles, assembly process and recorded tests) 
- Instructions given to the robot and what it should do (flowcharts and protocodes) 
- Code used and its updates (commits) 
- Wiring diagram made in **Wokwi** (Arduino project simulator) 

This vehicle owes its mobility to a DC motor, connected to two rear wheels for traction, joined through a single axle. A front axle controlled by a servomotor **(micro servo mg90)**, which can turn the axle to the left or right using levers depending on the degrees it has. The DC motor and the servomotor work with **5 volts**. The total weight of the vehicle is **1100 grams**. 

The **ultrasonic sensor** works with **5 volts**, the **visual sensor** (camera) with **3.3 volts**, the **Arduino Mega** board, on the other hand, uses **two 3.7 volt batteries** and the **5V servo motor**. 

3D printing was not used to make the parts for this robot. Various parts were collected for assembly based on our needs.

##### Materials: 
###### Electronic parts: 

- **Arduino Mega** board 
- DC-DC step up booster **XL6009** 5V to 32V 
- Jumpers 
- Network cables 
- 6 3.7 volt lithium batteries 
- 2 battery holders 
- Terminal blocks 
- **Huskylens (Gravity)** camera 
- 2 **Hc-SR04** ultrasonic sensors 


- ###### Traction system: 

- DC motor 
- Gearbox for DC motor 
- Rubber wheel hubs 
- 4 rubber wheels 
- Motor controller (**L298** driver) 
- 1 Servo (Servo motor **Mg995R or Mg996R**) 
- Steel bar for front hub 
- 5mm acrylic sheets and 3mm 
- Industrial Teflon spacers 
- Metal spacers with screw threads 
- Rigid copper wire 
- Nuts and bolts 

###### Mobility management: 

This vehicle owes its mobility to a DC motor, connected to two rear wheels for traction, joined through a single axle, and two front wheels connected to the steering system. 

**Steering system:** Front steering through a servo motor (servo motor **mg995r**) consisting of three pins, positive, negative and data that goes to the **Arduino Mega** board to pin 3, to control its turns by degrees, with a lever system that every time the servo turns between 0 and 180 degrees, left or right, pushes the main axis to the left or right respectively. This steering system has a lever that is fixed from the arm of the servo motor to the axle of one of the wheels, which connects to the other. We use rubber wheels to give it greater grip on the track. 

###### Power management: 

**Rear drive system electrical connection:** consisting of two 3.7 volt batteries connected in series to give 7.4 V, connected in turn to the voltage booster (**XL6009**) to give 10 V sustained to the **L298** driver, at its 12 volt input, to provide greater efficiency to the DC motor. This is connected from its pins n1 and n2 to the **Arduino Mega** board at its pins 8 and 7, to change the energy polarity that defines the rotation of the wheels, whether it moves forward or backward. From the **L298** they are connected to the 5V DC motor outputs. The microcontroller board is powered by two **18650** 3.7 V batteries in series connected to the 12 volt direct current port. 

###### Sensor System: 

The car has two ultrasonic sensors (**HCSR04**) consisting of 4 pins, positive, negative, trigger and echo, which are connected to the **Arduino Mega** board to provide the wall detection function. This works through ultrasonic waves that are emitted and received by it, detecting the proximity of an object, sending a logical signal to the board to execute an action. It also uses a vision sensor or camera, **Huskylens (Gravity)** to detect colored obstacles, which consists of four pins positive, negative, Tx (data transmission) and Rx (data reception) that are connected to the **Arduino Mega** board to pins 10 and 12 (Rx and Tx). 

###### Detailed CAD file: 

- Rexbot lower base (chassis): it has an oval front part in the shape of a bumper to avoid impacts during testing, which affect the ultrasonic sensor that is located in the center of the front area. 

- The chassis is made up of a 5 mm acrylic piece, a material that allows us the hardness to guarantee torsional rigidity and anchoring of parts, and resilience at the time of impacts. Its dimensions are 26 cm long and 19 cm wide. 

- In the chassis we have two symmetrical spaces on each side, to place the wheels, with enough capacity to provide the necessary field of movement within it. In the middle, two parallel semi-rounded tabs, which are used to place the base of the wheels and the steering system, which goes in the center of these tabs, then in the central part the motor controller will be placed (**L298N**). On the back of the chassis there will be a base to fix the DC motor reduction box and two supports for the rear drive axle, on both sides there are the spaces where the rear wheels are located. 

- The wheels are made of rubber, four in number, with measurements of 6.6 cm in diameter and 3.5 cm thick. 

- Upper Base: 26 cm long and 19 cm wide, in the front and central part of this base, the support for the **Huskylens** camera is located. Next is a **2x18650** battery holder to power the **Arduino Mega** microprocessor board which is located in the central part of this base, followed by a second **4x18650** battery holder.

