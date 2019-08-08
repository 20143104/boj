#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M, tmp;
vector<int> has;
vector<int> result;

int lower_bound(int num){
    int l = 0;
    int r = N-1;
    while(l < r){
        int mid = (l + r) / 2;
        if(has[mid] >= num)
            r = mid;
        else l = mid+1;
    }
    return r;
}
int upper_bound(int num){
    int l = 0;
    int r = N-1;
    while(l < r){
        int mid = (l + r) / 2;
        if(has[mid] > num)
            r = mid;
        else  
            l = mid +1;
    }
    return r;
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        has.push_back(tmp);
    }

    sort(has.begin(), has.end());

    // for(int i=0; i<N; i++)
    //     cout << has[i] << " ";
    // cout << endl;

    // cout << upper_bound(2) << endl;

    // cout << lower_bound(2) << endl;

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &tmp);
        int ub = upper_bound(tmp);
        int lb = lower_bound(tmp);
        if(ub == N-1 && has[N -1] == tmp)
            ub++;
        result.push_back(ub - lb);
    
    }

    for(int i=0; i<M; i++)
        cout << result[i] << " ";

}