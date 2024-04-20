#include <bits/stdc++.h>
using namespace std;
struct LRUNode
{
    int key, val;
    LRUNode *prev, *next;
    LRUNode() : key(0), val(0), prev(nullptr), next(nullptr){};
    LRUNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr){};
    LRUNode(int key, int val, LRUNode *prev, LRUNode *next) : key(key), val(val), prev(prev), next(next){};
};

class LRUCache
{
private:
    unordered_map<int, LRUNode *> cache;
    int cap;
    LRUNode *left, *right;
public:
    LRUCache(int cap)
    {
        this->cap = cap;
        left = new LRUNode();
        right = new LRUNode();
        left->next = right;
        right->prev = left;
    }

    void insert(LRUNode *node)
    {
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
    }

    void remove(LRUNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    int get(int key)
    {

        if (cache.find(key) != cache.end())
        {
            int val = cache[key]->val;
            // cout<<"got value:"<<cache[key]->val<<endl;
            remove(cache[key]);
            cache[key] = new LRUNode(key, val);
            insert(cache[key]);
            return val;
        }
        return -1;
    }

    void put(int key, int val)
    {
        if (cache.find(key) != cache.end())
        {
            // cout<<"found"<<endl;
            remove(cache[key]);
            cache.erase(cache.find(key));
        }

        if (cache.size() >= cap)
        {
            // cout << "cache full" << endl;
            cache.erase(cache.find(left->next->key));
            LRUNode *lru = left->next;
            left->next = lru->next;
            lru->next->prev = left;
            delete lru;
        }
        cache[key] = new LRUNode(key, val);
        insert(cache[key]);
    }

    void print()
    {
        // cout << "size:" << cache.size() << endl;
        // cout << "cap" << cap << endl;
        LRUNode *temp = left->next;
        while (temp != right)
        {
            cout << temp->key << " " << temp->val << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LRUCache obj = LRUCache(2);
    obj.put(1, 1);
    obj.put(2, 2);
    obj.print();
    cout << obj.get(1) << endl;
    obj.print();
    obj.put(3, 3);
    obj.print();
    cout << obj.get(2) << endl;
    obj.put(4, 4);
    obj.print();
    cout << obj.get(1) << endl;
    obj.print();
    cout << obj.get(3) << endl;
    obj.print();
    cout << obj.get(4) << endl;
    obj.print();
}


/// https://leetcode.com/problems/lru-cache/
