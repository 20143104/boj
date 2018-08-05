#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

long long int dp[91][1];
int main(){
  int num;
  cin >> num;
  dp[1][0]=0;
  dp[1][1]=1;
  for(int i=2; i<=num; i++){
    dp[i][0]=dp[i-1][0]+dp[i-1][1];
    dp[i][1]=dp[i-1][0];
  }

  cout<<dp[num][0]+dp[num][1]<<endl;


}
