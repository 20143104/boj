#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int numtestcases;

int main(int argc, const char * argv[]) {
    
    
    
    int box[1000][1000] = {0,}, visit[1000][1000] = {0,};
    
    int N, M;
    long long sum = 0;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin >> box[i][k];
            sum+= box[i][k];
        }
    }
    
    for(int i=0; i<M; i++){
        int max_v = 0, point_row, point_col;
        for(int k=0; k<N; k++){
            if(max_v < box[k][i]){
                max_v = box[k][i];
                point_row = k;
                point_col = i;
            }
        }
        visit[point_row][point_col] = 1;
    }
    
    for(int i=0; i<N; i++){
        int max_v = 0, point_row, point_col;
        for(int k=0; k<M; k++){
            if(max_v < box[i][k]){
                max_v = box[i][k];
                point_row = i;
                point_col = k;
            }
        }
        visit[point_row][point_col] = 1;
    }
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(visit[i][k] == 1)
                sum -= box[i][k];
        }
    }
    cout << sum << "\n";
    
    
}

