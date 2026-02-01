#include<stdio.h>
#include<stdlib.h>
// #include<windows.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void search();
void sort();
void reverse();
void dlt_begin();
void dlt_end();
void dlt_pos();

typedef struct node
{
    int data;
    struct node *next;
}node;
struct node *s=NULL;
int main()
{
    // system("color 12");
    int ch;
    while(1)
    {
        printf("\n ***********Welcome to Linked List Project************");
        printf("\n 1.Create \n");
        printf("\n 2.Display \n");
        printf("\n 3.Insert node at the beginning \n");
        printf("\n 4.Insert node at the end \n");
        printf("\n 5.Insert node at specified position \n");
        printf("\n 6.Search a node data \n");
        printf("\n 7.Sort the Linked List \n");
        printf("\n 8.Reverse the Linked List \n");
        printf("\n 9.Delete node from beginning \n");
        printf("\n 10.Delete node at the end \n");
        printf("\n 11.Delete node from specified position \n");
        printf("\n 12.Exit \n");
        printf ("\n-------------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    create();
                    break;
            case 2:
                    display();
                    break;
            case 3:
                    insert_begin();
                    break;
            case 4:
                    insert_end();
                    break;
            case 5:
                    insert_pos();
                    break;
            case 6:
                    search();
                    break;
            case 7:
                    sort();
                    break;
            case 8:
                    reverse();
                    break;
            case 9:
                    dlt_begin();
                    break;
            case 10:
                    dlt_end();
                    break;
            case 11:
                    dlt_pos();
                    break;
            case 12:
                    exit(1);
                    break;
            default:
                    printf("\n Wrong choice: \n");
                    break;
        }
    }
    return 0;
}
void create()
{
    struct node *s1,*p;
    p=(node *)malloc(sizeof(node));
    printf("\n Enter the data \n");
    scanf("%d",&(p->data));
    p->next=NULL;
    if(s==NULL)
    {
        s=p;
    }
    else
    {
        s1=s;
        while(s1->next!=NULL)
        {
            s1=s1->next;
        }
        s1->next=p;
    }
}
void display()
{
    struct node *s1;
    if(s==NULL)
    {
        printf("\n List is empty  \n");
        return;
    }
    else
    {
        s1=s;
        printf("\n Element in Linked List are \n");
        while(s1!=NULL)
        {
            printf("%d \t",s1->data);
            s1=s1->next;
        }
    }
}
void insert_begin()
{
    struct node *p;
    p=(node*)malloc(sizeof(node));
    printf("\n Enter  the data \n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(s==NULL)
    {
        s=p;
    }
    else
    {
        p->next=s;
        s=p;
    }
}
void insert_end()
{
    struct node *p,*s1;
    p=(node*)malloc(sizeof(node));
    printf("\n Enter the data \n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(s==NULL)
    {
        s=p;
    }
    else
    {
        s1=s;
        while(s1->next!=NULL)
        {
            s1=s1->next;
        }
        s1->next=p;
    }
}
void insert_pos()
{
    struct node *p,*s1;
    int pos;
    printf("\n Enter the position \n");
    scanf("%d",&pos);
    p=(node*)malloc(sizeof(node));
    printf("\n Enter the data \n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(pos==0)
    {
        p->next=s;
        s=p;
    }
    else
    {
        s1=s;
        for(int i=0;i<pos-1;i++)
        {
            s1=s1->next;
        }
        p->next=s1->next;
        s1->next=p;
    }
}
void search()
{
    struct node *s1;
    int data,i=0;
    printf("\n Enter data to be found \n");
    scanf("%d",&data);
    if(s==NULL)
    {
        printf("\n Linked List in empty \n");
    }
    else
    {
        s1=s;
        while(s1!=NULL)
        {
            if(s1->data==data)
            {
                printf("\n The data %d is found \n",data);
                i++;
                break;
            }
            s1=s1->next;
        }
        if(i==0)
        {
            printf("Element not found ");
        }
    }
}
void sort()
{
    struct node *s1,*s2=NULL;
    int temp;
    if (s==NULL)
    {
        printf("\n list is empty \n");
    }
    else
    {
        s1=s;
        while(s1!=NULL)
        {
            s2=s1->next;
            while(s2!=NULL)
            {
                if(s1->data>s2->data)
                {
                    temp=s1->data;
                    s1->data=s2->data;
                    s2->data=temp;
                }
                s2=s2->next;
            }
            s1=s1->next;
        }
        printf("After Sorting the list :\n");
        while(s!=NULL)
        {
            printf("%d\t",s->data);
            s=s->next;
        }
    }
}
void reverse()
{
    struct node *s1,*prev=NULL,*next=NULL;
    s1=s;
    while(s1!=NULL)
    {
        next=s->next;
        s1->next=prev;
        prev=s1;
        s1=next;
    }
    s=prev;
    printf("Reverse list is :\n");
    while(s!=NULL)
    {
        printf("%d\t",s->data);
        s=s->next;
    }
}
void dlt_begin()
{
    struct node *s1;
    if(s==NULL)
    {
        printf("List is empty \n");
        exit(0);
    }
    else
    {
        s1=s;
        s=s->next;
        printf("The deleted Element is :%d\t ",s1->data);
        free(s1);
    }
}
void dlt_end()
{
    struct node *s1,*temp;
    if(s==NULL)
    {
        printf("\n The list is empty\n");
        exit(0);
    }
    else if(s->next==NULL)
    {
        s1=s;
        s1=NULL;
        printf("The deleted Element is :%d\t ",s1->data);
        free(s1);
    }
    else
    {
        s1=s;
        while(s1->next!=NULL)
        {
            temp =s1;
            s1=s1->next;
        }
        temp->next=NULL;
        printf("\n The deleted Element is :%d",s1->data);
        free(s1);
    }
}
void dlt_pos()
{
    int i,pos;
    struct node *s1,*temp;
    if(s==NULL)
    {
        printf("\n The list is empty\n ");
        exit(0);
    }
    else
    {
        printf("\n Enter the position of the node to be delete :\t");
        scanf("%d",&pos);
        if(pos==0)
        {
            s1=s;
            s=s->next;
            printf("\n The deleted element is : %d\t",s1->next);
            free(s1);
        }
        else
        {
            s1=s;
            for(int i=0;i<pos;i++ && s1->next!=NULL)
            {
                temp=s1;
                s1=s1->next;
            }
            temp->next=s1->next;
            printf("\n The deleted element is ;%d\t",s1->data);
            free(s1);
        }
    }
}
