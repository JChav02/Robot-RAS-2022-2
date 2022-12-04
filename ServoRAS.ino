// Secuencia de movimiento RAS

/* Librerías */
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define minimo 125
#define maximo 575

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

/* Sintaxis de PWM(num, on, off)
        Parámetros:
            num -> En qué pin se encuentra
            on -> En qué punto del ciclo de 4096 partes se acata el PWM
            off -> En qué punto del ciclo de 4096 partes se ignora el PWM */

/* Relación de servos:
    Tobillo 1 -> 0
    Tobillo 2 -> 1
    Pierna 1 -> 2
    Pierna 2 -> 3
    Cadera -> 4
    Hombro 1 -> 5
    Hombro 2 -> 6
    Antebrazo -> 7 */

void resetServos(){
    for(int servoActual = 0; servoActual < 8; servoActual++){
        servos.setPWM(servoActual, 0, minimo);
    }
    Serial.println("Servos reseteados.");
    Serial.println("");
}

int anguloAPulso(int angulo){
    int pulso = map(angulo, 0, 180, minimo, maximo);
    return pulso;
}

void transformar(){
    servos.setPWM(2, 0, anguloAPulso(90));
    delay(2000);
    servos.setPWM(2, 0, anguloAPulso(120));
    delay(2000);
    servos.setPWM(2, 0, anguloAPulso(180));
    delay(2000);
    servos.setPWM(1, 0, anguloAPulso(110));
    delay(2000);
    servos.setPWM(1, 0, anguloAPulso(90));
    delay(2000);
    servos.setPWM(1, 0, anguloAPulso(-30));
    delay(2000);
}

void setup(){
    Serial.begin(9600);
    servoRas.begin();
    servoRas.setPWMFreq(60);
    yield();
}

void loop(){
    resetServos();
    delay(5000);
    transformar();
}