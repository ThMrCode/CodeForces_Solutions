#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x; int val_max = 0;
		for (int i = 2; i <= n; i++)
		{
			int k = (int)(n / i);
			int val = (k * (k + 1) / 2) * i;
			if (val > val_max) {
				x = i;
				val_max = val;
			}
 		}
		cout << x << endl;
	}
	return 0;
}