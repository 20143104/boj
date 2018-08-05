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

long long lan[10001];

int main(int argc, const char * argv[]) {
  int k, n;
  long long max_lan = 0;

  cin >> k >> n;

  for(int i=0; i<k; i++){
    cin >> lan[i];
    max_lan = max(lan[i], max_lan);
  }

  long long left = 1, right = max_lan;
  long long ans = 0;

  while(left <= right){
    long long mid = (left + right) / 2;
    long long result = 0;
    for(int i=0; i<k; i++){
      result += lan[i] / mid;
    }

    if(result >= n){
      if(ans < mid)
        ans = mid;
      left = mid + 1;
    }
    else
      right = mid - 1;
  }
  cout<< ans << endl;
}
