
#include <iostream>
#include <vector>

using namespace std;

void espacio() {
	cout << endl;
}

bool esSeguro(int x, int y, vector<vector<int>> tablero) {
	return (x >= 0 && x < tablero.size() && y >= 0 && y < tablero.size() && tablero[x][y] == 0);
}

void knightTour(int x, int y, vector<vector<int>>& tablero, bool& esPosible, int visitado = 1) {

	vector<int> movimientoX = { 2, 1, -1, -2, -2, -1, 1, 2 };
	vector<int> movimientoY = { 1, 2, 2, 1, -1, -2, -2, -1 };

	tablero[x][y] = visitado;

	if (visitado == tablero.size() * tablero.size()) {

		esPosible = true;

		for (int i = 0; i < tablero.size(); i++) {

			for (int j = 0; j < tablero.size(); j++) {
				cout << tablero[i][j] - 1 << " ";
			}

			espacio();
		}

		return;
	}

	if (esPosible != true) {

		for (int i = 0; i < 8; i++) {

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

int main() {

	vector<vector <int>> tablero;
	bool esPosible;
	int n;

	espacio();

	cout << "Input :" << endl;
	cout << "N = ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> auxiliar(n, 0);
		tablero.push_back(auxiliar);
	}

	espacio();

	cout << "Output : " << endl;

	esPosible = false;
	knightTour(0, 0, tablero, esPosible);

	if (esPosible == false) {
		cout << "NO HAY UNA POSIBLE SOLUCION!";
		espacio();
	}

	espacio();

	return 0;
}
