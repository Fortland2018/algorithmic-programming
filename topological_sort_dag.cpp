#include <bits/stdc++.h>
using namespace std;



void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<int> adj[]) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack, adj);
    }

    Stack.push(v);
}

void topologicalSort(vector<int> adj[], int V) { // lista sąsiedztwa dla i-tego wierzcholka, i-ty wierzcholek
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack, adj);

    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {

    int V; // Liczba wierzchołków w grafie
    cin >> V;
    vector<int> adj[V]; // Tworzenie listy sąsiedztwa

    // Dodawanie krawędzi do grafu
    // Tu dodaj swoje krawędzie
    int Z;
    cin >> Z;
    for(int i=0; i < Z; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Wywołanie funkcji sortowania topologicznego
    topologicalSort(adj, V);

    return 0;
}