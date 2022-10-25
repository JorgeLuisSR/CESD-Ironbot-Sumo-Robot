# CESD-Ironbot-Sumo-Robot
#---------------------
#deprecated
---Repositorio del robot de pelea sumo para el ironbot 2022.

Explicacion del robot:
  Componentes: 
    * 4 Motores de corriente directa para las 2 orugas de movimiento
    * 2 Servomotores para la pala de ataque 
    * 1 Modulo de antena Bluetooth HC-05 de arduino
  Funcionamiento general:
    * El robot es controlado por telefono via Bluetooth con la aplicacion de control de arduino
    * Los servomotores inician a 90 grados y levantan la pala de ataque
    * Los motores dc controlan las orugas permitiendo que avance, retroceda, rote (invirtiendo la direccion de los motores de la direccion hacia la que se rota)

Especificaciones:
  Estructura:
    AT+config: sirve para la configuracion del modulo bluetooth de arduino con los comandos AT+ NAME(nombre) - PSWD(pin) -
UART(velocidad) - Role(Eslave:0-Master:1) - CMODE(conexion especifica o aleatoria) - BIND(direccion si CMODE=0) - ORGL[reset to default values] - RESET [exit at mode]
Tomando '?' como consulta y '=<value>' como una asigación [excepto para comandos funcionales]
    Robot-code: tiene el codigo de manejo de los comando Bluetooth y el movimiento de todos los componentes
