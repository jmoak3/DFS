#include "Graph.h"

pNode Graph::getNode(int value)
{
	if (root == nullptr)
	{
		std::cout << "cannot perform operations on an empty graph" << std::endl;
		return nullptr;
	}
	return DFS(value, root);
}

pNode Graph::DFS(int value, pNode node)
{
	std::cout << node->getValue() << " ";
	if (node->getValue() == value)
	{
		return node;
	}
	if (node->getNumAdjacencies() > 0)
	{
		std::vector<pNode> adj = node->getAdj();
		std::vector<pNode>::iterator it = adj.begin();
		for (; it != adj.end(); ++it)
		{
			//Effectively a stack.
			pNode foundNode = DFS(value, *it);
			if (foundNode != nullptr) return foundNode;
		}
		std::cout << std::endl;
	}

	return nullptr;
}