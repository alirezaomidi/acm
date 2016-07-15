# Graph Theory and Algorithms

## 1. Graph Traversals
### 1.1 DFS (Depth First Search)
* For traversing a graph from a **distinguished source**.
* DFS with normal `visited` array will runs in **O(V+E)** on adjacency list and **O(V^2)** on adjacency matrix.
* Time complexity of backtracking is exponential.


#### Implementation with Stack

```c++
stack <int> dfs;
dfs.push(source);

vector <int> visited (vertexCount , 0);
visited[source] = 1;

while (!dfs.empty()){
    int current = dfs.top(); dfs.pop();

    for (i : iteration on adjList or adjMat in current'th row){
        if (!visited[i]){
            visited[i] = 1;
            dfs.push(i);
        }
    }
}
```

#### Implementation with Recursive Function

```c++

vi visited; // must be global or passed to function

void dfs (vertex){
    visited [vertex] = true;
    for (i : iteration on adjList or adjMat in current'th row){
        if (!visited [i]){
            dfs(i);
        }
    }
}

```
#### Relevant Problems
* **Finding Connected Components**:
```
visited --> component number (initially -1)
componentCounts time DFS
```

##### Flood Fill** Labeling and Counting Connected Components
##### Topological Sort
in a DAG is a linear ordering of vertices in a DAG so that u comes before v if (u --> v) was in DAG.
  * Find a possible sequence of madules that a University student has to take to fullfil the graduation requirements. **Solution:** ?????
* Bipartite Graph Check, **Solution:** Start with a vertex and choose a color then for all iteration change the color from previous vertex in tree then if you saw a vertex with same color then the graph is not bipartite. Also any graph with odd cycle is not bipartite.

##### Graph Edge Property Check ???
##### Articulation Points and Bridges
Given a undirected graph with sabotage cost to vertices and edges (intersection and roads), sabotage a vertex or an edge to break down the graph to more than one connected component and do it in the least cost way.
  * For **Articulation Point** iterate on all vertices. Remove them then do DFS to see if the number of CCs increases. The time complexity is O(V*(V+E))
  * Better algorithm with O(V+E) is Hopcroft-Tarjan algorithm




## 2. Minimum Spanning tree
Given an undirected and weighted Graph, select a subset of edges such that the graph still connected and total edge weights become Minimum.

* The best algorithm is **Kruscal** of O(E log E)

```c++
//asume we have these:
vector <pair <int , ii> > EdgeList;

sort (EdgeList.begin(), EdgeList.end()); // by weight

int mstCost = 0;
UnionFind UF(V);
for (int i = 0 ; i < E ; i++){
    pair <int , ii> front = EdgeList[i];
    if (!UF.isSameSet (front.second.first , front.second.second)){
        mstCost += front.first;
        UF.unionSet (front.second.first , front.second.second);
    }
}

```

## Single Source Shortest Path
Given a weighted graph G and a starting source vertex find the Shortest paths from s to every other vertices of G.

### Homogeneous Weighting (BFS)

```c++
queue <int> dfs;
dfs.push(source);

vector <int> visited (vertexCount , 0);
visited[source] = 1;

while (!bfs.empty()){
    int current = bfs.front(); bfs.pop();

    for (i : iteration on adjList or adjMat in current'th row){
        if (!visited[i]){
            visited[i] = 1;
            bfs.push(i);
        }
    }
}
```
* by changing the visited to parent we can save the path.

```c++
vector <int> path(vector <int> parent , i){
    vector <int> result
    while (parent[i] != i){
        result.push_back(i);
        i = parent [i];
    }
    return result;
}
```

### Dijkstra

```c++
vi dist(V, INF); dist[s] = 0;
// INF = 1B to avoid overflow
priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
while (!pq.empty()) {
    // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    // this is a very important check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second;
            // relax operation
            pq.push(ii(dist[v.first], v.first));
        } } }
// this variant can cause duplicate items in the priority queue
```

### Belman-Ford

```c++
vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++)
// relax all E edges V-1 times
for (int u = 0; u < V; u++)
// these two loops = O(E), overall O(VE)
for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    // record SP spanning here if needed
    dist[v.first] = min(dist[v.first], dist[u] + v.second);
    // relax
}
```

#### Negative Cycle Find

```c++
// after running the O(VE) Bellman Ford’s algorithm shown above
bool hasNegativeCycle = false;
for (int u = 0; u < V; u++)
// one more pass to check
for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dist[v.first] > dist[u] + v.second) // if this is still possible
    hasNegativeCycle = true;
    // then negative cycle exists!
}
printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");
```
