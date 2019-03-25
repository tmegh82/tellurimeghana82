#include <stdio.`h>
#include <stdlib.h>

  struct hash *hashTable = NULL;
  int eleCount = 0;

  struct node {
        int key;
        struct node *next;
  };

  struct hash {
        struct node *head;
        int count;
  };

  struct node * createNode(int key) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode ->key = key;
        newnode->next = NULL;
        return newnode;
  }


  void insertToHash(int key) {
        int hashIndex = key % eleCount;
        struct node *newnode =  createNode(key);
        
        if (!hashTable[hashIndex].head) {
                hashTable[hashIndex].head = newnode;
                hashTable[hashIndex].count = 1;
                return;
        }
        
        newnode->next = (hashTable[hashIndex].head);
        
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count++;
        return;
  }


  void deleteFromHash(int key) {
        
        int hashIndex = key % eleCount, flag = 0;
        struct node *temp, *myNode;
        
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
                printf("Given data is not present in Hash Table\n");
                return;
        }
        temp = myNode;
        while (myNode != NULL) {
                
                if (myNode->key == key) {
                        flag = 1;
                        if (myNode == hashTable[hashIndex].head)
                                hashTable[hashIndex].head = myNode->next;
                        else
                                temp->next = myNode->next;

                        hashTable[hashIndex].count--;
                        free(myNode);
                        break;
                }
                temp = myNode;
                myNode = myNode->next;
        }
        if (flag)
                printf("Deleted\n");
        else
                printf("Given data is not present in Hash Table\n");
        return;
  }

  void searchInHash(int key) {
        int hashIndex = key % eleCount, flag = 0;
        struct node *myNode;
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
                printf("Element not present\n");
                return;
        }
        while (myNode != NULL) {
                if (myNode->key == key) {
                        printf(" %d\n", myNode->key);
                        flag = 1;
                        break;
                }
                myNode = myNode->next;
        }
        if (!flag)
                printf("Element not present\n");
        return;
  }

  void display() {
        struct node *myNode;
        int i;
        for (i = 0; i < eleCount; i++) {
                if (hashTable[i].count == 0)
                        continue;
                myNode = hashTable[i].head;
                if (!myNode)
                        continue;
                printf("\nData at index %d in Hash Table:\n", i);
                
                while (myNode != NULL) {   
                        printf(" %d-> ", myNode->key);
                        myNode = myNode->next;
                }
        }
        return;
  }

  int main() {
        int n, ch, key;
        printf("Enter number of elements: ");
        scanf("%d", &n);
        eleCount = n;
        
        hashTable = (struct hash *)calloc(n, sizeof (struct hash));
        while (1) {
                printf("\n1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Display\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter value :");
                                scanf("%d", &key);
                                insertToHash(key);
                                break;

                        case 2:
                                printf("Enter element to be deleted: ");
                                scanf("%d", &key);
                                deleteFromHash(key);
                                break;

                        case 3:
                                printf("Enter element to be searched: ");
                                scanf("%d", &key);
                                searchInHash(key);
                                break;
                        case 4:
                                display();
                                break;
                        
                        default:
                                printf("Invalid choice\n");
                                break;
                }
        }
        return 0;
  }

