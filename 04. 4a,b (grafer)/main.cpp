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

pair<string,float> Graf::dijkstra(Node* fromNode, Node* toNode)
{
    bool foundToNode{ false };
    Node* delta{ fromNode };
    vector<vector<pair<string, float>>> dijkstraListe;
    int jk{ 0 };
    while (!foundToNode)
    {
        dijkstraListe.emplace_back();
        for (size_t i = 0; i < fromNode->m_kanter.size(); i++)
        {
            if(fromNode->m_kanter[i].m_tilnode->m_besokt)
            dijkstraListe[jk].emplace_back();
            if (!fromNode->m_kanter[i].m_tilnode->m_besokt)
            {
                dijkstraListe[jk][i].second += fromNode->m_kanter[i].m_vekt;
                dijkstraListe[jk][i].first.push_back(fromNode->m_kanter[i].m_tilnode->m_navn);
                fromNode->m_kanter[i].m_tilnode->m_besokt = true;
                
                if (fromNode->m_kanter[i].m_tilnode == toNode)
                    foundToNode = true;
            }
        }

        for (int i{ 0 }; i < dijkstraListe[jk].size(); i++)
        {
            for (auto j{ i + 1 }; j < dijkstraListe[jk].size(); j++)
            {
                if (dijkstraListe[jk][i].second > dijkstraListe[jk][j].second)
                {
                    std::swap(dijkstraListe[jk][i], dijkstraListe[jk][j]);
                }
            }
        }
        jk++;
    }
    return dijkstraListe[jk].front();
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