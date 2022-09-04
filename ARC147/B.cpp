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
	vector<long long> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	vector<pair<char, long long>> ansv(0);
	
	for (i = 0; i < n - 1; i++) {
		if ((p[i] + i) % 2 == 0) {
			continue;
		}

		j = i + 1;
		while ((p[j] + j) % 2 == 0) {
			j += 2;
		}
		for (k = j; k > i + 2; k -= 2) {
			swap(p[k], p[k - 2]);
			ansv.push_back({ 'B',k - 2 });
		}
		swap(p[i], p[i + 1]);
		ansv.push_back({ 'A',i });
	}
	
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i - 1; j++) {
			if (p[j] > p[j + 2]) {
				swap(p[j], p[j + 2]);
				ansv.push_back({ 'B',j });
			}
		}
	}
	

	cout << ansv.size() << endl;
	rep(i, ansv.size()) {
		cout << ansv[i].first << ' ' << ansv[i].second + 1 << endl;
	}
	/*
	rep(i, n) {
		cout << p[i];
	}
	*/
	
	
}