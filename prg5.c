#include<stdio.h>
#include<stdlib.h> 

struct Node {
    struct Node *Llink;
    int data;
    struct Node *Rlink;
};

int key, los, choice;
struct Node *header = NULL;

void insert_at_front(int key) {
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory is full\n"); 
        return;
    }
    newnode->data = key;
    newnode->Rlink = header;
    if (header != NULL) {
        header->Llink = newnode;
    }
    header = newnode;
    newnode->Llink = NULL;
}

void insert_at_any(int key, int los) {
    struct Node *newnode, *ptr;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory is full\n");
        return;
    }
    ptr = header;
    while (ptr != NULL && ptr->data != los) {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL) {
        printf("Key not found\n");
    } else {
        newnode->data = key;
        newnode->Rlink = ptr->Rlink;
        if (ptr->Rlink != NULL) {
            ptr->Rlink->Llink = newnode;
        }
        ptr->Rlink = newnode;
        newnode->Llink = ptr;
    }
}

void insert_at_end(int key) {
    struct Node *newnode, *ptr;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory is full\n");
        return;
    }
    newnode->data = key;
    newnode->Rlink = NULL;

    if (header == NULL) {
        header = newnode;
        newnode->Llink = NULL;
    } else {
        ptr = header;
        while (ptr->Rlink != NULL) {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = newnode;
        newnode->Llink = ptr;
    }
}

void delete_at_front() {
    struct Node *ptr; 
    if (header == NULL) {
        printf("No node to delete\n");
        return;
    }
    ptr = header;
    header = ptr->Rlink;
    if (header != NULL) {
        header->Llink = NULL;
    }
    printf("The deleted item is %d\n", ptr->data);
    free(ptr);
}

void delete_at_any(int key) {
    struct Node *ptr = header;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL) {
        printf("Key not found\n");
        return;
    }

    if (ptr->Llink != NULL) {
        ptr->Llink->Rlink = ptr->Rlink;
    } else {
        header = ptr->Rlink;
    }

    if (ptr->Rlink != NULL) {
        ptr->Rlink->Llink = ptr->Llink;
    }

    printf("The deleted item is %d\n", ptr->data);
    free(ptr);
}

void delete_at_end() {
    struct Node *ptr = header, *ptr1;
    if (ptr == NULL) {
        printf("No node to delete\n");
        return;
    }
    while (ptr->Rlink != NULL) {
        ptr = ptr->Rlink;
    }
    ptr1 = ptr->Llink;
    if (ptr1 != NULL) {
        ptr1->Rlink = NULL;
    } else {
        header = NULL;
    }
    printf("The deleted item is %d\n", ptr->data);
    free(ptr);
}

void display() {
    struct Node *ptr = header;
    if (ptr == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    printf("The linked list elements are:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->Rlink;
    }
}

int search(int key) {
    struct Node *ptr = header;
    int location = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Key found at location: %d\n", location);
            return 0;
        }
        ptr = ptr->Rlink;
        location++;
    }
    printf("Key not found\n");
    return 0;
}

int main() {
    printf("Double linked list\n");
    do {
        printf("\n1. Insert at front\n2. Insert at any\n3. Insert at end\n4. Delete at front\n5. Delete at any\n6. Delete at end\n7. Display\n8. Searching\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter a value to insert at front: ");
                scanf("%d", &key);
                insert_at_front(key);
                break;
            case 2:
                printf("Enter a value to insert: ");
                scanf("%d", &key);
                printf("Enter the location to insert: ");
                scanf("%d", &los);
                insert_at_any(key, los); 
                break;
            case 3:
                printf("Enter a value to insert at end: ");
                scanf("%d", &key);
                insert_at_end(key);
                break;
            case 4:
                delete_at_front();
                break;
            case 5:
                printf("Enter a value to delete at any: ");
                scanf("%d", &key);
                delete_at_any(key);
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter a value to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 9); 
    return 0;
}
