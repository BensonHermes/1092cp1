#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
    {
        int val;
        struct Node *next;
    } MyLinkedList;

MyLinkedList boxes[26];



MyLinkedList* CreateLinkedList()
    {
        MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        node->val = -1;
        node->next = NULL;
        return node;
    }

void myLinkedListAddAtHead(MyLinkedList * obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = obj->next;
    obj->next = node;
}
void myLinkedListAddAtTail(MyLinkedList * obj, int val)
{
    MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // printf("1\n");
    node->val = val;
    // printf("val=%d\n", val);
    node->next = NULL;
    // printf("2\n");
    MyLinkedList *p = obj;
    
    // printf("3\n");
    while (p->next != NULL)
    {
        p = p->next;
    }
    // printf("p->val=%d\n", p->val);
    p->next = node;
    // printf("6\n");
}

MyLinkedList* find(MyLinkedList* obj, int remain) {
    MyLinkedList *p = obj->next; /* Skip the virtual head */
    for (; remain && p; --remain){
        p = p->next;
    }
    return p;
}
int find_index(MyLinkedList* obj, int target) {
    MyLinkedList *p = obj->next; /* Skip the virtual head */
    int ind=0;
    while (p){
        if(p->val == target){
            return ind;
        }
        ind++;
        p = p->next;
    }
    return -1;
}
//尋找所在的堆 回傳boxes index
int find_boxes(int target){
    for (int i = 0; i < 26; i++)
    {
        MyLinkedList *p = &boxes[i]; /* Skip the virtual head */ //法二 
        while (p!=NULL)
        {
            if (p->val==target)
            {
                return i;
            }
            else
            {
                p = p->next;
            }
        }
    }
    return -1;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p = find(obj, index);
    if (p){
        return p->val;
    }
    return -1;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0){
        myLinkedListAddAtHead(obj, val);
    }
    else {
        MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        node->val = val;

        MyLinkedList *p = find(obj, index - 1);
    if (p) {
        node->next = p->next;
        p->next = node;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0) {
        if (obj->next) {
        MyLinkedList *p = obj->next;
        obj->next = obj->next->next;
        free(p);
        }
    }
    else {
        MyLinkedList *p = find(obj, index - 1);
        if (p && p->next) {
            MyLinkedList *q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *p = obj;
    MyLinkedList *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
}
void printNode(int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        MyLinkedList *p = &boxes[i];
        while(p!=NULL)
        {   if (myLinkedListGet(p, 0)== -1 )
            {
                printf(" ");
                break;
            }
        
            printf(" %d", myLinkedListGet(p, 0));
            p = p->next;
        }
        printf("\n");
        /* code */
    }
    
}
void put_back(int value){
    int boxIndex = find_boxes(value);
    MyLinkedList *p = &boxes[boxIndex];
    int ind = find_index(p, value);
    int indAbove = ind + 1;
    p = find(&boxes[boxIndex], indAbove);
    while(p!=NULL){
        // printf("@@@@\n");
        value = myLinkedListGet(&boxes[boxIndex], indAbove);
        myLinkedListAddAtTail(&boxes[value], value);
        myLinkedListDeleteAtIndex(&boxes[boxIndex], indAbove);
        p = p->next;
        indAbove++;
    }
    
}
void move_onto(int from, int to){
    int fromBoxIndex = find_boxes(from);
    // printf("fromBoxIndex=%d\n", fromBoxIndex);
    int toBoxIndex = find_boxes(to);
    // printf("toBoxIndex=%d\n", toBoxIndex);
    // printf("from=%d, to=%d\n", from, to);
    // printf("f1\n");
    put_back(from);
    put_back(to);
    // printf("f2\n");
    MyLinkedList *p = &boxes[fromBoxIndex];
    int fromInd = find_index(p, from);
    // int fromInd;
    // int value;
    
    //目標上的歸回原位
    // printf("f3\n");
    myLinkedListAddAtTail(&boxes[toBoxIndex], from);
    // printf("f4\n");
    myLinkedListDeleteAtIndex(&boxes[fromBoxIndex], fromInd);
    // printf("f5\n");

}
void move_over(int from, int to){
    //清掉from上
    put_back(from);
    int fromBoxIndex = find_boxes(from);
    MyLinkedList *p = &boxes[fromBoxIndex];
    int fromInd = find_index(p, from);
    //from 移到to 上
    int toBoxIndex = find_boxes(to);
    // int toInd = find_index(p, to);
    myLinkedListAddAtTail(&boxes[toBoxIndex], from);
    myLinkedListDeleteAtIndex(&boxes[fromBoxIndex], fromInd);

}

void pile_onto(int from, int to){
    //p -> to, q -> from
    put_back(to);
    int toBoxIndex = find_boxes(to);
    int value;
    int fromBoxIndex = find_boxes(from);
    MyLinkedList *q = &boxes[fromBoxIndex];
    int fromInd = find_index(q, from);
    // int fromIndAbove = find_index(q, from)+1;
    q=find(&boxes[fromBoxIndex], fromInd);
    //移動位置
    while(q!=NULL){
        value = myLinkedListGet(&boxes[fromBoxIndex], fromInd);
        myLinkedListAddAtTail(&boxes[toBoxIndex], value);
        myLinkedListDeleteAtIndex(&boxes[fromBoxIndex], fromInd);
        q = q->next;
        // fromInd++;
    }
}

void pile_over(int from, int to){
    //p -> to, q -> from
    int toBoxIndex = find_boxes(to);
    int value;    
    int fromBoxIndex = find_boxes(from);
    MyLinkedList *q = &boxes[fromBoxIndex];
    int fromInd = find_index(q, from);
    q=find(&boxes[fromBoxIndex], fromInd);
    //移動位置
    while(q!=NULL){
        value = myLinkedListGet(&boxes[fromBoxIndex], fromInd);
        myLinkedListAddAtTail(&boxes[toBoxIndex], value);
        myLinkedListDeleteAtIndex(&boxes[fromBoxIndex], fromInd);
        q = q->next;
        // fromInd++;
    }
}

int main(void)
{
    int n,from,to,i;
    char buff[50];
    char comd[10],on[10];
    scanf("%d",&n);
    scanf("\n");
    // printf("#1: n=%d\n", n);

    // printf("check1\n");
    

    // scanf("%s",comd);
    while(fgets(comd, 5, stdin)!=NULL){
        // printf("check2\n");
        // printf("#2: n=%d\n", n);
        // printNode(n);
        for (int i = 0; i < n; i++){
            boxes[i].val = -1;
            boxes[i].next = NULL;
            myLinkedListAddAtHead(&boxes[i], i);
        }
        // printNode(n);        
        while (strcmp(comd,"quit") != 0){  
            // printf("check5\n");
            scanf("%d",&from);
            scanf("%s",on);
            scanf("%d",&to);
            // printf("n=%d, comd=%s, from=%d, on=%s, to=%d\n", n,comd,from , on, to);
            if (find_boxes(from) == find_boxes(to)) {
                // printf("find_boxes(from)=%d\n", find_boxes(from));
                // printf("check6\n");
                // gets(buff);
                scanf("%s",comd);
                continue;
            }
            else if ((strcmp(comd,"move") == 0)&&(strcmp(on,"onto") == 0)){
                // printf("check7\n");
                
                move_onto(from, to);
                // printNode(n);
            }    
            else if ((strcmp(comd,"move") == 0)&&(strcmp(on,"over") == 0)){
                // printf("check9\n");
                move_over(from, to);
                // printNode(n);
            }
            else if ((strcmp(comd,"pile") == 0)&&(strcmp(on,"onto") == 0)){
                // printf("check10\n");
                pile_onto(from, to); 
                // printNode(n);
            }
            else{
                // printf("check11\n");
                pile_over(from, to);
                // printNode(n);
            }
            scanf("%d",&n);
            // scanf("\n");
            scanf("%s",comd);
        } 
        // printf("--------\n");
        printNode(n);

        for (int l = 0; l < 26; l++){
            // free(&boxes[l]);
            MyLinkedList *p = &boxes[l];
        //     // printf("l=%d\n", l);
            while(p != NULL)
            {
                // printf("1:p->value=%d\n", p->val);
                // free(p);
                myLinkedListDeleteAtIndex(p, 0);
                p=p->next;
                // printf("2:p->value=%d\n", p->val);
            }   

        }

        scanf("%d\n", &n);
        // free(&boxes);
    }
    
    // printNode(n);
    return 0;
}
