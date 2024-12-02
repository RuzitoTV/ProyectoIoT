#include <Servo.h>

Servo myServo;

void setup() {
   myServo.attach(2); 
   Serial.begin(9600);
}

void loop() {
   abrirPuerta();
   delay(5000); 
   cerrarPuerta();
   delay(5000); 
}

void abrirPuerta() {
   Serial.println("Abriendo puerta...");
   int angulo = 90; 
   do {
      angulo = angulo - 1; 
      myServo.write(angulo);
      delay(50); 
   } while (angulo > 0);
   Serial.println("Puerta abierta.");
}

void cerrarPuerta() {
   Serial.println("Cerrando puerta...");
   int angulo = 0; 
   do {
      angulo = angulo + 1; 
      myServo.write(angulo);
      delay(50); 
   } while (angulo < 90);
   Serial.println("Puerta cerrada.");
}
