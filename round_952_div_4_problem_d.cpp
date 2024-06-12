#include <iostream>
#include <vector>
using namespace std;
 
vector<int> vect_h;
vector<int> vect_k;
int n; int m;
char traduct(string& cadena, int x, int y) {
	return cadena[(y - 1) * m + (x - 1)];
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> m;
		string s;
		for (int i = 0; i < n; i++)
		{
			string s_aux; cin >> s_aux;
			s = s + s_aux;
		}
		int x = -1; int y = -1;
		bool val_for = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				// j es x, i es y
				int counter = 0;
				if (traduct(s, j, i) == '#') {
					for (int i_aux = (i + 1); i_aux <= n; i_aux++)
					{
						if (traduct(s, j, i_aux) == '#') counter++;
						else break;
					}
					x = j; y = i + (counter / 2);
					val_for = true;
					break;
				}
			}
			if (val_for) break;
		}
		vect_h.push_back(y);
		vect_k.push_back(x);
	}
	for (int i = 0; i < vect_h.size(); i++)
	{
		cout << vect_h[i] << " " << vect_k[i] << endl;
	}
	return 0;
}