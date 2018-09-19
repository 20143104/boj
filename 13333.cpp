#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int numtestcases;
int data[10001];
int main(int argc, const char * argv[]) {
    
    
    
        int N;
        cin >> N;
        
        for(int i=0; i<N; i++)
            cin >> data[i];
        
//         k번 이상 인용된 논문이 k개 이고 제외하고  k번 이하 인용된 n-k 개
        
        sort(data, data+N);
//        for(int i=0; i<N; i++)
//            cout << data[i] << " ";
//        cout << endl;
        
        
        for(int K = N; K >= 0; K--){
            int pos;
            for(pos = 0; pos <N; pos++){
                if(data[pos] >= K){
                    break;
                }
            }
            
            if(N-pos < K) continue;
            int cnt = 0;
            for(int i = 0; i< N-K; i++){
                if(data[i] <= K)
                    cnt ++;
            }
            if(cnt == N-K) cout << K << "\n";
            
        }
    
    }

