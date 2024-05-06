#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    struct MinHeap {
        int operator() (ListNode* p1, ListNode* p2) {
            return p1->val > p2->val;
        }
    };

public:
    void PrintSolList(ListNode* sol, const int nrSol) {
        cout << "Solution List " << nrSol << ":\n";
        
        ListNode* p = sol;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n\n";
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        const int sz = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, MinHeap> pq;

        for (int i = 0; i < sz; i++)
        {
            if (lists[i] == nullptr)
                continue;

            pq.push(lists[i]);
        }

        ListNode* beginSol = nullptr;
        ListNode* endSol = nullptr;

        while (!pq.empty())
        {
            ListNode* p = pq.top();
            pq.pop();

            if (p != nullptr && p->next != nullptr)
            {
                pq.push(p->next);
            }

            if (beginSol == nullptr)
                beginSol = p;
            else
                endSol->next = p;
        
            endSol = p;
            if (endSol != nullptr)
                endSol->next = nullptr;
        }
        
        return beginSol;
    }
};
int main()
{
    // Time Complexity: O(n * log(K)) - Using a Min-Heap (Priority Queue) to select the node with min-value each time.
    //
    // Example 1:
    vector<ListNode*> v1 = { new ListNode(1, new ListNode(4, new ListNode(5))), new ListNode(1, new ListNode(3, new ListNode(4))), new ListNode(2, new ListNode(6))};
    Solution s1;
    ListNode* sol1 = s1.mergeKLists(v1); // [1, 1, 2, 3, 4, 4, 5, 6]
    s1.PrintSolList(sol1, 1);


    // Example 2:
    vector<ListNode*> v2 = {};
    Solution s2;
    ListNode* sol2 = s2.mergeKLists(v2); // []
    s2.PrintSolList(sol2, 2);


    // Example 3:
    vector<ListNode*> v3 = { nullptr };
    Solution s3;
    ListNode* sol3 = s3.mergeKLists(v3); // []
    s3.PrintSolList(sol3, 3);

    
    return 0;
}

