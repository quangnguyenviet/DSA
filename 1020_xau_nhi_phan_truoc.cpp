#include <bits/stdc++.h>
using namespace std;
string x;
bool first_configuration(){
    for(auto &temp : x){
        if(temp == '1') return false;
    }
    return true;
}
void input(){
    cin >> x;
    int len_x = x.size();
    if(first_configuration()){
        string temp(len_x, '1');
        cout << temp << endl;
    }
    else{
        int i = len_x;
        i --;
        while(i >= 0 && x[i] == '0'){
            x[i] = '1';
            i --;
        }
        x[i] = '0';
        cout << x << endl;
    }

}
int main(){
    int t;
    cin >> t;
    while(t --){
        input();
    }
}