//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

// Position this line where user code will be pasted.

// Driver code
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a;
        cin >> a;
        MinHeap h(a);
        for (ll i = 0; i < a; i++)
        {
            int c;
            int n;
            cin >> c;
            if (c == 1)
            {
                cin >> n;

                h.insertKey(n);
            }
            if (c == 2)
            {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3)
            {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        // delete h.harr;
        h.harr = NULL;

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return -1; // Handle empty heap case
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    int val = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return val;
}

// Function to delete a key at index i
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin(); // Extract the min instead of manually adjusting
}

// Function to insert a value in Heap
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        // cout << "Heap is full.";
        return;
    }
    heap_size++;
    int indx = heap_size - 1;
    harr[indx] = k; // Fixed assignment error
    while (indx != 0 && harr[indx] < harr[parent(indx)])
    {
        swap(harr[parent(indx)], harr[indx]);
        indx = parent(indx);
    }
}

// Function to decrease a key value at index i
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[i] < harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// MinHeapify function to maintain heap property
void MinHeap::MinHeapify(int i)
{
    int lt = left(i);
    int rt = right(i);
    int smallest = i;
    if (lt < heap_size && harr[lt] < harr[smallest])
    {
        smallest = lt;
    }
    if (rt < heap_size && harr[rt] < harr[smallest])
    { // Fixed missing check for right child
        smallest = rt;
    }
    if (i != smallest)
    {
        swap(harr[smallest], harr[i]);
        MinHeapify(smallest);
    }
}
