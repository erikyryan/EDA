#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define D 1
#define E 2

struct node {
    int key; // valor do nó
    int bal; // fator de balanceamento
    struct node *left; // ponteiro para a subárvore esquerda
    struct node *right; // ponteiro para a subárvore direita
};

bool caso1(struct node *pt, bool *h) {
    struct node *ptu = pt->left;
    if (ptu->bal == -1) {
        pt->left = ptu->right;
        ptu->right = pt;
        pt = ptu;
        pt->right->bal = 0;
    } else {
        struct node *ptv = ptu->right;
        ptu->right = ptv->left;
        ptv->left = ptu;
        pt->left = ptv->right;
        ptv->right = pt;
        if (ptv->bal == 1) {
            pt->bal = 0;
            ptu->bal = -1;
        } else {
            pt->bal = 1;
            ptu->bal = 0;
        }
        pt = ptv;
        pt->bal = 0;
    }
    *h = false;
    return true;
}

void caso2(struct node **pt, bool *h) {
    struct node *ptu = (*pt)->right;
    if (ptu->bal == 1) {
        (*pt)->right = ptu->left;
        ptu->left = *pt;
        *pt = ptu;
        (*pt)->left->bal = 0;
    } else {
        struct node *ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        (*pt)->right = ptv->left;
        ptv->left = *pt;
        if (ptv->bal == -1) {
            (*pt)->bal = 0;
            ptu->bal = 1;
        } else {
            (*pt)->bal = -1;
            ptu->bal = 0;
        }
        *pt = ptv;
        (*pt)->bal = 0;
    }
    *h = false;
}

bool inserirAVL(int x, struct node **pt, bool *h) {
    if (*pt == NULL) {
        *pt = malloc(sizeof(struct node));
        (*pt)->key = x;
        (*pt)->bal = 0;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
        *h = true;
    } else {
        if (x == (*pt)->key) {
            printf("Elemento encontrado\n");
            return false;
        }
        if (x < (*pt)->key) {
            if (inserirAVL(x, &(*pt)->left, h)) {
                switch ((*pt)->bal) {
                    case 1:
                        (*pt)->bal = 0;
                        *h = false;
                        break;
                    case 0:
                        (*pt)->bal = -1;
                        break;
                    case -1:
                        caso1(*pt, h);
                        break;
                }
            }
        } else {
            if (inserirAVL(x, &(*pt)->right, h)) {
                switch ((*pt)->bal) {
                    case -1:
                        (*pt)->bal = 0;
                        *h = false;
                        break;
                    case 0:
                        (*pt)->bal = 1;
                        break;
                    case 1:
                        caso2(pt, h);
                        break;
                }
            }
        }
    }
    return true;
}

int altura(struct node *pt) {
    if (pt == NULL) {
        return 0;
    }
    int altura_esquerda = altura(pt->left);
    int altura_direita = altura(pt->right);
    return 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
}

bool verificaAVL(struct node *pt) {
    if (pt == NULL) {
        return true;
    }
    int bal = altura(pt->right) - altura(pt->left);
    if (bal != pt->bal || abs(bal) > 1) {
        return false;
    }
    return verificaAVL(pt->left) && verificaAVL(pt->right);
}

int contaNos(struct node *pt) {
    if (pt == NULL) {
        return 0;
    }
    return 1 + contaNos(pt->left) + contaNos(pt->right);
}

int main() {
    struct node *raiz = NULL;
    bool h;
    inserirAVL(10, &raiz, &h);
    inserirAVL(20, &raiz, &h);
    inserirAVL(30, &raiz, &h);
    inserirAVL(40, &raiz, &h);
    inserirAVL(50, &raiz, &h);
    printf("Altura da arvore: %d\n", altura(raiz));
    printf("Numero de nos na arvore: %d\n", contaNos(raiz));
    printf("A arvore e AVL? %s\n", verificaAVL(raiz) ? "Sim" : "Nao");
    return 0;
}
