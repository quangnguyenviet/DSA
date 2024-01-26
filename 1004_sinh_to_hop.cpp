#include <bits/stdc++.h>
using namespace std;
int n, k, a[20];

void init(){
    for(int i = 1; i <= k; i ++){
        a[i] = i;
    }
}

bool last_configuration(){
    for(int i = 1; i <= k; i ++){
        if(a[i] != n - k + i) return false;
    }
    return true;
}

void display(){
    for(int i = 1; i <= k; i ++){
        cout << a[i];
    }
    cout << " ";
    // cout << endl;
}

void generate(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i --;
    }
    if(i == 0) return;
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++){
            a[j] = a[j - 1] + 1;
        }

    }
}

void input(){
    cin >> n >> k;
    init();
    while(! last_configuration()){
        display();
        generate();
    }
    display();
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        input();
    }
}