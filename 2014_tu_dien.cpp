#include <bits/stdc++.h>
using namespace std;
int k, m, n;
char a[4][4];
vector<string> dict2;
set<string> dict;
void input(){
    cin >> k >> m >> n;
    string temp;
    for(int i = 0; i < k; i ++){
        cin >> temp;
        dict2.push_back(temp);
        dict.insert(temp);
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            cin >> a[i][j];
        }
    }
}

const int x_axis[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int y_axis[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string word;
vector<string> res;
bool visited[4][4];

void back_track(int i, int j){
    for(int k = 0; k < 8; k ++){
        int dx = i + x_axis[k];
        int dy = j + y_axis[k];
        if(dx >= 0 && dx < m && dy >=0 && dy < n && visited[dx][dy] == false){
            visited[dx][dy] = true;
            word += a[dx][dy];
            if(dict.count(word) == 1){
                res.push_back(word);
            }
            back_track(dx, dy);
            visited[dx][dy] = false;
            word.pop_back();
        }

    }
}

void solve(){
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            string temp;
            temp += a[i][j];
            word = temp;
            if(dict.count(temp) == 1){
                res.push_back(temp);
            }
            visited[i][j] = true;
            back_track(i, j);
            visited[i][j] = false;
        }
    }
    for(auto &temp : res){
        cout << temp << " ";
    }
    if(res.size() == 0) cout << -1;
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
        dict.clear();
        res.clear();
        dict2.clear();
    }
}