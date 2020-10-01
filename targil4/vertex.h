#pragma once
#include<string>
#include<iostream>
#include<list>
#include<iterator>
using namespace std;

enum Color { black, gray, white };
class Edge;//This class presents Edge in Graph
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//This class presents vertex in graph.
class Vertex
{
	int d;//Presents discovery time.
	int f;//Presents finish time.
	string key;//Presents the key of vertex.
	Vertex* pi;//Presents the previous vertex.
	Color vertexColor;//Presents the "color" of vertex, for topological sort.
	list<Edge> edgeList;//List of all edges of vertex.	

public:
	//Ctor to set key of vertex.
	Vertex(string key);

	//Initialize the vertex.
	void initialize();

	//Dtor.
	~Vertex();

	//Returns the key of vertex.
	string getKey();

	//Enable to set "color" of vertex.
	void setColor(Color myColor);

	//Returns the color of vertex.
	Color getColor();

	//Enable to set discover time.
	void setD(int d);

	//Returns the discover time.
	int getD();

	//Enable to set end time.
	void setF(int f);

	//Returns the end time.
	int getF();

	//Enable to set previous vertex.
	void setPI(Vertex* pi);

	//Returns the previous vertex.
	Vertex* getPI();

	//Enable to add edge.
	void addEdge(Vertex* a, Vertex* b);

	//Checks if destination between vertex exist.
	bool destinationExist(string v);

	//Returns the edge list.
	list<Edge> getEdgeList();

	//Prints all the edge of vertex.
	void print();

	//Removes edge.
	void removeEdge(string u, string v);

	//Returns num of neighbors.
	int numOfNeighbours();
};