#include <iostream>
#include <stdlib.h>
using namespace std;
 
int max_top(int a, int b) {
	if (a > b) return a;
	return b;
}
int min_top(int a, int b) {
	if (a < b) return a;
	return b;
}
 
int main() {
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int sum_x = 0;
		int sum_y = 0;
		int sum_n = 0;
		int sum_s = 0;
		int sum_e = 0;
		int sum_w = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'N') {
				sum_y++;
				sum_n++;
			}
			else if (s[i] == 'S') {
				sum_y--;
				sum_s++;
			}
			else if (s[i] == 'E') {
				sum_x++;
				sum_e++;
			}
			else if (s[i] == 'W') {
				sum_x--;
				sum_w++;
			}
		}
		if ((sum_x % 2 == 0 && sum_y % 2 == 0) && (((sum_x != 0) || (sum_y != 0)) || ((sum_n + sum_s + sum_e + sum_w) >= 4))) {
			int num_1 = max_top(sum_n, sum_s);
			int num_2 = min_top(sum_n, sum_s);
			int num_3 = max_top(sum_e, sum_w);
			int num_4 = min_top(sum_e, sum_w);
			int counter_n = 0;
			int counter_s = 0;
			int counter_e = 0;
			int counter_w = 0;
			bool alter_x = true;
			bool alter_y = true;
			bool aux_y = false;
			bool aux_x = false;
			if (num_2 >= 2) aux_y = true;
			if (num_4 >= 2) aux_x = true;
			for (int i = 0; i < n; i++)
			{
				if (s[i] == 'N') {
					if (counter_n < num_2) {
						if (aux_y && counter_n == 1) {
							s[i] = 'H';
							counter_n++;
						}
						else {
							s[i] = 'R';
							counter_n++;
						}
					}
					else {
						if (alter_x) {
							s[i] = 'R';
							alter_x = !alter_x;
						}
						else {
							s[i] = 'H';
							alter_x = !alter_x;
						}
					}
				}
				else if (s[i] == 'S') {
					if (counter_s < num_2) {
						if (aux_y && counter_s == 1) {
							s[i] = 'H';
							counter_s++;
						}
						else {
							s[i] = 'R';
							counter_s++;
						}
					}
					else {
						if (alter_x) {
							s[i] = 'R';
							alter_x = !alter_x;
						}
						else {
							s[i] = 'H';
							alter_x = !alter_x;
						}
					}
				}
				else if (s[i] == 'E') {
					if (counter_e < num_4) {
						if (aux_x && counter_e == 1) {
							s[i] = 'R';
							counter_e++;
						}
						else {
							s[i] = 'H';
							counter_e++;
						}
					}
					else {
						if (alter_y) {
							s[i] = 'R';
							alter_y = !alter_y;
						}
						else {
							s[i] = 'H';
							alter_y = !alter_y;
						}
					}
				}
				else if (s[i] == 'W') {
					if (counter_w < num_4) {
						if (aux_x && counter_w == 1) {
							s[i] = 'R';
							counter_w++;
						}
						else {
							s[i] = 'H';
							counter_w++;
						}
					}
					else {
						if (alter_y) {
							s[i] = 'R';
							alter_y = !alter_y;
						}
						else {
							s[i] = 'H';
							alter_y = !alter_y;
						}
					}
				}
			}
			cout << s << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}