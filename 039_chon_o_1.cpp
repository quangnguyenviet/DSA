#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
void generate_next_configuration(){
    int i = s.size() -1;
    while(i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if(i == -1) return;
    else{
        s[i] = '1';
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        generate_next_configuration();
        cout << s << endl;
    }
}