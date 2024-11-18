#include <Servo.h>
Servo myServo;
int rojo = 16;
int amarillo = 5;
int TRIG = 14;
int ECO = 12;
int BUZZER = 4;
int c = 261;  // Nota base
int d = 294;  // Nota un poco más alta
int e = 329;  // Nota aún más alta
int tiempo;
int distancia;

void setup() {
   pinMode(amarillo, OUTPUT);
   pinMode(rojo, OUTPUT);
   pinMode(TRIG, OUTPUT);
   pinMode(ECO, INPUT);
   pinMode(BUZZER, OUTPUT); // Configuramos el buzzer como salida

   myServo.attach(2);
   onOffLeds();
   Serial.begin(9600);
}

void loop() {
   leerDistancia();
   if (distancia < 10) {
      onOffLeds();
      abrirPuerta();
      delay(5000);
      cerrarPuerta();
      delay(2000); 
   }
}

void leerDistancia() {
   digitalWrite(TRIG, HIGH);
   delay(1);
   digitalWrite(TRIG, LOW);
   tiempo = pulseIn(ECO, HIGH);
   distancia = tiempo / 20.2;  
}

void onOffLeds() {
   digitalWrite(amarillo, HIGH);
   digitalWrite(rojo, HIGH);
   delay(100);
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, LOW);
   delay(100);
   digitalWrite(amarillo, HIGH);
   digitalWrite(rojo, HIGH);
   delay(100);
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, LOW);
}

void cerrarPuerta() {
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, HIGH);
   int angulo = 0;
   do {
      angulo = angulo + 1;
      myServo.write(angulo);
      delay(50);
   } while (angulo < 90);
   digitalWrite(amarillo, LOW);
   sonarBuzzerConRitmoCerrado();
   digitalWrite(rojo, LOW);
}

void abrirPuerta() {
   digitalWrite(amarillo, HIGH);
   digitalWrite(rojo, LOW);
   int angulo = 90;
   sonarBuzzerConRitmo(); 
   do {
      angulo = angulo - 1;
      myServo.write(angulo);
      delay(50);
   } while (angulo > 0);  
   digitalWrite(amarillo, LOW);
   digitalWrite(rojo, LOW);
}

void sonarBuzzerConRitmo() {
   for (int i = 0; i < 2; i++) { // Repetimos el ritmo 10 veces
      digitalWrite(BUZZER, HIGH); // Encendido del buzzer
      delay(200);                 // encendido por 100ms
      digitalWrite(BUZZER, LOW);  // Apagamos el buzzer
      delay(200);                 // Esperamos 100ms
   }
   delay(300); // Pausa larga para separar el ritmo
}

void sonarBuzzerConRitmoCerrado() {
   for (int i = 0; i < 1; i++) { // Repetimos el ritmo 10 veces
      digitalWrite(BUZZER, HIGH); // Encendido del buzzer
      delay(1000);                 // encendido por 100ms
      digitalWrite(BUZZER, LOW);  // Apagamos el buzzer
      delay(200);                 // Esperamos 100ms
   }
   delay(300); // Pausa larga para separar el ritmo
}
