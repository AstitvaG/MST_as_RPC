#include <bits/stdc++.h>
#include "IDL.h"
using namespace std;

typedef set<vector<int>> my_set;

struct graph
{
	int n;
	my_set kset;
	vector<int> arr;
	vector<int> weight;
};

map<string, graph> graphs;

int find(int src, graph &G)
{
	int hold = src;
	while (G.arr[src] != -1)
	{
		src = G.arr[src];
	}
	int temp;
	while (G.arr[hold] != -1)
	{
		temp = G.arr[hold];
		G.arr[hold] = src;
		hold = temp;
	}
	return src;
}

void uni(int x, int y, graph &G)
{
	int rx = find(x, G);
	int ry = find(y, G);
	if (rx == ry)
		return;
	if (G.weight[rx] >= G.weight[ry])
	{
		G.arr[ry] = rx;
		G.weight[rx] += G.weight[ry];
	}
	else
	{
		G.arr[rx] = ry;
		G.weight[ry] += G.weight[ry];
	}
}

long kruskals(graph &G)
{
	long sum = 0, number_edges = 0;
	G.arr = vector<int>(G.n, -1);
	G.weight = vector<int>(G.n, -1);
	auto kset = G.kset;
	vector<vector<int>> res;
	int size = kset.size();
	for (int i = 0; i < size; i++)
	{
		int wt = (*kset.begin())[0];
		int u = (*kset.begin())[1];
		int v = (*kset.begin())[2];
		kset.erase(kset.begin());
		cout << wt << "=weight " << u << "=n1 " << v << "=n2 ";
		int ux = find(u, G);
		int vx = find(v, G);
		cout << ux << "=f1 " << vx << "=f2\n";
		if (ux != vx)
		{
			uni(u, v, G);
			sum += wt;
			number_edges++;
			res.push_back({u, v, wt});
		}
	}
	for (auto j : res)
	{
		for (auto k : j)
			cout << k << " ";
		cout << endl;
	}
	return number_edges < G.n - 1 ? -1 : sum;
}

void *add_graph_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static char *result;
	cout << "Adding graph.." << endl;
	int n = argp->args[0];
	graphs[argp->graph_id] = {
		n,
		my_set(),
		vector<int>(n, -1),
		vector<int>(n, 1)};
	cout << "Graph added!" << endl;
	return (void *)&result;
}

void *add_egde_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static char *result;
	cout << "Adding edge.." << endl;
	graphs[argp->graph_id].kset.insert({argp->args[2], argp->args[0], argp->args[1]});
	cout << "Edge added!" << endl;
	return (void *)&result;
}

long *get_mst_6_svc(mpc_struct *argp, struct svc_req *rqstp)
{
	static long result;
	cout << "Getting MST" << endl;
	result = kruskals(graphs[argp->graph_id]);
	return &result;
}