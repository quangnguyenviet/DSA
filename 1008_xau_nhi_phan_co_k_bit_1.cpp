#include <bits/stdc++.h>
using namespace std;
int n, k, a[20];
void init(){
    for(int i = 1; i <= n; i ++){
        a[i] = 0;
    }
}
bool last_configuration(){
    for(int i = 1; i <= n; i ++){
        if(a[i] == 0) return false;
    }
    return true;
}
bool k_bit_1(){
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i] == 1) cnt ++;
    }
    return cnt == k;
}
void display(){
    for(int i = 1; i <= n; i ++){
        cout << a[i];
    }
    cout << endl;
}
void generate(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i --;
    }
    if(i == 0) return;
    else{
        a[i] ++;
    }
}


void input(){
    cin >> n;
    cin >> k;
    init();
    while(! last_configuration()){
        if(k_bit_1())
        display();
        generate();
    }
    if(k_bit_1())
    display();
}

int main(){
    int t;
    cin >> t;
    while(t --){
        input();
    }
}