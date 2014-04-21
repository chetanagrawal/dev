#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode * talloc(void) {
    return (struct tnode *) malloc (sizeof(struct tnode));
}

struct tnode* addtree(struct tnode* root,  char* word)
{
    int cmp;
    if (root == NULL) {
        root = talloc();
        if (root == NULL) {
            fprintf(stderr, "Failed to allocate memory\n");
            return NULL;
        }
       // printf("Adding %s to new node...\n", word);
        root->word = strdup(word);;
        root->count = 1;
        root->left = NULL;
        root->right = NULL;
    } else if ((cmp = strcmp(root->word, word)) > 0) {
        //printf("Adding %s to left tree...\n", word);
        root->left = addtree(root->left, word);
    } else if (cmp < 0) {
        //printf("Adding %s to right tree...\n", word);
        root->right = addtree(root->right, word);
    } else {
        root->count++;
    }
    return root;
}    

int getword(char* word, int limit)
{
    int c,i=0;
    while(isspace(c=getchar()));
    ungetc(c, stdin);
    while((c=getchar()) != EOF && !isspace(c) && i<limit) {
        word[i++] = c;
    }
    word[i]='\0';
    return i;
}

void printtree(struct tnode* p)
{
    if(p == NULL) {
        return;
    }
    printtree(p->left);
    printf("%s -> %d\n", p->word, p->count);
    printtree(p->right);
}

int main()
{
    int n;
    struct tnode *root = NULL;
    char word[MAXLEN];
    
    printf("Enter the words:\n");
    while((n = getword(word, MAXLEN)) > 0) {
        root = addtree(root, word);
    }

    printtree(root);
    return 0;
}
