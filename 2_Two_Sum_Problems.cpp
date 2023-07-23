#include "include_all.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}                   // Default constructor
    ListNode(int x) : val(x), next(nullptr) {}              // Constructor with one argument
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with two arguments
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(); // Create a dummy node to hold the result
        ListNode *curr = dummy;           // Initialize a pointer 'curr' to point to the dummy node
        int carry = 0;                    // Initialize a variable 'carry' to 0 to keep track of the carry during addition

        while (l1 || l2 || carry)
        {                                                              // Loop until l1 and l2 are null, and there is no carry left
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // Calculate the sum of digits at the current position
            printf("sum: %d || carry: %d || l1: %d || l2: %d\n", sum, carry, l1 ? l1->val : 0, l2 ? l2->val : 0);

            carry = sum / 10; // Calculate the carry for the next position (if any)
            sum = sum % 10;   // Calculate the single-digit result to be added to the resulting linked list

            curr->next = new ListNode(sum); // Create a new node with the calculated sum and attach it to the 'next' of 'curr'
            curr = curr->next;              // Move 'curr' to the newly added node

            if (l1)
                l1 = l1->next; // Move 'l1' to its next node if it's not null
            if (l2)
                l2 = l2->next; // Move 'l2' to its next node if it's not null
        }

        return dummy->next; // Return the 'next' of the dummy node, which points to the head of the resulting linked list
    }
};

int main()
{
    // l1 [2,4,3]
    // l2 [5,6,4]
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);

    while (result)
    {
        printf("%d ", result->val);
        result = result->next;
    }
}