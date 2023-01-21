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
	string s,t;
	cin >> n >> s;
	i = 0;
	t = "";
	while (i < n) {
		if (i < n - 1 && s.substr(i, 2) == "na") {
			t += "nya";
			i += 2;
		}
		else {
			t += s[i];
			i++;
		}
	}
	cout << t << endl;
}