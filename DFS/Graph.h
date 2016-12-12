#pragma once
#include "Util.h"
#include "Node.h"
//O(e + v)
class Graph
{
public:
	Graph() : root(nullptr) {}
	Graph(pNode node) : root(node) {}
	~Graph() {}

	pNode getNode(int value);

private:
	pNode root;
	pNode DFS(int value, pNode node);
};
