#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	cin >> n;

	vector<bool> d(2 * n + 1, true);
	j = 0;
	rep(i, n + 1) {
		while (!d[j]) {
			j++;
		}
		d[j] = false;
		cout << j + 1 << endl;
		
		if (i < n) {
			cin >> k;
			d[k - 1] = false;
		}
	}
}