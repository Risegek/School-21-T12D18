#include <stdio.h>
#include "bst.h"
void bst_create_test(struct t_btree** root);
void output_tree(struct t_btree* root, int l);
void bst_traverse_test(struct t_btree* root);
void bst_insert_test(struct t_btree* root);

int main() {
    struct t_btree* root = NULL;
    bst_create_test(&root);
    bst_insert_test(root);
    bst_traverse_test(root);
    return 0;
}

int cmpf(int a, int b) {
    return a - b;
}

void applyf(int val) {
    printf("%d -> ", val);
}

void bst_traverse_test(struct t_btree* root) {
    printf("\n----------------bstree_apply_infix-------------\n");
    bstree_apply_infix(root, applyf);
    printf("\n----------------bstree_apply_prefix-------------\n");
    bstree_apply_prefix(root, applyf);
    printf("\n----------------bstree_apply_postfix-------------\n");
    bstree_apply_postfix(root, applyf);
}

void bst_insert_test(struct t_btree* root) {
    int val = 1;
    printf("----------------bst_insert_test-------------\n");
    printf("Test 1: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
    printf("--------------\n");
    val = 43;
    printf("Test 2: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
    printf("--------------\n");
    val = 6;
    printf("Test 3: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(root, 0);
    printf("--------------\nStart...\n");
    bstree_insert(root, val, cmpf);
    output_tree(root, 0);
    printf("--------------\n");
}

void bst_create_test(struct t_btree** root) {
    printf("----------------bst_create_test-------------\n");
    int val = 5;
    printf("Test 1: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    *root = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
    val = 123;
    printf("Test 2: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    (*root)->right = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
    val = 2;
    printf("Test 3: test val - %d.\n", val);
    printf("Tree now\n--------------\n ");
    output_tree(*root, 0);
    printf("--------------\nStart...\n");
    (*root)->left = bstree_create_node(val);
    output_tree(*root, 0);
    printf("--------------\n");
}


void output_tree(struct t_btree* root, int l) {
    if (root != NULL) {
        output_tree(root->right, l+1);
        for (int i = 1; i <= 3 * l; i++) {
            printf(" ");
        }
        printf("(%d)\n", root->val);
        output_tree(root->left, l+1);
    }
}
