#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--)
	{
		string cadena; cin >> cadena;
		bool value = false; int pot_change;
		for (int i = 1; i < cadena.length(); i++)
		{
			if (cadena[i - 1] != cadena[i]) {
				value = true; pot_change = i;
				break;
			}
		}
		if (value) {
			cout << "YES" << endl;
			char cambio = cadena[pot_change];
			cadena[pot_change] = cadena[pot_change-1];
			cadena[pot_change - 1] = cambio;
			cout << cadena << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}