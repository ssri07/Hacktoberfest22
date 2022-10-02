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
    ListNode* partition(ListNode* head, int x) {
        vector<int> a,b;
        ListNode* cur=head;
        while(cur!=NULL)
        {
          if(cur->val <x)
              b.push_back(cur->val);
          else
              a.push_back(cur->val);
            
            cur=cur->next;
        }
        
        int l=0,n=b.size(),r=0,m=a.size();
        cur=head;
        while(cur!=NULL)
        {
          if(n)
          {
              n--;
              cur->val=b[l++];
          }
          else
              cur->val=a[r++];
            
            cur=cur->next;
        }
        return head;
    }
};