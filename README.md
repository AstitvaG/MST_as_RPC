# MST_as_RPC
Implementation of Minimum Spanning Tree with Client-Server RPCs
### Dependencies
Tested on Ubuntu 20.04.10
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
sudo ./IDL_server
```
### Run Cients with
```
sudo ./IDL_client localhost
```