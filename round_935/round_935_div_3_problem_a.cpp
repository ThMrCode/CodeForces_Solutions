#include <iostream>
using namespace std;
 
int array_sol[10000];
int main(){
	int t; cin >> t;
	int a;	int b;	int c;
	for (int i = 0; i < t; i++)
	{
		cin >> a;cin >> b;cin >> c;
		int res = (b % 3);
		int c_ex = 1;
		int b_ex = 1;
		int c_aux = c + res - 3;
		if (res == 0) {	c_aux = c;	b_ex = 0; }
		if ((c_aux % 3) == 0) { c_ex = 0; }
		array_sol[i] = a + (b / 3) + b_ex + (c_aux / 3) + c_ex;
		if ((c + res) < 3 && res != 0) array_sol[i] = -1;
	}
	for (int i = 0; i < t; i++)
	{
		cout << array_sol[i] << endl;
	}
}