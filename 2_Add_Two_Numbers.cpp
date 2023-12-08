#include <iostream>
using namespace std;

// Definition for singly-linked list.

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int rest = 0;

        ListNode* begin = nullptr;
        ListNode* end = nullptr;

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while (p1 != nullptr && p2 != nullptr)
        {
            int vl = (p1->val + p2->val + rest) % 10;

            if (p1->val + p2->val + rest > 9)
                rest = 1;
            else
                rest = 0;

            ListNode* p = new ListNode(vl);

            if (begin == nullptr)
            {
                begin = p;
                end = p;
            }
            else
            {
                end->next = p;
                end = p;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != nullptr)
        {
            int vl = (p1->val + rest) % 10;

            if (p1->val + rest > 9)
                rest = 1;
            else
                rest = 0;

            ListNode* p = new ListNode(vl);

            if (begin == nullptr)
            {
                begin = p;
                end = p;
            }
            else
            {
                end->next = p;
                end = p;
            }
            
            p1 = p1->next;
        }

        while (p2 != nullptr)
        {
            int vl = (p2->val + rest) % 10;

            if (p2->val + rest > 9)
                rest = 1;
            else
                rest = 0;

            ListNode* p = new ListNode(vl);

            if (begin == nullptr)
            {
                begin = p;
                end = p;
            }
            else
            {
                end->next = p;
                end = p;
            }

            p2 = p2->next;
        }

        if (begin != nullptr && rest == 1)
        {
            ListNode* p = new ListNode(1);
            end->next = p;
            end = p;
        }

        return begin;
    }

    void PrintList(ListNode* list)
    {
        ListNode* p = list;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    // Time Complexity: O(n + m) - Adding 2 numbers (first number of length "n", second number of length "m").
    //
    // Example 1:
    Solution s1;
    ListNode* l11 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l21 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* sum1 = s1.addTwoNumbers(l11, l21);
    cout << "Solution 1:\n";
    s1.PrintList(sum1); // [7, 0, 8]

    // Example 2:
    Solution s2;
    ListNode* l12 = new ListNode();
    ListNode* l22 = new ListNode();
    ListNode* sum2 = s2.addTwoNumbers(l12, l22);
    cout << "Solution 2:\n";
    s2.PrintList(sum2); // [0]

    // Example 3:
    Solution s3;
    ListNode* l13 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l23 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    ListNode* sum3 = s3.addTwoNumbers(l13, l23);
    cout << "Solution 3:\n";
    s3.PrintList(sum3); // [8, 9, 9, 9, 0, 0, 0, 1]

    return 0;
}

