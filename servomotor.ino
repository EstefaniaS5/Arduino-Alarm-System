//Servo motor para spray (bomba manual)
#include <Servo.h>

const int pinServo = 5;
const int posSegura = 0;
const int posSpray = 90;

Servo sprayServo;
bool sprayActivo = false;

void iniciarServo() {
  sprayServo.attach(pinServo);
  sprayServo.write(posSegura);
  sprayActivo = false;
}

void activarSpray() {
  sprayServo.write(posSpray);
  sprayActivo = true;
}

void detenerSpray() {
  sprayServo.write(posSegura);
  sprayActivo = false;
}
