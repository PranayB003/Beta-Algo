/* Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node and explores 
as far as possible along each branch before backtracking. */

import java.util.*;

class DFS_undirected_graph
{
	private LinkedList <Integer> adjLists[]; // Adjacency list to store the graph
	private boolean visited[]; // To mark the visited nodes

	DFS_undirected_graph(int vertices) // Constructor to initialize the global variables
	{
		adjLists=new LinkedList[vertices];
		visited=new boolean[vertices];

		for(int i=0;i<vertices;i++)
			adjLists[i]=new LinkedList <Integer>();
	}

	void addEdge(int start, int end)
	{
		adjLists[start].add(end); // Adding edge
        adjLists[end].add(start); // Adding edge
	}

	void DFSalgo(int vertex)
	{
		visited[vertex]=true; // Marking it to as visited
		System.out.print(vertex+" "); // Printing the vertices
		Iterator <Integer> it=adjLists[vertex].listIterator();
		while(it.hasNext())
		{
			int adj=it.next();
			if(!visited[adj])
				DFSalgo(adj);
		}
	}

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of vertices: ");
		int v=sc.nextInt(); // Accepting number of vertices from user
		DFS_undirected_graph obj=new DFS_undirected_graph(v); // Creating an object
		System.out.println("Enter the number of edges: ");
		int e=sc.nextInt(); // Accepting number of edges from user
		for(int i=0;i<e;i++)
		{
			System.out.println("Enter edge "+i+": ");
			int x=sc.nextInt();
			int y=sc.nextInt();
			obj.addEdge(x, y);
		}
		System.out.println("DFS starting from vertex 1 is: ");
		obj.DFSalgo(1); // Function calling
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
DFS starting from vertex 1 is: 
1 2 0 3
*/