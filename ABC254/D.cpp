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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	long long ok, ng, mid;
	vector<long long> a(n + 1);
	rep(i, n + 1) {
		a[i] = i * i;
	}
	ans = 0;

	for (i = 1; i <= n; i++) {
		cur = i;
		j = 1;
		while (a[j] < cur) {
			j++;
		}
		while (true) {
			if (cur % a[j] == 0) {
				cur /= a[j];
				break;
			}
			j--;
		}
		
		ok = 1; ng = n + 1;
		while (ng - ok > 1) {
			mid = (ng + ok) / 2;
			if (cur * a[mid] <= n) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		ans += ok;

	}
	cout << ans << endl;
}
