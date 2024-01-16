#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000], x[100], cnt = 0;

void create_array(){
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        x[i] = 0;
    }
}

bool last_configuration(){
    for(int i = 1; i <= n; i++){
        if(x[i] != 1) return false;
    }
    return true;
}

void generate_next_configuration(){
    int i = n;
    while(i >= 1 && x[i] == 1){
        x[i] = 0;
        i--;
    }
    if(i == 0) return;
    else{
        x[i] ++;
        return;
    }
}

bool check(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += x[i] * a[i];
    }
    return sum == k;
}

void display(){
    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    cin >> n >> k;
    create_array();
    init();
    while(!last_configuration()){
        if(check()){
            cnt++;
            display();
        }
        generate_next_configuration();
    }
    if(check()){
        display();
    }
    cout << cnt;

}