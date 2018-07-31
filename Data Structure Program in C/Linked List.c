#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *root = NULL;

void append();
void display();
void deletee();
int length();
void insertion();
int searching();
void update();
void sorting();

int main(){
    while(1){
    int choice;
    printf("1. Append \n2. Display\n3. Length\n4. Search\n5. Insertion\n6. Update\n7. Delete\n8. Sort\n9. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
    case 1: {
        append();
        break;
    }
    case 2: {
        display();
        break;
    }
    case 3: {
        printf("Length of the List : %d\n",length());
        break;
    }
    case 4: {
        int search = searching();
        if (search == -1) printf("Item does not exist\n");

        else printf("Position is %d\n",search);
        break;
    }

    case 5: {
        insertion();
        break;
    }
    case 6: {
        update();
        break;
    }
    case 7: {
        deletee();
        break;
    }
    case 8: {
        sorting();
        break;
    }
    case 9: {
        exit(1);
        break;
    }
    default: printf("Invalid Option\n");
    }
    printf("\n");
    }
}
void append(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if (root == NULL) {
        root = temp;
    }
    else {
        struct node* p;
        p = root;
        while (p->link!=NULL){
            p = p->link;
        }
        p->link = temp;
    }
}
void display() {
    struct node* temp;
    temp = root;
    if (temp == NULL) printf("List is empty");
    else {
        while (temp!= NULL){
            printf("%d -->",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }

}
int length(){
    int i =0;
    struct node* temp = root;
    while(temp!=NULL){
        i++;
        temp = temp->link;
    }
    return i;
}
void deletee(){
    struct node *temp;
    int loc,len;
    printf("Enter position to delete : ");
    scanf("%d",&loc);
    len = length();
    if(loc > len) {
        printf("Invalid Location\n");
    }
    else if (loc == 0){
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else {
        struct node* p= root, *q;
        int i=0;
        while(i< loc-1){
            p = p->link;
            i++;
        }
        q=p->link ;
        p->link = q->link;
        free(q);
    }
}
void insertion(){
    struct node* temp,*p;
    p = root;
    int loc,len,i=0;
    printf("Enter position : ");
    scanf("%d",&loc);
    len = length();
    if(loc > len) printf("Invalid Position\n");
    else {
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data : ");
        scanf("%d",&temp->data);
        temp->link = NULL;
        if (loc == 0){
            temp = root;
            temp->link = p;
        }
        else {
            while(i<loc-1){
                p=p->link;
                i++;
            }
            temp->link = p->link;
            p->link = temp;
        }
    }
}
int searching(){
    struct node* temp;
    temp = root;
    int i=0, item;
    printf("Enter item to search in the linked list: ");
    scanf("%d",&item);
    while(temp!=NULL){
        if(item == temp->data) {
                return i;}
        temp = temp->link;
        i++;
    }
    return -1;
}
void update(){
        struct node* p;
        p = root;
        int i =0, loc,len;
        printf("Enter location to update : ");
        scanf("%d",&loc);
        len = length();
        if (loc > len-1) printf("Invalid Location\n");
        else {
            while(i<loc){
                p = p->link;
                i++;
            }
            printf("Enter node data to update : ");
            scanf("%d",&p->data);
        }
}
void sorting() {
        struct node *p,*q;
        int k,len,ptr,temp,l;

        len = length();
        for(k=1; k < len ; k++){
            for(l=0; l< len-k; l++){
                p = root;
                q = p->link ;
                while(p->link!=NULL){
                    if(p->data >  q->data){
                        temp = p->data;
                        p->data = q->data;
                        q->data = temp;
                        p = q;
                        q = q->link;
                    }
                    else {
                        p = q;
                        q = q->link;
                    }
                }

            }
        }
    }
