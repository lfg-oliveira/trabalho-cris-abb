#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct BNo
{
    int *keys;
    struct BNo **children;
    struct BNo *parent;

    int deg;
    int last;
} BNo;

BNo *raiz = NULL;

void split(BNo **);
void printNode(BNo *);
void createRoot(BNo **, int, int);
void createNodeWithArray(BNo **, int *, int, int);
void insertInto(BNo **, int);
void merge(BNo **, BNo *);
// procura o nó a esquerda da chave com valor key
BNo *left(BNo *raiz, int key);
// procura o nó a direita da chave com valor key
BNo *right(BNo *raiz, int key);

void printNode(BNo *root)
{
    for (int i = 0; i <= root->last; i++)
    {
        printf("%d ", (root->keys)[i]);
    }
    printf("\n");
}

void createRoot(BNo **root, int key, int max)
{
    *root = (BNo *)calloc(1, sizeof(BNo));
    BNo *helper = *root;
    helper->children = NULL;
    helper->parent = NULL;
    helper->last = 0;
    helper->keys = (int *)calloc(helper->deg, sizeof(int));
    (helper->keys)[0] = key;

    helper->deg = (max > 2) ? max : 3;
}

void insertInto(BNo **root, int key)
{
    if (!(*root))
    {
        createRoot(root, key, 3);
        return;
    }
    BNo *helper = *root;
    int *cp = calloc(helper->last + 1, sizeof(int));
    BNo **children = calloc(2, sizeof(BNo *));
    ++(helper->last);

    for (int i = 0; i <= helper->last; i++)
    {
        if ((helper->keys)[i] > key && helper->children[0] == NULL)
        {
            int cp_size = (helper->last + 1 - i) * sizeof(int);
            memcpy(cp, helper->keys + i, cp_size);
            helper->keys[i] = key;
            memcpy(helper->keys + i + 1, cp, cp_size);
            return;
        }
    }
    helper->keys[helper->last] = key;
    // O nó está cheio, quebrando a regra da Arvore B, deve ser feito um split
    if (helper->last == helper->deg)
    {
        split(root);
    }
    free(cp);
    free(children);
}

void split(BNo **root) {
    BNo *helper = *root;
    BNo *r = calloc(1, sizeof(BNo));
    int t = (helper->deg + 1) / 2;
    int n_children = (helper->deg + 1);
    insertInto(&r, helper->keys[t - 1]);
    r->children = malloc(n_children * sizeof(BNo));

    for (int i = 0; i < n_children && r->children; i++)
    {
        r->children[i] = NULL;
    }

    BNo *l = NULL;
    int *l_keys = calloc(helper->deg, sizeof(int));
    BNo *ri = NULL;
    int *ri_keys = calloc(helper->deg, sizeof(int));
    memcpy(l_keys, helper->keys, (t - 1) * sizeof(int));
    memcpy(ri_keys, helper->keys + t, (t - 1)*sizeof(int));
    createNodeWithArray(&l, l_keys, t-1, helper->deg);
    createNodeWithArray(&ri, ri_keys, t-1, helper->deg);
    l->parent = r;
    ri->parent = r;

    // *(left(r, r->keys[0])) = l;
    // *(right(r, r->keys[0])) = ri;
}

void createNodeWithArray(BNo **root, int *arr, int size, int degree)
{
    degree = (degree > 2) ? degree : 3;

    *root = calloc(1, sizeof(BNo));
    BNo *helper = *root;

    helper->keys = calloc(helper->deg, sizeof(BNo));
    helper->children = NULL;
    helper->parent = NULL;
    helper->deg = degree;
    for (int i = 1; i <= size; i++){
        helper->keys[i - 1] = arr[i - 1];
    }
    helper->last = size-1;
}

int BSearch(BNo *root, int key) {
    int l = 0;
    int r = root->last;
    int m;
    while(l != r)
    {
        m = (l + r) / 2;
        if (key < root->keys[m])
        {
            r = m - 1;
        }
        if(key > root->keys[m])
        {
            l = m + 1;
        }
        if(key == root->keys[m])
        {
            l = r;
        }
    }
    return m;
}

BNo *left(BNo *root, int key){

}
