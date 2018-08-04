#include <iostream>
#include<stack>

using namespace std;

class TreeNode
{
  public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : value(v), left(NULL), right(NULL) {}
};

//实现二叉树的，先，中，后 三种遍历方式，包括递归和非递归方式
class allOrder
{
    //先序遍历的非递归形式
    static void pre_noRec(TreeNode* root){
        if(!root){
            stack<TreeNode*> sta;
            TreeNode *temp(0);
            sta.push(root);
            while(!sta.empty){
                temp=sta.top();
                sta.pop;
                cout<<temp->value<<" ";
                if(temp->right){
                    sta.push(temp->right);
                }
                if(temp->left){
                    sta.push(temp->left);
                }
            }

        }
    }

    //中序遍历的非递归形式
    static void in_noRec(TreeNode* root){
        if(!root){
            stack<TreeNode*> s;
            while(!s.empty()||root!=NULL){
                if(root!=NULL){
                    s.push(root);
                    root=root->left;
                }else{
                    root=s.top();
                    s.pop();
                    cout<<root->value<<" ";
                    root=root->left;
                }
            }
        }
    }
    // 后序遍历的非递归形式，左 右 中==反转（中 右 左） 相当于将另一种先序遍历反过来
    static void pos_noRec(TreeNode* root){
        if(!root){
            stack<TreeNode*> sta;
            stack<TreeNode*> help;
            TreeNode *temp(0);
            sta.push(root);
            while(!sta.empty){
                temp=sta.top();
                sta.pop;
                help.push(temp);
                if(temp->left){
                    sta.push(temp->right);
                }
                if(temp->right){
                    sta.push(temp->left);
                }
            }

            while(!help.empty()){
                TreeNode *p=help.top();
                cout<<p->value<<" ";
                help.pop();
            }

        }
    }
    

































    //pre
    static void pre(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->value << " ";
        pre(root->left);
        pre(root->right);
    }
    //in
    static void in(TreeNode *root)
    {
        if (root == NULL)
            return;
        in(root->left);
        cout<<root->value<<" ";
        in(root->right);
    }
    //post
    static void post(TreeNode *root){
        if(root==NULL){
            return;
        }
        post(root->left);
        post(root->right);
        cout<<root->value<<" ";
    }

};