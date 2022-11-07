//Programa que: Implementa un algoritmo solución para el Problema: "El Recorrido del Caballero", mediante BackTracking.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Domingo 06 de Noviembre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>
#include <iomanip>

//Ajuste a estandar.
using namespace std;

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
	cout << endl;
}

//Función que imprime el el orden de recorrido en el tablero, recibe como parámetro el tablero en forma de vector de vectores de enteros (una matriz), y no tiene valor de retorno.
void imprimirTablero(vector<vector<int>> tablero){ //Complejidad Computacional: O(n^2), siendo n cada valor en el tablero.

	//Complejidad Computacional: O(n^2), siendo n cada valor en el tablero.
	for (int i = 0; i < tablero.size(); i++) { //Complejidad Computacional: O(n), siendo n cada valor en cada fila del tablero.

		for (int j = 0; j < tablero[i].size(); j++) { //Complejidad Computacional: O(n), siendo n cada valor en cada columna de la fila del tablero.
			cout << " " << setw(2) << tablero[i][j] - 1 << " ";
		}

		espacio();
	}
}

//Función que verifica si un movimiento es seguro/valido dentro del tablero, recibe un entero x, un entero y el tablero en forma de vector de vectores de enteros, retorna un valor booleano.
bool esSeguro(int x, int y, vector<vector<int>> tablero) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
	return (x >= 0 && x < tablero.size() && y >= 0 && y < tablero.size() && tablero[x][y] == 0);
}

void knightTour(int x, int y, vector<vector<int>>& tablero, bool& esPosible, int visitado = 1) { //Complejidad Computacional: O(8^(n^2)) [8, debido a que es la cantidad de movimientos posibles que se pueden realizar], siendo n la cantidad de filas o columnas en el tablero [Forzosamente: cuadrado].

	vector<int> movimientoX = { 2, 1, -1, -2, -2, -1, 1, 2 };
	vector<int> movimientoY = { 1, 2, 2, 1, -1, -2, -2, -1 };

	tablero[x][y] = visitado;

	if (visitado == tablero.size() * tablero.size()) {

		esPosible = true;
		imprimirTablero(tablero); //Complejidad Computacional: O(n^2), siendo n cada valor en el tablero.
		return;
	}

	if (esPosible != true) {

		for (int i = 0; i < 8; i++) { //Complejidad Computacional: O(8), considerando cada una lo posibles movimientos que se pueden realizar. 

			int nuevaX = x + movimientoX[i];
			int nuevaY = y + movimientoY[i];

			if (esSeguro(nuevaX, nuevaY, tablero) && !tablero[nuevaX][nuevaY]) {
				knightTour(nuevaX, nuevaY, tablero, esPosible, visitado + 1);
			}
		}

		tablero[x][y] = 0;
		return;
	}
}

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main() { //Complejidad Computacional: O(1).

	vector<vector <int>> tablero;
	bool esPosible;
	int n;

	espacio();

	cout << "Input :" << endl;
	cout << "N = ";
	cin >> n;

	for (int i = 0; i < n; i++) { //Complejidad Computacional: O(n).
		vector<int> auxiliar(n, 0);
		tablero.push_back(auxiliar);
	}

	espacio();

	cout << "Output : " << endl;

	esPosible = false;
	knightTour(0, 0, tablero, esPosible); //Complejidad Computacional: O(8^(n^2)) [8, debido a que es la cantidad de movimientos posibles que se pueden realizar], siendo n la cantidad de filas o columnas en el tablero [Forzosamente: cuadrado].

	if (esPosible == false) {
		cout << "NO HAY UNA POSIBLE SOLUCION!";
		espacio();
	}

	espacio();

	return 0;
}