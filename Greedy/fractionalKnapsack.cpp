#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};

void printArray(int a[], int size)
{
    // int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printItem(Item a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "v: " << a[i].value << " w:" << a[i].weight << endl;
    }
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, [](const Item &a, const Item &b)
         { return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight); });

    // printItem(arr, 3);
    double value = 0.0;
    for (int i = 0; i < n && W > 0; i++)
    {

        if (arr[i].weight <= W)
        {
            value += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            value += W * (arr[i].value * 1.0 / arr[i].weight);
            W = 0;
            break;
        }
    }
    return value;
}

int main()
{
    Item arr[3] = {
        Item(60, 10),

        Item(120, 30),
        Item(100, 20),
    };
    // printItem(arr, 3);

    cout << fractionalKnapsack(50, arr, 3);
    // int arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    // cout << findPlatform(arr, dep, 6);
}

// problem_link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1