#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, ans;
int T[18], P[18], dp[18];

int main(){

    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=N; i++)
        scanf("%d %d", &T[i], &P[i]);


    for(int i=N; i>=1; i--){
        if(i + T[i] > N+1){
            dp[i] = max(dp[i+1], 0);
            continue;
        }
        else if(i + T[i] == N+1){
            dp[i] = max(dp[i+1] , P[i]);
            continue;
        }
        ans = dp[i + T[i]];
        dp[i] = max(dp[i+1], ans + P[i]);
        ans = 0;

    }

    cout << dp[1] << endl;
    
}