//
//  main.cpp
//  boj
//
//  Created by 조승현 on 2018. 7. 12..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int visit[101];
int data[101];

int main(int argc, const char * argv[]) {
  int N, K;
  int ans = 0;

  cin >> N >> K;
  for(int i=0; i<K; i++)
    cin >> data[i];

  for(int i=0; i<K; i++){
    int use = 0;
    for(int j=0; j<N; j++){
      if(visit[j] == data[i]){
        use = 1;
        break;
      }
    }
    if(use == 1)
      continue; // 꽂혀있으면 넘어가기

    use = 0; //꽂혀있지 않으면
    for(int j=0; j<N; j++){
      if(visit[j] ==0){
        visit[j] = data[i];
        use = 1;
        break;
      }
    }
    if(use == 1) // 비어있는 코드가 있으면 넘어가기
      continue;

    //비어있는 코드가 없다면 가장 나중에 사용될 코드를 뽑자
    int swap = 0, val = -1;
    for(int j=0; j<N; j++){
      int tmp = 0;
      for(int k = i+1; k<K; k++){
        if(visit[j] == data[k])
          break;
        else
          tmp++;
      }
      if(tmp > val){
        swap = j;
        val = tmp;
      }
    }
    ans ++;
    visit[swap] = data[i];
  }
  cout << ans << "\n";
}
