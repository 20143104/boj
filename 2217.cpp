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


vector<int> data;

int main(int argc, const char * argv[]) {
  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    int a; cin >> a;
    data.push_back(a);
  }

  sort(data.begin(), data.end(), greater<int>());

  int weight = data[0];

  for(int i=1; i<N; i++){
    while(1){
      if(data[i] > (weight)/(i+1)){
        weight++;
      }
      else
        break;
    }
  }
  cout<<weight<<endl;
}
