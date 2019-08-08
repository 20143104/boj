#include <iostream>
#include <cstring>

#define INF 987654321;

using namespace std;


int N, arr[5001], dp[5001][5001];
int solve(int s, int e){
    if(s > e)
        return 0;

    if(dp[s][e] != -1)
        return dp[s][e];
    
    if(arr[s] == arr[e])
        return dp[s][e] = solve(s+1, e-1);
    else
        return dp[s][e] = min(solve(s+1, e) + 1, solve(s, e-1) + 1);
    
}
int main(){
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    memset(dp, -1, sizeof(dp));

    printf("%d", solve(1, N));
    
}