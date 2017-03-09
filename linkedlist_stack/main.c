//
//  main.c
//  linkedlist_stack
//
//  Created by 楊博名 on 2016/11/14.
//  Copyright © 2016年 楊博名. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node* creates(void);         // ´ÿ•ﬂ∞Ô≈|
int isEmpty(Node*);           // ∞Ô≈|§w™≈
Node* add(Node*, int);   // ∑sºW§∏Ø¿
Node* del(Node*);     // ßR∞£§∏Ø¿
void list(Node*);      // ≈„•‹©“¶≥§∫Æe

int main(void) {
    Node* sTop;
    int input, select;
    
    sTop = creates(); //∂«¶^top™∫≠»
    
    while(1) {
        printf("\n\nenter option (-1 to quit)");
        printf("\n(1)add");
        printf("\n(2)delete");
        printf("\n(3)display\n\n");
        scanf("%d", &select);
        
        if(select == -1)
            break;
        
        switch(select) {
            case 1:
                printf("\nenter data\n");
                scanf("%d", &input);
                sTop = add(sTop, input);
                break;
            case 2:
                sTop = del(sTop);
                break;
            case 3:
                list(sTop);
                break;
            default:
                printf("\nWRONG option°I");
        }
    }
    
    printf("\n");
    
    return 0;
}

Node* creates() {
    return NULL; //∂«¶^sTop ™∫≠»¨∞NULL
}

int isEmpty(Node* top) {
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

Node* add(Node* top, int item) {
    Node* newnode;
    
    newnode = (Node*) malloc(sizeof(Node));
    
    if(newnode == NULL) {
        printf("\nmemory failed°I");
        return top;
    }
    
    newnode->data = item;
    newnode->next = top;
    top = newnode;
    
    return top;
}

Node* del(Node* top) {
    Node* tmpnode;
    
    tmpnode = top;
    if(isEmpty(tmpnode)==1) {
        printf("\nstack empty°I");
        return NULL;
    }
    
    top = top->next;
    free(tmpnode); //ƒ¿©Ò∞Oæ–≈È
    
    return top;
}

void list(Node* top) {
    Node* tmpnode;
    tmpnode = top;
    
    printf("\nstack°G");
    while(tmpnode != NULL) {
        printf("%d ", tmpnode->data);
        tmpnode = tmpnode->next; 
    } 
}

