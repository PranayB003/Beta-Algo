
/*
Breadth first search is a graph traversal algorithm that starts traversing the graph from root node and explores all the neighbouring nodes. Then, it selects the nearest node and explore all the unexplored nodes. The algorithm follows the same process for each of the nearest node until it finds the goal.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

//Structure For Queue
struct queue
{
    int a[SIZE];
    int front;
    int rear;
};

//Creating the starting pointer of queue
struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//Checking the queue
int isEmpty(struct queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue *q, int value)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->a[q->rear] = value;
    }
}

//Deleting elements from the queue
int dequeue(struct queue *q)
{
    int temp;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        temp = -1;
    }
    else
    {
        temp = q->a[q->front];
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
            temp = -1;
        }
        q->front++;
    }
    return temp;
}

int main()
{
    int i, n, m;
    printf("Enter the value of vertices and egde:-");
    scanf("%d %d", &n, &m);

    //V is adjacency matrix of the given graph
    int v[n + 1][n + 1];
    for (i = 0; i < m; i++)
    {
        int x, y;
        printf("Enter edge %d: ", i);

        //For undirected Graph x and y both are destin as well as origin.
        scanf("%d %d", &x, &y);
        v[x][y] = 1;
        v[y][x]=1;
    }

    //vis array will check that a given vertices is not visited twice for bfs
    int vis[100000];

    //Setting all vertices to non-visited position
    for (i = 0; i < 100000; i++)
        vis[i] = 0;

    //Creating the queue for bfs
    struct queue *q = createQueue();
    enqueue(q, 1);
    vis[1] = 1;
    printf("BFS of Directed Graph:-\n");
    while (!isEmpty(q))
    {
        // Dequeue a vertex from queue and print it
        int node = dequeue(q);
        if (node == -1)
            break;
        printf("%d ", node);
        vis[node] = 1;
        for (int it = 1; it <= n; it++)
        {
            if (v[node][it] == 1 && !vis[it])
            {
                enqueue(q, it);
                vis[it] = 1;
            }
        }
    }
}
/*
Sample Input & Ouput:-
Enter the value of vertices and egde:-7 7
Enter edge 0: 1 2
Enter edge 1: 1 3
Enter edge 2: 2 4
Enter edge 3: 2 5
Enter edge 4: 2 6
Enter edge 5: 2 7
Enter edge 6: 7 3
BFS of Undirected Graph:-
1 2 3 5 4 6 7
*/