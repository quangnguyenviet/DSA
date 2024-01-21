#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n, a[6];
bool ok = false;

void input(){
    for(long long i = 1; i <= 5; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 6);
}

long long res = 0;
long long x[5];

long long tinh(long long a, long long b, long long c){
    if(c == 1) return a + b;
    else if(c == 2) return a * b;
    else return a - b;
}

void caculate(){
    res = tinh(a[1], a[2], x[1]);
    for(long long i = 2; i <= 4; i ++){
        res = tinh(res, a[i + 1], x[i]);
    }
}

void Try(long long i){
    if(ok) return;
    for(long long j = 1; j <= 3; j ++){
        x[i] = j;
        if(i == 4){
            caculate();
            // cout << res << endl;
            if(res == 23){
                ok = true;
                return;
            }
        }
        else{
            Try(i + 1);
        }

    }
}

void solve(){
    do{
        Try(1);
        if(ok){
            cout << "YES\n";
            break;
        }
    }while(next_permutation(a + 1, a + 6));
    if(ok == false){
        cout << "NO\n";
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        input();
        solve();
        ok = false;
        res = 0;
    }
}