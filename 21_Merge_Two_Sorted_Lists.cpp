#include <iostream>
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
public:
    void Print_List(ListNode* lst)
    {
        ListNode* p = lst;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n\n";
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* begin = NULL;
        ListNode* end = NULL;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                if (begin == NULL)
                    begin = p1;
                if (end == NULL)
                {
                    end = begin;
                }
                else
                {
                    ListNode* t = end;
                    t->next = p1;
                    end = p1;
                }
                p1 = p1->next;
            }
            else
            {
                if (begin == NULL)
                    begin = p2;
                if (end == NULL)
                {
                    end = begin;
                }
                else
                {
                    ListNode* t = end;
                    t->next = p2;
                    end = p2;
                }
                p2 = p2->next;
            }
            if (end != NULL)
                end->next = NULL;
        }
        while (p1 != NULL)
        {
            if (begin == NULL)
                begin = p1;
            if (end == NULL)
            {
                end = begin;
            }
            else
            {
                ListNode* t = end;
                t->next = p1;
                end = p1;
            }
            p1 = p1->next;
            if (end != NULL)
                end->next = NULL;
        }
        while (p2 != NULL)
        {
            if (begin == NULL)
                begin = p2;
            if (end == NULL)
            {
                end = begin;
            }
            else
            {
                ListNode* t = end;
                t->next = p2;
                end = p2;
            }
            p2 = p2->next;
            if (end != NULL)
                end->next = NULL;
        }
        return begin;
    }
};
int main()
{
    // Example 1:
    ListNode* l11 = NULL;
    ListNode* l21 = NULL;
    l11 = new ListNode(1, new ListNode(2, new ListNode(4)));
    l21 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution s1;
    // s1.Print_List(l11);
    // s1.Print_List(l21);
    ListNode* sol_p1 = s1.mergeTwoLists(l11, l21);
    s1.Print_List(sol_p1);
    // Example 2:
    ListNode* l12 = NULL;
    ListNode* l22 = NULL;
    Solution s2;
    // s2.Print_List(l12);
    // s2.Print_List(l22);
    ListNode* sol_p2 = s2.mergeTwoLists(l12, l22);
    s2.Print_List(sol_p2);
    // Example 3:
    ListNode* l13 = NULL;
    ListNode* l23 = NULL;
    l23 = new ListNode();
    Solution s3;
    // s3.Print_List(l13);
    // s3.Print_List(l23);
    ListNode* sol_p3 = s3.mergeTwoLists(l13, l23);
    s3.Print_List(sol_p3);
    return 0;
}

