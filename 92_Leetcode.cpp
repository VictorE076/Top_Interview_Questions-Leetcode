#include <iostream>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

    ListNode* _get_nth_node(ListNode* head, int index) {

        ListNode* p = head;

        if (p == nullptr || index < 1)
            return nullptr;

        while (p != nullptr)
        {
            if (index == 1)
                return p;

            p = p->next;
            index--;
        }

        return nullptr;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (head == nullptr || left >= right)
            return head;

        ListNode* inferior = _get_nth_node(head, left - 1);
        ListNode* superior = _get_nth_node(head, right);

        if (superior == nullptr)
            return nullptr;

        ListNode* prev = nullptr, *c = nullptr, *urm = nullptr;

        if (inferior != nullptr)
        {
            prev = superior;
            c = inferior;
            urm = c->next;

            c->next = prev;
        }

        prev = superior->next;
        c = (inferior != nullptr) ? urm : head;
        urm = c->next;

        while (c != nullptr)
        {
            c->next = prev;

            if (c == superior)
                break;

            prev = c;
            c = urm;
            urm = c->next;
        }

        if (inferior == nullptr)
            head = superior;

        return head;
    }

    //
    void printLinkedList(ListNode* head) {
        
        ListNode* p = head;
        
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << "\n\n\n";
    }
};

int main()
{
    // Time Complexity: O(n) - Reverse Linked List of maximum "n" nodes.
    //
    // Example 1:
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int left1 = 2, right1 = 4;

    cout << "Solution 1:  ";
    Solution s1;
    ListNode* sol1 = s1.reverseBetween(head1, left1, right1);
    s1.printLinkedList(sol1); // [1, 4, 3, 2, 5]

    // Example 2:
    ListNode* head2 = new ListNode(5);
    int left2 = 1, right2 = 1;

    cout << "Solution 2:  ";
    Solution s2;
    ListNode* sol2 = s2.reverseBetween(head2, left2, right2);
    s2.printLinkedList(sol2); // [5]

    return 0;
}
