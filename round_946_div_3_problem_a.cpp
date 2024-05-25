#include <iostream>
using namespace std;
 
int tope_sup(double n) {
	if (n == (int)n) return n;
	else return n + 1;
	return 0;
}
int main() {
	int t; cin >> t;
	while (t--) {
		//import la cantidad de 2x2 5x3 cben 2 de 2por2, las de 1 no se ven afectados, residual y sumar
		int x; cin >> x; int y; cin >> y;
		int screen = tope_sup((double)y / 2.0);
		int res_1 = (screen * 15) - y * 4;
		int res_2 = x - res_1;
		if (res_2 > 0) {
			screen += tope_sup((double)res_2 / 15.0);
		}
		cout << screen << endl;
	}
	return 0;
}