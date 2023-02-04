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

struct item {
	long long a;
	bool need = false;
};
bool operator<(item a, item b) {
	return a.a < b.a;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000;
	cin >> n >> m;
	vector<item> vi(n);
	vector<long long> c(n);
	vector<long long> p(m);
	rep(i, n) {
		cin >> vi[i].a;
	}
	rep(i, n) {
		cin >> c[i];
	}
	rep(j, m) {
		cin >> x;
		p[j] = x - 1;
		vi[x - 1].need = true;
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1000000000000000000));
	vector<vector<long long>> cmin(n, vector<long long>(n, 1000000000000000000));
	rep(i, n) {
		cmin[i][i] = c[i];
		for (j = i + 1; j < n; j++) {
			cmin[i][j] = min(cmin[i][j - 1], c[j]);
		}
	}
	vector<long long> ms(n);
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, i + 1) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + vi[i].a + cmin[j][i]);
			if (vi[i].need == false) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
		}
	}
	ans = 1000000000000000000;
	rep(j, n + 1) {
		ans = min(ans, dp[p[m - 1]+1][j]);
	}
	cout << ans << endl;
	/*
	long long itr;
	rep(j, m) {
		while (i <= p[j]) {
			ms[i] = (vi[i].a);
			i++;
		}
		sort(ms.begin(), ms.begin() + i);
		cur = 200000000000; res = 0; itr = 0;
		for (k = 0; k <= p[j]; k++) {
			res += ms[k];
			if (cur >= res + c[p[j] - k]){
				itr = k;
				cur = res + c[p[j] - k];
			}
		}
		ans += cur;
		for (k = 0; k <= itr; k++) {
			cout << ms[k] << ' ';
			ms[k] = 0;
		}
		cout << endl;
		cout << ans << endl;
	}
	*/
	
}