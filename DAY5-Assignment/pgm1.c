#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define URL_LENGTH 100

typedef struct {
    char urls[MAX_PAGES][URL_LENGTH];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_PAGES - 1;
}

void push(Stack *s, char url[]) {
    if (!isFull(s)) {
        strcpy(s->urls[++s->top], url);
    }
}

char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->urls[s->top--];
    }
    return NULL;
}

char* peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->urls[s->top];
    }
    return NULL;
}

void visitPage(Stack *back, Stack *forward, char url[], char **current) {
    if (*current) {
        push(back, *current);
    }
    *current = url;
    while (!isEmpty(forward)) {
        pop(forward); // Clear forward history
    }
    printf("Visited: %s\n", *current);
}

void goBack(Stack *back, Stack *forward, char **current) {
    if (!isEmpty(back)) {
        push(forward, *current);
        *current = pop(back);
        printf("Action: Go Back\nCurrent Page: %s\n", *current);
    } else {
        printf("No pages in back history!\n");
    }
}

void goForward(Stack *back, Stack *forward, char **current) {
    if (!isEmpty(forward)) {
        push(back, *current);
        *current = pop(forward);
        printf("Action: Go Forward\nCurrent Page: %s\n", *current);
    } else {
        printf("No pages in forward history!\n");
    }
}

int main() {
    Stack backHistory, forwardHistory;
    initStack(&backHistory);
    initStack(&forwardHistory);
    
    char *currentPage = NULL;
    
    visitPage(&backHistory, &forwardHistory, "google.com", &currentPage);
    visitPage(&backHistory, &forwardHistory, "github.com", &currentPage);
    visitPage(&backHistory, &forwardHistory, "stackoverflow.com", &currentPage);
    
    goBack(&backHistory, &forwardHistory, &currentPage);
    goForward(&backHistory, &forwardHistory, &currentPage);
    
    return 0;
}
