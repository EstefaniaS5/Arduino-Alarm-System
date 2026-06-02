//Lógica
Estado estado = DESARMADO;

bool sistemaArmado = false;
String claveCorrecta = "1234";
String entrada = "";

extern LiquidCrystal_I2C lcd;

void verificarClave() {
  if (entrada == claveCorrecta) {
    if (estado == ALARMA || estado == COUNTDOWN) {
      estado = DESARMADO;
      sistemaArmado = false;
      detenerSpray();
      mostrarMensaje("Clave correcta", "DESARMADO");
    } else {
      sistemaArmado = !sistemaArmado;
      estado = sistemaArmado ? ARMADO : DESARMADO;
      if (sistemaArmado) {
        mostrarMensaje("Clave correcta", "ARMADO");
      } else {
        mostrarMensaje("Clave correcta", "DESARMADO");
      }
    }
  } else {
    if (estado == COUNTDOWN) {
      mostrarMensaje("Clave incorrecta", "Intruso!");
    } else {
      mostrarMensaje("Clave incorrecta", "");
    }
  }

  delay(1000);
  entrada = "";
  mostrarEstado();
}

void mostrarEstado() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema alarma");

  lcd.setCursor(0, 1);
  switch (estado) {
    case DESARMADO:
      lcd.print("DESARMADO");
      break;
    case ARMADO:
      lcd.print("Ingrese clave:");
      break;
    case COUNTDOWN:
      lcd.print("INGRESE CLAVE!");
      break;
    case ALARMA:
      lcd.print("ALARMA ACTIVA!");
      break;
  }
}

void actualizarAlarma() {
  if (estado == ARMADO && detectarMovimiento()) {
    estado = COUNTDOWN;
    mostrarMensaje("Movimiento!", "Alarma!");
  }

  if (estado == COUNTDOWN) {
    if (detectarMovimiento()) {
      estado = ALARMA;
      activarSpray();
      mostrarMensaje("ALARMA!", "INTRUSO!");
    }
  }

  if (estado == ALARMA) {
    activarSpray();
  }
}
