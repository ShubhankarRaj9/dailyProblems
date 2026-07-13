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
    bool isPalindrome(ListNode* head) {
        vector<int> res1;
        vector<int> res2;

        while(head){
            res1.push_back(head->val);
            head = head->next;
        }

        res2 = res1;
        reverse(res2.begin(),res2.end());

        return res1 == res2;

    }
};