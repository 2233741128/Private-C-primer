#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[20];
    char author[20];
    int status;
    struct Book* next;
};

struct Book* head = NULL;

void AddBook() {
	system("cls");
    struct Book* p = (struct Book*)malloc(sizeof(struct Book));
    printf("Please input book id: ");
    scanf("%d", &p->id);
    printf("Please input book name: ");
    scanf("%s", p->name);
    printf("Please input book author: ");
    scanf("%s", p->author);
    p->status = 0;
    p->next = head;
    head = p;
}

void RemoveBook() 
{
	system("cls");
    int id;
    printf("Please input book id: ");
    scanf("%d", &id);
    struct Book* p = head;
    struct Book* q = NULL;
    while (p != NULL) {
        if (p->id == id) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("Remove book successfully!\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("Book not found!\n");
}

void SearchBook() 
{
	system("cls");
    int id;
    printf("Please input book id: ");
    scanf("%d", &id);
    struct Book* p = head;
    while (p != NULL) 
	{
        if (p->id == id) {
            printf("Book id: %d\n", p->id);
            printf("Book name: %s\n", p->name);
            printf("Book author: %s\n", p->author);
            if (p->status == 0) {
                printf("Book status: available\n");
            } else {
                printf("Book status: borrowed\n");
            }
            return;
        }
        p = p->next;
    }
    printf("Book not found!\n");
}

void BorrowBook() {
	system("cls");
    int id;
    printf("Please input book id: ");
    scanf("%d", &id);
    struct Book* p = head;
    while (p != NULL) {
        if (p->id == id) {
            if (p->status == 0) {
                p->status = 1;
                printf("Borrow book successfully!\n");
            } else {
                printf("The book has been borrowed!\n");
            }
            return;
        }
        p = p->next;
    }
    printf("Book not found!\n");
}

void ReturnBook() {
	system("cls");
    int id;
    printf("Please input book id: ");
    scanf("%d", &id);
    struct Book* p = head;
    while (p != NULL) {
        if (p->id == id) {
            if (p->status == 1) {
                p->status = 0;
                printf("Return book successfully!\n");
            } else {
                printf("The book has not been borrowed!\n");
            }
            return;
        }
        p = p->next;
    }
}

int main() {
    int choice = 0;

    while (1) {
        printf("\n1. Add book\n");
        printf("2. Remove book\n");
        printf("3. Search book\n");
        printf("4. Borrow book\n");
        printf("5. Return book\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddBook();
                break;

            case 2:
                RemoveBook();
                break;

            case 3:
                SearchBook();
                break;

            case 4:
                BorrowBook();
                break;

            case 5:
                ReturnBook();
                break;

            case 6:
                exit(0);

            default:
                break;
        }
   }

   return 0;
}