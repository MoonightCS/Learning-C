#include <stdio.h>
#include <stdlib.h>


struct BTNode
{
    int key;
    struct BTNode *left;
    struct BTNode *right;
    struct BTNode *parent;
};

struct BTNode* InterativeTreeSearch(struct BTNode *root, int k) // Поиск ключа в дереве
{
    struct BTNode *x;
    x = root;
    while(x != NULL && k != x->key)
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}


struct BTNode* TreeMinimum(struct BTNode *root)   // минимальный ключ
{
    struct BTNode* x;
    x = root;
    while(x->left != NULL)
        x = x->left;
    return x;
}


struct BTNode* TreeMaximum(struct BTNode *root)   // максимальный ключ
{
    struct BTNode* x;
    x = root;
    while(x->right != NULL)
        x = x->right;
    return x;
}

struct BTNode* TreeSuccesor(struct BTNode* root, struct BTNode* x) // поиск последователя узла
{
    if (x->right != NULL)
        return TreeMinimum(x->right);
    struct BTNode* y;
    y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

struct BTNode* TreePredshestvennik(struct BTNode* root, struct BTNode* x) // поиск предшественника узла
{
    if (x->left != NULL)
        return TreeMaximum(x->left);
    struct BTNode* y;
    y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}
struct BTNode* ModifedSearch(struct BTNode *root, int k) // Модифицированный поиск ключа в дереве
{
    struct BTNode *y, *x;
    y = NULL;
    x = root;
    while(x != NULL && k != x->key)
    {
        y = x;
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (x != NULL)
        y = x;
    return y;
}
void TreeInsert(struct BTNode *root, struct BTNode *z)   // вставка элемента
{
    struct BTNode *y;
    y = ModifedSearch(root, z->key);
    z->parent = y;
    if (y == NULL)
        root = z;
    else
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
}

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
