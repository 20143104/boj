#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int M, N;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
const int n_ = 100 + 5;
bool visit[102][102];
char adj[102][102];

struct node {
	int x, y, w;
	node(int x, int y, int w) : x(x), y(y), w(w) {}
	bool operator <(node A)const { return w > A.w; }
};

int main() {
	priority_queue<node> pq;

  cin >> M >> N;
	for (int i = 0; i < N; i++) scanf("%s", adj[i]);

	pq.push(node(0, 0, 0));
	while (!pq.empty()) {
		node top = pq.top();
		pq.pop();
		if (top.x == N - 1 && top.y == M - 1) {
			printf("%d\n", top.w);
			break;
		}
		visit[top.x][top.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dir[i][0], ny = top.y + dir[i][1], nw = 0;
      if(adj[nx][ny] == '1') nw = top.w + 1;
      else nw = top.w;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny]) continue;
			pq.push(node(nx, ny, nw));
		}
	}

	return 0;
}
