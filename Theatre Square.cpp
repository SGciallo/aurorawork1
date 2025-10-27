#include <bits/stdc++.h>
using namespace std;
int n,m,a,ans = 0;
bool flag = 1;
int s[9999][9999];
void fz(int x,int y){
    for(int i = 0;i < a;i++){
        for(int j = 0;j < a;j++){
            s[x + i][y + j] = 1;
        }
    }
}
bool check(){
    for(int i = 0;i < n && flag == 1;i++){
        for(int j = 0;j < m;j++){
            if (s[i][j] == 0){
                flag = 0;
                break;
            }
        }
    }
    return 1;
}
int main(){
    cin >> n >> m >> a;
    for(int i = 0;i < n;i += a){
        for(int j = 0;j < m;j += a){
            fz(i,j);
            if (check()){
                ans++;
            }
        }
    }

    cout << ans;
	return 0;
}
