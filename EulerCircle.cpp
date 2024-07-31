#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <getopt.h>
#include <algorithm>

// Class representing a graph
class Graph {
public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices);
    // Method to add an edge between two vertices
    void addEdge(int u, int v);
    // Method which returns if this edge exists
    bool hasEdge(int u, int v);
    // Method to check if the graph has an Eulerian circuit
    bool hasEulerianCircuit();
    // Method to find and print the Eulerian circuit
    void findEulerianCircuit();

private:
    int vertices; // Number of vertices in the graph
    std::vector<std::vector<int>> adjMatrix; // Adjacency matrix to represent the graph
    // Helper method to check if the graph is connected
    bool isConnected();
    // Depth First Search (DFS) to check connectivity
    void DFS(int v, std::vector<bool>& visited);
    // Helper method to find Eulerian path
    bool hasEulerianPathUtil(int v, std::vector<int>& circuit);
};

// Constructor implementation
Graph::Graph(int v) : vertices(v)
{
    // Initialize the adjacency matrix with zeros
    adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
}

bool Graph::hasEdge(int u, int v){
    return adjMatrix[u][v];
}

// Method to add an edge to the graph
void Graph::addEdge(int u, int v)
{
    adjMatrix[u][v] = 1; // Increment the edge count for u -> v
    adjMatrix[v][u] = 1; // Increment the edge count for v -> u

}

// Method to check if the graph is connected
bool Graph::isConnected()
{
    int i;
    std::vector<bool> visited(vertices, false);

    // Find a vertex with a non-zero degree
    for (i = 0; i < vertices; ++i)
    {
        if (std::count(adjMatrix[i].begin(), adjMatrix[i].end(), 0) != vertices)
        {
            break;
        }
    }
    if (i == vertices)
    {
        return true; // If no such vertex is found, return true
    }

    DFS(i, visited); // Perform DFS from the first non-zero degree vertex

    // Check if all non-zero degree vertices are visited
    for (i = 0; i < vertices; ++i)
    {
        if (!visited[i] && std::count(adjMatrix[i].begin(), adjMatrix[i].end(), 0) != vertices)
        {
            return false;
        }
    }
    return true;
}

// DFS implementation to check connectivity
void Graph::DFS(int v, std::vector<bool>& visited)
{
    visited[v] = true; // Mark the current vertex as visited
    // Visit all adjacent vertices
    for (int i = 0; i < vertices; ++i)
    {
        if (adjMatrix[v][i] && !visited[i])
        {
            DFS(i, visited);
        }
    }
}

// Method to check if the graph has an Eulerian circuit
bool Graph::hasEulerianCircuit()
{
    if (!isConnected())
    {
        return false; // Graph must be connected
    }

    // All vertices with non-zero degree must have an even degree
    for (int i = 0; i < vertices; ++i)
    {
        if (std::count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

// Helper method to find Eulerian path
bool Graph::hasEulerianPathUtil(int v, std::vector<int>& circuit)
{
    // Explore all edges from the current vertex
    for (int u = 0; u < vertices; ++u)
    {
        if (adjMatrix[v][u])
        {
            adjMatrix[v][u]--; // Remove the edge v -> u
            adjMatrix[u][v]--; // Remove the edge u -> v
            hasEulerianPathUtil(u, circuit); // Recursively find the path from u
        }
    }
    circuit.push_back(v); // Add the vertex to the circuit
    return true;
}

// Method to find and print the Eulerian circuit
void Graph::findEulerianCircuit()
{
    if (!hasEulerianCircuit())
    {
        std::cout << "Euler's circle does not exist" << std::endl;
        return;
    }

    std::vector<int> circuit;
    hasEulerianPathUtil(0, circuit); // Find the Eulerian path starting from vertex 0

    std::cout << "Here is Euler's circle: ";
    for (auto it = circuit.rbegin(); it != circuit.rend(); ++it)
    {
        std::cout << *it << " "; // Print the Eulerian circuit
    }
    std::cout << std::endl;
}

// Function to generate a random graph
void generateRandomGraph(Graph& g, int edges, int vertices, unsigned int seed)
{
    srand(seed); // Seed the random number generator
    for (int i = 0; i < edges; ++i)
    {
        int u = rand() % vertices; // Random vertex u
        int v = rand() % vertices; // Random vertex v
        // Check no duplicating edges or a vertex with an edge to itself
        if (g.hasEdge(u,v) || u == v)
        {
            i--;
        }
        else
        {
            std::cout << "edge : " << u <<","<< v << "\n";
            g.addEdge(u, v); // Add edge u -> v and v -> u to the graph
        }
        
    }
}

int main(int argc, char** argv)
{
    int vertices = 0;
    int edges = 0;
    int option;
    unsigned int seed = static_cast<unsigned int>(time(nullptr));

    // Parse command-line options
    while ((option = getopt(argc, argv, "v:e:s:")) != -1)
    {
        switch (option)
        {
            case 'v':
                vertices = std::atoi(optarg);
                break;
            case 'e':
                edges = std::atoi(optarg);
                break;
            case 's':
                seed = static_cast<unsigned int>(std::atoi(optarg));
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -v vertices -e edges [-s seed]" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    // Ensure vertices and edges are positive integers
    if (vertices <= 0 || edges <= 0) {
        std::cerr << "Error: invalid vertices or edges!" << std::endl;
        exit(EXIT_FAILURE);
    }

    Graph g(vertices); // Create a graph with the specified number of vertices
    generateRandomGraph(g, edges, vertices, seed); // Generate a random graph with the specified edges and vertices
    g.findEulerianCircuit(); // Find and print the Eulerian circuit

    return 0;
}
