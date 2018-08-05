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


int arraya[200001];
int arrayb[200001];

int main(int argc, const char * argv[]) {
  int numa, numb;
  int cnt = 0;
  cin >> numa >> numb;
  for(int i=0; i<numa; i++)
    cin>>arraya[i];

  for(int i=0; i<numb; i++)
    cin >> arrayb[i];

  sort(arraya, arraya + numa);
  sort(arrayb, arrayb + numb);

  for(int i=0; i<numa; i++){
    int left = 0, right = numb -1;
    while(left<=right){
      int mid = (left+right) / 2;

      if(arrayb[mid] == arraya[i]) {
        cnt++;
        break;
      }
      else{
        if(arrayb[mid] > arraya[i]) right = mid -1;
        else left = mid + 1;
      }
    }
  }
  cout << numa+numb-cnt-cnt<<endl;


}
