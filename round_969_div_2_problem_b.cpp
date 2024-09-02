#include <iostream>
#include <string>
using namespace std;
 
 
int main() {
	int t; cin >> t;
	while (t--) {
		// Solo importa el mayor,
		// Hacia adelante, si alguno llega a superar al mayor primero debe llegar a ser igual al mayor y en ese momento el mayor original y este nuevo seguiran la misma trayectoria y mismos valores 
		// Hacia atras, nunca dejara de ser el mayor pues si llega a bajar hasta encontrarse con otro numero y luego manda a bajar mas, el otro numero igual, tambien bajara, el mayor original y este nuevo seguiran la misma trayectoria y mismos valores 
		int n; cin >> n; int m; cin >> m;
		int mayor = 0;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			if (a > mayor) mayor = a;
		}
		string solve;
		for (int i = 0; i < m; i++)
		{
			// Operaciones
			char c; cin >> c; int l; cin >> l; int r; cin >> r;
			if (l <= mayor && mayor <= r) {
				if (c == '+') mayor++;
				else mayor--;
			}
			solve += to_string(mayor) + " ";
		}
		cout << solve << endl;
	}
	return 0;
}