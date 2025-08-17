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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int round = 0; 

        ListNode* node_start = nullptr; 
        ListNode* node_itr   = nullptr; 

        while(l1 || l2 || round) 
        {
            int new_val = round; 
            if(l1) {
                new_val += l1->val; 
                l1 = l1->next;
            }
            if(l2) {
                new_val += l2->val;
                l2 = l2->next; 
            }
            
            ListNode *new_node = new ListNode(new_val % 10); 
            if(node_start == nullptr) node_start = new_node; 
            else node_itr->next = new_node; 
            round = new_val / 10; 
            node_itr = new_node; 
        }
        return node_start; 
    }
};