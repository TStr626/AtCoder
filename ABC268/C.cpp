#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<long long> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	
	vector<long long> sum(2 * n + 2);
	rep(i, n) {
		cur = (p[i] - i + n) % n;
		if (cur == 0) {
			sum[n - 1]++;
			sum[n + 2]--;
		}
		else {
			sum[cur - 1]++;
			sum[cur + 2]--;
			sum[cur + n - 1]++;
			sum[cur + n + 2]--;
		}
	}

	ans = 0;
	rep(i, n + 3) {
		sum[i + 1] += sum[i];
		ans = max(ans, sum[i]);
	}
	cout << ans << endl;
}