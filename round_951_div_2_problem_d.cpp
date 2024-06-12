#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
 
string s; int n; int k;
bool verify() {
	bool val_return = true;
	//verify_1
	for (int i = 1; i < k; i++)
	{
		if (s[i] != s[0]) {
			val_return = false;
			break;
		}
	}
	//verify_1
	for (int i = 0; i < (n-k); i++)
	{
		if (s[i] == s[i + k]) {
			val_return = false;
			break;
		}
	}
	return val_return;
}
void change_s(int pot_p) {
	string s_aux = s;
	int aux_counter = 0;
	for (int i = (pot_p); i < n; i++)
	{
		s_aux[aux_counter] = s[i];
		aux_counter++;
	}
	for (int i = (pot_p - 1); i >= 0; i--)
	{
		s_aux[aux_counter] = s[i];
		aux_counter++;
	}
	s = s_aux;
}
bool case_1(int& pot, int counter_1, int& counter_2) {
	bool val_return = false;
	for (int i = 0; i < (n - counter_1); i++)
	{
		if (s[i] == s[n - 1]) {
			if (pot == -1) pot = i;
			counter_2++;
			if ((counter_2 + counter_1 == k)) {
				//Verificacion extra 
				bool value_extra = s[i] != s[i + 1];
				if (value_extra == false) {
					if (i + k < n) {
						value_extra = true;
						for (int j = 1; j <= k; j++)
						{
							if (s[i + j] != s[i]) {
								value_extra = false;
								break;
							}
						}
					}
				}
				if (value_extra) {
					val_return = true;
					break;
				}
			}
		}
		else {
			pot = -1;
			counter_2 = 0;
		}
	}
	return val_return;
}
bool case_2(int& pot, int counter_1, int& counter_2) {
	counter_2 = 1;
	bool val_return = false;
	for (int i = 1; i < (n - counter_1); i++)
	{
		if (s[i] == s[i - 1]) {
			if (pot == -1) pot = i-1;
			counter_2++;
			if (counter_2 == 2 * k && s[i] != s[i + 1]) {
				val_return = true;
				counter_2 = (counter_2 / 2);
				break;
			}
		}
		else {
			pot = -1;
			counter_2 = 1;
		}
	}
	return val_return;
}
int change() {
	int p_return = -1;
	int counter_1 = 1;
	for (int i = (n - 2); i >= n - k; i--)
	{
		if (s[i] == s[n - 1]) counter_1++;
		else break;
	}
	if (counter_1 != k) {
		// 1 Caso (encontrar subcadena complete)
		int pot = -1; int counter_2 = 0;
		bool value_case = case_1(pot, counter_1, counter_2);
		// 2 Caso (encontrar doble par) grupo dolbe alternado
		if (value_case == false) {
			value_case = case_2(pot, counter_1, counter_2);
		}
		// Hacer cambio
		if (value_case) {
			change_s(pot + counter_2);
			p_return = (pot + counter_2);
		}
	}
	else {
		int pot = -1; int counter_2 = 0;
		// 2 Caso (encontrar doble par) grupo dolbe alternado
		bool value_case = case_2(pot, counter_1, counter_2);
		if (value_case) {
			change_s(pot + counter_2);
			p_return = (pot + counter_2);
		}
		else {
			p_return = n;
		}
	}
	return p_return;
}
 
int main() {
	vector<int> vect_sol;
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> k; cin >> s;
		// Es Greedy, revisar los ultimos digitos buscar una conexion (si hay mas de una sera que es imposible)
		int p = -1;
		if (n == k) {
			if (verify()) p = n;
		}
		else {
			// Verificar
			p = change();
			if (p != -1) {
				if (verify() == false) p = -1;
			}
		}
		vect_sol.push_back((int)p);
	}
	for (int i = 0; i < vect_sol.size(); i++)
	{
		cout << vect_sol[i] << endl;
	}
	return 0;
}