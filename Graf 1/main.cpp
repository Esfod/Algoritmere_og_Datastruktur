#include <iostream>
#include <list>

using namespace std;

struct Vertices;

struct Node
{
	char m_name;
	bool m_visited = false;
	list <Vertices> m_vertices;

	Node(char name) : m_name(name) {}

	void insertVertic(const Vertices& vertic)
	{
		m_vertices.push_back(vertic);
	}
	void depthFirst();
	void witdthFirst();
};

struct Vertices
{ 
	float m_cost;
	Node* m_toNode;
	
	Vertices(float cost, Node* toNode) : m_cost(cost), m_toNode(toNode) {}
	bool operator > (const Vertices& k) const { return m_cost > k.m_cost; }
};

void Node::depthFirst()
{
	if (!m_visited)
	{
		cout << m_name << endl;
		m_visited = true;
		for (auto vertric : m_vertices)
		{
			Node* nodePointer = vertric.m_toNode;

			if (!nodePointer->m_visited)
				nodePointer->depthFirst();
		}
		m_visited = false;
	}
}

void Node::witdthFirst()
{

}


struct Graph
{
	list<Node*> nodes;
	Graph() {}
	Node* findNode(char name);
	void insertNode(Node* name);
	//void insertVertic(char from_name, char to_name, float cost);
	//float mst();
};

void Graph::insertNode(Node* name)
{
	nodes.push_back(name);
}

Node* Graph::findNode(char name)
{
	return nullptr;
}


int main()
{
	Node* n_a = new Node('a');
	Node* n_b = new Node('b');
	Node* n_c = new Node('c');
	Node* n_d = new Node('d');
	Node* n_e = new Node('e');

	const Vertices ad(2, n_d);
	const Vertices ac(1, n_c);
	const Vertices bc(3, n_c);
	const Vertices cd(4, n_d);
	const Vertices ce(5, n_e);
	const Vertices de(6, n_e);
	const Vertices ed(7, n_d);

	Graph* g_a = new Graph;

	g_a->insertNode(n_a);

	n_a->insertVertic(ad);
	n_a->insertVertic(ac);
	n_b->insertVertic(bc);
	n_c->insertVertic(cd);
	n_c->insertVertic(ce);
	n_d->insertVertic(de);
	n_e->insertVertic(ed);
	
	n_a->depthFirst();

	return 0;
}