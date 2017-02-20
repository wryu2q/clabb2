#include <stdio.h>
#include <stdlib.h>


struct node {
  int num ;   // talet noden har

  struct node *next ;//ska peka pa en nasta nod av samma typ
  //next = malloc (sizeof(struct node))  ; // pekar pa nasta
} ;

typedef struct node node ;


node *link_node (int value , node *p_old);

void print_list (node *p_old) ;

node *reverse_list (node *p_a, node *p_b);

void free_list(node *p_kill) ;

node *add_lists(node *p_a1,node *p_b1,node *p_c0,int carry) ;

void save_list (node* p_node,FILE *file ) ;




