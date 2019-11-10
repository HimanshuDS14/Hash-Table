#include<stdio.h>

struct node
{
    int key;
    int value;
    struct node *next;
};

void display(struct node ar[] , int size);
void search(struct node ar[] , int size);
void insert(struct node ar[] , int size);

void main()
{
    int size ,  i  , temp , j;
    printf("Enter the size of the table : ");
    scanf("%d" , &size);

    struct node hash_table[size];
    while(j<size)
    {
        hash_table[j].next = NULL;
        j++;
    }
    j=0;
    while(j<size)
    {
        hash_table[j].value = -1;
        j++;

    }



    printf("Enter the elements : ");
    for(i=0;i<size;i++)
    {
        scanf("%d" , &temp);
        hash_table[temp%size].value = temp;
        hash_table[temp%size].key = temp%size;

    }
    printf("\n");
    display(hash_table , size);
    search(hash_table , size);
    insert(hash_table , size);
    display(hash_table , size);
     search(hash_table , size);


}

void display(struct node ar[] , int size)
{
    int i;
    printf("value\tkey\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t%d\n" , ar[i].value , ar[i].key);
        struct node *ptr;
        ptr = ar[i].next;
        while(ptr !=NULL)
        {
            printf("%d\n" , ptr->value);
            ptr = ptr->next;
        }
        printf("\n");

    }
}

void search(struct node ar[] , int size)
{
    int se;
    printf("Enter a element which you want a search : ");
    scanf("%d" , &se);

    if(ar[se % size].value == se)
    {
        printf("Element exist at : %d index " , se%size);
    }
    else if(ar[se%size].next!=NULL)
    {
        int flag=0;
        struct node*temp;

        temp= ar[se%size].next;
        while(temp!=NULL)
        {
            if(temp->value==se)
            {
                flag=1;
            }
            temp = temp->next;
        }
        if(flag==1)
        {
            printf("Value found at : %d position" , se%size);
        }

    }
    else
    {
        printf("Value not present into a hashtable");
    }
}

void insert(struct node ar[] , int size)
{
    int inp;

    printf("\nEnter a element which you want a insert into hash table : ");
    scanf("%d" , &inp);
    if(ar[inp%size].value ==-1)
    {
        ar[inp%size].value = inp;
    }
    else
    {
        if(ar[inp%size].next==NULL)
        {
            struct node *temp;

            temp = (struct node*)malloc(sizeof(struct node));
            temp->value = inp;
            temp->next = NULL;
            ar[inp%size].next = temp;
        }
        else
        {
            struct node *temp1 , *temp;
            temp1 = ar[inp%size].next;

            while(temp1->next!=NULL)
            {
                temp1 = temp1->next;
            }

            temp = (struct node*)malloc(sizeof(struct node));
            temp->value = inp;
            temp->next = NULL;
            temp1->next = temp;



        }
    }



}
