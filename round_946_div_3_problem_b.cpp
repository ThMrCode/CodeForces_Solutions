#include <iostream>
using namespace std;
 
int main() {
	int t; cin >> t;
	while (t--) {
		int r[26] = { 0 };
		char r_aux[26];
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; i++)
		{
			r[s[i] - 97] = 1;
		}
		int counter = 0;
		for (int i = 0; i < 26; i++)
		{
			if (r[i]) {
				r[i] += counter;
				counter++;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (r[j] != 0 && (r[j] + r[i]) == (counter + 1)) r_aux[i] = char(j + 97);
			}
		}
		for (int i = 0; i < n; i++)
		{
			s[i] = r_aux[s[i] - 97];
		}
		cout << s << endl;
	}
	return 0;
}