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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf=10000000;
	cin >> n;
	long long ax, ay, bx, by;
	vector<string> s(n);
	cin >> ax >> ay >> bx >> by;
	ax--; ay--; bx--; by--;

	rep(i, n) {
		cin >> s[i];
	}

	// validate check
	if ((ax + ay) % 2 != (bx + by) % 2) {
		cout << -1 << endl; return 0;
	}

	pair<int, int> p;
	queue<pair<int, int>> qu;
	vector<vector<long long>> dp(n, vector<long long>(n, inf));
	vector<vector<vector<bool>>> pass(n, vector<vector<bool>>(n, vector<bool>(2, true)));
	vector<int> dx = { 1,1,-1,-1 }, dy = { 1,-1,-1,1 };
	int curx, cury, curs;
	dp[ax][ay] = 0; qu.push({ ax,ay });
	while (!qu.empty()) {
		p = qu.front();
		qu.pop();
		rep(i, 4) {
			curx = p.first; cury = p.second; curs = dp[curx][cury];
			if (pass[curx][cury][i % 2] == false) {
				// already checked
				continue;
			}

			while (true) {
				curx += dx[i]; cury += dy[i];
				
				if (min(curx, cury) < 0 || max(curx, cury) >= n) {
					// out of range
					break;
				}
				else if (s[curx][cury] == '#') {
					// there is a pawn
					break;
				}
				else if (dp[curx][cury] == inf) {
					// first time
					dp[curx][cury] = curs + 1;
					qu.push({ curx,cury });
					pass[curx][cury][i % 2] = false;
				}
				else {
					pass[curx][cury][i % 2] = false;
				}
			}
		}

	}
	/*
	rep(i, n) {
		rep(j, n) {
			if (dp[i][j] != inf) {
				cout << dp[i][j];
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	*/
	if (dp[bx][by] == inf) {
		cout << -1 << endl;
	}
	else {
		cout << dp[bx][by] << endl;
	}
}

26
abcdefghijklmnopqrstuvwxyz