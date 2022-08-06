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

long long n, m;
vector<long long> a(0);

void output() {
	int j;
	rep(j, n) {
		if (j)cout << ' ';
		cout << a[j];
	}
	cout << endl;
	return;
}

void dfs(long long x) {
	int i;
	for (i = x + 1; i <= m; i++) {
		a.push_back(i);
		if (a.size() == n) {
			output();
		}
		else {
			dfs(i);
		}
		a.pop_back();
	}
	return;
}

int main() {
	long long j, k, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	dfs(0);
}