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
### Run Cients with
```
sudo ./CLIENT localhost
```
Also, in place of local host we could use any IP address where the SERVER binary is executing.
