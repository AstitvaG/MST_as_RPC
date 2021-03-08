#include "IDL.h"
#include <stdio.h>
#include <string.h>

float compute_6(char *host, mpc_struct struct, int type)
{
	CLIENT *clnt;
	// float *result_1;
	mpc_struct add_graph_6_arg;
	float *result_2;
	mpc_struct sub_6_arg;
	float *result_3;
	mpc_struct mul_6_arg;
	float *result_4;
	mpc_struct div_6_arg;

	if (op == '+')
	{

		add_6_arg.num1 = a;
		add_6_arg.num2 = b;
		add_6_arg.operation = op;

		clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}

		result_1 = add_6(&add_6_arg, clnt);
		if (result_1 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}

		clnt_destroy(clnt);

		return (*result_1);
	}

	else if (op == '-')
	{
		sub_6_arg.num1 = a;
		sub_6_arg.num2 = b;
		sub_6_arg.operation = op;

		clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}

		result_2 = sub_6(&sub_6_arg, clnt);
		if (result_2 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}

		clnt_destroy(clnt);

		return (*result_2);
	}

	else if (op == '*')
	{
		mul_6_arg.num1 = a;
		mul_6_arg.num2 = b;
		mul_6_arg.operation = op;

		clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
		if (clnt == NULL)
		{
			clnt_pcreateerror(host);
			exit(1);
		}

		result_3 = mul_6(&mul_6_arg, clnt);
		if (result_3 == (float *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}

		clnt_destroy(clnt);

		return (*result_3);
	}

	else if (op == '/')
	{
		if (b == 0)
		{
			printf("You are trying to divide by zero. Please insert a valid number.\n");
			exit(0);
		}
		else
		{
			div_6_arg.num1 = a;
			div_6_arg.num2 = b;
			div_6_arg.operation = op;

			clnt = clnt_create(host, COMPUTE, COMPUTE_VERS, "udp");
			if (clnt == NULL)
			{
				clnt_pcreateerror(host);
				exit(1);
			}

			result_4 = div_6(&div_6_arg, clnt);
			if (result_4 == (float *)NULL)
			{
				clnt_perror(clnt, "call failed");
			}

			clnt_destroy(clnt);

			return (*result_4);
		}
	}
}

int main(int argc, char *argv[])
{
	char *host;
	host = argv[1];
	while (1)
	{
		char *oper;
		int graph_id, type = 0, args[4] = {};
		mpc_struct struct_args;

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
			scanf("%d", &args[3]);
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
		
		struct_args.
		printf("Answer= %f\n", compute_6(host, oper, graph_id, args));
	}
	exit(0);
}
