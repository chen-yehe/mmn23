#include <stdio.h>
#include <math.h>
#include <malloc.h>


struct Node *head, *tail, *curr;
void createFibList(int);
void printFibList(struct Node *head);
double n;


/*Linked list node */
struct Node{
    int data;
    struct Node *next;
};


/*
*This program recieves a positive integer number from the user, creates a circular
*linked list that represents the fiboncci sequence of that number, and finally prints it.
*/

int main() {
    printf("\n*****WELCOME TO FIBONACCI PROGRAM!***** \n\n");
    printf("Please enter a POSITIVE INTEGER: \n");
    scanf("%le", &n);

    if((ceil(n) == n) && n > 0){ /*The ceiling value of n equals to n, therefor, n is an integer.*/
        createFibList(n);
        printFibList(head);

    }

    else{ /*If the input is not integer or negtive, exit the program*/
        printf("\nERROR. Invalid input.\n");
    }

    return 0;
}


/*
*The function gets a number and creates a circular
*linked list that represents the fiboncci sequence of that number.
*/
void createFibList(int n){
    struct Node *beforePrev, *prev;
    int i;
    for (i = 0 ; i < n+1; i++) {

        struct Node *currNode = NULL;
        currNode = malloc(sizeof(struct Node));

        if(i == 0 || i == 1){ /*two first nodes equal to 1*/
            currNode->data = 1;
            if(i == 0){
                tail = currNode;
                beforePrev = currNode;
            } else {
                prev = currNode;
                currNode->next = beforePrev;
            }
        }

        else{ /*curr node data equals to beforePrev + prev. move beforePrev and prev to the next node.*/
            currNode->data = beforePrev->data + prev->data;
            currNode->next = prev;
            beforePrev = prev;
            prev = currNode;
        }
    }

    /*Connects head and tail*/
    head = prev;
    tail->next = head;
}

/*
The function gets a parameter, which is a pointer to the head of a circular linked list and prints it.
*/
void printFibList(struct Node *head){
    int size = (int)n;
    printf("\nPrinting the fibonacci list for n = %d :\n\n", size);
    curr = head;
    do{
        printf("%d \n", curr->data);
	free(curr);
        curr = curr->next;

    }while(curr != head); /*as long as curr pointer doesn't get back to head*/
}
