#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
   int V;  // Number of vertices in the graph
   vector<vector<int>> adj;  // Adjacency list representation of the graph

    public:
    // Constructor to initialize the graph with V vertices
     Graph(int V): V(V) 
    {
    adj.resize(V);  // Resize the adjacency list to accommodate V vertices
    }

    // Method to add an edge between vertices u and v
    void addEdge(int u, int v)
    {
    adj[u].push_back(v);  // Add vertex v to the adjacency list of vertex u
    adj[v].push_back(u);  // Add vertex u to the adjacency list of vertex v (for undirected graph)
    }

    void DFSUtil(int v, vector<bool>& visited) 
    {
    visited[v] = true; //  Mark the current vertex as visited
    cout << " " << v; //  Print the current vertex

    for (int u : adj[v])//  Iterate over the adjacent vertices of the current vertex
    { 
        if (!visited[u]) // Check if the adjacent vertex has not been visited
         { 
            DFSUtil(u, visited); //  Recursively call DFSUtil for the unvisited adjacent vertex
        }
    }
    }


    void DFS(int start) {
    vector<bool> visited(V, false);  //  Initialize a boolean vector 'visited' to track visited vertices
    DFSUtil(start, visited);         //  Call the DFSUtil() function to perform DFS traversal starting from 'start'
    }

   void BFS(int start) 
   {
    queue<int> q; // Create a queue to store vertices to be visited
    vector<bool> visited(V, false); // Create a boolean array to mark visited vertices

    q.push(start); // Enqueue the starting vertex
    visited[start] = true; // Mark the starting vertex as visited

     while (!q.empty()) { // Continue the loop until the queue is empty
        int v = q.front(); //  Dequeue a vertex from the front of the queue
        q.pop(); // Remove the  dequeued vertex from the queue
        cout << " " << v; //  Print the dequeued vertex

        for (int u : adj[v]) { // Iterate over the adjacent vertices of the dequeued vertex
            if (!visited[u]) { //  Check if the adjacent vertex has not been visited
                visited[u] = true; // Mark the adjacent vertex as visited
                q.push(u); // Enqueue the adjacent vertex
            }
        }
     }
    }   
};

int main()
{
    int V,E;
    cout<<"Enter number of vertex and edge:";
    cin>>V>>E;

    Graph g(V);

    cout<<"Edges:\n";
    int u,v;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter:";
        cin>>u>>v;
        g.addEdge(u,v);
    }

    int start;
    
    cout<<"Enter Starting edge:";
    cin>>start;

    cout<<"DFS:";
    g.DFS(start);

    cout<<"\nBFS:";
    g.BFS(start);

    return 0;
}
