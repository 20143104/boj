#include <iostream>
#include <algorithm>
using namespace std;

int N, lego[1000001], num_lego;

// 1cm = 10^7nm

int inverse(double num){
    return num * 10000000;
}
int main(){
    while(scanf("%d", &N) != EOF){
    
    N = inverse(N);
    scanf("%d", &num_lego);
    for(int i=0; i<num_lego; i++)
        scanf("%d", &lego[i]);

    sort(lego, lego + num_lego);
    
    int l = 0, r = num_lego-1;
    bool chk = false;
    while(l < r){
        int sum = lego[l] + lego[r];
        
        if(sum > N)
            r--;
        else if(sum < N)
            l++;
        else{
            chk = true;
            break;
        }
            
    }

    if(chk)
        printf("yes %d %d\n", *(lego+l), *(lego+r));
    else
        printf("danger\n");
    }

}