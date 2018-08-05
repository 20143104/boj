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

int main(int argc, const char * argv[]) {
  int l, p, v;
  int i = 1;
  while(cin >> l >> p >> v){
    if( l == 0 && p == 0 && v == 0)
      return 0;

    int num = v/p;
    int end = v%p;

    if(end < l)
      cout << "Case "<< i << ": "<< num*l+end <<"\n";
    else
      cout << "Case "<< i << ": "<< num*l+l <<"\n";

    i++;
  }
}
