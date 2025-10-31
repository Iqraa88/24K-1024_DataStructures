#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node *right;

    Node(int n){
        data= n;
        left=right= NULL;
    }

};

    class Tree{


    public:
     Node* addNodes(int n, Node *root){
        if(root==NULL){
            return new Node(n);
        }

        char choice;
        cout<<"Where do you want to add the new Node?"<<endl;
        cin>> choice;

        if(choice =='L'|| choice=='l'){
            if(root->left==NULL){
                root->left= new Node(n);
            }
            else{

            addNodes(n, root->left);
            }

        }
        else if(choice=='R'|| choice=='r'){
            if(root->right==NULL){root->right= new Node(n);}
            else{
            addNodes(n, root->right);
            }
        }
        else{
            cout<<"No such choice exists!"<<endl;

        }

        return root;
    }

     void displayPreOrder(Node *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }

    bool isFullBinary(Node *root){
        if(root==NULL){
            return true;
        }

        if(root->left==NULL & root->right==NULL){
            return true;
        }
        if(root->left!=NULL && root->right!=NULL){
            return isFullBinary(root->left) && isFullBinary(root->right);
        }

        return false;
    }

};

int main(){

    Tree t;
    Node *root= NULL;
       int choice, val;

    do {
        cout << "===== Gaming Level Tree Menu ====="<<endl;
        cout << "1. Add Level (Node)\n";
        cout << "2. Display Tree (Preorder)\n";
        cout << "3. Check if Full Binary Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Level Number: ";
            cin >> val;
            root = t.addNodes(val, root);
            break;

        case 2:
            cout << "Preorder Traversal: ";
            t.displayPreOrder(root);
            cout << endl;
            break;

        case 3:
            if (t.isFullBinary(root))
                cout << " The tree IS a Full Binary Tree.\n";
            else
                cout << " The tree is NOT a Full Binary Tree.\n";
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 4);

    return 0;
}
