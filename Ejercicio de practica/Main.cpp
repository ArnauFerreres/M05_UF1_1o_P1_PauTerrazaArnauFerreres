#include <iostream> //libreria de la consola
using namespace std;

int main() 
{
	// << std::end1 = /n (salto de linea)
	//char letra_A;
	//char letra_B;
	//char letra_C;
	//std::cin >> letra_A;
	//std::cin >> letra_B;
	//std::cin >> letra_C;
	//std::cout << "has escrito" << letra_A << std::endl;
	//std::cout << "has escrito" << letra_B << std::endl;
	//std::cout << "has escrito" << letra_C << std::endl;
	/*int numero = 10;
	std::cin >> numero;
	cout << "has escrito" << numero << endl;
	std::cout << "has escrito" << numero << std::endl;
	system("CLS");*/
	/*float numero_A = 2;
	float numero_B = 3;
	float numero_C = 4;
	float respuesta = numero_C * numero_A * (numero_B - numero_C) / numero_B;
	cout << respuesta;*/
	int A = 0;
	int B = 0;
	cout << "Escribe el primer valor:" << endl;
	cin >> A;
	cout << "Escribe el primer valor:" << endl;
	cin >> B;
	cout << "Primer valor: " << A << endl;
	cout << "Segundo valor: " << B << endl;
	int resultado;
	char operacion;
	cout << "Que operacion queires hacer? (* o /)" << endl;
	cin >> operacion;
	if (operacion == '*')
	{
		resultado = A * B;
	}
	else if (operacion == '/')
	{
		resultado = A / B;
	}
	cout << "Resultado: " << resultado << endl;

}