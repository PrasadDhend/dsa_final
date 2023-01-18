#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{

    public:
        Node* root;
        BinaryTree(){
            root = NULL;
        }

        void preOrderTraversal(Node* node){
            if (node == NULL)
            {   
                return;
            }

            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
            
        }

        void inOrderTraversal(Node* node){
            if(node == NULL)return;

            inOrderTraversal(node->left);
            cout<< node->data << " ";
            inOrderTraversal(node->right);
        }


        void postOrderTraversal(Node* node){
            if(node == NULL) return;

            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    
};

int main(){

    BinaryTree binaryTree;

    binaryTree.root = new Node;

    binaryTree.root->data = 1;
    binaryTree.root->left = new Node;
    binaryTree.root->left->data = 2;
    binaryTree.root->left->left = NULL;
    binaryTree.root->left->right = NULL;
    binaryTree.root->right = new Node;
    binaryTree.root->right->data = 3;
    binaryTree.root->right->left = NULL;
    binaryTree.root->right->right = NULL;

    cout << endl << "------- Pre Order Traversal: -------" << endl;
    binaryTree.preOrderTraversal(binaryTree.root);

    cout << endl << "------- In Order Traversal ---------" << endl;
    binaryTree.inOrderTraversal(binaryTree.root);

    cout << endl << "------- Post Order Traversal -------" << endl;
    binaryTree.postOrderTraversal(binaryTree.root);

    return 0;
}