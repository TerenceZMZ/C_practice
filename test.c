#include <stdio.h>
#include <stdlib.h>

typedef struct SListNode
{
    int val;
    struct  SListNode* next;
}SListNode;

SListNode *SListInit()
{
    SListNode *head = malloc(sizeof(SListNode));
    head->val = -1;
    head->next = NULL;
    SListNode *pRear = head;
    int val =-1;
    while (1)
    {
        printf("Please enter vals:\n");
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        SListNode *newnode = malloc(sizeof(SListNode));
        newnode->val = val;
        newnode->next =NULL;
        pRear->next = newnode;
        pRear = newnode;
    }
    return head;
}
int SListAppend(SListNode* list, int val)
{
    SListNode *newnode = malloc(sizeof(SListNode));
    if (newnode ==NULL)
    {
        return -1;
    }
    newnode->val = val;
    newnode->next = NULL;
    if (NULL == list)
    {
        list = newnode;
    }
    else
    {
        SListNode *tmp = list;
        while (tmp->next != NULL)
        {
            tmp = tmp ->next;
        }
        tmp ->next = newnode;
    }
    return 1;
    
}

int SListInsertHead(SListNode* list, int val)
{
    SListNode *newnode = malloc(sizeof(SListNode));
    if (newnode ==NULL)
    {
        return 0;
    }
    newnode->val = val;
    newnode->next = NULL;
    if (NULL == list)
    {
        list = newnode;
    }
    else if (list->next == NULL)
    {
        list->next = newnode;
    }
    else
    {
        newnode->next=list->next;
        list->next = newnode;
    }
    return 1;
}

SListNode  *SListRemove(SListNode* list, int val)
{
    
}


SListNode  *SListReverse(SListNode* list)
{

}
int SListGetLength(SListNode *list)
{
    
}
void SListFree(SListNode *list)
{
    if (list ==NULL)
    {
        return;
    }
    SListNode *pcur = list->next;
    while (pcur!=NULL)
    {
        SListNode *pnext = pcur->next;
        free(pcur);
        pcur = pnext;
    }
    list->next = NULL;
}
void show(SListNode *head)
{
    if (head ==NULL)
    {
        return;
    }
    SListNode *cur = head->next;
    while(cur != NULL)
    {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}

int main()
{
    int a= 2;
    SListNode  *head = SListInit();
    SListAppend(head, a);
    SListInsertHead(head, a);
    show(head);
    SListFree(head);
    return 0;
}
