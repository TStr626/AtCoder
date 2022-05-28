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
	cin >> i >> j >> k;
	if (i == j || j == k) {
		cout << "Yes" << endl;
	}
	else if (i < j && j < k) {
		cout << "Yes" << endl;
	}
	else if (i > j && j > k) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}