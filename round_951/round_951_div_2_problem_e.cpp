#include <iostream>
#include <vector>
#include <map>
using namespace std;

// POR ALGUNA RAZON VOTA ERROR PONIENDO -1 EN EL INDICE 4618, no se porque, segun lo leo todo esta bien
const int max_size = 100000;
struct Point {
	int x;
	int y;
	int indice = -1;
};
int get_d_1(int x, int y) {
	int c = y + x;
	int x_aux; int y_aux;
	if (c > 0) {
		y_aux = max_size;
		x_aux = c - y_aux;
	}
	else {
		x_aux = -max_size;
		y_aux = c - x_aux;
	}
	int distance = 2*(x - x_aux);
	return distance;
}
int get_d_2(int x, int y) {
	int c = y - x;
	int x_aux; int y_aux;
	if (c > 0) {
		x_aux = -max_size;
		y_aux = c + x_aux;
	}
	else {
		y_aux = -max_size;
		x_aux = y_aux - c;
	}
	int distance = 2 * (x - x_aux);
	return distance;
}
vector<int> solve(map<int, map<int, Point>>& m_1, map<int, map<int, Point>>& m_2, int d) {
	bool val_bool = false;
	int sol_1 = 0; int sol_2 = 0; int sol_3 = 0;
	for (pair<int, map<int, Point>> pair_1 : m_1) {
		if (val_bool) break;
		for (pair<int, Point> pair_2 : pair_1.second) {
			if (m_1[pair_1.first][pair_2.first + d].indice != -1) {
				Point p_1 = pair_2.second;
				Point p_2 = m_1[pair_1.first][pair_2.first + d];
				// Si existe el comun, preguntar los 3 casos
				// Primer caso
				if (m_2[p_1.y - p_1.x][get_d_2(p_1.x, p_1.y) + d].indice != -1) {
					sol_1 = p_1.indice;
					sol_2 = p_2.indice;
					sol_3 = m_2[p_1.y - p_1.x][get_d_2(p_1.x, p_1.y) + d].indice;
					val_bool = true;
					break;
				}
				else if (m_2[p_1.y - p_1.x][get_d_2(p_1.x, p_1.y) - d].indice != -1) {
					sol_1 = p_1.indice;
					sol_2 = p_2.indice;
					sol_3 = m_2[p_1.y - p_1.x][get_d_2(p_1.x, p_1.y) - d].indice;
					val_bool = true;
					break;
				}
				// Primer caso Alternado
				if (m_2[p_2.y - p_2.x][get_d_2(p_2.x, p_2.y) + d].indice != -1) {
					sol_1 = p_1.indice;
					sol_2 = p_2.indice;
					sol_3 = m_2[p_2.y - p_2.x][get_d_2(p_2.x, p_2.y) + d].indice;
					val_bool = true;
					break;
				}
				else if (m_2[p_2.y - p_2.x][get_d_2(p_2.x, p_2.y) - d].indice != -1)
				{
					sol_1 = p_1.indice;
					sol_2 = p_2.indice;
					sol_3 = m_2[p_2.y - p_2.x][get_d_2(p_2.x, p_2.y) - d].indice;
					val_bool = true;
					break;
				}
				// Segundo Caso
				if (d % 4 == 0) {
					if (m_1[p_1.y + p_1.x + d][get_d_1(p_1.x + d * 0.75, p_1.y + d * 0.25)].indice != -1) {
						sol_1 = p_1.indice;
						sol_2 = p_2.indice;
						sol_3 = m_1[p_1.y + p_1.x + d][get_d_1(p_1.x + d * 0.75, p_1.y + d * 0.25)].indice;
						val_bool = true;
						break;

					}
					else if (m_1[p_1.y + p_1.x - d][get_d_1(p_1.x - d * 0.25, p_1.y - d * 0.75)].indice != -1) {
						sol_1 = p_1.indice;
						sol_2 = p_2.indice;
						sol_3 = m_1[p_1.y + p_1.x - d][get_d_1(p_1.x - d * 0.25, p_1.y - d * 0.75)].indice;
						val_bool = true;
						break;
					}
				}
				
			}
		}
	}
	// Segundo Caso Alternado
	for (pair<int, map<int, Point>> pair_1 : m_2) {
		if (val_bool) break;
		for (pair<int, Point> pair_2 : pair_1.second) {
			if (m_2[pair_1.first][pair_2.first + d].indice != -1) {
				Point p_1 = pair_2.second;
				Point p_2 = m_2[pair_1.first][pair_2.first + d];
				// Segundo Caso Alternado
				if (d % 4 == 0) {
					if (m_2[p_1.y - p_1.x - d][get_d_2(p_1.x + d * 0.75, p_1.y - d * 0.25)].indice != -1) {
						sol_1 = p_1.indice;
						sol_2 = p_2.indice;
						sol_3 = m_2[p_1.y - p_1.x - d][get_d_2(p_1.x + d * 0.75, p_1.y - d * 0.25)].indice;
						val_bool = true;
						break;
					}
					else if (m_2[d + p_1.y - p_1.x][get_d_2(p_1.x - d * 0.25, p_1.y + d * 0.75)].indice != -1) {
						sol_1 = p_1.indice;
						sol_2 = p_2.indice;
						sol_3 = m_2[d + p_1.y - p_1.x][get_d_2(p_1.x - d * 0.25, p_1.y + d * 0.75)].indice;
						val_bool = true;
						break;
					}
				}
			}
		}
	}
	vector<int> s = { sol_1, sol_2, sol_3 };
	return s;
}

vector<vector<int>> solutions;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; int d; cin >> d;
		map<int, map<int,Point>> map_1;
		map<int, map<int, Point>> map_2;
		for (int i = 1; i <= n; i++)
		{
			int x; int y; cin >> x; cin >> y;
			Point p;
			p.x = x;
			p.y = y;
			p.indice = i;
			// Primera Key x + y, segunda Key distancia manhatan a la esquina inferior izquierda
			map_1[y + x][get_d_1(p.x, p.y)] = p;
			map_2[y - x][get_d_2(p.x, p.y)] = p;
		}
		solutions.push_back(solve(map_1, map_2, d));
	}
	for (int i = 0; i < solutions.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << solutions[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}