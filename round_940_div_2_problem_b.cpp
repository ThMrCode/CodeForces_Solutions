#include <iostream>
#include <cmath>
using namespace std;
 
int array_n[10000];
int array_k[10000];
int array_solve[10000];
void solve(int n, int k, int pot) {
	int array_counting[32] = { 0 };
	int array_aux[32] = { 0 };
	int max_bin = log2(k);
	for (int i = 0; i <= max_bin; i++)
	{
		int binary_digit = ((k % ((int)pow(2, i + 1))) / ((int)pow(2, i)));
		array_counting[i] = binary_digit;
		array_aux[i] = binary_digit;
	}
	for (int i = 1; i <= max_bin; i++)
	{
		array_counting[i] += array_counting[i - 1];
	}
	for (int i = max_bin; i > 0; i--)
	{
		if (array_counting[i] < i) {
			array_aux[i] = 0;
			for (int j = (i - 1); j >= 0; j--)
			{
				array_aux[j] = 1;
			}
			break;
		}
	}
	int sol = 0;
	for (int i = 0; i <= max_bin; i++)
	{
		sol += array_aux[i] * pow(2, i);
	}
	array_n[pot] = n;
	array_k[pot] = k;
	array_solve[pot] = sol;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; int k; cin >> n; cin >> k;
		solve(n, k, i);
	}
	for (int i = 0; i < t; i++)
	{
		if (array_n[i] == 1) cout << array_k[i] << endl;
		else {
			cout << array_solve[i] << " " << (array_k[i] - array_solve[i]) << " ";
			for (int j = 2; j < array_n[i]; j++)
			{
				cout << 0 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}