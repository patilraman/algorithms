/*************************
*  RED BLACK TREE 
*
*  Algorithm from Introduction to algorithm 
*************************/
#include <stdio.h>
#include <stdlib.h>

typedef enum{
 RED,
 BLACK
}color;

typedef struct node{
   struct node *parent;
   struct node *left;
   struct node *right;
   color clr;
   int weight;
   int value; 
}bTree;

/*TODO: resolve what will be y*/
void Left_rotate(bTree *T, struct node *x)
{

   y = x->right;
   x->right = y->right; //turn y' subtree into x' right subtree

   if(y->left != NULL)  //if y' left subtree is not empty
      y->left->parent = x;

   y->parent = x->parent; //x' parent becomes y' parent

   if( x->parent == NULL) //if x was the root 
       T->parent = y;     //then y becomes the root
   else if(x == x->parent->left) //otherwise if x was a left child
            x->parent->left = y; //then y becomes a left child
        else{               //otherwise x was a 
           y->left = x;     //right child and now
           x->parent = y;   // y's left child
        }

}

/*implement right rotate*/
void right_rotate(bTree*T, struct node *x)
{
   
}

/*
y?

*/
void RB_INSERT_FIXUP(bTree *T, struct node *z)
{
   while( z->parent->color == RED)
   {
      if(z->parent == z->parent->parent->left) //is z' parent a left child ?
      {
          y = z->parent->parent->right;   //y is 2's uncle

          if( y>color == RED)  //z's parent & uncle both red ?
          {
             z->parent->color = BLACK;
             y->color = BLACK;
             z->parent->parent = RED;
             z = z->parent->parent;
          }
          else
          {
             if(z == z->parent->right)
             {
                z = z->parent;
                LEFT_ROTATE( T, z->parent);
             }
             z->parent->color = BLACK;
             z->parent->parent->color = RED;
             RIGHT_ROTATE(T, z->parent->parent);
          }
      }
      else  //same as lines 3-15 , but with right and left exchanged
      {
          y = z->parent->parent->left;
          if( y>color == RED)
          {
             z->parent->color = BLACK;
             y->color = BLACK;
             z->parent->parent->color = RED;
             z = z->parent->parent;
          }
          else
          {
             if( z == z->parent->left)
             {
                 z = z->parent;
                 RIGHT_ROTATE(T, z);
             }
             z->parent->color = BLACK;
             z->parent->parent->color = RED;    
             LEFT_ROTATE( T, z->parent->parent);
          }
     }
     T->color = BLACK;
}

/*
x?
y?
T.nil ?
*/
void RB_INSERT(bTree *T, struct node *z)
{
    x = T->parent; //node being compared with z
    y = NULL;     //y will be parent of z
 
    while( x != NULL)  //descend until reaching the sentinel
    {
       y=x;
       if(z->value <x->value){
         x = x->left;
       }
       else{
         x = x->right;
       }
    }
    z->parent = y; //found the location insert z with parent y
    
    if( y == NULL){
       T->parent = z; //tree T was empty
    else if(z->value < y>value){
            y->left = z;
         }
         else{
            y->right = z;
         }

    z->left = T->parent; //both of z' children are the sentinel
    z->right = T->parent;
    z->color = RED;     // the new node starts out red

    RB_INSERT_FIXUP(T,z) //correct any voilations of red-black properties
}

void inorder_parse_tree(bTree *root)
{
   if(NULL == root) return;
   
   if(root->left != NULL)
      inorder_parse_tree(root->left);

   printf("->%d\n",root->value);

   if(root->right !=NULL)
      inorder_parse_tree(root->right);

}
bTree* Allocate()
{
   return (bTree*)malloc(sizeof(bTree));
}
int main()
{
  bTree *root,*left,*right;

  root = (bTree*) malloc(sizeof(bTree));
  root->left = root->right= root->parent = NULL;
  root->value = 24;

  left = Allocate();
  left->left = left->right = left->parent = NULL;
  left->value = 15;

  right = Allocate();
  right->left = right->right = right->parent = NULL;
  right->value = 36;

  root->left = left;
  root->right = right;
  right->parent = left->parent = root;

  left = Allocate();
  left->left = left->right = NULL;
  left->parent = root->left;
  left->value = 11;
  
  root->left->left = left;

  right = Allocate();
  right->left = right->right = NULL;
  right->parent = root->left;
  right->value = 16;
  
  root->left->right = right;

 inorder_parse_tree(root);  
}
