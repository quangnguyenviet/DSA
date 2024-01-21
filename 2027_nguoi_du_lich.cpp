#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[20][20], amin = INT_MAX;
int fopt = INT_MAX;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i != j){
                amin = min(amin, a[i][j]);
            }
        }
    }
}

vector<bool> used(20, false);
vector<int> htrinh(20, 1);
void back_track(int i, int x, int g){
    for(int j = 2; j <= n; j++){
        if(used[j] == false){
            used[j] = true;
            htrinh[i] = j;
            x += a[htrinh[i]][htrinh[i - 1]];
            // cout << x << endl;
            g = x + amin * (n - i);
            if(i == n - 1){
                x += a[htrinh[i]][1];
                // cout << "hello " << x << endl;
                if(x < fopt){
                    fopt = x;
                }
            }
            else if(g < fopt){
                back_track(i + 1, x, g);
            }
            used[j] = false;
            x -= a[htrinh[i]][htrinh[i - 1]];
        }
    }
}

int main(){
    input();
    back_track(1, 0, 0);
    cout << fopt << endl;
}