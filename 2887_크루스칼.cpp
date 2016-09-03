#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> each_vertex;
vector<each_vertex> ex, ey, ez;


typedef struct edge {
	int v1;
	int v2;
	int cost;
}edge;

int cmp(const void *a, const void *b) {
	const edge *x = (const edge *)a;
	const edge *y = (const edge *)b;
	return x->cost > y->cost ? 1 : x->cost < y->cost ? -1 : 0;
}

int *parent;
int *height;
edge *a;

int find(int n) {

	
	//for (int i = 0; i <= n; i++)
	//printf("%d 의 부모 :%d 높이 : %d \n", n, parent[n], height[n]);
	if (n == parent[n])
		return n;
	else {
		parent[n] = find(parent[n]);
		return parent[n];
	//	return parent[n] = find(parent[n]);
	}
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);

	if (height[x] < height[y]) {
		parent[x] = y;
	
	}
	else {
		parent[y] = x;
		if (height[x] == height[y]) {
			height[x]++;
		}
	}
//	printf("-----------------%d-%d연결 추가 -----------\n", x, y);
//	for (int i = 0; i < 5; i++)
//		printf("%d : 루트%d 높이%d\n", i, parent[i], height[i]);

}
long long kru(int n) {
	long long res = 0;
	int i;
	qsort(a, 3 * n-3, sizeof(edge), cmp);
	
	for (i = 0; i <  n; i++) {
		parent[i] = i;
		height[i] = 1;
	}


	i = 0;
	int cnt = 0;
	for (i = 0; i < 3 * n-3 ; i++) {
		int tp1 = a[i].v1;
		int tp2 = a[i].v2;

		int rootOftp1 = find(tp1);
		int rootOftp2 = find(tp2);

		if (rootOftp1 != rootOftp2) {
			uni(tp1, tp2);
			res += a[i].cost;
			cnt++;
			if (cnt == n - 1)
			break;
		}
		
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);

	a = (edge *) malloc(sizeof(edge)*3*n);
	parent = (int*)malloc(sizeof(int)*n);
	height = (int*)malloc(sizeof(int)*n);

	int i;
	for (i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		ex.push_back(each_vertex(x, i));
		ey.push_back(each_vertex(y, i));
		ez.push_back(each_vertex(z, i));
	}
	
	sort(ex.begin(), ex.end());
	sort(ey.begin(), ey.end());
	sort(ez.begin(), ez.end());


	for (i = 0; i < n - 1; i++) {
		a[i * 3 + 0].v1 = ex[i].second;
		a[i * 3 + 0].v2 = ex[i+1].second;
		a[i * 3 + 0].cost = ex[i+1].first- ex[i].first;

		a[i * 3 + 1].v1 = ey[i].second;
		a[i * 3 + 1].v2 = ey[i + 1].second;
		a[i * 3 + 1].cost = ey[i + 1].first - ey[i].first;

		a[i * 3 + 2].v1 = ez[i].second;
		a[i * 3 + 2].v2 = ez[i + 1].second;
		a[i * 3 + 2].cost = ez[i + 1].first - ez[i].first;
	}

	printf("%lld\n", kru(n));
}