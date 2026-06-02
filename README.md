# Arduino Alarm System

Sistema de alarma para el hogar desarrollado con Arduino Uno, integrando sensores, actuadores y control mediante contraseña.

## Tecnologías y componentes utilizados

### Hardware

* Arduino Uno
* Sensor de movimiento PIR
* Teclado matricial 4x4
* Pantalla LCD 16x2 I2C
* Servomotor indicador
* LED rojo
* Resistencias y cableado de conexión

### Software

* Arduino IDE
* C++

## Descripción

El proyecto consiste en un sistema de alarma doméstica que utiliza un sensor PIR para detectar movimiento y un teclado matricial para ingresar una contraseña de acceso.

Cuando el sistema se encuentra armado y detecta movimiento, inicia una cuenta regresiva para que el usuario ingrese la contraseña. Si no se ingresa correctamente dentro del tiempo establecido, la alarma se activa ejecutando una respuesta física mediante un servomotor.

Adicionalmente, un segundo servomotor y un LED indican visualmente el estado actual del sistema.

## Componentes y pines

| Componente       | Pines              |
| ---------------- | ------------------ |
| Keypad filas     | 6, 7, 8, 9         |
| Keypad columnas  | 10, 11, 12, 13     |
| Sensor PIR       | 4                  |
| Servo indicador  | 3                  |
| LED rojo         | 2                  |
| LCD I2C          | A4 (SDA), A5 (SCL) |

## Funcionalidades

* Ingreso de contraseña mediante teclado matricial
* Activación y desactivación de la alarma
* Detección de movimiento mediante sensor PIR
* Cuenta regresiva de seguridad
* Activación automática de alarma
* Indicadores visuales mediante LED
* Indicadores mecánicos mediante servomotor
* Visualización de mensajes en pantalla LCD

## Estados del sistema

### DESARMADO

El sistema permanece inactivo esperando la activación mediante contraseña.

### ARMADO

La alarma se encuentra activa y monitorea constantemente el sensor de movimiento.

### COUNTDOWN

Cuando se detecta movimiento, se inicia una cuenta regresiva de 10 segundos para permitir el ingreso de la contraseña.

### ALARMA

Si no se ingresa la contraseña correctamente, el sistema activa la alarma y ejecuta la respuesta física programada.

## Contraseña

* Contraseña predeterminada: `1234`
* Confirmación mediante la tecla `#`
* La tecla `*` permite borrar la entrada actual

## Librerías utilizadas

Instalar desde el Library Manager de Arduino IDE:

* Keypad
* LiquidCrystal I2C
* Servo

## Cómo ejecutar el proyecto

1. Abrir Arduino IDE.
2. Instalar las librerías necesarias.
3. Abrir el archivo `alarma_usuario.ino`.
4. Seleccionar la placa Arduino Uno.
5. Seleccionar el puerto correspondiente.
6. Compilar y cargar el programa al Arduino.

## Lo que aprendí

Durante este proyecto aprendí a:

* Programar sistemas embebidos con Arduino
* Trabajar con sensores y actuadores
* Implementar máquinas de estados
* Utilizar comunicación I2C
* Integrar hardware y software en un mismo sistema
* Diseñar lógica de control basada en eventos
* Trabajar en equipo en un proyecto de ingeniería

## Proyecto académico

Este proyecto fue desarrollado como proyecto final de la materia de Electrónica Básica + Lab de la Universidad San Francisco de Quito (USFQ).

## Capturas de pantalla

<img src="https://github.com/user-attachments/assets/9576934a-3e45-4729-8cb9-f7b1f01161e2" width="200">
<img src="https://github.com/user-attachments/assets/ea258df8-fbc2-4ab5-a9ab-9c5e0d87973b" width="200">


## Autores

* Estefanía Solórzano
* Nicolás Naranjo

