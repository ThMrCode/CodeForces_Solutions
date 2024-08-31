#include <iostream>
using namespace std;
 
long long n; long long a; long long b;
long long benify(long long num) {
	return ((n - num) * a + b * num - num * (num - 1) / 2);
}
 
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; cin >> a; cin >> b;
		// beneficio = (n-k)*a + b*k - k(k-1) / 2; es parabola inversa, verificar si el maximo esta en medio, sino estara en costados
		long long max_ = n;
		if (n > b) max_ = b;
		long long benify_max = n * a;
		if (benify(max_) > benify_max)  benify_max = benify(max_);
		long long middle = (int)(b - a);
		// ratius para no calcular mucho
		for (int i = 0; i < 5; i++)
		{
			if ((i + middle) <= n && (i + middle) >= 0) {
				if (benify((i + middle)) > benify_max)  benify_max = benify((i + middle));
			}
			if ((middle - i) <= n && (middle - i) >= 0) {
				if (benify((middle - i)) > benify_max)  benify_max = benify((middle - i));
			}
		}
		cout << benify_max << endl;
	}
	return 0;
}