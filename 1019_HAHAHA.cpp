#include <bits/stdc++.h>
using namespace std;
int n, a[20];

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
bool ok(){
    for(int i = 2; i <= n; i ++){
        if(a[i] == 1 && a[i - 1] == 1) return false;
    }
    return true;
}
void display(){
    cout << "HA";
    for(int i = 1; i <= n; i ++){
        if(a[i] == 1){
            cout << "H";
        }
        else{
            cout << "A";
        }
    }
    cout << "A\n";
    
}

void generate(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i --;
    }
    if(i == 0) return;
    else{
        a[i] = 1;
    }
}

void input(){
    cin >> n;
    if(n == 2){
        cout << "HA" << endl;
    }
    else if(n == 3){
        cout << "HAA" << endl;
    }
    else if(n == 4){
        cout << "HAAA\nHAHA\n";
    }
    else{
        n -= 3;
        init();
        while(! last_configuration()){
            if(ok()){
                display();
            }
            generate();
        }
        if(ok()) display();

    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        input();
    }
}