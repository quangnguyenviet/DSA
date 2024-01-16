#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    set<int> se;
    for(int i = 0; i <n; i++){
        cin >> a[i];
        se.insert(a[i]);
    }
    for(int i = 0; i < n; i++){
        if(se.count(a[i]) == 1){
            cout << a[i] << " ";
            se.erase(a[i]);
        }
    }
}