#include <iostream>
#include <climits>

using namespace std;

// A utility function to find the vertex with minimum distance value
int minDistance(int dist[], bool sptSet[], int V) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int V) {
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t" << dist[i] << " \n";
}

// Function to implement Dijkstra's algorithm for a graph represented using adjacency matrix
void dijkstra(int graph[][100], int src, int V) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

// Driver's code
int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Input adjacency matrix
    int graph[V][100]; // Assuming maximum size of matrix as 100x100
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Source vertex
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    // Print the solution
    dijkstra(graph, src, V);

    return 0;
}
