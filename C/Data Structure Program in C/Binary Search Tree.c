#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;


void insertion();
void predisplay(struct node *root);
void indisplay(struct node *root);
void postdisplay(struct node *root);
struct node* deletion(struct node* root, int data);
struct node* maxvalue(struct node* root);
int search(struct node* root,int item);

int main(){
    printf("\n*********** BINARY SEARCH TREE **********\n");
    while(1){
        int choice,data,loc,item;
        char ch;
        printf("\n1. Insertion \n2. Deletion \n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Search\n7. Exit\n");
        printf("\nChoose an option (1-6) : ");
        scanf("%d",&choice);
        switch(choice){
        case 1: {
            insertion();
            break;
        }
        case 2: {
            printf("Enter number to delete from BST : ");
            scanf("%d",&data);
            deletion(root, data);
            break;
        }
        case 3: {
            predisplay(root);
            break;
        }
        case 4: {
            indisplay(root);
            break;
        }
        case 5: {
            postdisplay(root);
            break;
        }
        case 6: {
            printf("Enter search item : ");
            scanf("%d",&item);
            loc = search(root,item);
            if(loc == -1) printf("Data not found in binary search tree");
            else printf("Data Found!!");
            break;
        }
        case 7: {
            exit(0);
        }
        default : printf("\nSorry , Invalid option. Please try again");
        }
        printf("\n_________________________________________\n");
    }
    return 0;
}
void insertion(){
    struct node* temp,*parent;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->left = temp->right = NULL;
    if(root == NULL){
        root = temp;
    }
    else {
        struct node* current;
        current = root;
        while(current!= NULL){
            parent = current;
            if (temp->data > current->data){
                current = current->right;
            }
            else {
                current = current->left;
            }
        }
        if(temp->data >parent->data){
            parent->right = temp;
        }
        else {
            parent->left = temp;
        }
    }
}
void predisplay(struct node *root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        predisplay(root->left);
        predisplay(root->right);
    }
}
void indisplay(struct node *root){
    if(root != NULL)
    {
        indisplay(root->left);
        printf("%d ", root->data);
        indisplay(root->right);
    }
}
void postdisplay(struct node *root){
    if(root != NULL)
    {
        postdisplay(root->left);
        postdisplay(root->right);
        printf("%d ", root->data);
    }
}
struct node* deletion(struct node* root, int data){

    if(root == NULL) return root;
    else if (data < root->data) root->left = deletion(root->left,data);
    else if (data > root->data) root->right = deletion(root->right,data);
    else {
            // No Child
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
            // 1 Child
        else if(root->left == NULL){
            struct node* temp=root;
            root= root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct node* temp=root;
            root= root->left;
            free(temp);
        }
        // 2 Child
        else {
            struct node* temp;
            temp = maxvalue(root->right);
            root->data = temp->data;
            root->right = deletion(root->right,temp->data);
        }
    }
    return root;
}
struct node* maxvalue(struct node* root){
    struct node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
int search(struct node* root,int item){
    int i=0;
    struct node* current=root;

    while(current!=NULL){
        if (root == NULL) return -1;
        if (root->data == item)
        return i;
        if (root->data < item){
        return search(root->right, item);
        }
        return search(root->left, item);
        }
    return -1;
}
