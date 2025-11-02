#include <bits/stdc++.h>
using namespace std;
int len,len1,len2;
int x,y;
int n;

string a[10],b[10];
void zh1(int x,int y){
    int temp;
    string ans = "";
    while (y > 0){
        y--;
        temp = y % 26;
        if(temp == 0){
            ans += 'z';
        }else{
            ans += char(temp + 65);
        }
        y /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << x;
}
void zh2(int len,int len1,string a,int i){
    cout << 'R';
    for(int j = len1;j <= len;j++){
        cout << a[j];
    }
    cout << 'C';
    int ans;
    for(int j = 0;j < len1;j++){
        ans += ans * 26 + (int(a[j]) - 'A' + 1);
    }
    cout << ans - 2;
}
int main(){

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        len = a[i].length();
        if(int(a[i][0]) == 82 && int(a[i][1]) >= 48 && int(a[i][1]) <= 57){
            for(int j = 1;int(a[i][j]) != 67;j++){
                len1++;
            }
            len2 = len - len1 - 2;
            for(int j = 1;j <= len1;j++){
                x = x * 10 + (int(a[i][j]) - 48);
            }
            for(int j = len1 + 2;j < len;j++){
                y = y * 10 + (int(a[i][j]) - 48);
            }
            zh1(x,y);
        }
        else{
            for(int j = 0;j < len;j++){
                if(a[i][j] >= 'A' && a[i][j] <= 'Z'){
                    len1++;
                }
            }
            zh2(len,len1,a[i],i);
        }
    }
    return 0;
}