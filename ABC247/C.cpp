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

long long b;
vector<long long> a;
void dfs(int n) {
	if (n == 1) {
		a[b] = 1;
		b++;
		return;
	}
	else {
		dfs(n - 1);
		a[b] = n;
		b++;
		dfs(n - 1);
		return;
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	m = (1 << n) - 1;
	a.resize(m);
	b = 0;
	dfs(n);
	rep(i, m) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}