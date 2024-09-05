#include <iostream>
using namespace std;
 
long long array_a[200005];
long long vect_positive[200005];
long long vect_negative[200005];
long long abs_(long long num) {
	if (num < 0) return num * -1;
	return num;
}
bool posi(long long num) {
	// Posi inclusivo
	if (num >= 0) return true;
	return false;
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
		// Algoritmo Voraz positivo y negativo, solo importa el maximo positivo y el maximo negativo al que se puede llegar en cada posicion, a partir de el
		// Llegar al maximo hasta posicion i
		vect_positive[0] = abs_(array_a[0]);
		// Llegar al minimo hasta posicion i
		vect_negative[0] = array_a[0];
		long long counter_positive = 1;
		long long counter_negative = 1;
		if (posi(array_a[0])) {
			counter_positive *= 2;
			counter_negative *= 2;
		}
		for (int i = 1; i < n; i++){
			long long counter_positive_aux = counter_positive;
			long long counter_negative_aux = counter_negative;
			// Conteo hasta el positive iesimo
			long long p_p = array_a[i] + vect_positive[i - 1];
			long long p_n = array_a[i] + vect_negative[i - 1];
			vect_positive[i] = max_(abs_(p_p), abs_(p_n));
			if (abs_(p_p) > abs_(p_n)) {
				if (posi(p_p)) counter_positive = (counter_positive_aux * 2);
				else counter_positive = counter_positive_aux;
			}
			else if (abs_(p_n) > abs_(p_p)) {
				if (posi(p_n)) counter_positive = (counter_negative_aux * 2);
				else counter_positive = counter_negative_aux;
			}
			// Descontar cuando vect_positive[i - 1] == vect_negative[i - 1]
			else if (abs_(p_n) == abs_(p_p)) {
				long long sum = 0;
				if (posi(p_p)) sum += (counter_positive_aux * 2);
				else sum += counter_positive_aux;
				if (posi(p_n)) sum += (counter_negative_aux * 2);
				else sum += counter_negative_aux;
				counter_positive = sum;
				if (vect_positive[i - 1] == vect_negative[i - 1]) counter_positive = counter_positive / 2;
			}
			// Conteo hasta el negative iesimo
			long long n_p = array_a[i] + vect_positive[i - 1];
			long long n_n = array_a[i] + vect_negative[i - 1];
			vect_negative[i] = min_(n_p, n_n);
			if (n_p < n_n) {
				if (posi(n_p)) counter_negative = (counter_positive_aux * 2);
				else counter_negative = counter_positive_aux;
			}
			else if (n_n < n_p) {
				if (posi(n_n)) counter_negative = (counter_negative_aux * 2);
				else counter_negative = counter_negative_aux;
			}
			else if (n_p == n_n) {
				long long sum = 0;
				if (posi(n_p)) sum += (counter_positive_aux * 2);
				else sum += counter_positive_aux;
				if (posi(n_n)) sum += (counter_negative_aux * 2);
				else sum += counter_negative_aux;
				counter_negative = sum;
				if (vect_positive[i - 1] == vect_negative[i - 1]) counter_negative = counter_negative / 2;
			}
			if (counter_positive >= 998244353) counter_positive = counter_positive % 998244353;
			if (counter_negative >= 998244353) counter_negative = counter_negative % 998244353;
		}
		cout << counter_positive << endl;
	}
	return 0;
}