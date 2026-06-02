//LCD I2C
#include <LiquidCrystal_I2C.h>

extern bool sistemaArmado;
extern String entrada;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void iniciarLCD() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
}

void mostrarPantallaInicio() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema alarma");
  lcd.setCursor(0, 1);
  lcd.print("DESARMADO");
}

void mostrarClaveOculta() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ingrese clave:");

  lcd.setCursor(0, 1);
  for (int i = 0; i < entrada.length(); i++) {
    lcd.print('*');
  }
}

void mostrarMensaje(String linea1, String linea2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);
}
