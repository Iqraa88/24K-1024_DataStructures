#include<iostream>
using namespace std;

class Package{

    public:

    int pkgNo;
    Package *left;
    Package *right;

    Package(int n){
        pkgNo= n;
        left=right= NULL;
    }

};

    class Tree{


    public:
    Package* addPackages(int num, Package *root){
        if(root==NULL){
            return new Package(num);
        }

        char choice;
        cout<<"Where do you want to add the new package?"<<endl;
        cin>> choice;

        if(choice =='L'|| choice=='l'){
            if(root->left==NULL){
                root->left= new Package(num);
            }
            else{

            addPackages(num, root->left);
            }

        }
        else if(choice=='R'|| choice=='r'){
            if(root->right==NULL){root->right= new Package(num);}
            else{
            addPackages(num, root->right);
            }
        }
        else{
            cout<<"No such choice exists!"<<endl;

        }

        return root;

    }  


    void displayPreOrder(Package *root){
        if(root==NULL){
            return;
        }
        cout<<root->pkgNo<<" ";
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }

};



int main(){

    Tree t;
    Package *root= NULL;
    int num, choice;

    do {
        cout << "====== Tour Package Management ======"<<endl;
        cout << "1. Add Package"<<endl;
        cout << "2. Display Preorder"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter package number: ";
            cin >> num;
            root = t.addPackages(num, root);
            break;

        case 2:
            cout << "\nPreorder Display:"<<endl;
            t.displayPreOrder(root);
            cout << endl;
            break;

        case 3:
            cout << "Goodbye!"<<endl;
            break;

        default:
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 3);


    return 0;


}
