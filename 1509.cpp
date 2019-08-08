#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

string str;

int N, dp[2502][2502], cnt[2502];

int main(){
    cin >> str;
    
    str = " " + str;
    
    N = str.size() -1;

    for(int i=1; i<=N; i++)
        dp[i][i] = 1;
    for(int i=1; i<N; i++)
        dp[i][i+1] = (str[i] == str[i+1]);
    
    for(int len = 3; len <= N; len++){
        for(int s = 1; s<=N - len + 1; s++){
            int e = s + len - 1; 
            if(str[s] == str[e] && dp[s+1][e-1])
                dp[s][e] = 1;
        }
    }

    
    for(int i=1; i<=N; i++){
        cnt[i] = 987654321;
        for(int j=1; j<=i; j++){
            if(dp[j][i])
                cnt[i] = min(cnt[i], cnt[j-1] + 1);
        }
    }

    
    printf("%d", cnt[N]);
    
}