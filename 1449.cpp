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

using namespace std;

int data[1001];

int main(int argc, const char * argv[]) {
  int L, N;
  int ans = 1;
  cin >> N >> L;

  for(int i=0; i<N; i++)
    cin >> data[i];

  sort(data, data+N);
  
  int sta = data[0], end = sta +L-1;

  for(int i=0; i<N; i++){
    if(data[i]<= end)
      continue;
    else{
      ans++;
      sta = data[i];
      end = sta +L-1;
    }
  }
  cout<< ans << "\n";
}
