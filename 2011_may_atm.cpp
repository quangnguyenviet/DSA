#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, s;
int a[40], ans = 100;
void input(){
    cin >> n >> s;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
}
vector<bool> used(40, false);
int cnt = 0;
void back_track(int sum, int start){
    if(ans == 1) return;
    for(int j = start; j < n; j ++){
        if(used[j] == false){
            cnt ++;
            sum += a[j];
            used[j] = true;
            if(sum == s){
                ans = min(ans, cnt);
            }
            else if(sum < s && cnt < ans){
                back_track(sum, j + 1);
            }
            used[j] = false;
            sum -= a[j];
            cnt --;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 100;
        for(int i = 0; i < 40; i ++){
            used[i] = false;
        }
        input();
        sort(a, a + n);
        back_track(0, 0);
        if(ans == 100){
            cout << -1;
        }
        else cout << ans;
        cout << endl;

    }
}