//kruskal's algorithm for minimum spanning tree (for weighted, undirected, connected graphs)
//it is a greedy algorithm in which:
//1. first sort the edges in increasing order of weights
//2. traverse through the array and check if adding the edge causes a cycle
// if no, add the edge
//we represent the graph as a collection of edges and use custom comparator to sort the edges as per the weights

struct Edge
{
    int src, dest, wt;
    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

bool myCmp(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}

int Kruskal(vector<Edge> &arr)
{
    const int v = arr.size();
    sort(arr.begin(), arr.end(), myCmp);
    vector<int> parent(v, 0);
    vector<int> rank(v, 0);
    int res = 0;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0, s = 0; i < v - 1; i++)
    {
        Edge e = arr[i];
        int x = find(e.src);
        int y = find(e.dest);
        if (x != y)
        {
            res += e.wt;
            Union(x, y);
            s++;
        }
    }
    return res;
}

int main()
{
    int v = 5;
    // vector<vector<int>> graph(v, vector<int>(v, 0));
    vector<Edge> arr;
    //add edges using struct here: arr.push_back(Edge(s, d, w));
    int res = Kruskal(arr);
    cout << res;
    return 0;
}