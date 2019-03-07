#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int data[31];


int main(int argc, const char * argv[]) {
    for(int i=0; i<28; i++){
        int a;
        cin >> a;
        data[a] = 1;
    }

    for(int i=1; i<=30; i++){
        if(data[i] == 0)
            cout << i << "\n";
    }
}