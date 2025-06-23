# Linked List 

- Linear data structure composed of a sequence of nodes 
- Each node contains data and a pointer to the next node in the sequence 
- Nodes are not stored in contiguous memory 


## Node Structure 

Nodes are typically defined using a data structure that contains the data field and a pointer to a node. 

C Language example:

```C
typdef struct Node{
    data_type data;
    struct Node* next;
} Node;
``` 


## Head Pointer 

A Node* pointers, usually named head, points to the first node in the linked list. If the head pointer is NULL, the list is empty. 

## Dynamic Memory Allocation 

Nodes are created and destroyed using dynamic memory allocation, allowing the list to grow or shrink as needed during program execution. 

## Common List Operations 

### Insertion:

- Insert at beginning
    - Create new node 
    - Set new node pointer to the current head pointer
    - Update the head pointer to point to the new node
- Insert at end 
    - Creat new node
    - Traverse the list to find the last node.
    - Set last node's next pointer to new node 
    - Set the new node's next pointer to NULL 
- Insert before specific location
    - Create new node
    - Traverse the list to the node before the desired location 
    - Link the new node between the predecessor node and its successor 


### Deletion 

- Delete from beginning 
    - Update the head pointer to point to the second node 
    - Free memory of the original first node 
- Delete from end 
    - Traverse the list to the second to last node.
    - Set second to last node's next pointer to NULL
    - Free memory of last node 
- Delete from specific location 
    - Traverse to node before target node 
    - Link previous node's next pointer to target node's next pointer 
    - Free target node memory

### Traversal 

Iterate through the list from the head to the last node by following the next pointers.


## Advantages 
- Dynamic size allows efficient memory usage
- Efficient insertion and deletion operations compared to contiguous data structures like arrays 

## Disadvantages 
- Random access to data is not efficient, requiring traversal through the list 
- Requires more memory per element due to storage of pointers