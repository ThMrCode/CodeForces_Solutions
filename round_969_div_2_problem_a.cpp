#include <iostream>
using namespace std;
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		// todos los consecutivos de a 3 son pesi entre si, siempre cuando sea impar par impar
		// notar que si existe un k (!=1) tal que ->a // k, b // k, c // k, y a < b < c
		// Entonces a + k <= b, pero b es a + 1 si es consecutivo entonces no es posible
		// a + k <= c, pero c es  + 2 si es consecutivo y si k es distinto de 2 no es posible, k es distinto de 2 debido a que hay 2 impares y un unico par
		int l; cin >> l; int r; cin >> r;
		// RPTA Cantidad de operaciones = cantidad de impares entre 2
		if (r % 2 == 0) r--;
		if (l % 2 == 0) l++;
		// 2 3 4 5 6 7 8 9 10 se transforma a
		// 3 4 5 6 7 8 9, en esta forma ya se puede deducir impares = 1 + ((r - l) / 2)
		int impares = 1 + ((r - l) / 2);
		cout << (int)(impares / 2) << endl;
	}
	return 0;
}