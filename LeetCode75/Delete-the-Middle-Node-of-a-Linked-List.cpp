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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        } else if(head->next == nullptr){
            // delete head; 
            return nullptr; 
        } else {
            ListNode* prvNode = head; 
            ListNode* endNode = head->next->next; 

            while(endNode != nullptr && endNode->next != nullptr){
                // if(endNode->next == nullptr) break; 
                prvNode = prvNode->next; 
                endNode = endNode->next->next; 
            }

            ListNode* midNode = prvNode->next; 
            ListNode* nxtNode = midNode->next; 
            prvNode->next = nxtNode; 
            delete midNode; 

            return head; 
        }
    }
};