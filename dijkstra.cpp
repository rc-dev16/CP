#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w) {}
};

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Graph {
private:
    int vertices;
    vector<vector<Edge>> adjacencyList;
    
public:
    Graph(int V) : vertices(V) {
        adjacencyList.resize(V);
    }
    
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back(Edge(destination, weight));
    }
    
    vector<int> dijkstra(int source) {
        vector<int> distance(vertices, INT_MAX);
        vector<bool> visited(vertices, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        distance[source] = 0;
        pq.push({source, 0});
        
        while (!pq.empty()) {
            int u = pq.top().first;
            pq.pop();
            
            if (visited[u]) {
                continue;
            }
            
            visited[u] = true;
            
            for (const Edge& edge : adjacencyList[u]) {
                int v = edge.destination;
                int weight = edge.weight;
                
                if (!visited[v] && distance[u] != INT_MAX && 
                    distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({v, distance[v]});
                }
            }
        }
        
        return distance;
    }
    
    void printShortestPaths(int source, const vector<int>& distance) {
        cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < vertices; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Vertex " << i << ": INFINITY (Unreachable)\n";
            } else {
                cout << "Vertex " << i << ": " << distance[i] << "\n";
            }
        }
    }
};

int main() {
    int V = 6;
    Graph g(V);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);
    
    int source = 0;
    vector<int> distances = g.dijkstra(source);
    
    g.printShortestPaths(source, distances);
    
    return 0;
}
