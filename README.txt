!->notes,
*->IMP questions,
*|$*->asked in interview and needs revision,
^->logic needed,
$->needs revision easy to forget,
$$->needs revision and new concepts used,
#->Hard Question


## DSA Pattern Recognition

| Problem Clue                           | Technique                |
| -------------------------------------- | ------------------------ |
| Connected or adjacent cells/nodes      | DFS / BFS                |
| Shortest path in an unweighted graph   | BFS                      |
| Explore all possible choices           | Recursion / Backtracking |
| Overlapping subproblems; reuse results | Dynamic Programming (DP) |
| Count ways to reach a destination      | DP or Graph Algorithms   |

### Key Rules

* **DFS/BFS:** Explore connected cells or nodes.
* **DP:** Store and reuse results to avoid repeated calculations.
* **Large input:** Analyze time complexity; large constraints do not automatically imply DP.
* **Before choosing an algorithm:** Understand what the problem asks and identify its pattern.
