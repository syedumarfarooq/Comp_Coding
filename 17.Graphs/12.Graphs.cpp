*//Dijkstra's algorithm will not work on negative cycle
// negative cycle a graph having a cycle and its weights are negative 
eg:1-2-3-1 where wheight from (1-2):-2,(2-3):-3,(3-1):-4 
  //so the algorithm will keep on updating as from 1-1 keeps on decreasing i.e intially 1 has 0 distance but when we choose path from 1-2-3-1
  // the distance will be -9 which is less than 0 it will update then agin after one more cycle it will be -18 so it wont stop it keeps on updating
//ans also for undirected graph which has negative weight as this also makes a negative cycle for eg: 1-2 is -3 then 2-1 is also -3 as it is
  // undirected graph
  *//dijkstra will not work on negative cycle and negative weight(this will be taught later by taking some cases where it fails)
  //until then it is working perfectly for negative weights directed graph eg;1-2-3 1-3 (1-2):5 (2-3):-10 (1-3):2
