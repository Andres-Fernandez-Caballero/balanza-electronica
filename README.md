# balanza-electronica
balanza digital construida usando la plataforma arduio
<div align="center">
  <img src="https://github.com/Andres-Fernandez-Caballero/balanza-electronica/blob/main/documentation/render.png" width="350" title="hover text">
  <img src="https://github.com/Andres-Fernandez-Caballero/balanza-electronica/blob/main/documentation/Diagrama%20electrico%20Banalza.png" width="350" alt="accessibility text">
</div>

## Materiales necesarios
- 1x Arduino uno
- 1x telcado matrizial 4x4
- 1x modulo convertidor I2C PCF8574
- 1x buzzer pasivo
- 1x modulo HX711
- 1x celda de carga cualquier peso
- 3x Display digital 7 segmentos HT1621

## instricciones 
  - Conecte todos los componentes como figuran en la imagen del diagrama electrico
  - Descarga e instala el software de PlatformIO desde su página oficial.
  - Clona el repositorio de GitHub del proyecto en tu ordenador.
  - Abre el proyecto en PlatformIO desde la interfaz de usuario o desde la línea de comandos.
  - Configura las opciones de compilación y subida a la placa según las especificaciones de tu hardware de Arduino.
  - Carga el código del proyecto en tu placa Arduino y comprueba su correcto funcionamiento.

## Uso
Una vez cargado el codigo en el arduino bastara con colocar algun elemento sobre el modulo de carga y por medio del teclado numerico indicarle su peso, al oprimir el '#' se podran agregar decimales
si se oprime la tecla 'A' se reiniciara el valor del precio por peso
### ⚠️ IMPORTANTE 
  - la balanza esta calculara para peso en gramos
  - la calibracion del modulo de carga puede dar errores de medicion en algunos casos (esta agregado a la lista de pendientes )

## Contribucion
 puedes contribuir con el proyecto de las siguientes maneras
   - crea un fork del proyecto
   - crea una nueva rama y envía una solicitud de extracción (pull request) para que se revisen tus cambios.

## Lisencia
 decido compartir este proyecto con todo aquiel que quiera aprender arduino y programacion en general

