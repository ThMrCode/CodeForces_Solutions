#include <iostream>
using namespace std;
 
int main(void) {
	int array_n[100] = { 0 };
	char array_string[3];
	int t;  cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> array_n[i];
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 2; j > -1; j--)
		{
			int n_aux = (array_n[i] - j);
			if (n_aux > 26) n_aux = 26;
			array_string[j] = (char)(n_aux + 96);
			array_n[i] -= n_aux;
		}
		cout << array_string[0] << array_string[1] << array_string[2] << endl;
	}
	return 0;
}