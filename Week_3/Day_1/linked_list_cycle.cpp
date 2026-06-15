#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "false" << endl;
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        ListNode* node = new ListNode(val);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int pos;
    cin >> pos;

    if (pos >= 0) {
        ListNode* cycleNode = head;

        for (int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }

        tail->next = cycleNode;
    }

    Solution sol;

    if (sol.hasCycle(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}