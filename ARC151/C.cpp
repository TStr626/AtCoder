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
// WA
// input:
// 8 2
// 3 0
// 5 0
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 100000000;
	cin >> n >> m;

	// corner case
	if (m == 0) {
		if (n % 2 == 1) {
			cout << "Takahashi" << endl;
		}
		else {
			cout << "Aoki" << endl;
		}
		return 0;
	}


	vector<long long> px(m), py(m);
	ans = n - m;
	rep(i, m) {
		cin >> px[i] >> py[i];
		if (i > 0 && (((px[i] + py[i]) % 2) != ((px[i - 1] + py[i - 1]) % 2))) {
			ans--;
		}
	}
	
	cur = max(px[0] - 1,  n - px[m - 1]);
	res = min(px[0] - 1,  n - px[m - 1]);

	if (cur >= 2 && res <= 1) {
		cout << "Takahashi" << endl;
	}
	else if (cur <= 1 && (ans % 2 == 1)) {
		cout << "Takahashi" << endl;
	}
	else if (res >= 2 && cur != res) {
		cout << "Takahashi" << endl;
	}
	else {
		cout << "Aoki" << endl;
	}
}