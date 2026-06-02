//Sensor PIR
const int pinPIR = 4;

bool movimientoDetectado = false;

void iniciarSensor() {
  pinMode(pinPIR, INPUT);
}

bool detectarMovimiento() {
  return digitalRead(pinPIR) == HIGH;
}