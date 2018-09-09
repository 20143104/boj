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

int main(){
    int numtestcases;
    cin >> numtestcases;
    while(numtestcases--){
        int N, M = 0;
        int card[10001] = {0,};

        cin >> N;
        for(int i=0; i<N; i++)
            cin >> card[i];
        
        sort(card, card+N);
        
        M = max(M, card[N-1] * card[N-2] * card[N-3]);
        M = max(M, card[0] * card[1] * card[N-1]);
        M = max(M, card[N-1] * card[N-2]);
        M = max(M, card[0] * card[1]);
        
        cout << M << endl;
    }
}
