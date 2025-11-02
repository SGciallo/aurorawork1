#include <bits/stdc++.h>
using namespace std;
int main(){
    string name[1000],tname;
    int score,sum[1000],max = 0;
    int n;

    cin >> n;
    for(int i = 0;i < n;i++){
        bool check = 0;
        cin >> tname >> score;
        for(int j = 0;j < i;j++){
            if(tname == name[j]){
                sum[j] = score;
                check = 1;
                break;
            }
        }
        if(!check){
                name[i] = tname;
                sum[i] += score;
        }
    }
    for(int i = 0;i < n;i++){
        if(sum[i] > sum[max]){
            max = i;
        }
    }
    cout << name[max];
    return 0;
}