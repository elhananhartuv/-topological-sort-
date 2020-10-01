#pragma once
#include"vertex.h"

//This class presents Edge in Graph
class Edge
{
	Vertex* pointerToVertexSource;//PTR to next vertex.
	Vertex* pointerToVertexDets;//Ptr to previous vertex.
	int destBetweenSourceAndDest;
public:
	void setPointerToDest(Vertex* dest);//Enables to set PTR to next vertex.
	Vertex* getPointerToDest() const;//Returns the PTR to next vertex.
	void setPointerToSource(Vertex* source);//Enable to set PTR to previous vertex.
	Vertex* getPointerToSource() const;//Returns the PTR to previous vertex.
	bool operator==(const Edge& param) const;//Checks if two edge are equal.
};

