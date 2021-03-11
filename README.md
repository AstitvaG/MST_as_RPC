# MST_as_RPC
Implementation of Minimum Spanning Tree with Client-Server RPCs
### Dependencies
Tested on Ubuntu 20.04.1
- `rpcbind`:
```
sudo apt-get install rpcbind
```
### Compilation
```
make -f Makefile.MST
```
### Run server with
```
sudo ./SERVER
```
### Run Clients with
```
sudo ./CLIENT localhost
```
Also, in place of local host we could use any IP address where the SERVER binary is executing.
### File Structure
```
Assignment_3
├── CLIENT : 
        Client executable
├── input.txt : 
        Sample Input file used
├── Makefile.MST : 
        Makefile for building CLIENT and SERVER Executables
├── MST_client.cpp : 
        Code for CLIENT written here
├── MST_clnt.cpp : 
        File generated by `rpcgen` for client
├── MST.h : 
        Header file generated by `rpcgen` for defing RPC fuctions and Data types
├── MST_server.cpp : 
        Code for SERVER written here
├── MST_svc.cpp : 
        File generated by `rpcgen` for server
├── MST.x : 
        `Config` file fed to `rpcgen`
├── MST_xdr.cpp : 
        File generated by `rpcgen` for XDR
└── SERVER : 
        Server executable
```