#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------- EDGE CLASS ----------------
class Edge {
public:
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

// ---------------- DSU CLASS ----------------
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else {
                parent[pb] = pa;
                rank[pa]++;
            }
        }
    }
};

// ---------------- KRUSKAL FUNCTION ----------------
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskal(int V, vector<Edge> &edges) {

    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    int totalCost = 0;

    cout << "MST Edges:\n";

    for (auto e : edges) {

        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);

            cout << e.u << " - " << e.v << " : " << e.w << endl;

            totalCost += e.w;
        }
    }

    cout << "Total Cost = " << totalCost << endl;
}

// ---------------- MAIN ----------------
int main() {

    int V = 4;

    vector<Edge> edges;

    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 6));
    edges.push_back(Edge(0, 3, 5));
    edges.push_back(Edge(1, 3, 15));
    edges.push_back(Edge(2, 3, 4));

    kruskal(V, edges);

    return 0;
}
