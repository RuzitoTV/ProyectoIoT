#include <Servo.h> // Incluimos la librería Servo

Servo puerta; // Creamos un objeto servo para controlar el servomotor

const int trigPin = 2; // Pin del Trigger del sensor
const int echoPin = 3; // Pin del Echo del sensor

void setup() {
    Serial.begin(9600); // Inicializamos la comunicación serial
    puerta.attach(9); // Conectamos el servomotor al pin 9
    pinMode(trigPin, OUTPUT); // Configuramos el pin Trigger como salida
    pinMode(echoPin, INPUT); // Configuramos el pin Echo como entrada
}

void loop() {
    long duration, distancia;

    // Enviamos un pulso de 10 microsegundos al Trigger
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Leemos el tiempo que tarda el eco en regresar
    duration = pulseIn(echoPin, HIGH);

    // Calculamos la distancia (en cm)
    distancia = duration * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Si la distancia es menor o igual a 20 cm, abrimos la puerta
    if (distancia <= 20) {
        puerta.write(90); // Posicionamos el servo para abrir la puerta (90 grados)
        delay(2000); // Mantenemos la puerta abierta por 2 segundos
        puerta.write(0); // Cerramos la puerta (0 grados)
    }

    delay(500); // Esperamos medio segundo antes de volver a medir
}