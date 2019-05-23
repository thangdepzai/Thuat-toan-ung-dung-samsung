@@ -0,0 +1,61 @@


#include <iostream>
#include <stdio.h>
#define MAXN 100001

using namespace std;

int n_cases, n, l1, l2, a[MAXN];
FILE *ifp, *ofp;

int main(int argc, char const *argv[])
{
	ifp = fopen("Gold.inp", "r");
	ofp = fopen("Gold.out", "w");
	fscanf(ifp, "%d", &n_cases);
	// cin >> n_cases;
	for (int t = 0; t < n_cases; ++t) {
		fscanf(ifp, "%d %d %d", &n, &l1, &l2); 
		// cin >> n >> l1 >> l2;
		for (int i = 0; i < n; ++i) {
			fscanf(ifp, "%d", a+i);
			// cin >> a[i];
		}

		int max_s[n];
		// for (int i = 0; i < n; ++i) {
		// 	max_s[i] = 0;
		// }
		max_s[0] = a[0];
		for (int i = 1; i < n; ++i) {
			int lo = i - l2 > 0 ? i - l2 : 0;
			int hi = i - l1 >= 0 ? i - l1 : -1;
			if (lo > hi) {
				max_s[i] = a[i];
				continue;
			}
			int _max = 0;
			for (int k = lo; k <= hi; ++k) {
				if (max_s[k] > _max) {
					_max = max_s[k];
				}
			}
			max_s[i] = _max + a[i];
		}

		int result = max_s[0];
		for (int i = 1; i < n; ++i) {
			if (max_s[i] > result) {
				result = max_s[i];
			}
		}

		// cout << result << '\n';
		fprintf(ofp, "%d\n", result);
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}