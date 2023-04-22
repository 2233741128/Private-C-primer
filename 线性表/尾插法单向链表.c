#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Node)
// 定义链表节点结构体
struct Node {
    int data;             // 数据域
    struct Node* next;    // 指向下一个节点的指针
};

struct Node* head = NULL;  // 定义头指针，初始化为NULL
//指向结构体的指针
// 向链表中添加节点
void add_node(int data) 
{
    // 为新节点分配空间
    struct Node* new_node = (struct Node*) malloc(LEN);
    new_node->data = data;  // 新节点的数据域为传入的data
    new_node->next = NULL;  // 新节点的下一个节点指针初始化为NULL
    struct Node* current = head;        // 从头节点开始遍历直到最后一个节点
    while (current->next != NULL) 
    {    
        current = current->next;
    }
    current->next = new_node;           // 最后一个节点的指针指向新节点
}

// 从链表中删除节点
void delete_node(int data) 
{
   
    if (head->data == data) 
    {   // 如果要删除的节点是头节点，则将头指针指向下一个节点
        head = head->next;
    } else 
    {// 如果要删除的节点不是头节点，则遍历到要删除的节点，并将前一个节点的指针指向要删除节点的下一个节点
        struct Node* current = head;        // 从头节点开始遍历
        while (current->next != NULL && current->next->data != data) 
        {  // 找到要删除的节点
            current = current->next;
        }
        if (current->next != NULL) 
        {        // 如果找到了要删除的节点，则将前一个节点的指针指向要删除节点的下一个节点
            current->next = current->next->next;
        }
        
    }
}

// 打印链表中的所有节点
void print_list() {
    struct Node* current = head->next;    // 从头节点开始遍历
    while (current != NULL) {       // 遍历到最后一个节点
        printf("%d -> ", current->data);   // 打印当前节点的数据域
        current = current->next;    // 将指针指向下一个节点
    }
    printf("NULL\n");   // 所有节点打印完毕后，打印NULL
}

int main() {
    head=(struct Node*)malloc(LEN);
    head->data=0;
    head->next=NULL;
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);
    print_list();

    delete_node(3);
    delete_node(5);
    print_list();

    return 0;
}

