#include <stdio.h>
#include <stdlib.h>

/*
push_item pour ajouter un élément au sommet de la pile;
 pop_item pour enlever un élément de la pile (c’est-à-dire le dernier élément qui a été empilé) ;
 top_value qui renvoie l’entier en sommet de pile (sans l’enlever de la pile);
 print_stack pour imprimer le contenu de la pile.
*/

struct element {
    int valeur;
    struct element *suivant;
};
typedef struct element Element;

void push_item(Element **stack, int val) {
    if (*stack == NULL) {
        *stack = malloc(sizeof(Element));
        (*stack)->valeur = val;
        (*stack)->suivant = NULL;
    } else {
        Element *new = malloc(sizeof(Element));
        new->valeur = val;
        new->suivant = *stack;
        *stack = new;
    }
}

void pop_item(Element **stack) {
    if (*stack != NULL) {
        Element *tmp = *stack;
        *stack = (*stack)->suivant;
        free(tmp);
    }
}

int top_value(Element *stack) {
    if (stack != NULL) {
        return stack->valeur;
    }
    return -1;
}

void print_stack(struct element *stack) {
    while (stack->suivant) {
        printf("-------\n|  %d  |\n", stack->valeur);
        stack = stack->suivant;
    }
    printf("-------\n|  %d  |\n-------\n", stack->valeur);
}

int main() {
    Element *stack = NULL;
    push_item(&stack, 1);
    push_item(&stack, 2);
    push_item(&stack, 3);
    print_stack(stack);
    printf("\n");
    pop_item(&stack);
    print_stack(stack);
    return 0;
}

