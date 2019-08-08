#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, K, ans;

int main(){
    scanf("%d %d", &N, &K);

    int l = 1;
    int r = K;

    while(l <= r){
        // cout << l << " " << r << endl;
        // cout << ans << endl;
        int mid = (l+r) / 2;
        int cnt = 0;
        for(int i=1; i<=N; i++)
            cnt += min(N, mid / i);
        cout << l << " " << r << endl;
        cout << mid << endl;
        cout << cnt << endl;
        if(cnt >= K){
            r = mid -1; ans = mid;
        }
        else
            l = mid +1;
        
    }

    cout << ans;
    


}