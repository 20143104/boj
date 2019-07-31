#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

long long int N, B, C, ans;
vector<long long int> A;

void solve(){
    for(long long int i=0; i<A.size(); i++){
        if(A[i] - B < 0)
            A[i] = 0;
        else{
            A[i] -= B;
            if(A[i]%C == 0){
                ans += A[i]/C;
            }
            else{
                ans += A[i]/C + 1;
            }
        }
    }


}
int main(){
    scanf("%lld", &N);
    ans = N;
    for(long long int i=0; i<N; i++){
        long long int t; scanf("%lld", &t);
        A.push_back(t);
    }

    scanf("%lld %lld", &B, &C);
    
    solve();
    printf("%lld\n", ans);
}