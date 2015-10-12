# Lab 3
Group 44, Kim Kling & Pontus Malm, MPCSN15

## a.1
We do receive the response immediately. Netstat tells us that the connection is established.

```
tcp        0      0 localhost:34644             localhost:5703              ESTABLISHED 
tcp        0      0 localhost:5703              localhost:34645             ESTABLISHED 
tcp        0      0 localhost:34645             localhost:5703              ESTABLISHED 
tcp        0      0 localhost:5703              localhost:34644             ESTABLISHED
```

## a.2

* a -> Error occurred
* b -> The socket closed successfully
* c -> The buffer contains the recieved data
* d -> The buffer is completely filled with the recieved data

1 is added to kTransferBufferSize to allow space for the zero termination to be added when everything is received.

## a.3
