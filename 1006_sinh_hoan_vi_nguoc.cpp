#include <bits/stdc++.h>
using namespace std;
int n, a[20];

void init(){
    for(int i = 1; i <= n; i ++){
        a[i] = n - i + 1;
    }
}

bool last_configuration(){
    for(int i = 1; i <= n - 1; i ++){
        if(a[i] > a[i + 1]) return false;
    }
    return true;
}

void display(){
    for(int i = 1; i <= n; i ++){
        cout << a[i];
    }
    cout << " ";
    // cout << endl;
}

void generate(){
    int i = n - 1;
    while(i >= 1 && a[i] < a[i + 1]){
        i --;
    }
    if(i == 0) return;
    else{
        int j = n;
        while(a[j] > a[i]){
            j --;
        }
        swap(a[i], a[j]);
        reverse(a + 1 + i, a + n + 1);
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
    while(t--){
        input();
    }
}