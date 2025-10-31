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

    int countNodes(Node *root){

        if(root==NULL){return 0;}

        return 1+countNodes(root->left)+ countNodes(root->right);
    }

    int countLeaves(Node *root){

    if(root==NULL){return 0;}
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
   return  countLeaves(root->left) + countLeaves(root->right);
    }

   

    int calcHeight(Node *root){
        if(root==NULL){
            return 0;
        }
        int leftHeight= calcHeight(root->left);
        int rightHeight= calcHeight(root->right);

        return max(leftHeight, rightHeight)+1;
        }

    };




int main(){

    Tree t;
    Node *root= NULL;

     int num, choice;

    do {
        cout << "====== Tour Package Management ======"<<endl;
        cout << "1. Add Node"<<endl;
        cout << "2. Display Preorder"<<endl;
        cout << "3. Count Total Nodes"<<endl;
        cout << "4. Count Total Leaves"<<endl;
        cout << "5. Count Height"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Node Data: ";
            cin >> num;
            root = t.addNodes(num, root);
            break;

        case 2:
            cout << "\nPreorder Display:"<<endl;
            t.displayPreOrder(root);
            cout << endl;
            break;

        case 3:
            cout << "Total Nodes:"<<  t.countNodes(root) << endl;
            break;

        case 4:
          cout << "Total Leaves:"<<  t.countLeaves(root) << endl;
           
            break;

        case 5:

          cout << "Total Height:"<<t.calcHeight(root)<< endl;
        break;

        case 6:
          cout << "Exit!"<<endl;
          break;
           
        default:
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 6);
    


    return 0;


}
