#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int numtestcases;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> numtestcases;
    while(numtestcases--){
        int a, b, n, w;
        cin >> a >> b >> n >> w;
        if(b-a != 0){
            if( (b*n-w) % (b-a) == 0 && (-a*n+w) % (b-a) == 0){
                int x = (b*n-w) / (b-a);
                int y = (-a*n+w) / (b-a);
                if(x > 0 && y > 0)
                    cout << x << " " << y << "\n";
                else
                    cout << -1 << "\n";
            } 
            else
                cout << -1 << "\n";
        }
        else{
            if(w == a*n && n ==2)
                cout << 1 << " " << 1 << "\n";
            else
                cout << -1 << "\n";
        }
    }
}