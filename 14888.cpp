#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, num[13], A, S, M, D, board[13];
long long MAX = -1000000000, MIN = 1000000000;
void init(){
    scanf("%lld", &N);
    for(int i=0; i<N; i++)
        scanf("%lld", &num[i]);
    scanf("%lld %lld %lld %lld", &A, &S, &M, &D);

    int i=0;
    for( ; i<A; i++)
        board[i] = 1;
    for(int k = 0; k<S; k++,i++)
        board[i] = 2;
    for(int k = 0; k<M; k++,i++)
        board[i] = 3;
    for(int k = 0; k<D; k++,i++)
        board[i] = 4;
}
void cal(vector<int> arr){
    long long res = 0;
    for(int i=-1; i<N-1; i++){
        if(i == -1)
            res += num[0];
        else{
            switch(board[arr[i]]){
                case 1:
                    res += num[i+1];
                    break;
                case 2:
                    res -= num[i+1];
                    break;
                case 3:
                    res *= num[i+1];
                    break;
                case 4:
                    res /= num[i+1];
                    break;
            }   
        }
    }
    MAX = max(MAX, res);
    MIN = min(MIN, res);
}
void dfs(vector<int> arr, int visit[]){
    if(arr.size() == N-1){
        cal(arr);
        return ;
    }

    for(int i=0; i<N-1; i++){
        if(visit[i] == 0){
            arr.push_back(i);
            visit[i] = 1;
            dfs(arr, visit);
            arr.pop_back();
            visit[i] = 0;
        }
    }
}
int main(){
    init();

    vector<int> tmp;

    int visit[13] = {0, };

    for(int i=0; i<N-1; i++){
        tmp.push_back(i);
        visit[i] = 1;
        dfs(tmp, visit);
        tmp.pop_back();
        visit[i] = 0;
    }    

    printf("%lld\n%lld", MAX, MIN);
}