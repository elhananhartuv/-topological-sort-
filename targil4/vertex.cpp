#include"vertex.h"
#include"edge.h"

//Implementation of class Vertex.

//Ctor to set key of vertex.
Vertex::Vertex(string key)
{
	this->key = key;
}

//Initialize the vertex.
void Vertex::initialize()
{
	pi = NULL;
	vertexColor = (Color)2;
}

//Dtor.
Vertex::~Vertex()
{
	if (this)
		pi = NULL;
}

//Returns the key of vertex.
string Vertex::getKey()
{
	return this->key;
}

//Enable to set "color" of vertex.
void Vertex::setColor(Color myColor)
{
	if (this)
		this->vertexColor = myColor;
}

//Returns the color of vertex.
Color Vertex::getColor()
{
	return this->vertexColor;
}

//Enable to set discover time.
void Vertex::setD(int d)
{
	this->d = d;
}

//Returns the discover time.
int Vertex::getD()
{
	return this->d;
}

//Enable to set end time.
void Vertex::setF(int f)
{
	this->f = d;
}

//Returns the end time.
int Vertex::getF()
{
	return this->f;
}

//Enable to set previous vertex.
void Vertex::setPI(Vertex* pi)
{
	if (this)
		this->pi = pi;
}

//Returns the previous vertex.
Vertex* Vertex::getPI()
{
	return this->pi;
}

//Enable to add edge.
void Vertex::addEdge(Vertex* a, Vertex* b)
{
	Edge tmp;
	(tmp).setPointerToSource(a);
	(tmp).setPointerToDest(b);
	edgeList.push_back(tmp);
}

//Checks if destination between vertex exist.
bool Vertex::destinationExist(string v)
{
	list<Edge>::iterator it = edgeList.begin();
	for (; it != edgeList.end(); ++it)
	{
		if ((*it).getPointerToDest() != NULL && (*it).getPointerToDest()->key == v)
		{
			return true;
		}
	}
	return false;
}

//Returns the edge list.
list<Edge> Vertex::getEdgeList()
{
	return this->edgeList;
}

//Prints all the edge of vertex.
void Vertex::print()
{
	list<Edge>::iterator it = edgeList.begin();
	for (; it != edgeList.end(); ++it)
	{
		if ((*it).getPointerToDest() != NULL)
			cout << (*it).getPointerToDest()->key << " ";
	}
}

//Removes edge.
void Vertex::removeEdge(string u, string v)
{
	list<Edge>::iterator it = edgeList.begin();
	for (; it != edgeList.end(); ++it)
		if ((*it).getPointerToSource()->key == u && (*it).getPointerToDest()->key == v)
			break;
	if (it != edgeList.end())
		edgeList.remove(*it);
}

//Returns num of neighbors.
int Vertex::numOfNeighbours()
{
	list <Edge>::iterator it = edgeList.begin();
	int count = 0;
	for (; it != edgeList.end(); ++it)
		++count;
	return count;
}