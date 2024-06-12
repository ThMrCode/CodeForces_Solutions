#include <iostream>
#include <string>
using namespace std;
 
int array_a[55] = { 0 };
int main() {
	int t; cin >> t;
	while (t--) {
		// si son numeros grandex xxx + yyy su suma de cada digito msiempre sumara un 1 al siguiente es decir 1000 + ((x + y + 1)%10) * 100 + ((x + y + 1)%10) * 10 + ((x + y)%10) 
		// Su primer digito se debe poder formar con (x1 + y1)%10, no se puede para 9
		// el segundo digito se debe poder formar con ((x2 + y2 + 1)%10) se puede para todos
		// exepto el 0 xq 5 +5 +1 %10 es 1, solo el ultimo puede ser 0
		// Todo digito se puede formar con ((x2 + y2 + 1)%10) para numeros grandes
		// porque con (x1 + y1)%10 se puede formar todo digito exepto 8
		// La suma (x + y + 1) // 10 siempre es 1, lo que pasa al siguiente, por lo que cada digito tiene la regla de formacion 
		// Ambos numeros grandes deben tener la misma cantidad de digitos, si uno es 9xx y el otro 0yy puede que no se cumpla
		// para 1001 no se cumple
		// es necesario segundo digito distinto de cero ? 5555 5555
		// Minimo numero grande que cumple es de la forma 111111s0
		long long x; cin >> x;
		string s = to_string(x);
		long long cota = 0;
		long long p = 1;
		for (int i = 1; i < s.size(); i++)
		{
			p *= 10;
			cota += p;
		}
		
		if (s[0] == '1' && s[s.size() - 1] != '9' && x >= cota) {
			bool value_find = true;
			for (int i = 1; i < (s.size() - 1); i++)
			{
				if (s[i] == '0') {
					value_find = false;
					break;
				}
			}
			if (value_find) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}