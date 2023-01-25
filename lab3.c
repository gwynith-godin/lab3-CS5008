#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0

// node defined above, assume defined as node_t
typedef struct node{
    int num_wins;
    int year;
    struct node* next;
}node_t;

node_t* new_node(int wins, int year, node_t* next) {

// allocate a new node, we have to put it on the heap! 
   node_t* newNode = (node_t*)malloc(sizeof(node_t));
   if( newNode == NULL){
    return NULL;
   }

   newNode->num_wins = wins;
   newNode->year = year;
   newNode->next = next; 

   return newNode;
}

node_t* build_list(int* wins, int* years, int size){

    node_t* head = new_node(wins[0], years[0], NULL);
    node_t* tail = head;
    for(int i = 1; i <= size-1; i++){
        node_t* current_node = new_node(wins[i], years[i], NULL);
        tail->next = current_node;
        tail = current_node;
       // printf("%d  %d\n", tail->num_wins, tail->year);
    }
    return head; 
}
void printNodes(node_t* node){
    node_t* itr = node;
    while(itr != NULL){ // (&node1)-> data, 1
        printf("%d, %d wins\n", itr->year, itr->num_wins);
        itr = itr->next; // its = (&node1)-> next;
    }
}
void freeNodes(node_t* node){
    node_t* itr = node;
    while(itr != NULL){ // (&node1)-> data, 1
        free(itr);
        itr = itr->next; // its = (&node1)-> next;
    }
}
node_t* findYear(node_t* head, int year){
   node_t* itr = head; 
    while(itr != NULL){ // (&node1)-> data, 1
        if(itr->year == year){
            return itr;
        }
        itr = itr->next; // its = (&node1)-> next;
    }
    return NULL;
} 

int insert_year(node_t* head, int year_to_find, int year, int wins){
    node_t* find_year = findYear(head, year_to_find);
    if(find_year == NULL){
        return 1;
    }

    node_t* newNode = new_node(wins, year, find_year->next);
    find_year->next = newNode; 

    return 0;
}

int main() {
   // node_t* head = new_node(10, 5, NULL);
  //  node_t* new = new_node(1, 5, NULL);
  //  printf("Year %d, Wins: %d\n", head->year, head->num_wins);

    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    node_t* head2 = build_list(test_wins, test_years, 5);
    printNodes(head2); 
   // freeNodes(head2);
    findYear(head2, 2015);
    insert_year(head2, 2017, 2012, 100);
    printNodes(head2);
    freeNodes(head2);
   // head->next = new;
   // printf("%d %d \n", head->next->year,  head->next->num_wins);

}