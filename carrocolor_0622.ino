#include <Adafruit_TCS34725.h>  // Biblioteca para el sensor de color y lo inicialisamos
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
#include <NewPing.h> // Biblioteca para el sensor ultrasónico
#include <Servo.h> // Biblioteca para el servo
Servo myservo; // Crea un objeto servo para controlar el servo
//Definimos pines para manejar motor DC de traccion
#define ENA 5
#define IN1 8
#define IN2 7
//Definimos pines para ultrasonido
#define Echo A14
#define Trig A15
int middleDistance = 0;
int p=3, i=1;

void forward(){ //encendemos el motor hacia adelante
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  Serial.print("Fw- "); //mostramos proceso y distancia del ultrasonido
  Serial.println(middleDistance);



}

void adelante(){
  if(i%20 == 0){
    myservo.write(60); //centro
    Serial.println("-----------acomodo-----------");
    }
  else if(0){
    myservo.write(60); //centro
    Serial.println("-----------65-----------");
    }
    else{
    myservo.write(97); //centro
    }

  delay(50);
  i++;
  }

void back(){ //encendemos el motor hacia atras
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  Serial.print("B ");
}

void left(){
 myservo.write (50);
 Serial.print("L ");
}

void right(){
 myservo.write (130);
 Serial.print("R ");
}

void stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

int getDistance() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    return (int)pulseIn(Echo, HIGH) / 58;
}

int color(){
  float red,green,blue;
  tcs.getRGB(&red,&green,&blue);
  int R = int(red);
  int G = int(green);
  int B = int(blue);
  

  Serial.print("R: ");Serial.print(R); //imprimimos que recibimos del sensor
  Serial.print("   G: ");Serial.print(G);
  Serial.print("   B: ");Serial.println(B);

  if ((R > 110) && (R > G) && (R > B)){
    Serial.println("-----------red -----------");
    return(1);
  } else if ((G > 100) && (G > R) && (G > B)){
    Serial.println("-----------verde -----------");
    return(2);
  } else if ((120 > R) && (120 > G ) && (120 > B)){
    Serial.println("-----------negro -----------");
    return(3);
  } else if ((R & B > G) && (R & B > 120)) {//estacionar
    Serial.println("-----------MAGENTA-----------");
    return(4);
 }
}


void setup() {
  Serial.begin(9600); //open serial and set the baudrate
  myservo.attach(3);
  pinMode(IN1,OUTPUT); //before useing io pin, pin mode must be set first
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  tcs.begin();
  //pin sentido
  pinMode(40, OUTPUT);
  pinMode(41, INPUT);
  digitalWrite(40, HIGH);
}

void loop(){
  if(p!=0){ //inicializamos direccion
    left();
    delay(100);
    myservo.write(97);
    p=0;
    Serial.println("-----------inicio-----------");
    Serial.println(digitalRead(41));
  }

  forward();
  adelante();
  middleDistance = getDistance();

 if (middleDistance <= 40 & middleDistance > 1) {

  stop();
  delay(1000);
//color();
switch(color()){
//switch(3){
  case 1:
    //rojo - obstaculo

    back();
    delay(200);
        
    left();
    forward();
    delay(200);

    right();
    forward();
    delay(200);

    myservo.write(70); //centro
    forward();
    delay(500);

    right();
    forward();
    delay(200);

    left();
    forward();
    delay(200);


  break;
  case 2:
    //verde - obstaculo
    
    back();
    delay(200);

    right();
    forward();
    delay(200);

    left();
    forward();
    delay(200);

    myservo.write(97); //centro
    forward();
    delay(500);

    left();
    forward();
    delay(200);

    right();
    forward();
    delay(200);

    myservo.write (88);
  break;
  case 3:
    //negro - pared
    //41 = 0 (conectado) = horario
    if (digitalRead(41)){

      right();
      back();
      delay(500);//tiempo maniobra atras
      stop();

      left();
      forward();
      delay(500);//tiempo maniobra adelante

      myservo.write(97); //centro
      forward();

    } else{

      left();
      back();
      delay(500);//tiempo maniobra atras
      stop();

      right();
      forward();
      delay(500);//tiempo maniobra adelante

      myservo.write(60); //centro

    }

  break;
  case 4:
    //magenta - estacionarse
    back();
    delay(700);
    
    myservo.write (125);
    forward();
    delay(2000);
    
    myservo.write (75);
    back();
  
    delay(2000);
    stop();
    forward();
    delay(500);
  break;
}//switch

}//distancia
}//loop
