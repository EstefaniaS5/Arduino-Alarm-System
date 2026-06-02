//Segundo servo motor para indicar estado del sistema
#include <Servo.h>

extern Estado estado;

Servo servoIndicador;

const int pinServoIndicador = 3;   
const int pinLedRojoAnodo = 2;     //LED rojo (+)
const int pinLedRojoCatodo = 3;    //LED rojo (-)
const int pinLedAzulAnodo = 0;     //LED azul (+)
const int pinLedAzulCatodo = 1;    //LED azul (-)

const int posReposo = 0;           //desarmado
const int posActivo = 90;          //armado - countdown - alarma


void iniciarIndicador() {
  servoIndicador.attach(pinServoIndicador);
  servoIndicador.write(posReposo);

  pinMode(pinLedRojoAnodo, OUTPUT);
  pinMode(pinLedRojoCatodo, OUTPUT);
  pinMode(pinLedAzulAnodo, OUTPUT);
  pinMode(pinLedAzulCatodo, OUTPUT);
  digitalWrite(pinLedRojoAnodo, LOW);
  digitalWrite(pinLedRojoCatodo, LOW);
  digitalWrite(pinLedAzulAnodo, LOW);
  digitalWrite(pinLedAzulCatodo, LOW);
}

void actualizarIndicador() {
  //Desarmado - apagado
  if (estado == DESARMADO) {
    servoIndicador.write(posReposo);
    digitalWrite(pinLedRojoAnodo, LOW);
    digitalWrite(pinLedRojoCatodo, LOW);
    digitalWrite(pinLedAzulAnodo, HIGH);
    digitalWrite(pinLedAzulCatodo, LOW);
  }

  //Armado
  else if (estado == ARMADO) {
    servoIndicador.write(posActivo);
    digitalWrite(pinLedRojoAnodo, LOW);
    digitalWrite(pinLedRojoCatodo, LOW);
    digitalWrite(pinLedAzulAnodo, HIGH);
    digitalWrite(pinLedAzulCatodo, LOW);
  }

  //Countdown - dectecto movimiento 
  else if (estado == COUNTDOWN) {
    servoIndicador.write(posActivo);
    digitalWrite(pinLedRojoAnodo, LOW);
    digitalWrite(pinLedRojoCatodo, LOW);
    digitalWrite(pinLedAzulAnodo, HIGH);
    digitalWrite(pinLedAzulCatodo, LOW);
  }

  //Alarma para intruso
  else if (estado == ALARMA) {
    servoIndicador.write(posActivo);
    digitalWrite(pinLedRojoAnodo, HIGH);
    digitalWrite(pinLedRojoCatodo, LOW);
    digitalWrite(pinLedAzulAnodo, LOW);
    digitalWrite(pinLedAzulCatodo, LOW);
  }
}

