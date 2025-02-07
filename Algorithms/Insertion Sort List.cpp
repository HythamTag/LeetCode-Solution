#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
     ListNode* insertionSortList(ListNode* head) {
          if (!head || !head->next) return head;

          ListNode* dummy = new ListNode(0);
          dummy->next = head;
          ListNode* previous_node = head;
          ListNode* current_node = head->next;

          while (current_node != nullptr) {
               if (current_node->val >= previous_node->val) {
                    previous_node = current_node;
                    current_node = current_node->next;
               } else {
                    ListNode* temp = dummy;
                    while (temp->next->val < current_node->val) {
                         temp = temp->next;
                    }
                    previous_node->next = current_node->next;
                    current_node->next = temp->next;
                    temp->next = current_node;
                    current_node = previous_node->next;
               }
          }
          return dummy->next;
     }
};

void printList(ListNode* head) {
     while (head) {
          std::cout << head->val << " ";
          head = head->next;
     }
     std::cout << std::endl;
}

int main() {
     ListNode* head = new ListNode(4);
     head->next = new ListNode(2);
     head->next->next = new ListNode(1);
     head->next->next->next = new ListNode(3);

     Solution solution;
     head = solution.insertionSortList(head);

     printList(head);

     return 0;
}
