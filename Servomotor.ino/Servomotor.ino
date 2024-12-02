#include <Servo.h>

Servo myServo;

void setup() {
   myServo.attach(2); // Pin donde está conectado el servomotor
   Serial.begin(9600);
}

void loop() {
   abrirPuerta();
   delay(5000); // Espera 5 segundos antes de cerrar la puerta
   cerrarPuerta();
   delay(5000); // Espera 5 segundos antes de volver a iniciar el ciclo
}

void abrirPuerta() {
   Serial.println("Abriendo puerta...");
   int angulo = 90; // Comienza en la posición cerrada (90 grados)
   do {
      angulo = angulo - 1; // Disminuye el ángulo para abrir
      myServo.write(angulo);
      delay(50); // Control de velocidad
   } while (angulo > 0);
   Serial.println("Puerta abierta.");
}

void cerrarPuerta() {
   Serial.println("Cerrando puerta...");
   int angulo = 0; // Comienza en la posición abierta (0 grados)
   do {
      angulo = angulo + 1; // Incrementa el ángulo para cerrar
      myServo.write(angulo);
      delay(50); // Control de velocidad
   } while (angulo < 90);
   Serial.println("Puerta cerrada.");
}
