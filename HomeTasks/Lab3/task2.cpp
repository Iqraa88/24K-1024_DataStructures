#include <iostream>
using namespace std;

class Item
{

public:
    string name;
    double price;
    Item *next;

    Item()
    {

        name = "";
        price = 0;
        next = NULL;
    }

    Item(string item, double price)
    {

        this->name = item;
        this->price = price;
        next = NULL;
    }
};
class ShoppingCart
{

public:
    Item *head;
    Item *tail;
    Item *temp;

    ShoppingCart()
    {

        head = tail = temp = NULL;

        addAtEnd(new Item("Laptop", 1000));
        addAtEnd(new Item("Phone", 700));
        addAtEnd(new Item("Tablet", 400));
        addAtEnd(new Item("HeadPhones", 150));
    }

    void addAtEnd(Item *i)
    {

        if (head == NULL)
        {

            head = tail = i;
        }
        else
        {

            tail->next = i;
            tail = i;
        }
    }

    void deleteFromFront()
    {

        if (head == NULL)
        {

            cout << "kuch hai hi nahi to kya delete kroge?" << endl;
            return;
        }
        else
        {

            temp = head->next;
            delete head;
            head = head->next;
            cout << "hogaya delete bhai, sukoon ka sans lo ab." << endl;
        }
    }

    void searchByPos(int pos)
    {

        if (head == NULL)
        {
            cout << "khaali cart mein kya search krhy ho?" << endl;
            return;
        }
        else
        {
            bool found = false;
            temp = head;
            int i = 1;
            while (temp != NULL)
            {

                if (i == pos)
                {
                    found = true;
                    cout << "Item at position " << pos << " found:" << endl;
                    cout << "Item: " << temp->name << "  - Price: " << temp->price << " $." << endl;
                    break;
                }
                temp = temp->next;
                i++;
            }
            if (!found)
            {
                cout << "nahi mila bhai kuch bhe apki position pe." << endl;
                return;
            }
        }
    }
    void searchByName(string itemName)
    {

        if (head == NULL)
        {

            cout << " Empty Cart!" << endl;
            return;
        }
        else
        {

            temp = head;
            bool found = false;
            while (temp != NULL)
            {

                if (temp->name == itemName)
                {

                    found = true;
                    cout << "Item: " << temp->name << " Exists." << endl;
                    cout << "The Price for your item is: " << temp->price << " $" << endl;
                    break;
                }

                temp = temp->next;
            }
            if (!found)
            {

                cout << " Couldn't find: " << itemName << " !" << endl;
            }
        }
    }

    void displayCart()
    {

        temp = head;
        cout << "---------Displaying Items in Cart-----------" << endl;
        while (temp != NULL)
        {

            cout << " " << temp->name << "  -  " << temp->price << " $" << endl;
            temp = temp->next;
        }
        cout << " No more items." << endl;
    }
};

int main()
{

    ShoppingCart c1;
    cout << "Adding item to tail...." << endl;
    c1.addAtEnd(new Item("EarBuds", 100));
    cout << "--------------------------" << endl;

    cout << " Deleting from front...." << endl;
    c1.deleteFromFront();
    cout << "--------------------------" << endl;

    cout << " Searching by name...." << endl;
    c1.searchByName("Phone");
    cout << "--------------------------" << endl;

    cout << " Searching by position...." << endl;
    c1.searchByPos(3);

    c1.displayCart();

    return 0;
}