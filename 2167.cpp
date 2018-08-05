#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[301][301];
int arr[301][301];
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
      int value;
      scanf("%d", &value);
      dp[i][k] = dp[i-1][k] + dp[i][k-1] -dp[i-1][k-1] + value;
    }
  }

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    int result = 0;
    int x1,x2,y1,y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    result=dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1];
    cout<<result<<endl;
  }
}
