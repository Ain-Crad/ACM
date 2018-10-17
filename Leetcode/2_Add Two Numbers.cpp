/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list = new ListNode(0);
        ListNode* rec = list;
        int c = 0, d, d1, d2;
        while(1){
        	if(l1 == NULL) d1 = 0;
        	else {
        		d1 = l1->val;
        		l1 = l1->next;
        	}
        	if(l2 == NULL) d2 = 0;
        	else{
        		d2 = l2->val;
        		l2 = l2->next;
        	}
        	d = d1 + d2 + c;
        	if(d > 9){
        		d -= 10;
        		c = 1;
        	}
        	else c = 0;
        	list->val = d;
        	if(l1 == NULL && l2 == NULL && c == 0) break;
        	list->next = new ListNode(0);
        	list = list->next;
        }
        return rec;
    }
};
