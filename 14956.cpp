#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K, numtestcases, pos, cnt = 1;
vector<pair<int, int> > v;

void solve(int size, int x, int y, int dir){
	if(size == 2){
		if(dir == 1){
			v.push_back(make_pair(x, y));
			v.push_back(make_pair(x+1, y));
			v.push_back(make_pair(x+1, y+1));
			v.push_back(make_pair(x, y+1));
		}
		else if(dir == 2){
			v.push_back(make_pair(x, y));
			v.push_back(make_pair(x, y+1));
			v.push_back(make_pair(x+1, y+1));
			v.push_back(make_pair(x+1, y));	
		}
		else if(dir == 3){
			v.push_back(make_pair(x+1, y+1));
			v.push_back(make_pair(x, y+1));
			v.push_back(make_pair(x, y));
			v.push_back(make_pair(x+1, y));
		}
		else{
			v.push_back(make_pair(x+1, y+1));
			v.push_back(make_pair(x+1, y));
			v.push_back(make_pair(x, y));
			v.push_back(make_pair(x, y+1));
		}
		return ;
	}

	
	if( dir == 2){
	//1사분면
		if( size * size / 4 >= pos){
			pos = pos;
			solve(size/2, x, y, 1);
		}
	//2사분면
		else if( size * size / 4 * 2 >= pos){
			pos = pos - size*size/4;
			solve(size/2, x, y + size/2, 2);
		}
	//3사분면
		else if( size * size / 4 * 3 >= pos){
			pos = pos - size*size/4*2;
			solve(size/2, x + size/2, y + size/2, 2);
		}
	//4사분면
		else{
			pos = pos - size * size/4 * 3;
			solve(size/2, x + size/2, y, 3);
		}
	}
	else if(dir == 1){
	//1사분면
		if( size * size / 4 >= pos){
			pos = pos;
			solve(size/2, x, y, 2);
		}
	//2사분면
		else if( size * size / 4 * 2 >= pos){
			pos -= size * size / 4;
			solve(size/2, x + size/2, y, 1);
		}
	//3사분면
		else if( size * size / 4 * 3 >= pos){
			pos -= size * size / 4 * 2;
			solve(size/2, x + size/2, y + size/2, 1);
		}
	//4사분면
		else{
			pos -= size * size / 4 * 3;
			solve(size/2, x, y+size/2, 4);
		}
	}
	else if(dir == 3){
	//1사분면
		if( size * size / 4 >= pos){
			pos = pos;
			solve(size/2, x+size/2, y+size/2, 4);
		}
	//2사분면
		else if( size * size / 4 * 2 >= pos){
			pos -= size * size / 4;
			solve(size/2, x, y + size/2, 3);
		}	
	//3사분면
		else if( size * size / 4 * 3 >= pos){
			pos -= size * size / 4 * 2;
			solve(size/2, x, y, 3);
		}	
	//4사분면
		else{
			pos -= size * size / 4 * 3;
			solve(size/2, x + size/2, y, 2);
		}
	}
	else {
	//1사분면
		if( size * size / 4 >= pos){
			pos = pos;
			solve(size/2, x+size/2, y+size/2, 3);
		}	
	//2사분면
		else if( size * size / 4 * 2 >= pos){
			pos -= size * size / 4;
			solve(size/2, x+size/2, y, 4);
		}	
	//3사분면
		else if( size * size / 4 * 3 >= pos){
			pos -= size * size / 4 * 2;
			solve(size/2, x, y, 4);
		}
	//4사분면
		else{
			pos -= size * size / 4 * 3;
			solve(size/2, x, y+size/2, 1);
		}
	}
	
}
int main(){
    cin >> numtestcases;
    while(numtestcases--){
		v.clear(); 
		cin >> N >> pos;
		solve(N, 1, 1, 2);
		if(pos == 0)
			pos = 4;
		cout << v[pos-1].first << " " << v[pos-1].second << "\n";
	}

	return 0;
}

