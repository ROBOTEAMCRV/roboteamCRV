# Documentación
___

## Materiales: 

### Parte electrónica:

  Placa **Arduino Mega**

  Elevador DC-DC step up **XL6009** 5V a 32V 

  Jumpers

  Cables de red

  6 Pilas de litio de 3.7 voltios

  2 porta pilas

  Borneras

  Cámara **HuskyLens (Gravity)**

  2 Sensores ultrasónicos **Hc-SR04**
  

### Sistema de tracción:

  Motor DC

  Caja de engranajes para motor DC

  Bujes para ruedas de goma

  4 ruedas de goma

  Controlador de motores (driver **L298**)

  1 Servo (Servo motor **Mg995R** o **Mg996R**)

  Barra de acero para buje de parte delantera

  Laminas de Acrilico de 5 mm y 3 mm

  Espaciadores de teflón industrial

  Espaciadores de metal con rosca para tornillos

  Cable de cobre rígido

  Tuercas y tornillos
  
___
## Gestión de movilidad:

Este vehículo debe su movilidad a un motor DC, conectado a dos ruedas traseras para la tracción, unidas a través de un solo eje, y dos ruedas delanteras conectadas al sistema de dirección.

Sistema de dirección: dirección delantera a través de un servomotor (servomotor **mg995r**) que consta de tres pines, positivo, negativo y datos que va a la placa **Arduino Mega** al pin 3, para controlar sus giros mediante grados, con un sistema de palanca que cada vez que gira el servo entre 0 y 180 grados, a la izquierda o derecha, empuja el eje principal hacia la izquierda o hacia la derecha respectivamente.  

Este sistema de dirección cuenta con una palanca que va fija desde el brazo del servomotor hasta el eje de una de las ruedas, que conecta con la otra. Utilizamos ruedas de goma para que tenga mayor adherencia a la pista.
___

## Gestión de energía:

Conexión eléctrica del sistema de tracción trasera: constituido por dos pilas de 3.7 voltios conectadas en serie para dar 7.4 V, conectadas a su vez al elevador de voltaje (**XL6009**) para dar 10 V sostenidos al driver **L298**, en su entrada de 12 voltios, para proporcionar mayor eficiencia al motor DC. Este va conectado de sus pines n1 y n2 a la placa **Arduino Mega** en sus pines 8 y 7, para cambiar polaridad de energía que defina el giro de las ruedas, si avanza o retrocede. Del **L298** van conectados a las salidas del motor DC de 5V.

La placa microcontroladora está alimentada mediante dos baterías **18650** 3.7 V en serie conectadas al puerto de 12 voltios corriente directa.

___

## Sistema de Sensores:

El carro cuenta con dos sensores ultrasónicos (**HCSR04**) que consta de 4 pines, positivo, negativo, trigger y echo, que van conectados a la placa **Arduino Mega** para dar la función de detección de paredes. Este funciona a través de ondas ultrasónicas que son emitidas y recibidas por el mismo, detectando la proximidad de un objeto, enviando una señal lógica a la placa para ejecutar una acción. Además utiliza un sensor de visión o cámara, **HuskyLens (Gravity)** para detectar los obstáculos de colores, que consta de cuatro pines positivo, negativo, Tx (transmisión de datos) y Rx (recepción de datos) que van conectados a la placa **Arduino Mega** a los pines 10 y 12(Rx y Tx).

___

## Detallado del archivo CAD:

Base Inferior de Rexbot (chasis): tiene la parte frontal ovalada en forma de parachoques para evitar golpes durante las pruebas, que afecten al sensor ultrasónico que está ubicado en el centro de la zona frontal. 

El chasis está constituido por una pieza de acrílico de 5 mm, material que nos permite la dureza para  garantizar la rigidez torsional y el anclaje de piezas, y la resiliencia al momento de impactos. Sus dimensiones son de 26cm de largo y 19cm de Ancho.

En el chasis tenemos dos espacios simétricos a cada lado, para colocar las ruedas, con la capacidad suficiente para brindar el campo de movimiento necesario dentro del mismo. En su intermedio, dos pestañas semiredondeadas paralelas, que se utilizan para colocar la base de las ruedas y el sistema de dirección, que va en el centro de estas pestañas, luego en la parte central estará colocado el controlador de motores(L298N). En la parte posterior del chasis estará colocada una base para fijar la caja reductora del motor DC y dos soportes del eje de tracción trasera, a ambos lados se encuentran los espacios donde se ubican las ruedas traseras.

Las ruedas son de goma, en número de cuatro, con medidas de 6,6 cm de diámetro y 3,5 cm de grosor.

Base Superior: de 26 cm de largo y 19 cm de ancho, en la parte frontal y central de esta base, se ubica el soporte de la cámara Huskylens. Seguidamente se ubica un porta baterías de 2x**18650** para alimentar la placa microprocesadora **Arduino Mega** que está ubicada en la parte central de esta base, seguidamente de un segundo porta baterías 4x**18650**.

