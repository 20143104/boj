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

pair <int, int> data[200001];
priority_queue<int, vector<int>, greater<int> > pq;
int main(int argc, const char * argv[]) {
  int N;
  int ans = 1;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> data[i].first >> data[i].second;

  sort(data, data+N);

  int end = data[0].second;
  pq.push(end);
  for(int i=1; i<N; i++){
    if(pq.top() <= data[i].first){
      pq.push(data[i].second);
      pq.pop();
    }
    else{
      ans ++;
      pq.push(data[i].second);
    }
  }

  cout<<ans<<"\n";

}
