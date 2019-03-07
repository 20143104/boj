#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int numtestcases = 4;
int visit[101][101];
int main(int argc, const char * argv[]) {
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;


    while(numtestcases -- ){
        cin >> x1 >> y1 >> x2 >> y2;
        
    

        for(int i=x1; i<x2; i++){
            for(int k= y1; k<y2; k++){
                visit[k][i] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<101; i++){
        for(int k=0; k<101; k++){
            if(visit[i][k])
                cnt ++;
        }
    }
    cout << cnt << "\n";
    
}