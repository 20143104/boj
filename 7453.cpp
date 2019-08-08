#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[4001], B[4001], C[4001], D[4001], N;
long long ans;
vector<int> AB, CD;

void solve(){
    int len = AB.size();

    for(int i=0; i<len; i++){

        int l = 0, r = len;
        int lb, ub;
        long long search = -1 * AB[i];
        while(l < r){
            int mid = (l+r)/2;
            if(CD[mid] >= search)
                r = mid;
            else
                l = mid+1;
        }

        lb = r;

        l = 0; r = len;

        while(l < r){
            int mid = (l + r) / 2;
            if(CD[mid] > search)
                r = mid;
            else
                l = mid+1;
        }

        ub = r;

        ans += (ub - lb);
    }
}
int main(){
    scanf("%d", &N);
    int t;
    for(int i=0; i<N; i++){
        scanf("%d", &t); A[i] = t;
        scanf("%d", &t); B[i] = t;
        scanf("%d", &t); C[i] = t;
        scanf("%d", &t); D[i] = t;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(CD.begin(), CD.end());
    solve();
    cout << ans;
}