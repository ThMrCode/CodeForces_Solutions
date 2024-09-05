#include <iostream>
using namespace std;
 
int array_a[55] = { 0 };
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> array_a[i];
		}
		int counter_1 = 1;
		int counter_2 = 0;
		int ref = array_a[0];
		int pot = -1;
		// si hay al menos 3 elementos distintos en los cuales al menos 1 sea distinto, se puede
		for (int i = 1; i < n; i++)
		{
			if (array_a[i] != ref) counter_2++;
			else counter_1++;
			if (counter_2 >= 2) {
				pot = i;
				break;
			}
			else if (counter_2 == 1 && counter_1 >= 2) {
				pot = 0;
				break;
			}
		}
		if (pot != -1) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
			{
				if (i == pot) cout << "R";
				else cout << "B";
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}