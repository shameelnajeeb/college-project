#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

void display(struct node*head){
    struct node *temp=head;
    if(head==NULL){
        printf("Linked list is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
struct node* insertAtBeginning(struct node *head, int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Memory allocation failed!\n");
        return head;

    }
    newnode->data = value;
    newnode->next =head;
    head = newnode;
    return head;
}
struct node* instertAtEnd(struct node* head, int value){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Memory allocation failed!\n");
        return head;
    }
    newnode->data = value;
    newnode->next = NULL;
    if (head==NULL){
        return newnode;
    }
    struct node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
struct node* insertAfterNode(struct node* head, int targetvalue, int value){
    struct node *temp = head;
    while(temp != NULL && temp->data != targetvalue){
        temp = temp-> next;
    }
    if(temp == NULL){
        printf("Node with value %d not found in the list!\n", targetvalue);
        return head;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Memory allocation failed!\n");
        return head;
    }
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
struct node* deleteFromBeginning(struct node* head){
    if (head == NULL){
        printf("List is already empty! NOthing to delete.\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted successfully.\n");
    return head;
}
struct node* deleteFromEnd(struct node* head){
     if (head == NULL){
        printf("List is already empty! NOthing to delete.\n");
        return NULL;
    }

}
int main(){
    struct node *head=NULL,*newnode,*temp;
    int choice=1;
    while(choice == 1){
        newnode =(struct node*)malloc(sizeof(struct node));
        if(newnode == NULL){
            printf("Memory allocation failed\n");
            break;
        }
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if (head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to insert more data?(1 for yes, 0 for no):");
        scanf("%d", &choice);
    }
    printf("The linked list is:");
    display(head);
    printf("\nthe linked list after inserting 10 at the beginning: ");
    head = insertAtBeginning(head, 10);
    display(head);
    printf("\nThe linked list after inserting 200 at the end is: ");
    display(instertAtEnd(head, 200));
    printf("\nThe linked list after insterting 300 in between is: ");
    display(insertAfterNode(head, 300,400));
    printf("\nThe linked list after deleting from beginning is: ");
    head = deleteFromBeginning(head);
    display(head);
    return 0;


}