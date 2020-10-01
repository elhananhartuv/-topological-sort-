#pragma once
#include<string>
#include<iostream>
#include<iterator>
#include<list>
#include<map>
#include "vertex.h"
#include"edge.h"
using namespace std;

//This class for "Graph" 
class Graph
{
	map<string, Vertex*> myMap;//All the vertex stored in the MAP.
	list<Vertex*> order;//List for order graph after topologic sort.
	int timer;//The timer to calculate start time & end time of each vertex.
public:
	//Ctor
	Graph();

	//Dtor
	~Graph();

	//Func to add vertex, if success return true, ifedge already exist return false. 
	bool addv(string vertexForAdd);

	//Func to add Edge, if success return true, ifedge already exist return false. 
	bool adde(string keySource, string keyDest);

	//Reqursive func to "visit" all neighbors. 
	void DFS_visit(Vertex* u);

	//Prints all the Graph
	void printAll();

	//Prints graph of specifik vertex.
	void printGraph(Vertex* vertex);

	//Returns the sort list after topologic sort. 
	list<Vertex*> getOrderList();

	//DFS sort.
	list<Vertex*> DFS();
	list<Vertex*> topologicalSort();

	//Returns all the edge of specific vertex.
	list<Edge> getAllEdgeOfVertex(Vertex* vertex);
};