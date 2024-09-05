#include <iostream>
#include <vector>
using namespace std;
 
// Nota, No se porque falla en el test 24, luego lo reviso, pero en general esta correcto

/*
* ANALISIS PREVIO
// Estructura que resume una cadena con el valor mex
// Si la cadena no tiene huecos de 1 complete = -1 (no se puede completar)
// La cadena entonces solo dara su valor de mex, o mex + 1 si x = mex;
// Si la cadena tiene hueco de 1 complete = valor del hueco
// Si x tiene el valor del hueco la cadena dara su valor de mex
// Si x no tiene el valor del hueco la cadena dara el valor del hueco 
 
Estructura de referencia pues ya no es necesaria despues
struct Data {
	int mex = 0;
	int complete = -1;
};
 
// Las cadenas de un hueco son autocompletables y mex(x,cadena) sera:
// Si x es el hueco -> dara su mex
// Si x no es el hueco -> dara el hueco y luego dara su mex
 
// La cadena sin hueco (o hueco > 1) sera:
// si x es el mex -> dara mex + 1
// si x no es el mex -> dara mex y luego dara su mex + 1
 
 
// analizar todas las cadenas y comparar la que tenga mayor mex 
// En todos los casos, no importa el valor inicial de x pues tras una suboperacion
// este siempre tomara el valor del hueco y luego mex (completables) 
// del mex en cadenas completas y luego mex + 1 (completas)
 
// Todo esto se resume en un vector que almacenara el mex de cada cadena que es
// independiente de x inicial, en cadenas completas sera su mex + 1
// en completables sera su mex tras completar primer hueco
*/
 
// Ambos casos en realidad son el mismo
// sacar el mex, agregarlo y luego el siguiente mex
// forma mas rapida, hacer un counting hasta (lsize+1) que sera el maximo mex a alcanzar
// si x > mexMax, se queda con x
 
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; long long m; cin >> m;
		int mexMax = 0;
		for (int i = 0; i < n; i++)
		{
			int l; cin >> l;
			int lMax = l + 5;
			vector<int> vect_counting(lMax, 0);
			for (int j = 0; j < l; j++)
			{
				int a; cin >> a;
				if (a < lMax) vect_counting[a]++;
			}
			bool value_hueco = true;
			int mex = 0;
			for (mex = 0; mex < lMax; mex++)
			{
				if (vect_counting[mex] == 0) {
					if (value_hueco) {
						vect_counting[mex] = 1;
						value_hueco = false;
					}
					else {
						// Encontro el segundo hueco, ahi queda entonces
						break;
					}
				}
			}
			if (mex > mexMax) mexMax = mex;
		}
		if (m > mexMax) {
			long long value = (((m * (m + 1)) + (mexMax * (mexMax + 1))) / 2);
			cout << value << endl;
		}
		else {
			long long value = mexMax * (m + 1);
			cout << value << endl;
		}
	}
 
	return 0;
}