#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return dummy.next;
    }
};

int main() {
    int n1;
    cin >> n1;

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i=0; i<n1; i++) {
        int val;
        cin >> val;

        ListNode* node = new ListNode(val);

        if (list1 == nullptr) {
            list1 = node;
            tail1 = node;
        } else {
            tail1->next = node;
            tail1 = node;
        }
    }

    int n2;
    cin >> n2;

    ListNode* list2 = nullptr;
    ListNode* tail2 = nullptr;

    for (int i=0; i<n2; i++) {
        int val;
        cin >> val;

        ListNode* node = new ListNode(val);

        if (list2 == nullptr) {
            list2 = node;
            tail2 = node;
        } else {
            tail2->next = node;
            tail2 = node;
        }
    }

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    while (merged != nullptr) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}