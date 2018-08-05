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
#include <vector>

using namespace std;

pair<int,int> data[1000000];
int main(int argc, const char * argv[]) {
  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int a, b;
    cin >> a >> b;
    data[i] = pair<int,int>(a,b);
  }

  sort(data, data + n);
  int sta = data[0].first, end = data[0].second;
  int ans = 0;
  for(int i=0; i<n; i++){
    if(end < data[i].first){
      ans += end - sta;
      sta = data[i].first;
      end = data[i].second;
    }
    else
      end = max(end, data[i].second);
  }
  ans += end -sta;
  cout<<ans << "\n";
}
