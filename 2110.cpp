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

using namespace std;

int house[200001];

int main(int argc, const char * argv[]) {
  int n, c;
  cin >> n >> c;

  for(int i=0; i<n; i++)
    cin >> house[i];

  sort(house, house + n);

  int left = 1, right = house[n-1] - house[0];
  int ans = 0;
  while(left <= right){
    int mid = (left + right) / 2;
    int cnt = 1;
    int prev = house[0];
    for(int i=1; i<n; i++){
      if(house[i] - prev >= mid){
        cnt++;
        prev = house[i];
      }
    }
    if(cnt >=c){
      left = mid + 1;
      ans = max(ans, mid);

    }
    else{
      right = mid - 1;
    }
  }
  cout<< ans << endl;
}
