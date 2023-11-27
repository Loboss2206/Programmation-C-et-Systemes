#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node *tree;

tree create_empty_tree() {
    tree t = NULL;
}

tree add_tree(tree t, int v) {
    if (t == NULL) {
        t = malloc(sizeof(tree));
        t->value = v;
        t->left = NULL;
        t->right = NULL;
    }
    else if (v < t->value) {
        t->left = add_tree(t->left, v);
    }
    else {
        t->right = add_tree(t->right, v);
    }
    return t;
}

void print_tree_recursive(tree t) {
    if (t != NULL) {
        print_tree_recursive(t->left);
        printf("%d ", t->value);
        print_tree_recursive(t->right);
    }
}

void print_tree(tree t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
    } else {
        printf("Tree elements in order: ");
        print_tree_recursive(t);
        printf("\n");
    }
}

tree find_tree(tree t, int v) {
    if (t == NULL) {
        return NULL;
    }
    else if (t->value == v) {
        return t;
    }
    else if (v < t->value) {
        return find_tree(t->left, v);
    }
    else {
        return find_tree(t->right, v);
    }
}

void free_tree(tree t) {
    if (t != NULL) {
        if (t->left != NULL) free_tree(t->left);
        if (t->right != NULL) free_tree(t->right);
        if (t->left == NULL && t->right == NULL) free(t);
    }
}

int main() {
    tree t = create_empty_tree();
// Création de l'arbre du sujet
    t = add_tree(t, 8);
    t = add_tree(t, 3);
    t = add_tree(t, 10);
    t = add_tree(t, 1);
    t = add_tree(t, 6);
    t = add_tree(t, 7);
    t = add_tree(t, 4);
    t = add_tree(t, 14);
    t = add_tree(t, 13);
// Impression de l'arbre (trié)
    printf("Valeurs dans l'arbre: ");
    print_tree(t);
    printf("\n");
// Recherches
    printf("\nRecherches:\n");
    for (int i = 0; i < 20; i++) {
        printf("%2d: %s, ", i, find_tree(t, i) ? "oui" : "non");
        if (i % 5 == 4) printf("\n");
    }
// Free
    printf("\nLibération mémoire de l'arbre\n");
    free_tree(t);
    return 0;
}