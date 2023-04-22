//用链表保存m个整数，|date|<=n,设计一个高效算法，把链表中date绝对值相等的节点仅保留第一次出现节点而删除其余绝对值相等的节点
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 创建链表
Node *createList(int m, int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail = head;
    for (int i = 0; i < m; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        if (abs(newNode->data) <= n) // 判断绝对值是否小于等于 n
        {
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            free(newNode); // 如果绝对值大于 n，直接释放该节点内存
        }
    }
    return head;
}

// 删除重复节点
/*使用 prev 和 curr 两个指针遍历链表，
并使用 cnt 数组统计节点数据的出现次数，
如果某个节点数据已经出现过，就删除该节点，
并将 curr 指向下一个节点；*/
void deleteDuplicates(Node *head)
{
    int cnt[100] = {0}; // 统计节点数据的出现次数
    Node *prev = head;
    Node *curr = head->next;
    while (curr)
    {
        if (cnt[abs(curr->data)] == 0) // 如果该节点数据未出现过，将其出现次数加 1，并继续向下遍历
        {
            cnt[abs(curr->data)]++;
            prev = curr;
            curr = curr->next;
        }
        else // 如果该节点数据已经出现过，删除该节点并将 curr 指向下一个节点
        {
            Node *temp = curr;
            curr = curr->next;//指针向后移动跳过这个节点
            prev->next = curr;//这个节点前面的节点的指针域跳过它指向下一个
            free(temp);//释放这个节点的内存；
        }
    }
}

// 输出链表
void printList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("输入表长: ");
    scanf("%d", &m);
    printf("输入最大值: ");
    scanf("%d", &n);

    printf("请输入链表: ");
    Node *head = createList(m, n); // 创建链表

    printf("链表为: ");
    printList(head);

    printf("删除绝对值相等的节点后链表为: ");
    deleteDuplicates(head); // 删除重复节点
    printList(head);

    return 0;
}
