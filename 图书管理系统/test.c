#include <stdio.h>
#include <stdlib.h>

struct Info {
    int id;
    char name[20];
};

void Output_BookInfo(struct Info* bth) {
    printf("ID: %d\n", bth->id);
    printf("Name: %s\n", bth->name);
}

struct Info* Search(struct Info* bth, int x, int* k, int* flag) {
    struct Info* p = bth;
    *k = 0;
    *flag = 0;
    while (p->id != -1) {
        (*k)++;
        if (p->id == x) {
            *flag = 1;
            return p;
        }
        p++;
    }
    return NULL;
}

int main() {
    struct Info book[3] = {{1, "book1"}, {2, "book2"}, {-1, ""}};
    int k = 0;
    int flag = 0;
    struct Info* p = Search(book, 2, &k, &flag);
    if (flag == 1) {
        Output_BookInfo(p);
        printf("Search times: %d\n", k);
    } else {
        printf("Not found!\n");
        printf("Search times: %d\n", k);
    }
}