/* Breadth-first search is an algorithm for searching a graph for a node that satisfies a given property. It starts at the tree root and 
explores all nodes at the present depth prior to moving on to the nodes at the next depth level.*/

import java.util.*;

public class BFS_undirected_graph
{
    private int v; //To store the number of vertices
    private LinkedList <Integer> adj[]; // Adjacency list to store the graph
    
    BFS_undirected_graph(int ver) // Constructor to initialize the global variables
    {
        v=ver;
        adj=new LinkedList[v];
        for(int i=0;i<v;i++)
            adj[i]=new LinkedList();
    }

    void addEdge(int x, int y)
    {
        adj[x].add(y); // Adding edge
        adj[y].add(x); // Adding edge
    }

    void BFSalgo(int s)
    {
        boolean vis[]=new boolean[v];
        LinkedList <Integer> queue =new LinkedList();
        vis[s]=true; // Marking it to as visited
        queue.add(s);
        while(queue.size()!=0)
        {
            s=queue.poll();
            System.out.print(s+" "); // Printing the vertices
            Iterator <Integer> it=adj[s].listIterator();
            while(it.hasNext())
            {
                int n=it.next();
                if(!vis[n])
                {
                    vis[n]=true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of vertices: ");
        int accept=sc.nextInt(); // Accepting number of vertices from user
        BFS_undirected_graph obj=new BFS_undirected_graph(accept); // Creating an object
        System.out.println("Enter the number of edges: ");
		int e=sc.nextInt(); // Accepting number of edges from user
        for(int i=0;i<e;i++)
		{
			System.out.println("Enter edge "+i+": ");
			int x=sc.nextInt();
			int y=sc.nextInt();
			obj.addEdge(x, y);
		}
        System.out.println("BFS starting from vertex 1 is: ");
		obj.BFSalgo(1); // Function calling
    }
}
/*
Time Complexity: O(vertices + edges)
Space Complexity: O(vertices)
Sample I/O:
INPUT:
Enter the value of vertices: 
4
Enter the number of edges: 
6
Enter edge 0: 
0
1
Enter edge 1: 
0
2
Enter edge 2: 
1
2
Enter edge 3: 
2
0
Enter edge 4: 
2
3
Enter edge 5: 
3
3
OUTPUT:
BFS starting from vertex 1 is: 
1 0 2 3
*/