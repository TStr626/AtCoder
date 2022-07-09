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
	string s, t;
	cin >> s >> t;
	i = 0; j = 0;
	long long cur1, cur2;
	while (i < s.size() && j < t.size()) {
		if (s[i] != t[j]) {
			break;
		}
		cur1 = 1; cur2 = 1;
		while (i < s.size() - 1 && s[i] == s[i + 1]) {
			cur1++;
			i++;
		}
		while (j < t.size() - 1 && t[j] == t[j + 1]) {
			cur2++;
			j++;
		}
		if (cur1 == 1 && cur2 >= 2) {
			break;
		}
		if (cur1 > cur2) {
			break;
		}
		i++; j++;
	}
	if (i == s.size() && j == t.size()) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}