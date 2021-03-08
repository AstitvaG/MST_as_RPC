#include "IDL.h"
#include <stdio.h>
#include <string.h>

int compute_6(char *host, mpc_struct struct_args, int type)
{
	CLIENT *clnt;
	// float *result_1;
	// mpc_struct add_graph_6_arg;
	// float *result_2;
	// mpc_struct sub_6_arg;
	void *result_1;
	void *result_2;
	long *result_3;
	// mpc_struct mul_6_arg;
	// float *result_4;
	// mpc_struct div_6_arg;

	clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	if (type == 1)
	{
		result_1 = add_graph_6(&struct_args, clnt);
		if (result_1 == (void *)NULL)
			clnt_perror(clnt, "call failed");
		printf("Added graph!");
		clnt_destroy(clnt);
		return 0;
	}
	else if (type == 2)
	{
		result_2 = add_egde_6(&struct_args, clnt);
		if (result_2 == (void *)NULL)
			clnt_perror(clnt, "call failed");
		printf('Added edge!');
		clnt_destroy(clnt);
		return 0;
	}
	else if (type == 3)
	{
		result_3 = get_mst_6(&struct_args, clnt);
		if (result_3 == (long *)NULL)
			clnt_perror(clnt, "call failed");
		printf('Got result: ',*result_3);
		clnt_destroy(clnt);
		return *result_3;
	}
}


int main(int argc, char *argv[])
{
	char *host;
	host = argv[1];
	while (1)
	{
		char *oper;
		int graph_id, type = 0, args[3] = {};

		printf("Started client server...\n");
		scanf("%s", &oper);
		scanf("%d", &graph_id);
		if (oper == "add_graph")
		{
			scanf("%d", &args[0]);
			type = 1;
		}
		else if (oper == "add_edge")
		{
			type = 2;
			scanf("%d", &args[0]);
			scanf("%d", &args[1]);
			scanf("%d", &args[2]);
		}
		else if (oper == "exit")
			exit(0);
		else if (oper != "get_mst")
		{
			printf("Only allowed operations are:\n\tadd_graph\n\tadd_edge\n\tget_mst\n\texit");
			continue;
		}
		else
			type = 3;

		mpc_struct struct_args;
		memcpy(struct_args.args, args, sizeof(args));
		strcpy(struct_args.oper, oper);
		struct_args.graph_id = graph_id;

		printf("Answer= %f\n", compute_6(host, struct_args, type));
	}
	exit(0);
}
