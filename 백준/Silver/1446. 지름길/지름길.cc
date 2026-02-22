#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

void Dijkstra(int D, vector<Edge>& edges)
{
    vector<int> dist(D+1);
    for(int i=0; i<=D; i++)
        dist[i] = i;
    
    for (Edge e : edges)
    {
        if(dist[e.v] > dist[e.u] + e.w)
        {
            dist[e.v] = dist[e.u] + e.w;
            for(int i = 1; e.v+i<=D; i++)
                dist[e.v+i] = min(dist[e.v+i], dist[e.v]+i);
        }
    }
    
    cout << dist[D];
}

bool cmp(const Edge& a, const Edge& b) {
    if(a.u != b.u)
        return a.u < b.u;
    if(a.v != b.v)
        return a.v < b.v;
    return a.w < b.w;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, D;
    cin >> N >> D;
    
    int u, v, w;
    vector<Edge> edges;
    for(int i=0; i<N; i++)
    {
        cin >> u >> v >> w;
        if(u > D || v > D || w > v-u) continue;
        edges.push_back({u, v, w});
    }
    
    sort(edges.begin(), edges.end(), cmp);
    
    Dijkstra(D, edges);

    return 0;
}