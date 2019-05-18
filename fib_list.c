#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "Node.h"

double n;
struct Node *head, *tail, *curr;

void createFibList(int);
void printFibList(struct Node *head);

int main() {
    printf("\n*****WELCOME TO FIBONACCI PROGRAM!***** \n\n");
    printf("Please enter a POSITIVE INTEGER: \n");
    scanf("%le", &n);

    if((ceil(n) == n) && n > 0){
        createFibList(n);
        printFibList(head);

    }

    else{
        printf("\nERROR. Invalid input.\n");
    }

    return 0;
}


void createFibList(int n){
    struct Node *beforePrev, *prev;
    int i;
    for (i = 0 ; i < n+1; i++) {

        struct Node *currNode = NULL;
        currNode = malloc(sizeof(struct Node));

        if(i == 0 || i == 1){
            currNode->data = 1;
            if(i == 0){
                tail = currNode;
                beforePrev = currNode;
            } else {
                prev = currNode;
                currNode->next = beforePrev;
            }
        }

        else{
            currNode->data = beforePrev->data + prev->data;
            currNode->next = prev;
            beforePrev = prev;
            prev = currNode;
        }
    }

    head = prev;
    tail->next = head;
}

void printFibList(struct Node *head){
    int size = (int)n;
    printf("\nPrinting the fibonacci list for n = %d :\n\n", size);
    curr = head;
    do{
        printf("%d \n", curr->data);
        curr = curr->next;

    }while(curr != head);
}
