#include <iostream>
using namespace std;
 
int array_n[100005];
int array_aux[100005];
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_n[i];
		}
		for (int i = 0; i < (n-1); i++)
		{
			array_aux[i] = max(array_n[i], array_n[i + 1]);
		}
		int min = array_aux[0];
		for (int i = 1; i < (n-1); i++)
		{
			if (array_aux[i] < min) min = array_aux[i];
		}
		cout << (min-1) << endl;
	}
	return 0;
}