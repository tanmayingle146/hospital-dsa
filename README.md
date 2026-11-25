# Hospital DSA

A simple C++ implementation that models a hospital department network using an undirected graph. It provides BFS and DFS traversals starting from a department selected by the user.

## Departments

- General Medicine
- Cardiology
- Neurology
- Radiology
- Pathology
- Emergency

## Features

- Displays department connections
- Performs Breadth First Search (BFS)
- Performs Depth First Search (DFS)
- Accepts a starting department from the menu

## Run

```bash
g++ hospital.cpp -o hospital
./hospital
```

On Windows:

```bash
hospital.exe
```

## Data Structures

- `vector<string>`: stores department names
- `vector<vector<int>>`: stores the graph using an adjacency list
- `queue<int>`: supports BFS traversal
- `vector<bool>`: tracks visited departments
