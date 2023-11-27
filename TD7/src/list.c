#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int valeur;
    struct list *suivant;
} List;

// Ajouter la valeur v au début de la liste lst
void prepend_element(List **lst, int v) {
    if (*lst == NULL) {
        *lst = malloc(sizeof(List));
        (*lst)->valeur = v;
        (*lst)->suivant = NULL;
    } else {
        List *new = malloc(sizeof(List));
        new->valeur = v;
        new->suivant = *lst;
        *lst = new;
    }
}

// Ajouter la valeur v à la fin de la liste lst
void append_element(List **lst, int v) {
    if (*lst == NULL) {
        *lst = malloc(sizeof(List));
        (*lst)->valeur = v;
        (*lst)->suivant = NULL;
    } else {
        List *new = malloc(sizeof(List));
        new->valeur = v;
        new->suivant = NULL;
        List *tmp = *lst;
        while (tmp->suivant) {
            tmp = tmp->suivant;
        }
        tmp->suivant = new;
    }
}

// Ajouter la valeur v dans la liste ordonnée lst
void insert_element(List **lst, int v) {
    if (*lst == NULL) {
        *lst = malloc(sizeof(List));
        (*lst)->valeur = v;
        (*lst)->suivant = NULL;
    } else {
        List *new = malloc(sizeof(List));
        new->valeur = v;
        new->suivant = NULL;
        List *tmp = *lst;
        while (tmp->suivant && (tmp->suivant->valeur < new->valeur)) {
            tmp = tmp->suivant;
        }
        new->suivant = tmp->suivant;
        tmp->suivant = new;
    }
}

// Supprimer la (première) valeur égale à v de la liste lst
void delete_element(List **lst, int v) {
    if (*lst != NULL) {
        List *tmp = *lst;
        if (tmp->valeur == v) {
            *lst = tmp->suivant;
            free(tmp);
        } else {
            while (tmp->suivant && (tmp->suivant->valeur != v)) {
                tmp = tmp->suivant;
            }
            if (tmp->suivant) {
                List *tmp2 = tmp->suivant;
                tmp->suivant = tmp2->suivant;
                free(tmp2);
            }
        }
    }
}

// Supprimer tous les éléments égaux à v dans la liste lst
void delete_elements(List **lst, int v) {
    while (*lst != NULL && (*lst)->valeur == v) {
        List *tmp = *lst;
        *lst = (*lst)->suivant;
        free(tmp);
    }

    if (*lst != NULL) {
        List *tmp = *lst;
        while (tmp->suivant) {
            if (tmp->suivant->valeur == v) {
                List *tmp2 = tmp->suivant;
                tmp->suivant = tmp2->suivant;
                free(tmp2);
            } else {
                tmp = tmp->suivant;
            }
        }
    }
}



// Tester si la valeur v est dans liste lst
int find_element(List lst, int v) {
    while (lst.suivant) {
        if (lst.valeur == v) return 1;
        return find_element(*lst.suivant, v);
    }
    return 0;
}

// Imprimer la liste lst
void print_list(List *lst) {
    while (lst->suivant) {
        printf("-------\n|  %d  |\n", lst->valeur);
        lst = lst->suivant;
    }
    printf("-------\n|  %d  |\n-------\n", lst->valeur);
}

int main() {
    List *lst = NULL;
    prepend_element(&lst, 8);
    prepend_element(&lst, 6);
    prepend_element(&lst, 4);
    append_element(&lst, 10);
    insert_element(&lst, 7);
    insert_element(&lst, 6);
    print_list(lst);
    delete_element(&lst, 4);
    print_list(lst);
    delete_elements(&lst, 6);
    print_list(lst);
    printf("4 in list ? %d\n", find_element(*lst, 4));
    printf("9 in list ? %d", find_element(*lst, 8));
    return 0;
}