#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *add;
};struct node *start = NULL,*temp,*new1,*next,*prev;
void create(){
    char ch;
    int n;
    printf("Enter an element :");
    scanf("%d",&n);
    start = (struct node*)(malloc(sizeof(struct node)));
    start->data = n;
    start->add = NULL;
    temp = start;
    printf("Want to continue :");
    ch = getche();
    while(ch=='y'||ch=='Y'){
        printf("\nEnter next element :");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1->data = n;
        new1->add = NULL;
        temp->add = new1;
        temp = temp->add;
        printf("want to continue :");
        ch = getche();

    }
}
void display(){
    if(start==NULL){
        printf("List not found ");
    }
    else{
        temp = start;
        while(temp!=NULL){
            printf("\t %d",temp->data);
            temp = temp->add;
        }
    }
}
int insert_first(){
    int n;
    if(start==NULL){
    printf("list not found");
}
else{
    printf("Enter new element for insert :");
    scanf("%d",&n);
    new1 = (struct node*)(malloc(sizeof(struct node)));
    new1->data=n;
    new1->add=NULL;
    new1->add=start;
    start=new1;
}
return 0;
}
int insert_last(){
    int n;
   if(start==NULL){
    printf("List not found");
   }
   else{
    printf("enter your element for insert :");
    scanf("%d",&n);
    new1 = (struct node*)(malloc(sizeof(struct node)));
    new1->data=n;
    new1->add=NULL;
    temp = start;
    while(temp->add!=NULL){
        temp = temp->add;
    }
    temp->add=new1;
   }
   return 0;
}
 int insert_middle(){
    int n,post;
    int i=1;
    if(start==NULL){
        printf("list not found");
    }
    else{
        printf("Enter your element for insert :");
        scanf("%d",&n);
        new1 = (struct node*)(malloc(sizeof(struct node)));
        new1->data=n;
        new1->add=NULL;
        printf("Enter the position :");
        scanf("%d",&post);
        next = start;
        while(i<post){
            prev = next;
            next=next->add;
            i++;
        }
        prev->add=new1;
        new1->add=next;

    }
    return 0;
}
int delete_first(){
    if(start==NULL){
    printf("List not found");
    }
    else{
    temp=start;
    start= start->add;
    printf("Deleted node is %d",temp->data);
    free(temp);

    }
    return 0;
}
int delete_last(){
    if(start==NULL){
        printf("list not found");
    }
    else{
        temp=start;
        while(temp->add!=NULL){
            prev=temp;
            temp=temp->add;
        }
        prev->add=NULL;
        printf("Deleted node is %d",temp->data);
        free(temp);
    }
}
int delete_middle(){
    int pos;
    int i=1;
    if(start==NULL){
        printf("list not found");

    }
    else{
        printf("Enter the position :");
        scanf("%d",&pos);
        temp=start;
        while(i<pos){
            prev=temp;
            temp=temp->add;
            i++;
        }
        next=temp->add;
        prev->add=next;
        printf("Deleted node is %d",temp->data);
        free(temp);
    }
    return 0;
}

int main(){
    int choise;
    do{
    printf("\nEnter your choise :");
    scanf("%d",&choise);
    switch (choise)
    {
    case 1: create();break;
    case 2: display();break;
    case 3: insert_first();break;
    case 4: insert_middle();break;
    case 5: insert_last();break;
    case 6: delete_first();break;
    case 7: delete_last();break;
    case 8: delete_middle();break;
    default:printf("Invlid choise");
    }
    }while(choise!=0);
    return 0;
}

