#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
// Extras
void show(vector<long long> v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void show(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
long long pow_long(long long b, int a) {
	long long iter = 1;
	for (int i = 0; i < a; i++)
	{
		iter *= b;
	}
	return iter;
}
 
// Iniciales
vector<long long> vect_sol;
vector<long long> get_primos(long long k_ref) {
	vector<long long> primos;
	long long  k_aux = k_ref;
	long long sq = sqrt(k_aux);
	for (int i = 2; i <= sq; i++)
	{
		while ((k_aux % i == 0)) {
			primos.push_back(i);
			k_aux = k_aux / i;
		}
	}
	if (k_aux != 1) primos.push_back(k_aux);
	return primos;
}
vector<long long> vect_primos;
vector<int> vect_num;
void traduct_primos(long long k_) {
	vector<long long> v = get_primos(k_);
	vect_primos = { v[0] };
	vect_num = { 1 };
	int pot = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == vect_primos[pot]) vect_num[pot]++;
		else {
			vect_primos.push_back(v[i]);
			vect_num.push_back(1);
			pot++;
		}
	}
}
 
// Main, requiere vect_primos y vect_num bien definidos
long long max_solution;
long long max_1; long long max_2; long long max_3;
long long valor(long long x, long long y, long long z) {
	return ((1 + max_1 - x) * (1 + max_2 - y) * (1 + max_3 - z));
}
void recursion_2(int pt_2, long long fact_1, long long fact_2, vector<int> vect_resto_2, vector<int>& vect_resto_1) {
	// Hallar el segundo vect_resto (que implica hallar el segundo factor)
	if (pt_2 < vect_resto_1.size()) {
		recursion_2(pt_2 + 1, fact_1, fact_2, vect_resto_2, vect_resto_1);
		long long iter = 1;
		for (int i = 1; i <= vect_resto_1[pt_2]; i++)
		{
			iter *= vect_primos[pt_2];
			vect_resto_2[pt_2] -= i;
			recursion_2(pt_2 + 1, fact_1,(fact_2*iter), vect_resto_2, vect_resto_1);
			vect_resto_2[pt_2] += i;
		}
	}
	else {
		// Ya tenemos el vect_resto_2 que implica tener los dos primeros factores, el ultimo queda determinado, comparar con el max anterior
		if (fact_2 <= max_2) {
			// Calcular fact_3
			long long fact_3 = 1;
			for (int i = 0; i < vect_primos.size(); i++)
			{
				fact_3 *= pow_long(vect_primos[i], vect_resto_2[i]);
			}
			if (fact_3 <= max_3) {
				// Comparar
				long long val = valor(fact_1,fact_2,fact_3);
				if (val > max_solution) max_solution = val;
			}
		}
	}
 
}
void recursion_1(int pt, long long fact_1, vector<int> vect_resto) {
	if (pt < vect_num.size()) {
		recursion_1(pt + 1, fact_1, vect_resto);
		long long iter = 1;
		for (int i = 1; i <= vect_num[pt]; i++)
		{
			iter *= vect_primos[pt];
			vect_resto[pt] -= i;
			recursion_1(pt + 1, (fact_1*iter), vect_resto);
			vect_resto[pt] += i;
		}
	}
	else {
		// Ya tenemos el vect resto que es = vect_num - vect_factor
		// Mandamos recursion 2 solo si fact_1 cumple condicion
		if (fact_1 <= max_1) recursion_2(0, fact_1, 1, vect_resto, vect_resto);
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> max_1; cin >> max_2; cin >> max_3; long long k; cin >> k;
		// Vector solo factores necesarios
		if (k != 1) {
			traduct_primos(k);
			max_solution = 0;
			recursion_1(0, 1, vect_num);
		}
		else max_solution = valor(1,1,1);
		vect_sol.push_back(max_solution);
	}
	for (int i = 0; i < vect_sol.size(); i++)
	{
		cout << vect_sol[i] << endl;
	}
	return 0;
}