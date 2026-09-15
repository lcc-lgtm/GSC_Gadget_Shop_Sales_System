// get all variables and functions from source.h
#include "source.h"

void admin_login() {
    cout << "===========================================" << endl
         << "               Admin Login                 " << endl
         << "===========================================" << endl;

    string input_id;
    bool authenticated = false;

    /*
        admin_ids[] = { "admin123", "kelvinlcc" }; 
    */

    for (int i = 1; i <= 3; i++) {
        cout << "\n Enter Staff ID to login (Attempt " << i << "/3) : ";
        cin >> input_id;

        for (int j = 0; j < 2; j++) {
            if (input_id == admin_ids[j]) {
                authenticated = true;
                break;
            }
        }

        if (authenticated) {
            cout << endl 
                 << "[Login Successful] Welcome Admin!\n" << endl;
            break;
        }
        else {
            cout << endl 
                 << "[Error] Invalid Staff ID. Please try again.\n" << endl;
            if (i == 3) {
                cout << endl
                     << "[Error] Too many failed login attempts. Returning to main menu..." << endl;
                return;
            }
        }
    }

    if (!authenticated) return;

    char admin_choice;
    do {
        cout << endl
             << "===========================================" << endl
             << "                 Admin Menu                " << endl
             << "===========================================" << endl
             << "  1.  View & Export Sales Report" << endl
             << "  2.  Change Staff ID / Password" << endl
             << "  3.  Logout" << endl
             << endl
             << "  Enter your choice (1-3) : ";
        
        cin >> admin_choice;

        switch (admin_choice) {
        case '1':
            clear_screen();
            report();
            cout << endl << "Press Enter to return to Admin Menu...";
            cin.ignore();
            cin.get();
            clear_screen();
            break;
        case '2': {
            clear_screen();
            cout << ">--- Change Staff ID / Password ---<" << endl;
            string old_id, new_id;
            cout << "> Enter current Staff ID to modify : ";
            cin >> old_id;

            bool found = false;
			for (int j = 0; j < 2; j++) {   // max with 2 accs
                if (old_id == admin_ids[j]) {
                    cout << ">Enter new Staff ID : ";
                    cin >> new_id;
                    admin_ids[j] = new_id;
                    found = true;
                    cout << endl << "[Success] Staff ID / Password updated successfully!" << endl;
                    break;
                }
            }
            if (!found) {
                cout << endl << "[Error] Staff ID not found in system records." << endl;
            }
            cout << endl << "Press Enter to return to Admin Menu...";
            cin.ignore();
            cin.get();
            clear_screen();
            break;
        }
        case '3':
            clear_screen();
            cout << "[Logout] Successfully logged out from Admin session." << endl << endl;
            return;
        default:
            cout << "[Error] Invalid choice! Please select 1, 2, or 3." << endl;
            break;
        }
    } while (admin_choice != '3');
}