// ImprimirFotogramas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Start();
void Logica();
void ImprimirScore();
void LimpiarPantalla();

enum MAP_TILES {EMPTY = ' ', WALL = 'ò', BOLA = '+' };
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



int main(){

    RellenarMapa();
    while (run)
    {
        Inputs();
        Logica();
        LimpiarPantalla();
        ImprimirPantalla();
        ImprimirScore();
  
        
    }
}
void Start() {
    
        RellenarMapa();
        
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
        ConsoleScreen[8][0] = MAP_TILES::EMPTY;
        ConsoleScreen[9][0] = MAP_TILES::EMPTY;
        ConsoleScreen[10][0] = MAP_TILES::EMPTY;
        ConsoleScreen[11][0] = MAP_TILES::EMPTY;
        ConsoleScreen[15][0] = MAP_TILES::EMPTY;
        ConsoleScreen[16][0] = MAP_TILES::EMPTY;
        ConsoleScreen[17][0] = MAP_TILES::EMPTY;
        ConsoleScreen[18][0] = MAP_TILES::EMPTY;
        ConsoleScreen[8][CONSOLE_WIDTH-1] = MAP_TILES::EMPTY;
        ConsoleScreen[9][CONSOLE_WIDTH-1] = MAP_TILES::EMPTY;
        ConsoleScreen[10][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
        ConsoleScreen[11][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
        ConsoleScreen[15][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
        ConsoleScreen[16][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
        ConsoleScreen[17][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;
        ConsoleScreen[18][CONSOLE_WIDTH - 1] = MAP_TILES::EMPTY;

        ConsoleScreen[0][58] = MAP_TILES::EMPTY;
        ConsoleScreen[0][59] = MAP_TILES::EMPTY;
        ConsoleScreen[CONSOLE_HEIGHT - 1][58] = MAP_TILES::EMPTY;
        ConsoleScreen[CONSOLE_HEIGHT - 1][59] = MAP_TILES::EMPTY;


        ConsoleScreen[4][12] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[6][15] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[20][14] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[12][17] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[14][17] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[21][8] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[17][14] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[20][100] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[27][17] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[24][56] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[3][70] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[9][69] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[25][96] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[26][13] = MAP_TILES::BOLA;
        map_points++;
        ConsoleScreen[2][110] = MAP_TILES::BOLA;
        map_points++;
    }
    void Inputs() {
        char input_raw = _getch();
        //cin >> input_raw;
        switch (input_raw)
        {
            case 'W':
            case 'w':
            case 'H':
                input = USER_INPUTS::UP;
                break;
            case 'S':
            case 's':
            case 'P':
                input = USER_INPUTS::DOWN;
                break;
            case 'D':
            case 'd':
            case 'M':
                input = USER_INPUTS::RIGHT;
                break;
            case 'A':
            case 'a':
            case 'K':
                input = USER_INPUTS::LEFT;
                break;
            case 'Q':
            case 'q':
            case 27:
                run = false;
                break;
            default:
                input = USER_INPUTS::NONE;
                break;

        }

    }
    void LimpiarPantalla()
    {
        COORD cursorPosition; cursorPosition.X = 0; cursorPosition.Y = 0; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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
        case NONE:
            break;
        }
        if (personaje_x_new < 0) {
            personaje_x_new = CONSOLE_WIDTH - 1;

        }
        else if (personaje_y_new < 0)
        {
            personaje_y_new = CONSOLE_HEIGHT - 1;
        }
        personaje_x_new %= CONSOLE_WIDTH;
        personaje_y_new %= CONSOLE_HEIGHT;
        if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::WALL) {
            personaje_y_new = personaje_y;
            personaje_x_new = personaje_x;
        }
        else if (ConsoleScreen[personaje_y_new][personaje_x_new] == MAP_TILES::BOLA) {
            map_points--;
            personaje_puntos++;
            ConsoleScreen[personaje_y_new][personaje_x_new] = MAP_TILES::EMPTY;
        }
        personaje_y = personaje_y_new;
        personaje_x = personaje_x_new;
        
      
    }
    

    void ImprimirPantalla(){  
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
        cout << "Score: " << personaje_puntos<<" ";
    }
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
