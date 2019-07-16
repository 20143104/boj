#include<iostream>
#define MAX_SIZE 13
using namespace std;
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int K;
 
void dfs(int start, int depth) {
    
    if(depth == 6) {            
        for(int i=0; i<6; i++) {
            cout << combi[i] << " "; 
        }
        cout << "\n";
        return;
    }                                   
    for(int i=start; i<K; i++) {    
        combi[depth] = lotto[i];    
        dfs(i+1, depth+1);    
    }
}
 
int main() {
    while( cin >> K && K){
        for(int i=0; i<K; i++){
            cin >> lotto[i];
        }
        dfs(0, 0);
        cout << "\n";
    }
    return 0;
}
