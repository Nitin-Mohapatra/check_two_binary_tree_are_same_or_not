#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// step-1 node counter
void nd_counter(struct TreeNode* root, int *count) {
    if (root == NULL) return;
    (*count)++;
    nd_counter(root->left, count);
    nd_counter(root->right, count);
}

// step-2 preorder traversal (fixed version)
void preorder(struct TreeNode* root, int *arr, int *i) {
    if (root == NULL){
        arr[(*i)++] = 0;
        return;
    };
    // printf("%d\n", root->val);
    arr[(*i)++] = root->val;
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}

// step-3 compare
bool cmp(int *arr1, int *arr2, int len1, int len2) {
    if (len1 != len2) {
        return false;
    } else {
        for (int i = 0; i < len1; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int nd_p = 0, nd_q = 0;
    nd_counter(p, &nd_p);
    nd_counter(q, &nd_q);

    int arr_p[nd_p], arr_q[nd_q];
    int index_p = 0, index_q = 0;
    preorder(p, arr_p, &index_p);
    preorder(q, arr_q, &index_q);

    return cmp(arr_p, arr_q, nd_p, nd_q);
}

int main() {
    struct TreeNode p1 = {1, NULL, NULL};
    struct TreeNode p2 = {2, NULL, NULL};
    p1.left = &p2;

    struct TreeNode q1 = {1, NULL, NULL};
    struct TreeNode q3 = {2, NULL, NULL};
    q1.right = &q3;

    bool same = isSameTree(&p1, &q1);

    if (same)
        printf("Both trees are same\n");
    else
        printf("Trees are NOT same\n");

    return 0;
}
