/*Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph.
This algorithm works for both the directed and undirected weighted graphs. If there is no direct distance between two vertices
then it is considered as -1*/

import java.util.*;

public class warshall
{
    int size; // the size of the graph
    
    void warshall_algorithm(int[][] g)
    {
        int i, j, k;
        int[][] dist=new int[size][size]; // A 2D array to store distance
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                dist[i][j]=g[i][j];
            }
        }
        for(k=0;k<size;k++)
        {
            for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    if((dist[i][k]+dist[k][j]<dist[i][j]) && (dist[i][k]!=-1) && (dist[k][j]!=-1)) // Finding the smallest distance between two vertexes if it exists
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        System.out.println("The distance graph is: \n"); // Printing the 2D array storing distance
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(dist[i][j]>=0)
                System.out.print(dist[i][j]+" ");
                else
                System.out.print("-1 ");
            }
            System.out.println();
        }
    }

    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        warshall obj=new warshall(); //Creation of an object
        System.out.println("Enter the number of vertices: ");
        obj.size=sc.nextInt();
        int[][] graph=new int[obj.size][obj.size];
        System.out.println("Enter the graph: ");
        for(int i=0;i<obj.size;i++)
        {
            for(int j=0;j<obj.size;j++)
            {
                graph[i][j]=sc.nextInt();
            }
        }
        obj.warshall_algorithm(graph); // Calling the Warshall algorithm function
    }
}

/*
Time Complexity:O(size^3)
Space Complexity:O(size^2)
Input/Output:-
Enter the number of vertices: 
4
Enter the graph: 
1
2
3
4
1
5
3
-3
-2
0
-1
5
-4
-3
2
-1
The distance graph is: 

1 2 3 -1 
-1 -1 3 -1 
-1 -1 -1 -1 
-1 -1 -1 -1 
*/
