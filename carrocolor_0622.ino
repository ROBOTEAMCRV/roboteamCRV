#include <Adafruit_TCS34725.h>
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);

#include <NewPing.h> // Biblioteca para el sensor ultrasónico
#include <Servo.h> // Biblioteca para el servo
Servo myservo; // Crea un objeto servo para controlar el servo


#define ENA 5
#define IN1 8
#define IN2 7

int Echo = A14;
int Trig = A15;
int rightDistance = 0, leftDistance = 0, middleDistance = 0;



void forward(){

  digitalWrite(ENA,HIGH); //enable L298n A channel
  digitalWrite(IN1,HIGH); //set IN1 hight level
  digitalWrite(IN2,LOW);  //set IN2 low level
  Serial.print("Forward- ");//send message to serial monitor
  Serial.println(middleDistance);
}

void back(){
  digitalWrite(ENA,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  Serial.print("B ");}


void left(){
 myservo.write (150);
 forward();
 Serial.println("left");
}



void stop(){
  digitalWrite(ENA,LOW);
  digitalWrite(IN1,LOW); //set IN1 hight level
  digitalWrite(IN2,LOW);  //set IN2 low level
}


int getDistance() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    return (int)pulseIn(Echo, HIGH) / 58;
}


void setup() {
  Serial.begin(9450);//open serial and set the baudrate
  myservo.attach(3);
  pinMode(IN1,OUTPUT);//before useing io pin, pin mode must be set first
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  tcs.begin();
  //pin sentido
  pinMode(40, OUTPUT);
  pinMode(41, INPUT);
}
/*int rojo = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
int verde = pulseIn(salidaTCS, LOW);  // obtiene duracion de pulso de salida del senso
int azul = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
*/
void loop(){
myservo.write(104);
forward();
middleDistance = getDistance();

if (middleDistance <= 40 & middleDistance > 1) {
//back(); //freno
//delay(104);
stop();
delay(1040);



  //color
  float red,green,blue;
  tcs.getRGB(&red,&green,&blue);
  int R = int(red);
  int G = int(green);
  int B = int(blue);
  String color = "";

Serial.print("R: ");Serial.print(int(red));
Serial.print("   G: ");Serial.print(int(green));
Serial.print("   B: ");Serial.print(int(blue));
Serial.println();

 if ((R > 150) && (R > G) && (R > B)){
  color = "Red";
  Serial.println("-------------red -----------");
 
  myservo.write (150);
 forward();
 Serial.println("left");
 
  delay(500);
  back();//freno
  delay(104);

   myservo.write (55);
   back();; //enderezar
  delay(500);
  stop();
  back();//freno
  delay(500);

    myservo.write (55);
    back();//regresar al medio
  delay(500);
  stop();
  back();//freno
  delay(104);

  myservo.write (150);
 forward();
 Serial.println("left");
  delay(500);
  back();//freno
  delay(104);
  myservo.write(80);
 }

         
 else if ((G > 150) && (G > 150) && (G > B)){
  color = "Green";
  Serial.println("-------------verde -----------");
   myservo.write (55);
   forward();
  delay(500);
  stop();
  back();//freno
  delay(104);


  myservo.write (150);
 forward();
 Serial.println("left");
 
  delay(500);
  stop();
  back();
  delay(500);
  forward();

  myservo.write (150);
 forward();
 Serial.println("left");
 
  delay(500);
  back();//freno
  delay(104);

   myservo.write (55);
   back();//enderezar
  delay(500);
  stop();
  back();//freno
  delay(104);
myservo.write(104);
}

else if ((300 > R) && (300 > G ) && (300 > B)){
    color = "Black";
    Serial.println("-------------negro -----------");
    digitalRead(41);
    Serial.println(digitalRead(41));//0 (conectado) = horario
    
    if (digitalRead(41)){
    stop();
     myservo.write (55);
     back();
    delay(500);
    stop();
 
    myservo.write (150);
 forward();
 Serial.println("left");
 
    delay(500);
    myservo.write(80);
    forward();
    }
    
     myservo.write (150);  
     back();
    delay(500);
    stop();
     myservo.write (55);  
    forward();
    delay(500);
    myservo.write(104);
    forward();
    
   Serial.println("pared");
    }

   
//estacionar
 else if ((R & B > G) && (R & B > 104)) {
  color = "Magenta";
  Serial.println("MAGENTA");
  back();
  delay(800);
  
   myservo.write (150);
   forward();
  delay(2000);
  
 myservo.write (80);
 back();

 
  delay(2000);
  stop();
  forward();
  delay(500);
 }
 

}
}
 
}
