#include<stdio.h>
#include<stdlib.h>
// struct node{   
// int  data;
// struct node *next;
// };
// int main(){
//   struct node a,b,c,*p;
//   a.data=15;
//   b.data=20;
//   c.data=5;
//   a.next=b.next=c.next=NULL;
//   p=&a;
//   a.next=&c;
//   c.next=&b;
//   while(p!=NULL){
//      printf("%d ",p->data);
//      p=p->next;
//    }
// }

struct node{
    int    num;
    struct node *next;
} ; 

int main() {


struct node *hp,*p;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    hp = NULL;
    for(int i=0;i<10;i++)
    {
       p = (struct node *) malloc(sizeof(struct node));
       p->num = a[i];
       p->next=hp;
       hp=p;
    }
    p=hp->next;
    while(p)
    {
        printf("%d", p->num);    
        p = p->next;    
    }
}