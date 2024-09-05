#include <iostream>
#include <cmath>
using namespace std;
 
int n_primos = 8;
int array_primos[] = { 2,3,5,7,11,13,17,19 };
int array_k[55];
int array_k_aux[55];
int mcm(int s) {
	// sacar mcm del array_k;
	int mcm_ = 1;
	for (int j = 0; j < n_primos; j++)
	{
		bool value_primo = false;
		do
		{
			value_primo = false;
			for (int i = 0; i < s; i++)
			{
				if (array_k[i] % array_primos[j] == 0) {
					array_k[i] = array_k[i] / array_primos[j];
					value_primo = true;
				}
			}
			if (value_primo) mcm_ *= array_primos[j];
		} while (value_primo);
	}
	return mcm_;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> array_k[i];
			array_k_aux[i] = array_k[i];
			sum += 1.0 / (double)array_k[i];
		}
		if (sum < 0.9999999) {
			int mc = mcm(n);
			for (int i = 0; i < n; i++)
			{
				cout << (mc / array_k_aux[i]) << " ";
			}
			cout << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}