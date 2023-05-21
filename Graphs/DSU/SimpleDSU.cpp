
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// A class to represent a disjoint set
class DisjointSet
{
    unordered_map<int, int> parent;
 
public:
 
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe) {
            parent[i] = i;
        }
    }
 
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is root
        if (parent[k] == k) {
            return k;
        }
 
        // recur for the parent until we find the root
        return Find(parent[k]);
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 