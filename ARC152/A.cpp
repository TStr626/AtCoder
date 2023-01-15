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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long l;
	cin >> n >> l;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	cur = l; i = 0;
	while (true) {
		if (cur < a[i] + 1) {
			break;
		}
		cur -= (a[i] + 1);
		i++;
	}
	if (a[i] == 2 && cur == 2) {
		i++;
	}
	while (i < n) {
		if (a[i] == 2) {
			cout << "No" << endl;
			return 0;
		}
		i++;
	}
	cout << "Yes" << endl;
}