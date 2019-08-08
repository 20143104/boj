#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[1002][1002], N, M;
pair<int, int> chk[1002][1002];
char ans[1002];

int main(){
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    N = str1.size();
    M = str2.size();
    for(int i=1; i<N; i++){
        for(int j=1; j<M; j++){
            if(dp[i-1][j] > dp[i][j-1]){
                chk[i][j] = make_pair(i-1, j);
                dp[i][j] = dp[i-1][j];
            }
            else{
                chk[i][j] = make_pair(i, j-1);
                dp[i][j] = dp[i][j-1];
            } 
            if(str1[i] == str2[j]){
                if(dp[i][j] < dp[i-1][j-1] + (str1[i] == str2[j])){
                    chk[i][j] = make_pair(i-1, j-1);
                    dp[i][j] = dp[i-1][j-1] + (str1[i] == str2[j]);
                }
            }
        }
    }
    int idx1 = N-1, idx2 = M-1;
    int cnt = dp[N-1][M-1];
    while(idx1>0 && idx2 >0){
        if(str1[idx1] == str2[idx2]){
            ans[cnt--] = str1[idx1];
            idx1--; idx2--;
        }
        else{
            int tmp_idx1 = chk[idx1][idx2].first;
            int tmp_idx2 = chk[idx1][idx2].second;

            idx1 = tmp_idx1;
            idx2 = tmp_idx2;
        }    
    }
    printf("%d\n", dp[N-1][M-1]);
    for(int i=1; i<=dp[N-1][M-1]; i++)
        printf("%c", ans[i]);
}

