#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAXWORD 100
struct tnode{
      char *word;
      int count;
     struct tnode *left;
     struct tnode *right;
    };
/* talloc: utworz wezel*/
struct tnode *talloc(void)
{
       return(struct tnode*)malloc(sizeof(struct tnode));
}
/* strdup: sporzadz kopie s */
char *strdup(char *s)
{
     char *p;
     p=(char *)malloc(strlen(s)+1); /* +1 dla '/0' */
     if(p!=NULL)
                strcpy(p,s);
     return p;
}
struct tnode *addtree(struct tnode *p, char *w)
{
       int cond;
       if(p==NULL){
                   p=talloc();
                   p->word=strdup(w);
                   p->count=1;
                   p->left = p->right=NULL;
       } else if((cond=strcmp(w, p->word))==0)
                   p->count++;
       else if(cond<0)
                   p->left=addtree(p->left, w);
       else
                   p->right=addtree(p->right, w);
       return p;
}
void treeprint(struct tnode *p)
{
     if(p!=NULL){
                 treeprint(p->left);
                 printf("%4d %s\n", p->count, p->word);
                 treeprint(p->right);
     }
}
int getword(char *, int);

/*zliczanie wystapien slow*/
main()
{
      struct tnode *root; /*wskaznik do korzenia drzewa*/
      char word[MAXWORD];
      
      root=NULL;
      while(getword(word, MAXWORD)!=EOF){
                          if(isalpha(word[0]))
                          root=addtree(root, word);
                          }
      treeprint(root);
      return 0;
}
                                               
      
       
       
