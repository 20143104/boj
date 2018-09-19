//
//  main.cpp
//  algorithm
//
//  Created by 조승현 on 2018. 9. 6..
//  Copyright © 2018년 csh. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here..
    ifstream instream;
    instream.open("input.txt");
    
    if(instream.fail())
        cout << "fail"<<endl;
    int A, B, V;
    
    instream >> A >> B >> V;
    
    V = V-A;
    int num = A-B;
    
    if(V % num == 0 ){
        cout << V/num+1 << "\n";
    }
    else{
        cout << V/num+2 << "\n";
    }
    
    return 0;
}
