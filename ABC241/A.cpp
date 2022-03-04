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
	long long n, m, i, j, k, ans, cur, res, jud, mod;
	vector<int> a(10);
	rep(i, 10) {
		cin >> a[i];
	}
	cout << a[a[a[0]]] << endl;
}