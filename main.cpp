// get all variables and functions from source.h
#include "source.h"

void menu() {
    do {
        cout << endl
             << "------ Welcome to CSG Gadget Shop System -----"<< endl 
             << endl
             << "    A.  Our Products Menu"                     << endl
             << "    B.  Customer Service"                      << endl
             << "    C.  Admin Login"                           << endl
             << "    D.  Exit"                                  << endl
             << endl
             << " Enter your choice : ";

        cin >> menuchoice;

        switch (menuchoice) {
            case 'A': case 'a':
                clear_screen();
				order_menu(); // order menu system for guest
                cout << endl << "Thanks for using our system! Have a nice day!" << endl << endl;
                break;
            case 'B': case 'b':
                clear_screen();
				customer_service(); // customer service system
                cout << endl << "Thanks for using our system! Have a nice day!" << endl << endl;
                break;
            case 'C': case 'c':
                clear_screen();
                admin_login(); // admin login system
                cout << endl << "Thanks for using our system! Have a nice day!" << endl << endl;
                break;
            case 'D': case 'd':
                cout << endl << "Thanks for using our system! Goodbye!" << endl << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
                break;
        }
    } while (menuchoice != 'D' && menuchoice != 'd');
}

int main() {
    get_current_time();
    menu();
    return 0;
}