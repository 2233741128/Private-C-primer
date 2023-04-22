#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct stu)

struct stu
{
    int score;
    struct stu *next;
};

struct stu *head = NULL;

void addnode(int score)
{
    struct stu *newnode = (struct stu*)malloc(LEN);
    newnode->score = score;
    newnode->next = head->next;
    head->next = newnode;
}

void delete_node(int score)
{
    struct stu *current = head->next;
    struct stu *previous = head;
    while(current != NULL)
    {
        if(current->score == score)
        {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void printnode()
{
    struct stu *current = head->next;
    while(current != NULL)
    {
        printf("%d->", current->score);
        current = current->next;
    }
    printf("NULL");
}

int main()
{
    //头节点为空
    head = (struct stu*)malloc(LEN);
    head->score = 0;
    head->next = NULL;
    
    addnode(30);
    addnode(50);
    addnode(40);
    addnode(60);
    addnode(70);

    delete_node(40);
    printnode();
    printf("\n");

    return 0;
}