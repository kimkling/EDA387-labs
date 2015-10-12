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

```
Simulating 100 clients.
Establishing 100 connections... 
  successfully initiated 100 connection attempts!
Connect timing results for 100 successful connections
  - min time: 0.990722 ms
  - max time: 6.016197 ms
  - average time: 2.417829 ms
 (0 connections failed!)
Roundtrip timing results for 100 connections for 10000 round trips
  - min time: 2894.553222 ms
  - max time: 3669.167915 ms
  - average time: 3440.605040 ms
```

* a -> Error occurred
* b -> The socket closed successfully
* c -> The buffer contains the recieved data
* d -> The buffer is completely filled with the recieved data

1 is added to kTransferBufferSize to allow space for the zero termination to be added when everything is received.

## a.3
