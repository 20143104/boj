#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int numtestcases, N, K, res;

int main(int argc, const char * argv[]) {
    ifstream instream("input.txt");
    
    instream >> numtestcases;
    
    while(numtestcases--){
        vector<int> data;
        
        instream >> N >> K;
        for(int i=0; i<N; i++){
            int a;
            instream >> a;
            data.push_back(a);
        }
        
        sort(data.begin(), data.end());

        int left= 0, right = N-1;
        int miv = 99999999;
        int res = 1;
        while(left <N-1 && right >0 && left < right){
            if(miv > abs(K-data[left]-data[right])){
                res = 1;
                miv = abs(K-data[left]-data[right]);
            }
            
            else if(miv == abs(K-data[left]-data[right])){
                res ++ ;
            }
            if(data[left] + data[right] > K)
                right --;
            else
                left ++;
        }
        cout << res << "\n";
    }
}
