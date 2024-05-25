#include <iostream>
#include <cmath>
 
using namespace std;
int tope(double c) {
	if ((int)c == c) return c;
	else return c + 1;
	return 0;
}
int main() {
	int t; cin >> t;
	// encontrar cuadrado interior y cuadrado exterior?
	while (t--)
	{
		int r; cin >> r;
		int sum = 0;
		for (int i = 1; i <= r; i++)
		{
			double y_1 = sqrt(pow(r, 2) - pow(i, 2));
			double y_2 = sqrt(pow((r + 1), 2) - pow(i, 2));
			// contar cuantos puntos enteros hay entre y_1 <= y < y_2
			sum += tope(y_2) - tope(y_1);
		}
		sum = sum * 4;
		cout << sum << endl;
	}
	return 0;
}