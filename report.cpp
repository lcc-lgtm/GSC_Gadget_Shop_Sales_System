// get all variables and functions from source.h
#include "source.h"

void report() {
    for (int i = 1; i <= 3; i++) {
        cout << "Hello, please enter your staff ID : ";
        cin >> admin_id;

        bool valid = false;
        for (int j = 0; j < 2; j++) {   // max with 2 accs
            if (admin_id == admin_ids[j]) {
                valid = true;
            }
        }

        if (valid) {
			// display daily report
            cout << endl << endl;
            cout << "            Daily Report" << endl;
            cout << "-------------------------------------" << endl;
            cout << " Date                  : " << day << "/" << month << "/" << year << endl;
            cout << " Today total customers : " << invoicenum << endl;
            cout << " Today total sales     : " << custnum << endl;
            cout << " Today total warranty  : " << warrantynum << endl;
            cout << " Today total refund    : " << refundnum << endl;
            cout << "-------------------------------------" << endl;
            
            // Automatically export report to a .txt file
            string filename = "Sales_Report_" + to_string(day) + "_" + to_string(month) + "_" + to_string(year) + ".txt";
            ofstream outfile(filename);
            if (outfile.is_open()) {
                outfile << "            Daily Report\n";
                outfile << "-------------------------------------\n";
                outfile << " Date                  : " << day << "/" << month << "/" << year << "\n";
                outfile << " Today total customers : " << invoicenum << "\n";
                outfile << " Today total sales     : " << custnum << "\n";
                outfile << " Today total warranty  : " << warrantynum << "\n";
                outfile << " Today total refund    : " << refundnum << "\n";
                outfile << "-------------------------------------\n";
                outfile.close();

                cout << endl << "[Success] Report exported to .txt file successfully!" << endl;
                cout << "Generated File Name    : " << filename << endl;

            }
            else {
                cout << "[Error] Failed to create report text file." << endl;
            }

            break;
        }
        else {
            cout << "Invalid Staff ID..." << endl << endl;
            if (i == 3) {
                cout << "Too many failed attempts! Returning to main menu..." << endl << endl;
            }
        }
    }
}