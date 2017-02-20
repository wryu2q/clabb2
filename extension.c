
#include "extension.h"


/*notera alla mina fnk är rekursiva förutom link_node, ha det i åtanke om du vill fatta en fnk

 */




node *link_node (int value , node *p_old) {
  //fnk skapar nod, tar varde och nodpek  returnera pek till nya noden
  //printf("i fnk link\n" );
  node *p_new = malloc (sizeof(node));
  p_new->num = value ;
  p_new->next = p_old ;
  return  p_new;
}

void print_list (node *p_old) {
  //printf("in print 1\n" );
  putchar(( (p_old->num) + '0' ) ) ;
  if (p_old->next != NULL){
    //printf("\nin print not null\n" );
    print_list ( p_old->next );}
}

 node *reverse_list (node *p_a, node *p_b) {//a ar det b ska peka pa
  /*tar en lankad lista och gor den baklanges
  tanket bakom ar: vi har en serie pekare som pekar varan i ardning
  null a->b->c->d ... och vi far null a<-b c->d ...
  vi tar alltsa  pekare 1 som pekar pa en nad som andrat riktning
  och pekare 2 som pekar pa foljande cell som ingen nod pekar pa
  */
  //printf("in reverse\n");
  node *p_c= p_b->next ;
  p_b->next=p_a ;
  if (p_c == NULL )
    return p_b;
  else
    reverse_list ( p_b, p_c);
}

void free_list(node *p_kill) {
  /* ska doda alla mallocs i an lista*/
  node *p_next_victim= p_kill->next ;
  free (p_kill) ;
  if (p_next_victim != NULL )
  free_list(p_next_victim) ;
}

node *add_lists(node *p_a1,node *p_b1,node *p_c0,int carry) {
  /*adderar 2 listor men tar inte dod pa nan, skapar ny lista av summan.
  in listorna forutsats vara lankade fran minst signifikanta till mest.
  den nya ar fran metst signifikanta till minst
  logicen bakom ar: vi har lista a dvs a1->a2->a3... samt b och vi vill fa
  c0<-c1<-c2<-... dar c1 ar den nya noden och c0 det c1 ska peka pa.
  carry nar tex 6+7 = 13 vilket gor att ettan i 13 ska till nasta nod
  */
  if (p_a1 == NULL && p_b1 == NULL ){
    if (carry)
      return (link_node(carry, p_c0));
    else
      return p_c0 ;}
  else {
    int sum ;
    //p_a1->num + p_b1->num + carry ;
    node *p_c1 ;
    node *p_not_null=NULL;//om tva en p ar null blir denna den som inte ar null
    if (p_a1 != NULL && p_b1 != NULL)
      sum = p_a1->num + p_b1->num + carry ;
    else if (p_a1 != NULL)
      p_not_null=p_a1;
    else
      p_not_null=p_b1;

    if (p_not_null != NULL)
      sum = p_not_null->num + carry ;

    p_c1 = link_node(sum%10 , p_c0) ;
    if (p_not_null == NULL)
      add_lists(p_a1->next ,p_b1->next ,p_c1, sum/10 ) ;
    else
      add_lists(NULL ,p_not_null->next ,p_c1, sum/10 ) ;
    }
}


void save_list (node* p_node,FILE *file ) {
  /*lägger till alla tal i en lista i filen file som förutsäts vara öppnad så att vi kan
    använda fputc
   */
  if (p_node != NULL ){//
    
    fputc ( p_node->num + '0' , file) ;
    save_list (p_node->next , file ) ;

  }
}



