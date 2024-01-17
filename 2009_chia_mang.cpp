#include <bits/stdc++.h>
using namespace std;
int n, k, a[30], val;
int ans = 0;
vector<int> used(30, 0);
void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
}
void back_track(int sum, int cnt, int start){
    if(cnt == k){
        ans = 1;
        return;
    }
    if(ans == 1) return;
    for(int j = start; j < n && sum <= val; j ++){
        if(used[j] == 0){
            sum += a[j];
            used[j] = 1;
            if(sum == val){
                back_track(0, cnt + 1, 0);
            }
            else if(sum < val){
                back_track(sum, cnt, j + 1);
            }
            sum -= a[j];
            used[j] = 0;
        }
    }
    
}
int solve(){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    if(sum % k != 0) return 0;
    else{
        val = sum / k;
        back_track(0, 0, 0);
        // cout << ans << endl;
        return ans;
    }
    

}
int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        for(auto &temp : used){
            temp = 0;
        }
        input();
        sort(a, a + n);
        cout << solve() << endl;
        
    }
}