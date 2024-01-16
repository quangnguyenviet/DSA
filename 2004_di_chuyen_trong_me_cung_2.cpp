#include <bits/stdc++.h>
using namespace std;
int n, a[1000][1000];
bool ok = false;
string res;
void create_matrix(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}
void back_track(int i, int j){
    if(i == n-1 && j == n-1){
        cout << res << " ";
        ok = true;
        return;
    }
    if(i + 1 < n && a[i + 1][j] == 1){
        res += 'D';
        a[i][j] = 0;
        back_track(i + 1, j);
        res.pop_back();
        a[i][j] = 1;
    }
    if(j - 1 >= 0 && a[i][j - 1] == 1){
        res += 'L';
        a[i][j] = 0;
        back_track(i, j - 1);
        res.pop_back();
        a[i][j] = 1;
    }
    if(j + 1 < n && a[i][j + 1] == 1){
        res += 'R';
        a[i][j] = 0;
        back_track(i, j + 1);
        res.pop_back();
        a[i][j] = 1;
    }
    if(i - 1 >= 0 && a[i - 1][j] == 1){
        res += 'U';
        a[i][j] = 0;
        back_track(i - 1, j);
        res.pop_back();
        a[i][j] = 1;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        res = "";
        ok = false;
        cin >> n;
        create_matrix();
        if(a[0][0] && a[n-1][n-1]){
            back_track(0, 0);
        }
        if(ok == false) cout << "-1\n";
        else cout << endl;
    }
}