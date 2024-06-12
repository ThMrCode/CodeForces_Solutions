#include <iostream>
#include <vector>
using namespace std;
 
long long array_a[200005];
vector<int> vect_sol;
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		for (int i = 1; i < n; i++)
		{
			array_a[i] += array_a[i-1];
		}
		int cant_i = 0;
		if (array_a[0] == 0) cant_i++;
		int candidato_ant = array_a[0];
		for (int i = 1; i < n; i++)
		{
			// Existe elemento que sea la mitad de la suma?, de existir seria el maximo
			// si en uno cumple en el siguiente solo estan de candidatos este mismo u el nuevo
			// El nuevo candidato ant debe ser el mayor
			long long sum = array_a[i];
			long long candidato_new = (array_a[i] - array_a[i - 1]);
			if (2 * candidato_ant == sum) cant_i++;
			else if(2 * candidato_new == sum) cant_i++; 
			if (candidato_new > candidato_ant) candidato_ant = candidato_new;
		}
		vect_sol.push_back(cant_i);
	}
	for (int i = 0; i < vect_sol.size(); i++)
	{
		cout << vect_sol[i] << endl;
	}
	return 0;
}