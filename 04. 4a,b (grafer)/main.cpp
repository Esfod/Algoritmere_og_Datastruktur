#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

struct Kant;
struct Node
{
    char m_navn;
    bool m_besokt;
    vector<Kant> m_kanter;
    Node(char navn) : m_navn(navn), m_besokt(false) { }
    void settinn_kant(const Kant& kant);
};

struct Kant
{
    float m_vekt;
    Node* m_tilnode;
    Kant(float vekt, Node* tilnode) : m_vekt(vekt), m_tilnode(tilnode) { }
    bool operator > (const Kant& k) const { return m_vekt > k.m_vekt; }
};

void Node::settinn_kant(const Kant& kant)
{
    for (Kant k : m_kanter)
    {
        if (k.m_tilnode == kant.m_tilnode && k.m_vekt == kant.m_vekt) break;
    }
    m_kanter.push_back(kant);
}

struct Graf
{
    std::list<Node*> noder;
    Graf() { }
    pair<string, float> dijkstra(Node*, Node*);
    void checkNodePath(Node*, Node*);
    Node* finn_node(char navn)
    {
        for (Node* n : noder)
            if (n->m_navn == navn)
                return n;
        return nullptr;
    };
    void settinn_node(char navn)
    {
        for (Node* n:noder)
            if (n->m_navn == navn)
                break;
        noder.push_back(new Node(navn));
    }
    void settinn_kant(char fra_navn, char til_navn, float vekt)
    {

        Node* senderNode{ nullptr }, *mottakerNode{ nullptr };
        for (Node* n : noder)
        {
            if (fra_navn == n->m_navn)
                mottakerNode = n; break;
        }

        if (!mottakerNode) return;

        for (Node* n : noder)
        {
            if (fra_navn == n->m_navn)
                senderNode = n; break;
        }

        if (!senderNode) return;

        senderNode->settinn_kant(Kant(vekt,mottakerNode));
    }

    float mst()
    {
        return 0;
    }
};

pair<string, float> Graf::dijkstra(Node* fraNode, Node* toNode)
{
    bool foundToNode{ false };
    Node* delta{ fraNode };
    vector<pair<string, float>> dijkstraListe;
    while (!foundToNode)
    {
        dijkstraListe.emplace_back();

        for (size_t i = 0; i < delta->m_kanter.size(); i++)
        {
            if (!delta->m_kanter[i].m_tilnode->m_besokt)
            {
                dijkstraListe[i].second += delta->m_kanter[i].m_vekt;
                dijkstraListe[i].first.push_back(delta->m_kanter[i].m_tilnode->m_navn);
                delta->m_kanter[i].m_tilnode->m_besokt = true;

                if (delta->m_kanter[i].m_tilnode == toNode)
                {
                    foundToNode = true;

                    for (Node* n : noder)
                    {
                        n->m_besokt = false;
                    }
                }
                delta = delta->m_kanter[i].m_tilnode;
            }
        }
    }

    for (int i{ 0 }; i < dijkstraListe.size(); i++)
    {
        for (int j{ i + 1 }; j < dijkstraListe.size(); j++)
        {
            if (dijkstraListe[i].second > dijkstraListe[j].second)
                swap(dijkstraListe[i], dijkstraListe[j]);
        }
    }
    return dijkstraListe.front();
}

void Graf::checkNodePath(Node* fraNode, Node* tilNode)
{

}

int main()
{
    Graf* graf = new Graf();

    graf->settinn_node('A');
    graf->settinn_node('B');
    graf->settinn_node('C');
    graf->settinn_node('D');
    graf->settinn_node('E');

    graf->settinn_kant('A', 'B', 1);
    graf->settinn_kant('A', 'C', 2);
    graf->settinn_kant('B', 'C', 2);
    graf->settinn_kant('C', 'B', 3);
    graf->settinn_kant('D', 'E', 1);
    graf->settinn_kant('A', 'E', 5);
    graf->settinn_kant('C', 'E', 4);

    pair<string, float> a = graf->dijkstra(graf->finn_node('A'), graf->finn_node('D'));

    return 0;
}