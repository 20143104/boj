#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[3];
int dp_max[2][3];
int dp_min[2][3];
int row;



int main(int argc, const char * argv[]) {
    cin >> row;
    
    for(int k=0; k<3; k++){
        cin >> graph[k];
    }
    dp_max[0][0] = dp_min[0][0] = graph[0]; dp_max[0][1] = dp_min[0][1] = graph[1]; dp_max[0][2] = dp_min[0][2] = graph[2];
    
    for(int i=1; i<row; i++){
        for(int k=0; k<3; k++){
            cin >> graph[k];
        }
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + graph[0];
        dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + graph[1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + graph[2];
        
        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + graph[0];
        dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + graph[1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + graph[2];
        
        for(int j=0; j<3; j++){
            dp_max[0][j] = dp_max[1][j];
            dp_min[0][j] = dp_min[1][j];
        }
    }

    cout << max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) << " ";
    cout << min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) << "\n";
    
}
