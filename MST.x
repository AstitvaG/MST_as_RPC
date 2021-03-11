/*The Config File  --- name MST.x*/

/*Structure to hold the values to be used in computation*/

struct mpc_struct{
    char graph_id[10];
    int args[3];
};

/*Programme, version and procedure definition*/

program COMPUTE{
    version COMPUTE_VERS{
        void ADD_GRAPH(mpc_struct)=1;
        void ADD_EGDE(mpc_struct)=2;
        long GET_MST(mpc_struct)=3;
    } = 6;
} = 456123789;