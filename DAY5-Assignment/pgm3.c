#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char song[50];
    struct Node* next;
} Node;

void insertSong(Node** head, char* songName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, songName);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void playSongs(Node* head) {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Node* current = head;
    do {
        printf("Current Song: %s\n", current->song);
        printf("Next Song: %s\n", current->next->song);
        current = current->next;
    } while (current != head);
}

int main() {
    Node* playlist = NULL;
    
    insertSong(&playlist, "Song A");
    insertSong(&playlist, "Song B");
    insertSong(&playlist, "Song C");
    
    playSongs(playlist);
    
    return 0;
}
