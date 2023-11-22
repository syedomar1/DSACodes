#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    struct Node *left;
    int data;
    int bf;
    struct Node *right;
} *root = NULL;

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->bf = 0;
        p->left = p->right = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->left;
        }
        else if (key > t->data)
        {
            t = t->right;
        }
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right = NULL;
    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}

struct Node *LLRotation(struct Node *p)
{
    int lbf, rbf;
    struct Node *pl = p->left;
    pl->bf = 0;
    p->left = p->right;
    pl->right = p;
    lbf = height(p->left) + 1;
    rbf = height(p->right) + 1;
    p->bf = lbf - rbf;
    if (p == root)
        root = pl;
    return pl; 
}

struct Node *LRRotation(struct Node *p)
{
    int lbf, rbf;
    struct Node *pl = p->left;
    struct Node *plr = pl->right;
    plr->bf = 0;

    p->left = plr->right;
    pl->right = plr->left;
    plr->left = pl;
    plr->right = p;
    lbf = height(p->left) + 1;
    rbf = height(p->right) + 1;
    p->bf = lbf - rbf;

    lbf = height(pl->left) + 1;
    rbf = height(pl->right) + 1;
    pl->bf = lbf - rbf;
    if (p == root)
        root = plr;
    return plr;
}
struct Node *RRRotation(struct Node *p)
{
    int lbf, rbf;
    struct Node *pr = p->right;
    pr->bf = 0;
    p->right = pr->left;
    pr->left = p;
    lbf = height(p->left) + 1;
    rbf = height(p->right) + 1;
    p->bf = lbf - rbf;
    if (p == root)
        root = pr;
    return pr;
}
struct Node *RLRotation(struct Node *p)
{
    int lbf, rbf;
    struct Node *pr = p->right;
    struct Node *prl = pr->left;
    prl->bf = 0;

    p->right = prl->left;
    pr->left = prl->right;
    prl->right = pr;
    prl->left = p;
    lbf = height(p->left) + 1;
    rbf = height(p->right) + 1;
    p->bf = lbf - rbf;

    lbf = height(pr->left) + 1;
    rbf = height(pr->right) + 1;
    pr->bf = lbf - rbf;
    if (p == root)
        root = prl;
    return prl;
}
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    int lbf, rbf;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->bf = 0;
        t->left = t->right = NULL;
        return t;
    }
    if (key < p->data)
        p->left = RInsert(p->left, key);
    else if (key > p->data)
        p->right = RInsert(p->right, key);

    lbf = height(p->left) + 1;
    rbf = height(p->right) + 1;
    p->bf = lbf - rbf;
    if (p->bf == 2 && p->left->bf == 1)
        return LLRotation(p);
    if (p->bf == 2 && p->left->bf == -1)
        return LRRotation(p);
    if (p->bf == -2 && p->right->bf == -1)
        return RRRotation(p);
    if (p->bf == -2 && p->right->bf == 1)
        return RLRotation(p);
    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}
struct Node *Search(int key)
{
    struct Node *t = root;

    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}
int main()
{
    struct Node *temp;
    Insert(30);
    RInsert(root, 50);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 10);
    RInsert(root, 42);
    RInsert(root, 46);

    Inorder(root);
    printf("\n");

    temp = Search(20);
    if (temp != NULL)
        printf("element %d is found\n", temp->data);
    else
        printf("element is not found\n");

    return 0;
}