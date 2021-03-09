# MST_as_RPC
Implementation of Minimum Spanning Tree with Client-Server RPCs
1. Install rpcbind
```
sudo apt-get install rpcbind
```
2. Compile with
```
rpcgen -a -C IDL.x
```
3. Run server with
```
sudo ./IDL_server
```
4. Run Cients with
```
sudo ./IDL_client localhost
```