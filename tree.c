#include <stdio.h>
#include <stdlib.h>

struct tree {
	int value;
	struct tree *leftchild;
    struct tree *rightchild;
    struct tree *parent;
      int height;
};

typedef struct tree Tree;
Tree *x;
Tree *y;
Tree *z;
Tree *root;
Tree *tail;
Tree *temp;
Tree *tm;
Tree *var;
Tree *bl;
Tree *rotateLeft(Tree *root);
Tree *rotateRight(Tree *root);
int i;
main()
{
    
    
    int choice;
	int value;
	int srch;
	while(1) {
		printf("What do you want to do?\n\n");
		printf("1. Insert \n2. search \n3. display \n4. Remove\n5. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter the value you want to insert!\n");
				scanf("%d", &value);
				insert(value);
				printf("\nInserted the value %d into tree\n", value); 
				break;
                case 2:
                printf("which no. u want to search\n");
                scanf("%d",&srch);
                search(srch);
                break;
			/*case 2:
				printf("\nValue at what index you want to fetch\n");
				scanf("%d", &index);
				value = fetch(index);
				printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
				break;
			case 3:
				
				display();
                break;
            case 4:
            removee();
            break;
           case 5:
                   printf("\nExiting...\n"); 
                  exit(0);*/  
			default:
				break;
		}
	}
    
    
    
    
}
void insert( int value)
{
 
    if(root==NULL)
    {
       root =(Tree *)malloc(sizeof (Tree));
            root->value = value;
        
        root->height=1;
        root->leftchild = NULL;
		root->rightchild = NULL;
        root->parent=NULL;
        temp=root;
        tail=root;
       
		
    }
    else 
    {
       
        if(value<temp->value)
        {
        
        inleft(value);   
           
        }
        else
        {
           inright(value);
        }
       
    }
    
}

void search(int srch)
{
    temp=root;
    int i=0;
  if(srch==temp->value) 
  {
 printf("value is found and value is ROOT Value %d\n",srch);
 printf("Height of Node is %d\n ", temp->height);
  }
  else
      {
          if(srch<temp->value)
          {
        
           srchleft(srch);   
              
          }
      
     else
       {
       srchright(srch);
       
      }
         
      }  
          
      }
      void inleft(int value)
      {
         var=tail;
          while(value<temp->value && temp->leftchild!=NULL)
        {
         
           temp=temp->leftchild;
        }
           if(value<temp->value)
           {
               
           temp->leftchild =(Tree *)malloc(sizeof (Tree));
            temp->leftchild->value = value;
            temp->leftchild->leftchild=NULL;
            temp->leftchild->rightchild=NULL;
            temp->leftchild->parent= var;
            
            tail=temp->leftchild;
            bl=tail;
            tm=temp;
            temp->leftchild->height=ht(tm);
            balance(bl);
            temp=root;
           }
           else if(value==temp->value)
           {
               printf("Oh!! Given Value Already Exists");
           }
           else
              inright(value);  
      }
      
      
      
      void inright(int value)
      {
        var=tail; 
        while(value>temp->value && temp->rightchild!=NULL)
        {
         
           temp=temp->rightchild;
        }
          if(value>temp->value)
          {
            temp->rightchild =(Tree *)malloc(sizeof (Tree));
            temp->rightchild->value = value;
            temp->rightchild->leftchild=NULL;
            temp->rightchild->rightchild=NULL;
            temp->rightchild->parent= var;
            tail=temp->rightchild;
            bl=tail;
            tm=temp;
            temp->rightchild->height=ht(tm);
            balance(bl);
            temp=root;   
          }
          else if(value==temp->value)
           {
               printf("Oh!! Given Value Already Exists");
           }
          else 
              inleft(value);
          
        }
        
        void srchleft(int srch)
        {
            while(srch<temp->value && temp->leftchild!=NULL)
                { 
             temp=temp->leftchild;
             
                }
          if(srch==temp->value)
                    {  printf("The value is found\n");
                    printf("Height of Node is %d\n", temp->height);
                        temp=root;
                        return;
                    }
          else if(srch>temp->value)
                    srchright(srch);
          else
              printf("OOps!! %d Not Found and not in the Tree\n", srch);
              return;
        }
         
         
         
         
         void srchright(int srch)
         {
                while(srch>temp->value && temp->rightchild!=NULL)
         { 
             temp=temp->rightchild;
            
         }
          if(temp->value==srch)
            {  printf("The value is found\n\n",i,srch);
               printf("Height of Node is %d\n", temp->height);
              temp=root;
              return;
            }
            else if(srch<temp->value)
                    srchleft(srch);
          else
             printf("OOps!! %d Not Found and not in the Tree\n",srch);  
             return;
         }

