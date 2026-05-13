#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(int x) : val(x), lchild(NULL), rchild(NULL) {}
};


//插入构建BST二叉排序树
TreeNode* Insert(TreeNode* root, int x){
    if(root == NULL){
        return new TreeNode(x);
    }

    if(x < root->val){
        root->lchild = Insert(root->lchild, x);
    }
    else if(x > root->val){
        root->rchild = Insert(root->rchild, x);
    }
    return root;
}

TreeNode* find(TreeNode* root, int x){
    while(root){
        if(root == NULL){
            return NULL;
        }
        if(x < root->val){
            root = root->lchild;
        }
        else if(x > root->val){
            root = root->rchild;
        }
        else if(root->val == x){
            return root;
        }
    }
    return NULL;
}

//LCA
TreeNode* getLCA(int p, int q, TreeNode* root){
    if(root == NULL){
        return NULL;
    }

    while(root){
        if(root->val < p && root->val < q){
            root = root->rchild;
        }
        else if(root->val > p && root->val > q){
            root = root->lchild;
        }
        else{
            return root;
        }
    }
    return NULL;
}

void print1(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    print1(root->lchild);
    print1(root->rchild);
}

void print2(TreeNode* root){
    if(root == NULL){
        return;
    }
    print2(root->lchild);
    cout << root->val << " ";
    print2(root->rchild);
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> ret(n);
    TreeNode *root = NULL;
    for (int i = 0; i < n; ++i){
        cin >> ret[i];
        root = Insert(root, ret[i]);
    }

    while(m--){
        int p, q;
        cin >> p >> q;
        TreeNode *x = find(root, p);
        TreeNode *y = find(root, q);
        if(!x && !y){
            cout << "ERROR: " << p << " and " << q << " are not found." << endl;
        }
        else if(!x){
            cout << "ERROR: " << p << " is not found." << endl;
        }
        else if(!y){
            cout << "ERROR: " << q << " is not found." << endl;
        }
        else{
            TreeNode *ans = getLCA(p, q, root);
            if(ans->val == p){
                cout << p << " is an ancestor of " << q << "." << endl;
            }
            else if(ans->val == q){
                cout << q << " is an ancestor of " << p << "." << endl;
            }
            else{
                cout << "LCA of " << p << " and " << q << " is " << ans->val << "." << endl;
            }
        }
    }
    return 0;
}