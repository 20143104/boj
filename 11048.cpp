#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int getmax(int a, int b){
  if(a>b)
    return a;
  return b;
}
int main(void){
  int row, col, n;
  scanf("%d %d", &row, &col);
  for(int i=1; i<=row; i++){
    for(int k=1; k<=col; k++){
      scanf("%d", &arr[i][k]);
    }
  }

  for(int i=1; i<=row; i++){
    for(int k=1; k<=col; k++){
      int result = getmax(dp[i-1][k-1], getmax(dp[i-1][k], dp[i][k-1]));
      dp[i][k] = result + arr[i][k];
    }
  }

  cout<<dp[row][col]<<endl;
}
