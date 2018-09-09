//
//  main.cpp
//  boj
//
//  Created by 조승현 on 2018. 9. 3..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, P, res;
vector<int> v;
int visit[101];

int main(){
    cin >> N >> P;
    
    visit[N] = 1;
    v.push_back(N);
    
    int point = N*N%P;
    
    while(visit[point] == 0){
        visit[point] = 1;
        v.push_back(point);
        point = point * N % P;
    }
    
    int i;
    for(i=0; i<v.size(); i++){
        if(v[i] == point)
            break;
    }
    
    cout << v.size() - i << endl;
}

