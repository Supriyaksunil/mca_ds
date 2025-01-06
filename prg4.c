#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*link;
};
struct Node*header=NULL;
struct Node*newnode;
struct Node*ptr;
struct Node*ptr1;
void insert_at_front(int key)
{
	if(header==NULL)
	{
		newnode=(struct Node*)malloc(sizeof(struct Node));
		newnode->data=key;
		newnode->link=NULL;
		header=newnode;
	}
	else{
		newnode=(struct Node*)malloc(sizeof(struct Node));
		newnode->data=key;
		newnode->link=header;
		header=newnode;
	}
}
void insert_at_end(int key)
{
if(header==NULL){
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=key;
	newnode->link=NULL;
	header=newnode;
}
else{
	ptr=header;
	while(ptr->link!=NULL){
		ptr=ptr->link;
	}
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=key;
	newnode->link=NULL;
	ptr->link=newnode;
}
}
void insert_at_anypart(int key,int val){
	if (header==NULL)
	{
	newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=key;
	newnode->link=NULL;
	header=newnode;	
	}
	else{
		ptr=header;
		while((ptr!=NULL)&&(ptr->data!=val))
		{
			ptr=ptr->link;
		}
		if(ptr==NULL)
		{
			printf("Key is not found\n");
		}
		else{
			newnode=(struct Node*)malloc(sizeof(struct Node));
			newnode->data=key;
			newnode->link=ptr->link;
			ptr->link=newnode;
		}
	}
}

void delete_at_front()
{
	ptr=header;
	if(ptr==NULL)
	{
	printf("Linked list is empty");
	}
	else
	{
	header=ptr->link;
	free (ptr);
	}
}
void delete_at_end()
{
	ptr=header->link;
	if(ptr==NULL)
	{
		printf("linked list is empty");
	}
	else
	{
		while(ptr->link!=NULL)
		{
		ptr1=ptr;
		ptr=ptr->link;
		}
		ptr1->link=NULL;
		free(ptr);

	}
}
void delete_at_any(int key)
{
	ptr=header->link;
	ptr1=header;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			ptr1->link=ptr->link;
			free(ptr);
			break;
		}
		else
		{
			ptr1=ptr;
			ptr=ptr->link;

		}
		if (ptr==NULL)
		{
			printf("No key found");
		}
	}
}
int search(int key)
{
	int location=1;
	ptr=header;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			printf("location:%d\n",location);
			break;
		}
		else{
			ptr=ptr->link;
			location=location+1;
		}

		
	}
	if(ptr==NULL)
	{
		printf("Key is not found");
	}
	
}

void display()
{
	ptr=header;
	if(ptr==NULL)
	{
		printf("linked list is empty");
	}
	else
	{
	    printf("elements in the list: ");
	    while(ptr!=NULL)
	    {
	        printf("%d ",ptr->data);
	        ptr=ptr->link;
	    }
	}
}

void main()
{
    int choice,key,val;

    do
    {
        printf("\n1.insert_front\n2.insert_end\n3.insert_anypart\n4.delete_front\n5.delete_nd\n6.delete_anypart\n7.display\n8.search\n9.exit\n");
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("enter the item:");
                scanf("%d",&key);
                insert_at_front(key);
                break;
                }
            case 2:
            {
            printf("enter the item:");
            scanf("%d",&key);
            insert_at_end(key);
            break;
            }
            case 3:
            {
            printf("enter the item:");
            scanf("%d",&key);
            printf("enter the position:");
            scanf("%d",&val);
            insert_at_anypart(key,val);
            break;
		    }
		    case 4:
		    {
		        delete_at_front(key);
		        break;
		        }
		        case 5:
		        {
		            delete_at_end(key);
		            break;
		        }
		    case 6:
		    {
		        printf("enter the item:");
		        scanf("%d",&key);
		        delete_at_any(key);
		        break;
		    }
		    case 7:
		    {
		        display(key);
		        break;
		    }
		    case 8:
		    {
		        printf("enter the item:");
		        scanf("%d",&key);
		        search(key);
		        break;
		    }
		    case 9:
		    {
		        printf("truth");
		        break;
		    }
		    default:printf("invalid choice");
		    }
		}
	while(choice!=9);
	}




