#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 100001


int array[101][101];

int min(int a, int b){
	if(a<b)
		return a;
	return b;
}

int main(int argc, char* argv[]) {

	int city, bus;

	cin>>city>>bus;
	for(int i=1; i<=city; i++){
		for(int k=1; k<=city; k++){
			array[i][k] =  INF;
		}
	}
	for(int i=0; i<bus; i++){
		int a,b;
		cin >>a>>b;
		if(array[a][b]==0)
			cin >> array[a][b];
		else{
			int c;
			cin>> c;
			array[a][b] =min(array[a][b],c);
		}
	}

	for(int k=1; k<=city; k++){
		for(int i=1; i<=city; i++){
			for(int j=1; j<=city; j++){
				if(i==j);
				else if(array[i][j] > array[i][k] + array[k][j])
					array[i][j] = array[i][k] + array[k][j];

			}
		}
	}

	for(int i=1; i<=city; i++){
		for(int k=1; k<=city; k++){
			if(array[i][k]==INF)
				cout<<0<<" ";
			else
				cout<<array[i][k]<<" ";
		}
		cout<<endl;
	}

}
