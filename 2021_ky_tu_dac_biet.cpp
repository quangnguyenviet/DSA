#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, n2;
string s;
char timkiem(ll n, ll k){
    if(n <= s.size()) return s[n - 1];
    if(n <= k / 2){
        return timkiem(n, k / 2);
    }
    else{
        ll temp = n - k / 2;
        if( temp == 1) return timkiem(k / 2, k / 2);
        else{
            return timkiem(temp - 1, k / 2);
        }
    }
}
void input(){
    cin >> s >> n;
    ll len = s.size();
    while(len < n) len *= 2;
    cout << timkiem(n, len) << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        input();
    }
}