#include <bits/stdc++.h>
using namespace std;
int n, k, a[1001];
void init(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}
void read_array(){
    for(int i = 1; i <= k; i++){
        cin >> a[i];
    }
}
void generate_next_configuration(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    if(i == 0){
        init();
    }
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}
void display(){
    for(int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        read_array();
        generate_next_configuration();
        display();
    }
}