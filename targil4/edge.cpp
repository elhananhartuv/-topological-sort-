#include"edge.h"

//Implementation of class Edge.

//Enables to set PTR to next vertex.
void Edge::setPointerToDest(Vertex* dest)
{
	this->pointerToVertexDets = dest;
}

//Returns the PTR to next vertex.
Vertex* Edge::getPointerToDest() const
{
	return this->pointerToVertexDets;
}

//Enable to set PTR to previous vertex.
void Edge::setPointerToSource(Vertex* source)
{
	this->pointerToVertexSource = source;
}

//Returns the PTR to previous vertex.
Vertex* Edge::getPointerToSource() const
{
	return this->pointerToVertexSource;
}

//Checks if two edge are equal.
bool Edge::operator==(const Edge& param) const
{
	return(this->destBetweenSourceAndDest == param.destBetweenSourceAndDest &&
		this->pointerToVertexSource == param.pointerToVertexSource &&
		this->pointerToVertexDets == param.pointerToVertexDets);
}