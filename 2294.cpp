#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>
#include <vector>
#define INF 0x7fffffff

using namespace std;

int dp[10001];
int coin[101];
int n, k;

int min(int a, int b){
  if(a>b)
    return b;
  return a;
}

int main(void){
  cin >> n >> k;
  for(int i=0; i<n; i++)
    cin >> coin[i];

  for(int i=1; i<=k; i++){
    dp[i] = INF;
    for(int j=0; j<n; j++){
      int tmp = i - coin[j];
      if(tmp >= 0 && dp[tmp] != INF)
        dp[i] = min(dp[i], dp[tmp] + 1);
    }
  }
  if(dp[k] == INF)
    cout<<-1<<endl;
  else
    cout<<dp[k]<<endl;
  return 0;
}
