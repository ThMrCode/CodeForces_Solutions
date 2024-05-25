#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--)
	{
		int a; cin >> a; int b; cin >> b;
		int c; cin >> c; int d; cin >> d;
		if (a > b) {
			int aux = b; b = a; a = aux;
		}
		bool range_c = (c < b) && (c > a);
		bool range_d = (d < b) && (d > a);
		if (range_c == range_d) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}