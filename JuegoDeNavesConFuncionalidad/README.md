Juego de Nave Espacial

Este es un juego simple de consola escrito en C++ donde controlas una nave espacial para evitar enemigos. A medida que pasa el tiempo, el nivel de dificultad aumenta al generar enemigos más rápido. El juego termina cuando un enemigo toca la nave.

Requisitos

Compilador C++ compatible con C++98 o versiones superiores.

Sistema operativo compatible con el uso de la biblioteca <conio.h> (por ejemplo, Windows).

Cómo jugar

Usa la tecla a para mover la nave hacia la izquierda.
Usa la tecla d para mover la nave hacia la derecha.
Presiona la tecla x para salir del juego.
El objetivo es evitar que los enemigos (E) toquen tu nave (A). El juego se vuelve más desafiante a medida que aumenta la dificultad.

Controles

a: Mover la nave hacia la izquierda.
d: Mover la nave hacia la derecha.
x: Salir del juego.

Funcionalidades principales

Nave espacial: Representada por el carácter A, controlada por el jugador.
Enemigos: Representados por el carácter E, aparecen en la parte superior de la pantalla y descienden hacia la nave.
Dificultad dinámica: El nivel de dificultad aumenta cada dos minutos simulados, reduciendo el intervalo de aparición de los enemigos.
Colisión: El juego termina si un enemigo toca la nave.

Compilación y ejecución

Compila el programa usando un compilador compatible, por ejemplo:
g++ -o juego_nave juego_nave.cpp

Ejecuta el programa:
./juego_nave

Notas adicionales

El archivo requiere la biblioteca <conio.h>, que no está disponible de forma nativa en algunos sistemas operativos como macOS o Linux. Si usas uno de estos sistemas, se necesita una implementación alternativa o ajustes al código.
El rendimiento y la fluidez del juego dependen del hardware y la velocidad del procesador.

Personalización

Puedes modificar las constantes anchoPantalla y altoPantalla para cambiar el tamaño de la pantalla.
Cambia ciclosPorSegundo para ajustar la velocidad del juego.

Licencia

Este proyecto se distribuye bajo la Licencia MIT. Puedes usarlo, modificarlo y distribuirlo libremente, siempre y cuando incluyas este aviso de licencia.