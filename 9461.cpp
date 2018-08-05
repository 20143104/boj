#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

long long int dp[101];
int arr[1001];
int getmax(int a, int b){
  if(a>b)
    return a;
  return b;
}
int main(void){
  int numtestcases;
  scanf("%d", &numtestcases);
  dp[0]= 1;
  dp[1]= 1;
  dp[2] =1;
  while(numtestcases--){
    int n;
    scanf("%d", &n);
    for(int i=3; i<n; i++){
      dp[i] = dp[i-3] + dp[i-2];
    }
    cout<<dp[n-1]<<endl;
  }
}
