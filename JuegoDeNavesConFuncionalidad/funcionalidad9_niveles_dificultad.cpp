#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

const int anchoPantalla = 20;
const int altoPantalla = 20;
int posicionX = anchoPantalla / 2;
int posicionY = altoPantalla - 2;
int nivelDificultad = 1;
int intervaloEnemigos = 20;
vector<int> enemigosX, enemigosY;

// Variables para simular el tiempo
int contadorTiempo = 0;
int contadorEnemigos = 0;
const int ciclosPorSegundo = 10; // Ciclos por segundo (ajustado manualmente)
const int ciclosParaDosMinutos = ciclosPorSegundo * 120; // 2 minutos simulados

void dibujarPantalla() {
    system("cls");
    cout << "Nivel de Dificultad: " << nivelDificultad << endl;
    for (int i = 0; i < altoPantalla; i++) {
        for (int j = 0; j < anchoPantalla; j++) {
            if (i == posicionY && j == posicionX) {
                cout << "A"; // Nave
            } else {
                bool esEnemigo = false;
                for (int e = 0; e < enemigosX.size(); e++) {
                    if (i == enemigosY[e] && j == enemigosX[e]) {
                        cout << "E";
                        esEnemigo = true;
                    }
                }
                if (!esEnemigo) cout << ".";
            }
        }
        cout << endl;
    }
}

void moverNave(char tecla) {
    switch(tecla) {
        case 'a':
            if (posicionX > 0) posicionX--;
            break;
        case 'd':
            if (posicionX < anchoPantalla - 1) posicionX++;
            break;
    }
}

void generarEnemigo() {
    enemigosX.push_back(rand() % anchoPantalla);
    enemigosY.push_back(0);
}

void moverEnemigos() {
    for (int e = 0; e < enemigosX.size(); e++) {
        enemigosY[e]++;
        if (enemigosY[e] >= altoPantalla) {
            enemigosX.erase(enemigosX.begin() + e);
            enemigosY.erase(enemigosY.begin() + e);
            e--; // Ajustar el índice tras la eliminación
        }
        // Verificar colisión con la nave
        else if (enemigosY[e] == posicionY && enemigosX[e] == posicionX) {
            cout << "\nGAME OVER! Los enemigos te han tocado.\n";
            exit(0);
        }
    }
}

void aumentarDificultad() {
    if (contadorTiempo >= ciclosParaDosMinutos) { // Incrementar dificultad cada 2 minutos simulados
        nivelDificultad++;
        intervaloEnemigos -= 2;
        if (intervaloEnemigos < 5) intervaloEnemigos = 5; // Límite mínimo para la dificultad
        contadorTiempo = 0; // Reiniciar el contador de tiempo
        cout << "\nDificultad aumentada: Nivel " << nivelDificultad << "\n";
    }
}

int main() {
    srand(time(0));
    char tecla;
    int contador = 0;
    do {
        // Captura de entrada del teclado
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == 'x') break;
            moverNave(tecla);
        }

        // Generar enemigos a intervalos definidos
        if (contadorEnemigos >= intervaloEnemigos) {
            generarEnemigo();
            contadorEnemigos = 0;
        }

        // Mover enemigos
        moverEnemigos();

        // Aumentar dificultad si es necesario
        aumentarDificultad();

        // Dibujar pantalla
        dibujarPantalla();

        // Contadores
        contadorEnemigos++;
        contadorTiempo++;

        // Ciclos por segundo ajustados manualmente
        for (volatile int i = 0; i < 1000000; i++); // Breve retraso manual
    } while(true);

    return 0;
}
