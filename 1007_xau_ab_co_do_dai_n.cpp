#include <bits/stdc++.h>
using namespace std;
int n, a[15];
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
void display(){
    for(int i = 1; i <= n; i ++){
        if(a[i] == 0) cout << 'A';
        else{
            cout << 'B';
        }
    }
    cout << " ";
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
    while(t --){
        input();
    }
}