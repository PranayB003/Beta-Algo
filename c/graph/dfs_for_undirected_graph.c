
/*
Depth first search (DFS) algorithm starts with the initial node of the graph G, and then goes to deeper and deeper until we find the goal node or the node which has no children. The algorithm, then backtracks from the dead end towards the most recent node that is yet to be completely unexplored.
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int vis[100000];
//V is adjacency matrix of the given graph
int v[100][100];

void DFS(int node)
{
    int j;

    //Printing the vertices
    printf("%d ", node);

    //Marking it to as visited
    vis[node] = 1;
    for (j = 1; j <= n; j++)
        if (!vis[j] && v[node][j] == 1)
            DFS(j);    //Going deep in the graph until we reach leaf element
}

int main()
{
    int i;
    printf("Enter the value of vertices:-");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int x, y;
        printf("Enter edge %d: ", i);

        //For undirected Graph x and y both are destin as well as origin.
        scanf("%d %d", &x, &y);
        v[x][y] = 1;
        v[y][x] = 1;
    }

    //Intiailzation of vis array as 0(non-visited vertices)
    for (i = 0; i < 100000; i++)
        vis[i] = 0;
    printf("DFS of Undirected Graph:-\n");
    DFS(1);
}
/*
Sample Input & Ouput:-
Enter the value of vertices and egde:-7
Enter edge 0: 1 2
Enter edge 1: 1 3
Enter edge 2: 2 4
Enter edge 3: 2 5
Enter edge 4: 2 6
Enter edge 5: 2 7
Enter edge 6: 7 3
DFS of Undirected Graph:-
1 2 4 5 6 7 3
*/