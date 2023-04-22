#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void add_node(int data) 
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    if (head == NULL) 
	{
        head = new_node;
        head->next = head;
        return;
    }
    struct Node* current = head->next;
    while (current->next != head) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list() {
    struct Node* current = head->next; 
    while (current != head) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d -> ...\n", current->data);
}

int main() {
    add_node(1);
    add_node(2);
    add_node(3);
	add_node(4);
    print_list();
}