int ht(Tree *tm)
{
  int lh,rh;
               if(tm==NULL)
                        return(0);
               if(tm->leftchild==NULL)
                              lh=0;
               else
                              lh=1+tm->height;
               if(tm->rightchild==NULL)
                              rh=0;
               else
                              rh=1+tm->height;
               if(lh>rh)
                return(lh);
                return(rh);   

}

void balance(Tree *bl)
{
int rh, lh, df;

 
y=bl->parent;
int val;
while(y!=NULL)
{
int l=0;
int r=0;
lh=0;
rh=0;
x=y;
z=y;

if (z->leftchild!=NULL)
{
while(z->leftchild!=NULL)
{z=z->leftchild;
}
   if (z->rightchild!=NULL)   
{
while(z->rightchild !=NULL)
   {
   z=z->rightchild;
   }
   
 lh=(z->height - y->height);
}
    lh=(z->height - y->height);
    
}

else
lh=0;
if(x->rightchild!=NULL)   
{
while(x->rightchild !=NULL)
   {
   x=x->rightchild;
   }
    if (x->leftchild!=NULL)   
{
while(x->leftchild !=NULL)
   {
   x=x->leftchild;
   }
   
 rh=(x->height - y->height);
}
   
 rh=(x->height - y->height);
 
}
else
rh=0; 
 df =(lh-rh);
 val=y->value;
 if (df==2 ||df==-2)
{
    x=y;
    z=y;
    if(df==2)
        {y=y->leftchild;
        x=y;}
    else
       { y=y->rightchild;
       x=y;}
       
    while(x->leftchild!=NULL)
       { l=l+1;
       x=x->leftchild;}
       x=y;
    while (x->rightchild!=NULL)
       { r=r+1;
       x=x->rightchild;}
       x=y;
    if(r>l)
        x=y->rightchild;
    else
        x=y->leftchild;
        
        
    int fi;
    printf("Tree is Not Balance at Value %d. (Z) = %d and (Y) = %d and (X) = %d.\n ",val, z->value, y->value, x->value ); 
    printf("Do you want to fix it\n");
    printf("1. Yes\n2. No\n");
    scanf("%d",&fi);
    switch(fi)
    {
        case 1:
            rotate();
            break;
        case 2: 
          break;
        default:
          break;
    }
    break;
}
y=y->parent;
 
}

}

void rotate()
{
 if(y==z->leftchild && x==y->leftchild)
 {
rotateRight(z);
printf("Tree again become Balance"); 
 }
 if(y==z->rightchild && x==y->rightchild)
 {
rotateLeft(z); 
printf("Tree again become Balance"); 
 }
 if(y==z->leftchild && x==y->rightchild)
 {
rotateLeft(y);
rotateRight(z);
printf("Tree again become Balance");  
 
 }

if(y==z->rightchild && x==y->leftchild)
 {
rotateRight(y);
rotateLeft(z);
printf("Tree again become Balance");  
 }



  
}
Tree *rotateRight(Tree *root)
{
Tree *ramp=root->leftchild;
root->leftchild=ramp->rightchild;
ramp->rightchild=root;
ramp->height = (ramp->height -1);
root->height =(root->height -1);
while(ramp->leftchild!=NULL)
{
    ramp=ramp->leftchild;
    ramp->height=(ramp->height -1);
}

return ramp;

}
Tree *rotateLeft(Tree *root)
{
Tree *ramp=root->rightchild;
root->rightchild=ramp->leftchild;
ramp->leftchild=root;
return ramp;

}

