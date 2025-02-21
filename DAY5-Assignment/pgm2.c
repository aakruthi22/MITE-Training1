#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char items[MAX_ITEMS][ITEM_NAME_LENGTH];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_ITEMS - 1;
}

void push(Stack *s, char item[]) {
    if (!isFull(s)) {
        strcpy(s->items[++s->top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Stock is full! Cannot add more items.\n");
    }
}

char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return NULL;
}

void displayStock(Stack *s) {
    if (isEmpty(s)) {
        printf("No stock remaining.\n");
        return;
    }
    printf("Remaining Stock: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%s", s->items[i]);
        if (i < s->top) printf(", ");
    }
    printf("\n");
}

int main() {
    Stack warehouse;
    initStack(&warehouse);
    
    push(&warehouse, "Item A");
    push(&warehouse, "Item B");
    push(&warehouse, "Item C");
    
    printf("\nDispatching Item: %s\n", pop(&warehouse));
    displayStock(&warehouse);
    
    return 0;
}
