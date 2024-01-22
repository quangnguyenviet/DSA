#include <bits/stdc++.h>
using namespace std;
int n, cnt = 1;
vector<vector<int>> res;
vector<int> cauhinh(15);
void display2(){
    for(int i = 1; i <= cnt; i ++){
        cout << cauhinh[i] << ' ';
    }
    cout << endl;
}
void save(){
    vector<int> temp;
    for(int i = 1; i <= cnt; i ++){
        temp.push_back(cauhinh[i]);
    }
    res.push_back(temp);
    temp.clear();
}
void init(){
    cauhinh[1] = n;
}
bool last_configuration(){
    for(int i = 1; i <= n; i ++){
        if(cauhinh[i] != 1) return false;
    }
    return true;
}
void generate(){
    int i = cnt;
    while(cauhinh[i] == 1 && i >= 1){
        i --;    }
    if(i == 0) return;
    else{
        cauhinh[i] --;
        int thieu = cnt - i + 1;
        cnt = i;
        int du = thieu % cauhinh[i];
        for(int j = 1; j <= thieu / cauhinh[i]; j ++){
            cauhinh[j + i] = cauhinh[i];
            cnt ++;        } 
        if(du){
            cauhinh[cnt + 1] = du;
            cnt++;        }
    }
}
void display(){
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i ++){
        cout << "(";
        int size_resi = res[i].size();
        for(int j = 0; j < size_resi; j ++){
            cout << res[i][j];
            if(j != size_resi - 1) cout << " ";
        }
        cout << ") ";
    }
}

void input(){
    cin >> n;
    init();
    while(!last_configuration()){
        save();
        generate();
    }
    save();
    display();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cnt = 1;
        res.clear();
        input();
        cout << endl;
    }
}