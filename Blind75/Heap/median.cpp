
#include <bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void printHeap(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
class MedianFinder
{
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        small.push(num);
        if (large.empty() && small.size() > 1)
        {
            large.push(small.top());
            small.pop();
        }
        while (!small.empty() && !large.empty() && small.top() > large.top())
        {
            int t = small.top();
            small.pop();
            small.push(large.top());
            large.pop();
            large.push(t);
        }

        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        // printHeap(small);
        // printHeap(large);
    }

    double findMedian()
    {
        if (small.size() > large.size())
        {
            return (double)small.top();
        }
        else if (small.size() < large.size())
        {
            return (double)large.top();
        }
        return (double)(small.top() + large.top()) / 2;
    }
};

int main(){
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    mf.addNum(4);
    cout << mf.findMedian() << endl;
    mf.addNum(5);
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(7);
    cout << mf.findMedian() << endl;
    mf.addNum(8);
    cout << mf.findMedian() << endl;
    mf.addNum(9);
    cout << mf.findMedian() << endl;
    mf.addNum(10);
    cout << mf.findMedian() << endl;
    mf.addNum(11);
    cout << mf.findMedian() << endl;
    mf.addNum(12);
    cout << mf.findMedian() << endl;
    mf.addNum(13);
    cout << mf.findMedian() << endl;
    mf.addNum(14);
    cout << mf.findMedian() << endl;
    mf.addNum(15);
    cout << mf.findMedian() << endl;
    mf.addNum(16);
    cout << mf.findMedian() << endl;
    mf.addNum(17);
    cout << mf.findMedian() << endl;
    mf.addNum(18);
    cout << mf.findMedian() << endl;
    mf.addNum(19);
    cout << mf.findMedian() << endl;
    mf.addNum(20);
    cout << mf.findMedian() << endl;
    mf.addNum(21);
    cout << mf.findMedian() << endl;
    mf.addNum(22);
    cout << mf.findMedian() << endl;
    mf.addNum(23);
    cout << mf.findMedian() << endl;
    mf.addNum(24);
    cout << mf.findMedian() << endl;
    mf.addNum(25);
    cout << mf.findMedian() << endl;
    mf.addNum(26);
    cout << mf.findMedian() << endl;
    mf.addNum(27);
    cout << mf.findMedian() << endl;
    mf.addNum(28);
    cout << mf.findMedian() << endl;
    mf.addNum(29);
    cout << mf.findMedian() << endl;
    mf.addNum(30);
    cout << mf.findMedian() << endl;
}

// https://leetcode.com/problems/find-median-from-data-stream/