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

using namespace std;

int N;
vector<int> v;

bool isok(){
    for(int i=0; i<v.size(); i++){
        if(v[i] != v[v.size()-1-i])
            return false;
    }
    return true;
}
int main(){
    
    int numtestcases;
    cin >> numtestcases;
    
    while(numtestcases--){
        bool chk = false;
        cin >> N;
        for(int i=2; i<65; i++){
            v.clear();
            int tmpn = N;
            while(tmpn>=i){
                v.push_back(tmpn%i);
                tmpn/=i;
            }
            v.push_back(tmpn);
           
            if(isok()){
                cout << 1 << "\n";
                chk = true;
                break;
            }
        }
        if(!chk)
            cout << 0 <<"\n";
    }
     
}
