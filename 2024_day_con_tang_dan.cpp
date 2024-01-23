#include <bits/stdc++.h>
using namespace std;
int n, a[30];
vector<string> res;
string s;
int x[30];

bool cmp(string a, string b){
    return a < b;
}

void Try(int i, int start){
    for(int j = start; j <= n; j ++){
        if(a[j] > x[i - 1]){
            x[i] = a[j];
            if(i >= 2){
                string temp;
                for(int k = 1; k <= i; k ++){
                    temp += to_string(x[k]) + " ";
                }
                res.push_back(temp);
            }
            Try(i + 1, j + 1);
        }
    }
}

void input(){
    res.clear();
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    Try(1, 1);
    sort(res.begin(), res.end(), cmp);
    for(auto temp : res){
        cout << temp << endl;
    }
}
int main(){
    input();
}