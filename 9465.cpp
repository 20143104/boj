#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#include <queue>
#include <vector>
#define INF 0x7fffffff

using namespace std;

int dp[100001][3];
int arr[100001][2];
int numtestcases;

int min(int a, int b){
  if(a>b)
    return b;
  return a;
}
int max(int a, int b){
  if(a<b)
    return b;
  return a;
}
int main(void){
  cin >> numtestcases;
  while(numtestcases--){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
      cin >> arr[i][0];
    for(int i=0; i<n; i++)
      cin >> arr[i][1];

    dp[0][0] = 0;
    dp[0][1] = arr[0][0];
    dp[0][2] = arr[0][1];

    for(int i=1; i<n; i++){
      dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      dp[i][0] = max(dp[i][0], dp[i-1][2]);
      dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + arr[i][0];
      dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + arr[i][1];
    }
    int result = max(dp[n-1][0], dp[n-1][1]);
    result = max(result, dp[n-1][2]);
    cout<<result<<endl;
  }
}
