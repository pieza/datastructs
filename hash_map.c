#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"

int hash(const char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (31 * hash + key[i]) % SIZE;
    }
    return hash;
}

Node* createNode(const char *key, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Error creating new node");
        exit(EXIT_FAILURE);
    }
    newNode->pair.key = strdup(key);
    newNode->pair.value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(HashMap *map, const char *key, int value) {
    int index = hash(key);
    Node *newNode = createNode(key, value);
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int get(HashMap *map, const char *key) {
    int index = hash(key);
    Node *current = map->buckets[index];
    while (current != NULL) {
        if (strcmp(current->pair.key, key) == 0) {
            return current->pair.value;
        }
        current = current->next;
    }
    return -1;
}
