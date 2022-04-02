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
	cin >> n;
	j = 1000000; ans = 1000000000000000000ll;
	for (i = 0; i * i * i <= n; i++) {
		while (true) {
			cur = i * i * i + i * i * j + i * j * j + j * j * j;
			if (cur >= n) {
				ans = min(cur, ans);
				j--;
			}
			else {
				break;
			}
		}
	}
	cout << ans << endl;
}