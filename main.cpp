
#include <iostream>
#include <vector>

using namespace std;

int DirX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int DirY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool isPossible = false;

void espacio(){
	cout << endl;
}

bool isSafe(int i, int j, int n, vector<vector<int> >& Board) {
	return (i >= 0 && j >= 0 && i < n && j < n && Board[i][j] == 0);
}

void knightTour(vector<vector<int>>& ChessBoard, int N, int x, int y, int visited = 1) {

	ChessBoard[x][y] = visited;

	if (visited == N * N) {

		isPossible = true;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {
				cout << ChessBoard[i][j] - 1 << " ";
			}

			cout << endl;

		}

		return;
	}

	for (int i = 0; i < 8; i++) {

		int newX = x + DirX[i];
		int newY = y + DirY[i];

		if (isSafe(newX, newY, N, ChessBoard) && !ChessBoard[newX][newY]) {
			knightTour(ChessBoard, N, newX, newY, visited + 1);
		}
	}

	ChessBoard[x][y] = 0;
}

int main() {

	int n;
	cin >> n;
	vector<vector<int> > ChessBoard(n, vector<int>(n, 0));
	int N = ChessBoard.size();
	int X = 1;
	int Y = 1;

	knightTour(ChessBoard, N, X - 1, Y - 1);

	if (!isPossible) {
		cout << "NO HAY UNA POSIBLE SOLUCION";
		espacio();
	}

	return 0;
}
