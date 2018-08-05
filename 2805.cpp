//
//  main.cpp
//  study
//
//  Created by 조승현 on 2018. 7. 12..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>

using namespace std;

long long height[1000001]={};
int main(int argc, const char * argv[]) {
    long long n,m;
    long long max = 0;
    long long ans = 0;
    long long left, right;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin>>height[i];
        if(max < height[i]) max = height[i];
    }
    //cout<< max<<endl;
    left = 0; right = max;
    
    while(left<=right){
        long long mid = (left+right) / 2;
        long long result = 0;
        for(int i=0; i<n; i++){
            if(mid < height[i])
                result += height[i] - mid;
        }
        
        
        if(result >= m){
            if(ans < mid)
                ans = mid;
            left = mid + 1;
        }
        else{
            right = mid -1;
        }
    }
    
    cout<<ans<<endl;
    
}
