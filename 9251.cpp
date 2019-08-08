#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string str1, str2;

int dp[1002][1002];

int main(){
    cin >> str2 >> str1;
    int N = str1.size();
    int M = str2.size();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (str1[i-1] == str2[j-1]));
        }
    }
    cout << dp[N][M] << endl;
}