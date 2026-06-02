//Teclado
#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;

char teclas[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {6, 7, 8, 9};
byte pinesColumnas[COLUMNAS] = {11, 10, 12, 13};

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

void iniciarTeclado() {
}

void leerTeclado() {
  char tecla = teclado.getKey();

  if (tecla == NO_KEY) {
    return;
  }

  if (tecla >= '0' && tecla <= '9') {
    if (entrada.length() < 4) {
      entrada += tecla;
      mostrarClaveOculta();
    }
  }

  else if (tecla == '*') {
    entrada = "";
    mostrarMensaje("Clave borrada", "");
    delay(700);
    mostrarEstado();
  }

  else if (tecla == '#') {
    verificarClave();
  }
}
