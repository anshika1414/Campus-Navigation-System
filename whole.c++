#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define V 6 // Number of locations

string places[V] = {"Gate", "Library", "Hostel", "Canteen", "Auditorium", "Admin"};


int minDistance(int dist[], bool visited[]) {
    
    int min=INT_MAX, index=-1;
    for (int v=0; v<V; v++)
        if (!visited[v] && dist[v]<=min)
            min=dist[v], index=v;
    return index;
}


// Dijkstra to get distances and parent path
void dijkstra(int graph[V][V], int start, int dist[], int parent[]) {
    bool visited[V]={false};

    for (int i=0; i<V; i++) {
        dist[i]=INT_MAX;
        parent[i]=-1;
    }
    dist[start]=0;

    for (int count=0; count< V-1; count++) {
        int u=minDistance(dist, visited);
        if (u==-1) break;
        visited[u]=true;

        for (int v=0; v<V; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v]) {
                dist[v]=dist[u] + graph[u][v];
                parent[v]=u;
            }
        }
    }
}

// Print path from start to target
void printPath(int parent[], int j) {
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    cout<<" -> "<<places[j];
}


// Display all locations
void displayLocations() {
    cout<<"\nLocations:\n";
    for (int i=0; i<V; i++)
        cout<<i<<". "<<places[i]<<"\n";
}


// Find shortest distances from a location
void shortestFromLocation(int graph[V][V]) {
    int start;
    displayLocations();
    cout<<"Enter start location: ";
    cin>>start;

    int dist[V], parent[V];
    dijkstra(graph, start, dist, parent);

    cout<<"\nShortest distances from "<<places[start]<<":\n";
    for (int i=0; i<V; i++)
        cout<<places[start]<<" -> "<<places[i]<<" = "<<dist[i]<<" units\n";
}


// Find shortest path between two locations
void shortestPathBetween(int graph[V][V]) {
    int start, end;
    displayLocations();
    cout<<"Enter start location: ";
    cin>>start;
    cout<<"Enter destination location: ";
    cin>>end;

    int dist[V], parent[V];
    dijkstra(graph, start, dist, parent);

    cout<<"\nShortest path from "<<places[start]<<" to "<<places[end]<<":\n";
    cout<< places[start];
    printPath(parent, end);
    cout<<"\nDistance: "<<dist[end]<<" units\n";
}

// Update distance between two locations
void updateDistance(int graph[V][V]) {
    int loc1, loc2, distance;
    displayLocations();
    cout<<"Enter first location: ";
    cin>>loc1;
    cout<<"Enter second location: ";
    cin>>loc2;
    cout<<"Enter new distance (0 if no direct path): ";
    cin>>distance;

    graph[loc1][loc2]=distance;
    graph[loc2][loc1]=distance; // Since undirected graph
    cout<<"Distance updated successfully!\n";
}

int main() {
    int graph[V][V]={
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 3, 5, 0},
        {0, 7, 3, 0, 2, 6},
        {0, 0, 5, 2, 0, 4},
        {0, 0, 0, 6, 4, 0}
    };

    char cont='y';

    while(cont=='y' || cont=='Y') {
        int choice;
        cout<<"\n--- MENU ---\n";
        cout<<"1. Display all locations\n";
        cout<<"2. Find shortest distances from a location\n";
        cout<<"3. Find shortest path between 2 locations\n";
        cout<<"4. Update distance between two locations\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {
            case 1: displayLocations(); break;
            case 2: shortestFromLocation(graph); break;
            case 3: shortestPathBetween(graph); break;
            case 4: updateDistance(graph); break;
            case 5: 
                cout<<"Exiting...\n"; 
                cout<<"Thank you for using the Campus Navigation System. Have a great day!\n";
                return 0; 
            default: 
                cout<<"Invalid choice! Try again.\n";
        }

        cout<<"\nDo you want to continue (y/n)? ";
        cin>>cont;
    }


    cout<<"Thank you for using the Campus Navigation System. Have a great day!\n";
    return 0;
}
