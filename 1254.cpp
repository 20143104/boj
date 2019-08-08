#include <iostream>
#include <cstring>
using namespace std;

string str;
int N, dp[1001][1001];

void is_palin(){
    for(int i=1; i<=N; i++)
        dp[i][i] = 1;
    
    for(int i=1; i<N; i++){
        if(str[i] == str[i+1])
            dp[i][i+1] = 1;
    }

    for(int len = 3; len<=N; len++){
        for(int s = 1; s<=N - len + 1; s++){
            int e =  s + len -1;
            if(str[s] == str[e] && dp[s+1][e-1])
                dp[s][e] = 1;
        }
    }
}
int main(){
    cin >> str;
    str = " " + str;
    N = str.size();
    
    is_palin();        

    int idx = 987654321;
    for(int i=1; i<N; i++){
        if(dp[i][N-1])
            idx = min(idx, i);
    }
    
    printf("%d", N + idx -2);
}