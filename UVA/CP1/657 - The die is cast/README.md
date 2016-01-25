# Runtime

[solve1.cc]
6754138     148 Chiahsun Cheng (chiahsun cheng)   Accepted  C++11   0.000


[1] 0.000


Note that would be tricky if you use double-DFS.

Consider 
  
    XX*XX

you may stop before before *


but if you not DFS all Xs first, for the below case

   XXX
   X *
   XXX

   XXX
     *

You may stop at * and thought the Xs afterwards are new X.


