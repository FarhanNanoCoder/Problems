#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void printGraph(Node *node)
{
    if (node == NULL)
        return;
    unordered_set<Node *> visited;
    queue<Node *> q;
    q.push(node);
    visited.insert(node);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        for (int i = 0; i < curr->neighbors.size(); i++)
        {
            if (visited.find(curr->neighbors[i]) == visited.end())
            {
                q.push(curr->neighbors[i]);
                visited.insert(curr->neighbors[i]);
            }
        }
    }
}

Node *clone(Node *node, unordered_map<Node *, Node *> &oldToNew)
{
    if (oldToNew.find(node) == oldToNew.end())
    {
        Node *copy = new Node(node->val);
        oldToNew[node] = copy;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            copy->neighbors.push_back(clone(node->neighbors[i], oldToNew));
        }
    }

    return oldToNew[node];
}

Node *cloneGraph(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    unordered_map<Node *, Node *> oldToNew;
    Node *head = clone(node, oldToNew);
    return head;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    printGraph(node1);
    cout << endl;
    Node *copy = cloneGraph(node1);
    printGraph(copy);
    return 0;
}