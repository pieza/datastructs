#ifndef HASH_MAP_H
#define HASH_MAP_H

#define SIZE 10

typedef struct {
    char *key;
    int value;
} Pair;

typedef struct node {
    Pair pair;
    struct node *next;
} Node;

typedef struct {
    Node *buckets[SIZE];
} HashMap;

int hash(const char *key);
Node* createNode(const char *key, int value);
void insert(HashMap *map, const char *key, int value);
int get(HashMap *map, const char *key);

#endif /* HASH_MAP_H */
