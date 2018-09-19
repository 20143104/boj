#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> data;
int is(int num){
    for(int i=0; i<44; i++){
        for(int k=0; k<44; k++){
            for(int j=0; j<44; j++){
                if(data[i] + data[k] + data[j] == num)
                    return 1;
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here..
    ifstream instream;
    instream.open("input.txt");
    
    if(instream.fail())
        cout << "fail"<<endl;
    int numtestcases;
    
    instream >> numtestcases;
    for(int i=1; i<50; i++){
        int a = i * (i+1) / 2;
        data.push_back(a);
    }
    
    while(numtestcases--){
        int num;
        instream >> num;
        cout << is(num) << "\n";
    }
}
