#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// ---------------- NODE CLASS ----------------
class Node {
public:
    int id;
    int g;   // cost from start
    int f;   // total cost

    Node(int id, int g, int f) {
        this->id = id;
        this->g = g;
        this->f = f;
    }
};

// ---------------- COMPARATOR CLASS (NO STRUCT) ----------------
class Compare {
public:
    bool operator()(Node a, Node b) {
        return a.f > b.f;   // min-heap (lowest f first)
    }
};

// ---------------- A* FUNCTION ----------------
void aStar(vector<vector<pair<int,int>>> &adj,
           vector<int> &heuristic,
           int start, int goal) {

    int n = adj.size();

    vector<int> gCost(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<Node, vector<Node>, Compare> pq;

    gCost[start] = 0;

    pq.push(Node(start, 0, heuristic[start]));

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        int u = current.id;

        if (u == goal) break;

        for (auto edge : adj[u]) {

            int v = edge.first;
            int cost = edge.second;

            int newG = gCost[u] + cost;
            int newF = newG + heuristic[v];

            if (newG < gCost[v]) {
                gCost[v] = newG;
                parent[v] = u;

                pq.push(Node(v, newG, newF));
            }
        }
    }

    // ---------------- PRINT PATH ----------------
    cout << "Shortest Path: ";

    vector<int> path;
    for (int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";

    cout << "\nCost: " << gCost[goal] << endl;
}

// ---------------- MAIN ----------------
int main() {

    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    // Directed graph
    adj[0] = {{1, 1}, {2, 4}};
    adj[1] = {{3, 2}, {4, 5}};
    adj[2] = {{4, 1}};
    adj[3] = {};
    adj[4] = {};

    vector<int> heuristic = {7, 6, 2, 1, 0};

    int start = 0, goal = 4;

    aStar(adj, heuristic, start, goal);

    return 0;
}
