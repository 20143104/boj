#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 1 2 1 3 1 2 1
int N, arr[2002], M, S, E;
int dp[2002][2002];

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    for(int i=1; i<=N; i++)
        dp[i][i] = 1;
    for(int i=1; i<N; i++){
        if(arr[i] == arr[i+1])
            dp[i][i+1] = 1;    
    }

    
    for(int len = 3; len <=N; len++){
        for(int s =1; s<=N-len + 1; s++){
            int e = s + len - 1;
            if(arr[s] == arr[e] && dp[s+1][e-1])
                dp[s][e] = 1;
        }
    }

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
}