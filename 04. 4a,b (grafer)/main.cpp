#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Kant;
struct Node
{
    char m_navn;
    bool m_besokt;
    std::list<Kant> m_kanter;
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
        Kant k(vekt, mottakerNode);

        senderNode->settinn_kant(k);
    }

    float mst()
    {
        return 0;
    }
};

struct Vei
{

};

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

    return 0;
}