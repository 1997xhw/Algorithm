//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            return b ? gcd(b, a % b) : a;
        };
        ListNode *p =head;
        while (p->next != nullptr) {
            ListNode *n = new ListNode(__gcd(p->val, p->next->val), p->next);
            p->next = n;
            p = p->next->next;
        }
        return head;
    }
};

int main() {


}