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


string ans[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(int argc, const char * argv[]) {
  int m, d;
  cin >> m >> d;

  int cnt = 0;

  for(int i=1; i<m; i++){
    switch(i){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        cnt+=31;
        break;
      case 4: case 6: case 9: case 11:
        cnt+=30;
        break;
      case 2:
        cnt+=28;
        break;
    }
  }
  cnt += d;
  cnt %= 7;
  cout<< ans[cnt]<< endl;
}
