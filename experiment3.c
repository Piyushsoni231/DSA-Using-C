#include <stdio.h>
#include <string.h>

#define MAX 100

char books[MAX][50];
int top = -1;

void addBook(char book[]) {
    if (top == MAX - 1) {
        printf("Stack is full. Can't add more books.\n");
        return;
    }
    top++;
    strcpy(books[top], book);
    printf("Book '%s' added to the stack.\n", book);
}

void removeBook() {
    if (top == -1) {
        printf("No books to remove. Stack is empty.\n");
        return;
    }
    printf("Book '%s' removed from the stack.\n", books[top]);
    top--;
}

void viewRecentBook() {
    if (top == -1) {
        printf("No books in the stack.\n");
        return;
    }
    printf("Most recent book: %s\n", books[top]);
}


void displayBooks() {
    if (top == -1) {
        printf("No books in the stack.\n");
        return;
    }
    printf("Books in the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", books[i]);
    }
}

int main() {
    int choice;
    char book[50];

    while (1) {
        printf("\nBook Management System\n");
        printf("1. Add a returned book\n");
        printf("2. Remove the most recent book\n");
        printf("3. View the most recent book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the book name: ");
                scanf(" %[^\n]%*c", book); // To accept multi-word book names
                addBook(book);
                break;
            case 2:
                removeBook();
                break;
            case 3:
                viewRecentBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
  return 0;
}