
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<string> departments = {
    "General Medicine",
    "Cardiology",
    "Neurology",
    "Radiology",
    "Pathology",
    "Emergency"
};

vector<vector<int>> graph(6);

// Add connection between two departments
void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Display department connections
void displayGraph() {
    cout << "\nHospital Department Connections:\n";

    for (int i = 0; i < 6; i++) {
        cout << departments[i] << " -> ";

        for (int j : graph[i]) {
            cout << departments[j] << ", ";
        }

        cout << endl;
    }
}

// Breadth First Search (BFS)
void BFS(int start) {
    vector<bool> visited(6, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << departments[current] << " -> ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << "END\n";
}

// Depth First Search (DFS)
void DFS(int current, vector<bool>& visited) {
    visited[current] = true;

    cout << departments[current] << " -> ";

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

int main() {

    // Creating connections
    addEdge(0, 1);  
    addEdge(0, 2);  
    addEdge(0, 5);  
    addEdge(1, 3);  
    addEdge(2, 4);  
    addEdge(3, 4);  
    addEdge(4, 5); 

    
    displayGraph();

    // Accept starting department
    cout << "\nEnter starting department:\n";

    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << departments[i] << endl;
    }

    int choice;
    cout << "Enter choice (1-6): ";
    cin >> choice;

    if (choice < 1 || choice > 6) {
        cout << "Invalid choice!";
        return 0;
    }

    int start = choice - 1;

    // BFS Traversal
    BFS(start);

    // DFS Traversal
    vector<bool> visited(6, false);

    cout << "\nDFS Traversal: ";
    DFS(start, visited);
    cout << "END\n";

    return 0;
}
