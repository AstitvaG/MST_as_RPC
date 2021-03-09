#include <bits/stdc++.h>
#include "IDL.h"
using namespace std;

typedef set<pair<int, pair<int, int>>> my_set;

struct graph
{
	int n;
	my_set kset;
	vector<int> arr;
	vector<int> weight;
};
long long sum = 0;

int n;
my_set kset;
int arr[100001];
int weight[100001];

map<string, graph> graphs;

int find(int src)
{
	int hold = src;
	while (arr[src] != -1)
	{
		src = arr[src];
	}
	int temp;
	while (arr[hold] != -1)
	{
		temp = arr[hold];
		arr[hold] = src;
		hold = temp;
	}
	return src;
}

void uni(int x, int y)
{
	int rx = find(x);
	int ry = find(y);
	if (rx == ry)
		return;
	if (weight[rx] >= weight[ry])
	{
		arr[ry] = rx;
		weight[rx] += weight[ry];
	}
	else
	{
		arr[rx] = ry;
		weight[ry] += weight[ry];
	}
}

void kruskals()
{
	for (int i = 0; i < n - 1; i++)
	{
		int wt = (*kset.begin()).first;
		int u = (*kset.begin()).second.first;
		int v = (*kset.begin()).second.second;
		kset.erase(kset.begin());
		cout << wt << "=weight " << u << "=n1 " << v << "=n2 ";
		int ux = find(u);
		int vx = find(v);
		cout << ux << "=f1 " << vx << "=f2\n";
		if (ux != vx)
		{
			uni(u, v);
			sum += wt;
		}
	}
}

void *add_graph_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static char *result;
	printf("add graph called\n");
	/*
	 * insert server code here
	 */

	return (void *)&result;
}

void *add_egde_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static char *result;

	printf("add edge called\n");
	/*
	 * insert server code here
	 */

	return (void *)&result;
}

long *get_mst_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static long result;

	printf("get mst called\n");
	/*
	 * insert server code here
	 */

	return &result;
}