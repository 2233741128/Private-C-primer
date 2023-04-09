#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAX_BOOKS 100  
  
struct book {  
    char name[50];  
    int quantity;  
};  
  
struct book books[MAX_BOOKS];  
int num_books = 0;  
  
void add_book() {  
    if (num_books >= MAX_BOOKS) {  
        printf("Error: library is full.\n");  
        return;  
    }  
    strcpy(books[num_books].name, "New book");  
    books[num_books].quantity = 1;  
    num_books++;  
    printf("Book added successfully.\n");  
}  
  
void remove_book() {  
    if (num_books <= 0) {  
        printf("Error: library is empty.\n");  
        return;  
    }  
    int index = num_books - 1;  
    strcpy(books[index].name, "Old book");  
    books[index].quantity--;  
    num_books--;  
    printf("Book removed successfully.\n");  
}  
  
void display_books() {  
    printf("Books in library:\n");  
    for (int i = 0; i < num_books; i++) {  
        printf("%s: %d\n", books[i].name, books[i].quantity);  
    }  
}  
  
int main() {  
    int choice;  
    do {  
        printf("\n");  
        printf("1.Add book\n");  
        printf("2. Remove book\n");  
        printf("3. Display books\n");  
        printf("4. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch (choice) {  
            case 1:  
                add_book();  
                break;  
            case 2:  
                remove_book();  
                break;  
            case 3:  
                display_books();  
                break;  
            case 4:  
                printf("Goodbye!\n");  
                exit(0);  
            default:  
                printf("Invalid choice.\n");  
        }  
    } while (choice != 4);  
    return 0;  
}