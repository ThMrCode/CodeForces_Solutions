#include <iostream>
#include <vector>
using namespace std;
 
// ascii -> del 97 (a) al 122 (z) son 26 en total
#define N 26
vector<int> array_counter(N,0);
 
void reset() {
	for (int i = 0; i < N; i++)
	{
		array_counter[i] = 0;
	}
}
 
void counter(string& s, int size) {
	for (int i = 0; i < size; i++)
	{
		array_counter[(int)(s[i] - 97)]++;
	}
}
 
string solve(string& s) {
	reset();
	counter(s, s.length());
	string s_return(s.length(), ' ');
	bool value_loop = true;
	int s_counter = 0;
	while (value_loop) {
		value_loop = false;
		for (int i = 0; i < N; i++)
		{
			if (array_counter[i] > 0) {
				s_return[s_counter] = (char)(97 + i);
				array_counter[i]--;
				s_counter++;
				value_loop = true;
			}
		}
	}
	return s_return;
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}