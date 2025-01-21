#include <stdio.h>
#include <stdbool.h>

#define INF 1000000000

int tsp(int graph[4][4], int path[], bool visited[], int current, int n, int cost)
{
    if (n == 1)
    {
        return cost + graph[current][0]; // Return to the starting city
    }

    int minCost = INF;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            path[n - 1] = i;
            int newCost = tsp(graph, path, visited, i, n - 1, cost + graph[current][i]);
            minCost = (minCost < newCost) ? minCost : newCost;
            visited[i] = false;
        }
    }

    return minCost;
}

int main()
{
    // Example graph - replace this with your own adjacency matrix
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = 4; // Number of cities

    // Initialize path and visited arrays
    int path[n];
    bool visited[n];
    for (int i = 0; i < n; ++i)
    {
        path[i] = -1; // Initialize path with invalid values
        visited[i] = false;
    }

    // Start from the first city (index 0)
    path[0] = 0;
    visited[0] = true;

    // Find the minimum cost using the tsp function
    int minCost = tsp(graph, path, visited, 0, n, 0);

    // Output the result
    printf("Minimum Cost: %d\n", minCost);

    return 0;
}
