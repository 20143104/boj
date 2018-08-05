//
//  main.cpp
//  boj
//
//  Created by 조승현 on 2018. 7. 12..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int world[10001];
/*
int max (int a, int b){
  if(a>b)
    return a;
  return b;
}*/
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n;

    int max_int = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
      cin >> world[i];
      sum += world[i];
      max_int = max(max_int, world[i]);
    }

    cin >> m;

    if(sum <= m){
      cout<< max_int<<endl;
      return 0;
    }

    int left = 0;
    int right = max_int;
    int ans = 0;
    while(left <= right){
      int mid = (left + right) / 2;
      int result = 0;
      for(int i=0; i<n; i++){
        if(world[i] > mid)
          result += mid;
        else
          result += world[i];
      }

      if(result > m)  right = mid-1;
      else {
        left = mid+1;
        ans = max(ans, mid);
      }

    }
    cout<< ans<<endl;
}
