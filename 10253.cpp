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
int gcd(int a, int b){
    int m = min(a, b);
    int M = 1;
    for(int i=m; i>=1; i--){
        if(a%i == 0 && b%i == 0){
            M = i;
            break;
        }
    }
    return M;
}
int main(){
    int numtestcases;
    cin >> numtestcases;
    
    while(numtestcases--){
        int a, b, henry;
        cin >> a >> b;
        while(a>1){
            if(b%a == 0) henry = b/a;
            else henry = b/a + 1;
            //cout << henry << " ";
            a= a*henry - b;
            b = henry*b;
            int g = gcd(a,b);
            a /=g; b/=g;
            //cout << b << " " << a << endl;
        }
        cout << b << "\n";
    }
}

