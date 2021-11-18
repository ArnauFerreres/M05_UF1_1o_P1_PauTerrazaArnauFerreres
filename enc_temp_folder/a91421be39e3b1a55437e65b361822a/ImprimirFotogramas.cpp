// ImprimirFotogramas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119


void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Start();
void Logica();
void ImprimirScore();

enum MAP_TILES {EMPTY = ' ', WALL = '#', POINT = 'Ñ' };
enum USER_INPUTS {NONE, UP, DOWN, RIGHT, LEFT, QUIT};

MAP_TILES ConsoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
int map_points = 0;
char personaje = 'O';
int personaje_x = 59;
int personaje_puntos = 0;
int personaje_y = 14;
USER_INPUTS input = USER_INPUTS::NONE;
enum MAP_TITLES mapa[29][119];
bool run = true;
int score = 0;


int main(){

    RellenarMapa();
    ImprimirPantalla();
    ImprimirScore();
    while (run)
    {
        Inputs();
        Logica();
        ImprimirPantalla();
        ImprimirScore();
        
    }
}
void Start() {
    
        RellenarMapa();
        ImprimirPantalla();
        
    }

    void RellenarMapa(){


        for (int i = 0; i < CONSOLE_HEIGHT; i++)
        {
            for (int j = 0; j < CONSOLE_WIDTH; j++)
            {
                if (i == CONSOLE_HEIGHT - 1 || i == 0 || j == CONSOLE_WIDTH - 1 || j == 0)
                {
                    ConsoleScreen[i][j] = MAP_TILES::WALL;
                }
                else {
                    ConsoleScreen[i][j] = MAP_TILES::EMPTY;
                }
            } 
        }
        ConsoleScreen[2][0] = MAP_TILES::EMPTY;
        ConsoleScreen[3][0] = MAP_TILES::EMPTY;
        ConsoleScreen[2][CONSOLE_WIDTH-1] = MAP_TILES::EMPTY;
        ConsoleScreen[3][CONSOLE_WIDTH-1] = MAP_TILES::EMPTY;
        ConsoleScreen[4][12] = MAP_TILES::POINT;
        map_points++;
        ConsoleScreen[4][15] = MAP_TILES::POINT;
        map_points++;
        ConsoleScreen[4][14] = MAP_TILES::POINT;
        map_points++;
        ConsoleScreen[4][17] = MAP_TILES::POINT;
        map_points++;
    }
    void Inputs() {
        char input_raw;
        cin >> input_raw;
        switch (input_raw)
        {
            case 'W':
            case 'w':
                input = USER_INPUTS::UP;
                break;
            case 'S':
            case 's':
                input = USER_INPUTS::DOWN;
                break;
            case 'D':
            case 'd':
                input = USER_INPUTS::RIGHT;
                break;
            case 'A':
            case 'a':
                input = USER_INPUTS::LEFT;
                break;
            case 'Q':
            case 'q':
                run = false;
                break;
            default:
                break;

        }

    }

    void Logica() {
        int personaje_y_new = personaje_y;
        int personaje_x_new = personaje_x;
        switch (input)
        {
        case UP:
            personaje_y_new--;
            break;
        case DOWN:
            personaje_y_new++;
            break;
        case RIGHT:
            personaje_x_new++;
            break;
        case LEFT:
            personaje_x_new--;
            break;
        case QUIT:
            run = false;
            break;
        }
        if (personaje_x_new < 0) {
            personaje_x_new = CONSOLE_WIDTH - 1;
        }
        personaje_x_new %= CONSOLE_WIDTH;
        if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
            personaje_y_new = personaje_y;
            personaje_x_new = personaje_x;
        }
        else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::POINT) {
            map_points--;
            personaje_puntos++;
            ConsoleScreen[personaje_y_new][personaje_x_new] = MAP_TILES::EMPTY;
        }
        personaje_y = personaje_y_new;
        personaje_x = personaje_x_new;
        
        /*if (mapa[personaje_y][personaje_x] == MAP_TILES::POINT) {
            mapa[personaje_y][personaje_x] = MAP_TILES::EMPTY;
            score++;
        }*/
    }
    

    void ImprimirPantalla(){

        system("CLS");

    for (int i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (int j = 0; j < CONSOLE_WIDTH; j++)
        {
            if (personaje_x == j && personaje_y == i)
            {
                cout << personaje;
            }
            else {
                cout << (char)ConsoleScreen[i][j];

            }
        }
        cout << endl;
    }
    
    
}
    void ImprimirScore() {
        cout << "Score: " << personaje_puntos;
    }
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln