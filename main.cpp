
#include <iostream>
#include <vector>

using namespace std;

vector<int> DirX = { 2, 1, -1, -2, -2, -1, 1, 2 };
vector<int> DirY = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool isPossible = false;

void espacio(){
	cout << endl;
}

bool isSafe(int i, int j, int n, vector<vector<int>>& Board) {
	return (i >= 0 && j >= 0 && i < n && j < n && Board[i][j] == 0);
}

void knightTour(vector<vector<int>>& ChessBoard, int n, int x, int y, int visited = 1) {

	ChessBoard[x][y] = visited;

	if (visited == n * n) {

		isPossible = true;

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {
				cout << ChessBoard[i][j] - 1 << " ";
			}

			cout << endl;

		}

		return;
	}

	if (isPossible != true){
		for (int i = 0; i < 8; i++) {

		int newX = x + DirX[i];
		int newY = y + DirY[i];

			if (isSafe(newX, newY, n, ChessBoard) && !ChessBoard[newX][newY]) {
				knightTour(ChessBoard, n, newX, newY, visited + 1);
			}
		}

		ChessBoard[x][y] = 0;
		return;
	}

}

int main() {

	vector<vector <int>> tablero;
	int n;

	espacio();

	cout << "Input :" << endl;
	cout << "N = ";
	cin >> n;

	for (int i = 0; i<n; i++){
		vector<int> auxiliar(n,0);
		tablero.push_back(auxiliar);
	}

	espacio();

	cout << "Output : " << endl;

	knightTour(tablero, tablero.size(), 0, 0);

	if (isPossible == false) {
		cout << "NO HAY UNA POSIBLE SOLUCION!";
		espacio();
	}

	espacio();

	return 0;
}
