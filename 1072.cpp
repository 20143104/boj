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



int main(int argc, const char * argv[]) {
  long long x, y, z;
  while(cin >> x >> y){
    z = 100 * y/x;

    long long left = 0, right = 1000000000;
    long long ans = right;
    int flag = 0;
    while(left <= right){
      long long mid = (left + right) / 2;
      long long tmpz = 100 * (y+mid) / (x+mid);
      if(tmpz > z){
        ans = min(ans , mid);
        right = mid - 1;
        flag = 1;
      }
      else
        left = mid + 1;
      }
      if(flag)
        cout<< ans<<endl;
      else
        cout<< -1 <<endl;
  }
}
