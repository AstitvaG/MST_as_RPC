#include "IDL.h"
#include <bits/stdc++.h>

using namespace std;

void compute_6(char *host, mpc_struct struct_args, int type)
{
	CLIENT *clnt;
	void *result_1;
	void *result_2;
	long *result_3;

	clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		return;
	}
	if (type == 1)
	{
		result_1 = add_graph_6(&struct_args, clnt);
		if (result_1 == (void *)NULL)
			clnt_perror(clnt, "call failed");
		clnt_destroy(clnt);
		return;
	}
	else if (type == 2)
	{
		result_2 = add_egde_6(&struct_args, clnt);
		if (result_2 == (void *)NULL)
			clnt_perror(clnt, "call failed");
		clnt_destroy(clnt);
		return;
	}
	else if (type == 3)
	{
		result_3 = get_mst_6(&struct_args, clnt);
		if (result_3 == (long *)NULL)
			clnt_perror(clnt, "call failed");
		clnt_destroy(clnt);
		cout << "Result = " << *result_3 << endl;
	}
}

int main(int argc, char *argv[])
{
	char *host;
	host = argv[1];
	string oper, graph_id;
	int type = 0, args[3] = {};

	// printf("Started client server...\n");

	string line;
	while (getline(cin, line))
	{
		// istringstream(line);
		cout << "Line::" << line << endl;
		cin.rdbuf(istringstream(line).rdbuf());
		cin >> oper >> graph_id;
		if (oper == "add_graph")
		{
			cin >> args[0];
			type = 1;
		}
		else if (oper == "add_edge")
		{
			type = 2;
			cin >> args[0] >> args[1] >> args[2];
		}
		else if (oper == "exit")
			return 0;
		else if (oper == "get_mst")
			type = 3;
		else
		{
			printf("Only allowed operations are:\n\tadd_graph\n\tadd_edge\n\tget_mst\n\texit\n");
			continue;
		}

		mpc_struct struct_args;
		memcpy(struct_args.args, args, sizeof(args));
		memcpy(struct_args.graph_id, graph_id.c_str(), sizeof(graph_id.c_str()));
		compute_6(host, struct_args, type);
		cout << "Line::" << line << endl;
	}
	return 0;
}
