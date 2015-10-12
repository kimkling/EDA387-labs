# Lab 3
Group 44, Kim Kling & Pontus Malm, MPCSN15

## a.1
We do receive the response immediately. Netstat tells us that the connection is established.

```
tcp    0     0 localhost:34644     localhost:5703      ESTABLISHED 
tcp    0     0 localhost:5703      localhost:34645     ESTABLISHED 
tcp    0     0 localhost:34645     localhost:5703      ESTABLISHED 
tcp    0     0 localhost:5703      localhost:34644     ESTABLISHED
```

## a.2
Below is our timing for the concurrent server and the iterative server. The concurrent server handles multiple clients well, and the time clients need to spend waiting is minimized.

```
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

```
Connect timing results for 100 successful connections
  - min time: 3.168992 ms
  - max time: 15000.369521 ms
  - average time: 5480.162936 ms
 (0 connections failed!)
Roundtrip timing results for 64 connections for 10000 round trips
  - min time: 230.742278 ms
  - max time: 7289.022922 ms
  - average time: 3230.925516 ms
```

## a.3
This attack is no longer possible since the server can serve multiple clients, at the same time.