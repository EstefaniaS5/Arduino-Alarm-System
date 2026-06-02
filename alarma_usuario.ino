//Main
#include <Servo.h>

enum Estado { 
  DESARMADO, ARMADO, COUNTDOWN, ALARMA 
};

void setup() {
  iniciarLCD();
  iniciarTeclado();
  iniciarSensor();
  iniciarServo();
  iniciarIndicador();
  mostrarPantallaInicio();
}

void loop() {
  leerTeclado();
  actualizarAlarma();
  actualizarIndicador();
}
