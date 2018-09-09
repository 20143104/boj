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
#include <stack>
#include <algorithm>
using namespace std;

int N, M;
long long score[1005], loss[1005];
void roop(){
    for(int i=0; i<1005; i++){
        score[i] = 0;
        loss[i] = 0;
    }
}
int main(){
    
    int numtestcases;
    cin >> numtestcases;
    
    while(numtestcases--){
        
        cin >> N >> M;
        for(int i=0; i<M; i++){
            int team_1, team_2, score_1, score_2;
            cin >>team_1 >> team_2 >> score_1 >> score_2;
            score[team_1] += score_1; loss[team_1] += score_2;
            score[team_2] += score_2; loss[team_2] += score_1;
        }
        long long M = 0, m = 1000;
        for(int i=1; i<=N; i++){
            long long tmp;
            if(score[i] ==0 && loss[i] == 0)
                tmp = 0;
            else
                tmp = score[i]*score[i]*1000/(score[i]*score[i]+loss[i]*loss[i]);
            M = max(M,tmp);
            m = min(m,tmp);
        }
        cout << M << "\n" << m << "\n";
        roop();
    }
    
}
