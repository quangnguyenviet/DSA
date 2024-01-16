#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec(100);
void init(){
    for(int i = 1; i <= n; i++){
        vec[i] = 0;
    }
}

bool last_configuration(){
    for(int i = 1; i <= n; i++){
        if(vec[i] != 1) return false;
    }
    return true;
}

void display(){
    for(int i = 1; i <= n; i++){
        cout << vec[i]  << " ";
    }
    cout << endl;
}

void generate_next_configuration(){
    int i = n;
    while(i >= 1 && vec[i] == 1){
        vec[i] = 0;
        i--;
    }
    if(i == 0) return;
    else{
        vec[i] = 1;
        return;
    }
}

bool tn(){
    int l = 1, r = n;
    while(l < r){
        if (vec[l] != vec[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main(){
    cin >> n;
    init();
    while(!last_configuration()){
        if(tn())
        display();
        generate_next_configuration();
    }
    if(tn())
    display();
}