#include <iostream>
using namespace std;
 
int n;
int array_f[300005];
int array_sol[20005];
 
void solve(int i) {
	int f_optimo = n;
	int pot_optimo = -1;
	if ((2 * array_f[n - 1]) >= n) {
		int f_aux = (n / 2);
		f_optimo = f_aux;
		pot_optimo = 0;
	}
	for (int j = 1; j < n; j++)
	{
		if ((2 * (j - array_f[j - 1])) >= j && (2 * (array_f[n - 1] - array_f[j - 1])) >= (n - j)) {
			int f_aux = ((n - 2*j)/ 2);
			if (f_aux < 0) f_aux *= -1;
			if (f_aux < f_optimo) {
				f_optimo = f_aux;
				pot_optimo = j;
			}
		}
	}
	if ((2 * (n - array_f[n - 1])) >= n) {
		int f_aux = (n / 2);
		if (f_aux < f_optimo) {
			f_optimo = f_aux;
			pot_optimo = n;
		}
	}
	array_sol[i] = pot_optimo;
}
int main(){
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n; string cadena; cin >> cadena;
		for (int j = 0; j < n; j++) {
			if (cadena[j] == '1') array_f[j] = 1; else array_f[j] = 0;
		}
		for (int j = 1; j < n; j++) { array_f[j] += array_f[j - 1]; }
		solve(i);
		for (int j = 0; j < n; j++) { array_f[j] = 0; }
	}
	for (int i = 0; i < t; i++)
	{
		cout << array_sol[i] << endl;
	}
}