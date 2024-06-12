#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
NODE * root=NULL;


void preorder(NODE *p)
{
    if(p!=NULL)
    {
        printf("%d", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(NODE *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d", p->data);
        inorder(p->right);
    }
}

void postorder(NODE *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d", p->data);
    }
}

int search(int key)
{
    NODE *p;
    p=root;
    while(p!=NULL && p->data!=key)
    {
        if(key>p->data)
            p=p->right;
        else
            p=p->left;
    }
    if(p==NULL)
        return 0;
    else
        return 1;
}


int insert(int key)
{
    NODE *ptr, *p, *prev;
    ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("BST is full");
        return 0;
    }
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=key;

    if(root==NULL)
        root=ptr;

    else
    {
        p=root;
        prev=NULL;
        while(p != NULL && p->data!=key)
        {
            prev=p;
            if(key > p->data) {
                p=p->right;
            }
            else{
                p=p->left;
            }
        }

        if(p->data==key)
        {
            printf("Duplicate key not allowed");
            return -1;
        }
        if(key>prev->data)
            prev->right=ptr;
        else
            prev->left=ptr;
    }
    return 1;
}

int minimum()
{
    NODE *p;
    p=root;
    if(root==NULL)
        return 0;

    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p->data;
}

int maximum()
{
    NODE *p;
    p=root;
    if(root==NULL)
        return 0;

    while(p->right!=NULL)
    {
        p=p->right;
    }
    return p->data;
}


int delete_node(int key)
{
    NODE *p, *prev;
    NODE *s, *prev_s;
    p=root;
    prev=NULL;
    while(p!=NULL && p->data!=key)
    {
        prev=p;

        if(key>p->data)
            p=p->right;
        else
            p=p->left;
    }
    if(p==NULL)
    {
        printf("Key not found");
        return -1;
    }

    if(p->left==NULL && p->right==NULL) ///CASE 1
    {

        if(p==root) ///or prev==NULL /// Case 1.1
        {
            root=NULL;
        }
        else if(prev->left==p) /// Case 1.2
        {
            prev->left=NULL;
        }
        else /// Case 1.3
        {
            prev->right=NULL;
        }

        free(p);
        return 1; ///return key
    }
    else if(p->left!=NULL && p->right==NULL) ///CASE 2
    {
        if(p==root) ///Case 2.1
        {
            root=p->left;
        }
        else if(prev->left==p) ///Case 2.2
        {
            prev->left=p->left;
        }
        else /// Case 2.3
        {
            prev->right=p->left;
        }
        p->left=NULL;
        free(p);
        return 1;
    }

    else if(p->left==NULL && p->right!=NULL) /// CASE 3
    {
        if(p==root) /// Case 3.1
        {
            root=p->right;
        }
        else if(prev->left==p) ///Case 3.2
        {
            prev->left=p->right;
        }
        else ///Case 3.3
        {
            prev->right= p->right;
        }
        p->right=NULL;
        free(p);
        return 1;
    }

    else
    {
        s=p->right;
        prev_s=p;
        while(s->left!=NULL)
        {
            prev_s=s;
            s=s->left;
        }
        p->data=s->data;

        if(s==p->right)
            prev_s->right=s->right;
        else
            prev_s->left= s->right;

        s->right=NULL;
        free(s);
        return 1;
    }
}


void main()
{
    int option,res,input,c=0;
    NODE * key;
    do
    {
        printf("Enter the option \n 1.Insert \n 2.Delete \n 3.Preorder \n 4.Postorder \n 5.Inorder \n 6. Search 7. Minimum \n 8. Maximum \n 9. Quit \n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter value\n");
            scanf("%d",&input);
            res=insert(input);
            if(res==1)
                printf("Element inserted");
            else
                printf("Element not inserted");
            break;

        case 2:
            printf("enter value\n");
            scanf("%d",&input);
            res=delete_node(input);
            if(res==0)
                printf("Element not deleted");
            else
                printf("Element deleted");
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            printf("enter key to search\n");
            scanf("%d",&input);
            key=search(input);
            if(key==1)
                printf("Element found");
            else
                printf("Element not found");
            break;
        case 7:
            key=minimum();
            if(key==0)
                printf("Tree is empty");
            else
                printf("Minimum key is %d", key);
            break;
        case 8:
            key=maximum();
            if(key==0)
                printf("Tree is empty");
            else
                printf("Maximum key is %d", key);
            break;

        case 9:
            break;

        default:
            printf("Invalid option");
            break;

        }

    }
    while(option!=9);
}






/*
Step 1:
Search for the key.. if not found => fail and return..
    If found, continue..
    We will have to keep p and prev while searching

Step 2:


CASE 1: p is leaf node

Case 1.1 : p has no parent, i.e it is a single node
Mark root as NULL

Case 1.2 : p is left child of prev
prev-> left =NULL


Case 1.3:
p is right child of prev
prev->right = NULL


CASE 2:
p-> left is NOT NULL AND right is NULL

Case 2.1:
p has no parent, i.e p is root
root= p->left


Case 2.2:
p is left child of prev
prev->left = p-> left


Case 2.3 :
p is right child of prev
prev-> right = p -> left

CASE 3:
p-> left is NULL AND right is NOT NULL

Case 3.1:
p has no parent, i.e p is root
root = p->right

Case 3.2:
p is left child of prev
prev-> left = p->right

Case 3.3 :
p is right child of prev
prev-> right = p->right
*/













