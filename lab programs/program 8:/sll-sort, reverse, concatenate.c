#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    int swapped;
    struct ListNode* ptr;
    struct ListNode* lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->val > ptr->next->val) {
                int temp = ptr->val;
                ptr->val = ptr->next->val;
                ptr->next->val = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);

    return head;
}

struct ListNode* concatLists(struct ListNode* head1, struct ListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct ListNode* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct ListNode* head1 = newNode(3);
    head1->next = newNode(1);
    head1->next->next = newNode(4);

    struct ListNode* head2 = newNode(7);
    head2->next = newNode(2);
    head2->next->next = newNode(5);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    head1 = sortList(head1);
    printf("\nSorted List 1: ");
    printList(head1);

    head2 = reverseList(head2);
    printf("Reversed List 2: ");
    printList(head2);

    struct ListNode* merged = concatLists(head1, head2);
    printf("\nConcatenated List: ");
    printList(merged);

    return 0;
}
