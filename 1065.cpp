#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int data[3];
int main(){
  int N, ans = 0;
  cin >> N;
  for(int i=1; i<=N; i++){
    if(i < 100) ans = i;
    else if(i==1000) break;
    else{
      int a=0, tmp = i;
      while(tmp>0){
        data[a] = tmp%10;
        tmp /=10;
        a++;
      }
      if(data[0] - data[1] == data[1] - data[2]) ans ++;
    }
  }
  cout<< ans<<endl;
}
