#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--) {
		// En una pila si o si va ir el ultimo y va a ganar ese, asegurar entonces la otra
		int n; cin >> n;
		int max = 0;
		for (int i = 0; i < (n-1); i++)
		{
			int a; cin >> a;
			if (a > max) {
				max = a;
			}
		}
		int a; cin >> a;
		max += a;
		cout << max << endl;
	}
	return 0;
}