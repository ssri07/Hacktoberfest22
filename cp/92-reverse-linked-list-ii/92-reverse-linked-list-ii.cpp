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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int n=0;
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
            n++;
        }
        
        if(n==1 || l==r)
        {
            return head;
        }
        
        reverse(v.begin()+l-1,v.begin()+r);
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            temp->val=v[i++];
            temp=temp->next;
        }
        
        
        return head;
    }
};