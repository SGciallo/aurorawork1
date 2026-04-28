#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<vector<int>> dp2, dp5;
vector<vector<char>> path2, path5;

pair<int,int> get25(int x) {
    if (x == 0) return {0, 0};
    int c2 = 0, c5 = 0;
    while (x % 2 == 0){
		c2++;
		x /= 2;
	}
    while (x % 5 == 0){
		c5++;
		x /= 5;
	}
    return {c2, c5};
}

int run_dp(int type, vector<vector<char>>& path) {
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    dp[0][0] = (type == 0 ? get25(a[0][0]).first : get25(a[0][0]).second);
    path[0][0] = 'S';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            int val = (type == 0 ? get25(a[i][j]).first : get25(a[i][j]).second);
            int up = (i > 0) ? dp[i-1][j] : pow(10,9);
            int left = (j > 0) ? dp[i][j-1] : pow(10,9);
            if (up < left) {
                dp[i][j] = up + val;
                path[i][j] = 'D';
            } else {
                dp[i][j] = left + val;
                path[i][j] = 'R';
            }
        }
    }
    return dp[n-1][n-1];
}

string get_path(vector<vector<char>>& path) {
    string res;
    int i = n-1, j = n-1;
    while (i != 0 || j != 0) {
        if (path[i][j] == 'D') {
            res += 'D';
            i--;
        } else if (path[i][j] == 'R') {
            res += 'R';
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cin >> n;
    a.resize(n, vector<int>(n));
    bool has_zero = false;
    int zero_i = -1, zero_j = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                has_zero = true;
                zero_i = i; zero_j = j;
            }
        }
    }
    path2.assign(n, vector<char>(n));
    path5.assign(n, vector<char>(n));
    int ans2 = run_dp(0, path2);
    int ans5 = run_dp(1, path5);

    string best_path;
    int best_zeros = min(ans2, ans5);
    if(ans2 <= ans5)best_path = get_path(path2);
    else best_path = get_path(path5);
    if (has_zero && best_zeros > 1) {
        best_zeros = 1;
        best_path.clear();
        string path_to_zero;
        for (int i = 0; i < zero_i; i++) path_to_zero += 'D';
        for (int j = 0; j < zero_j; j++) path_to_zero += 'R';
        string path_from_zero;
        for (int i = zero_i; i < n-1; i++) path_from_zero += 'D';
        for (int j = zero_j; j < n-1; j++) path_from_zero += 'R';
        best_path = path_to_zero + path_from_zero;
    }

    cout << best_zeros << endl << best_path << endl;
    return 0;
}
