#include"graph.h"
#include"edge.h"
//Implementation of Graph class.

//Ctor
Graph::Graph() { timer = 0; }

//Dtor
Graph::~Graph()
{
	if (!myMap.empty())
	{
		for (std::map<string, Vertex*>::iterator it = myMap.begin(); it != myMap.end(); ++it)
			it->second->~Vertex();
	}
}

//Func to add vertex, if success return true, ifedge already exist return false. 
bool Graph::addv(string vertexForAdd)
{
	map<string, Vertex*>::iterator it = myMap.find(vertexForAdd);
	if (it != myMap.end())
		return false;
	if (!myMap[vertexForAdd])
		Vertex* temp = new Vertex(vertexForAdd);
	myMap[vertexForAdd] = new Vertex(vertexForAdd);
	return true;
}

//Func to add Edge, if success return true, ifedge already exist return false. 
bool Graph::adde(string key, string key1)
{
	if (!(myMap.find(key1) == myMap.end()))
	{
		if (!myMap[key]->destinationExist(key1))
		{
			myMap[key]->addEdge(myMap[key], myMap[key1]);
			return true;
		}
		return false;
	}
	else
		return false;
}

//Returns all the edge of specific vertex.
list<Edge> Graph::getAllEdgeOfVertex(Vertex* vertex)
{
	return myMap[vertex->getKey()]->getEdgeList();
}

//Prints all the Graph
void Graph::printAll()
{
	for (std::map<string, Vertex*>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		if ((*it).second != NULL)
		{
			cout << (*it).second->getKey() << ": ";
			(*it).second->print();
			cout << endl;
		}
	}
}

//Prints graph of specifik vertex.
void Graph::printGraph(Vertex* vertex)
{
	vertex->print();
}

//Returns the sort list after topologic sort.
list<Vertex*> Graph::getOrderList()
{
	return order;
}

//Topoligical sort.
list<Vertex*> Graph::topologicalSort()
{
	DFS();
	list<Vertex*> tmp = getOrderList();
	list<Vertex*>::iterator it = tmp.begin();
	cout << "order ";
	for (; it != tmp.end(); ++it)
	{
		cout << (*it)->getKey() << " ";
	}
	return tmp;
}

//DFS sort.
list<Vertex*> Graph::DFS()
{
	for (std::map<string, Vertex*>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		(*it).second->setColor(white);
		(*it).second->setPI(NULL);
	}

	timer = 0;
	order.clear();

	for (std::map<string, Vertex*>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		if ((*it).second != NULL && (*it).second->getColor() == (Color)2)
			DFS_visit(it->second);
	}
	return order;
}

//Reqursive func to "visit" all neighbors. 
void Graph::DFS_visit(Vertex* u)
{
	u->setColor((Color)1);
	timer += 1;
	u->setD(timer);
	list<Edge> tmp = u->getEdgeList();
	list<Edge>::iterator it = tmp.begin();

	for (; it != tmp.end(); ++it)
	{
		if ((it)->getPointerToDest() != NULL && (it)->getPointerToDest()->getColor() == (Color)2)
		{
			(it)->setPointerToSource(u);
			DFS_visit((it)->getPointerToDest());
		}
	}

	u->setColor((Color)0);
	u->setF(timer);
	timer += 1;
	order.push_front(u);
}