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

int visit[100001];
int bfs(int n, int k){
  queue<int> q;
  q.push(n);
  int ans = 0;
  while(1){
    int size = q.size();
    for(int i=0; i<size; i++){
      int tmp = q.front();
      q.pop();
      if(tmp == k)
        return ans;
      if(tmp>0 && visit[tmp-1] == 0){
        q.push(tmp-1);
        visit[tmp-1] = 1;
      }
      if(tmp<100000 && visit[tmp+1] == 0){
        q.push(tmp+1);
        visit[tmp+1] = 1;
      }
      if(2*tmp<=100000 && visit[2*tmp] == 0){
        q.push(2*tmp);
        visit[2*tmp] = 1;
      }

    }
    ans++;
  }
}
int main(int argc, const char * argv[]) {
  int sta, end, ans = 0;
  cin >> sta >> end;
  cout << bfs(sta, end) << "\n";
}
