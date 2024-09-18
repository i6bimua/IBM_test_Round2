#include <iostream>
using namespace std;

class transitCard
{
    // protected for changing afterwards
protected:
    int Balance = 150; // original balance

public:
    // virtual function for override afterwards.
    virtual void topUp()
    {
        cout << "enter the money." << endl;
        int money = 0;
        cin >> money;
        Balance += money;
    }

    virtual void spending()
    {
        cout << "enter the distance." << endl;
        int distance = 0;
        cin >> distance;

        Balance -= distance;
    }

    void showBalance()
    {
        cout << "the balance is " << Balance << " now." << endl;
    }
};

class studentCard : public transitCard
{
public:
    // student have a discount when topping up and taking a bus
    void topUp() override
    {
        cout << "add money to the student card." << endl;
        int money;
        cin >> money;
        Balance += money * 1.4;
    }

    void spending() override
    {
        cout << "enter the distance and go with a student-discount." << endl;
        int distance = 0;
        cin >> distance;
        Balance -= 0.8 * distance;
    }
};

void afterCreating(transitCard &obj);

int main()
{
    cout << "choose a type of card you want to create." << endl
         << "1 for normal card,2 for student card." << endl
         << "a code is required when creating a student card." << endl;
    // action selector
    int actionCode1;
    cin >> actionCode1;

    if (actionCode1 == 1)
    {
        // creat a normal instance
        transitCard card1;
        afterCreating(card1); // call the function after creating.
    }

    else if (actionCode1 == 2)
    {
        // passcode checking step(123)
        int passcode = 0;
        cout << "enter the code for a student card" << endl;
        cin >> passcode;
        if (passcode == 123)
        {
            // create a student card instance
            studentCard card2;
            afterCreating(card2);
        }
        else
        {
            cout << "wrong code,fail to create." << endl;
        }
    }
    // check the validity of the input
    else
    {
        cout << "invalid actioncode.";
    }
}

void afterCreating(transitCard &obj)
{
    int code = 0;
    cout << "the original balance of the card is 150." << endl;
    // loop
    while (code != 3)
    {
        cout << "enter the actioncode you want " << endl
             << "1 for top up and 2 for taking a bus." << endl
             << "or enter 3 to quit the system." << endl;
        cout << endl;

        cin >> code;
        // 1 for top up.
        if (code == 1)
        {
            obj.topUp();
        }
        // 2 for taking a bus.
        else if (code == 2)
        {
            obj.spending();
        }
        // showcase the real time balance after action
        obj.showBalance();
    }

    cout << "goodbye!";
}