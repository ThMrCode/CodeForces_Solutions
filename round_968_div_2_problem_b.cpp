#include <iostream>
#include <vector>
using namespace std;
 
vector<int> counting_sort(vector<int>& vect, int max) {
	// iniciando desde el 0 hasta max (inclusivo)
	vector<int> vect_counting((max + 1), 0); int n = vect.size();
	vector<int> vect_return(n);
	for (int i = 0; i < n; i++)
	{
		vect_counting[vect[i]]++;
	}
	for (int i = 0; i < max; i++)
	{
		vect_counting[i + 1] += vect_counting[i];
	}
	for (int i = 0; i < n; i++)
	{
		vect_counting[vect[i]]--;
		vect_return[vect_counting[vect[i]]] = vect[i];
	}
	return vect_return;
}
 
int find_max(vector<int>& vect) {
	int max = vect[0];
	int n = vect.size();
	for (int i = 1; i < n; i++)
	{
		if (vect[i] > max) max = vect[i];
	}
	return max;
}
 
void show(vector<int> vect) {
	int n = vect.size();
	for (int i = 0; i < n; i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		// Problema greedy, eliminar pareja de mayor/menor valor, entre 3 2, 2 3, 2 2
		// no hay diferencia porque la operacion unicamente termina eliminando el 2 
		// Similar para turtle, y piggy
		// turtle -> elimina los minimos (seleccionando una pareja que contenga min)
		// piggy -> elimina los maximos (seleccionando una pareja que contenga max)
		// si ordenamos el array de menor a mayor, vemos que si van quitando
		// minimo maximo minimo maximo ... y asi sucesivamente
		// al final solo quedara la mediana (de ser par tocara el de la derecha central)
		// Algoritmo de ordenamiento, radix sort
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int a_max = find_max(a);
		vector<int> a_sort = counting_sort(a, a_max);
		int pot = (a_sort.size() / 2);
		cout << a_sort[pot] << endl;
	}
	return 0;
}