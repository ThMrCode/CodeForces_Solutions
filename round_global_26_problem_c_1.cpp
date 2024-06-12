#include <iostream>
using namespace std;
 
long long array_a[200005];
long long vect_positive[200005];
long long vect_negative[200005];
long long abs_(long long num) {
	if (num < 0) return num * -1;
	return num;
}
long long max_(long long a, long long b) {
	if (a > b) return a;
	else return b;
}
long long min_(long long a, long long b) {
	if (a < b) return a;
	else return b;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		// Algoritmo Voraz positivo y negativo, solo importa el maximo positivo y el maximo negativo al que se puede llegar en cada posicion, a partir de ell
		vect_positive[0] = abs_(array_a[0]);
		vect_negative[0] = array_a[0];
		for (int i = 1; i < n; i++)
		{
			// Para el positivo i
			vect_positive[i] = max_(abs_(array_a[i] + vect_positive[i - 1]), abs_(array_a[i] + vect_negative[i - 1]));
			vect_negative[i] = min_((array_a[i] + vect_positive[i - 1]), (array_a[i] + vect_negative[i - 1]));
		}
		// Para el ultimo
		cout << vect_positive[n - 1] << endl;
	}
	return 0;
}