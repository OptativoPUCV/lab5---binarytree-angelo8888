#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    if (new == NULL || pair === NULL){
        return NULL;
    }
pair->key = key;
pair->value = value;
new->pair = pair;
new->parent = new->left = new->right = NULL;
return new;
}


TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    TreeMap* map = (TreeMap*)malloc(sizeof(TreeMap));
    map->root = NULL;
    map->current = NULL;
    map->lower_than = lower_than;
    return map;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    if (searchTreeMap(tree, key) != NULL) {
        return;
    }

    TreeNode* newNode = createTreeNode(key, value);
    if (newNode == NULL) {
        return;
    }

    TreeNode* parent = NULL;
    TreeNode* current = tree->root;

    while (current != NULL) {
        parent = current;
        if (tree->lower_than(key, current->pair->key) < 0){
            current = current->left;
        } 
        else{
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (parent == NULL) {
        tree->root = newNode; // Árbol vacío
    } else if (tree->lower_than(key, parent->pair->key) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

TreeNode * minimum(TreeNode * x){
    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}

Pair * searchTreeMap(TreeMap * tree, void* key) {
    TreeNode* current = tree->root;
    while (current != NULL) {
        int cmp = tree->lower_than(key, current->pair->key);
        if (cmp == 0) {
            tree->current = current;
            return current->pair;
        } else if (cmp < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
