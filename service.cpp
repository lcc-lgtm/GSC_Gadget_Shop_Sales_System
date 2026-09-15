// get all variables and functions from source.h
#include "source.h"

void customer_service() {
    cout << "===========================================" << endl
         << "             Customer Service              " << endl
         << "===========================================" << endl
         << "Would you like to refund or claim warranty?" << endl
         << "\tR\t-\trefund\n\tW\t-\twarranty" << endl
         << "Which mode to proceed :\t";

    cin >> cust_choice;

    while (cust_choice != 'R' && cust_choice != 'r' && cust_choice != 'W' && cust_choice != 'w') {
        cout << "Invalid choice. Please enter again : ";
        cin >> cust_choice;
    }

    if (cust_choice == 'R' || cust_choice == 'r') {
        cout << endl << "Proceeding to refund process." << endl << endl;
        refund();
    }
    else if (cust_choice == 'W' || cust_choice == 'w') {
        cout << endl << "Proceeding to warranty process." << endl << endl;
        warranty();
    }
}

void refund() {
    get_current_time();

    cout << "Enter your name : ";
    cin.ignore();
    getline(cin, cust_R_name);

    bool phonedigit;
    do {
        cout << "Enter phone number without '-' : ";
        cin >> cust_R_phone;
        phonedigit = true;
        for (size_t i = 0; i < cust_R_phone.length(); i++) {
            if (!isdigit(cust_R_phone[i])) phonedigit = false;
        }
        if (!phonedigit) cout << "Invalid input, numbers only." << endl;
    } while (!phonedigit);

    cout << "Enter name of product to refund : ";
    cin.ignore();
    getline(cin, refund_product);

    cout << "Enter price of product : RM ";
    cin >> refundprice;
    cout << endl;

    cout << "Please select a reason for refund:" << endl;
    cout << "\t1.  Product is not working." << endl;
    cout << "\t2.  Received wrong model/color." << endl;
    cout << "\t3.  Physical damage upon opening." << endl;
    cout << "\t4.  Battery issue." << endl;
    cout << "\t5.  Not compatible with device." << endl;
    cout << "\t6.  Wrong quantity received." << endl;
    cout << "\t7.  Other." << endl;

    bool valid_reason;
    do {
        cout << "Enter reason number (1-7) : ";
        cin >> input_R_reason;
        valid_reason = true;
        for (size_t i = 0; i < input_R_reason.length(); i++) {
            if (!isdigit(input_R_reason[i])) valid_reason = false;
        }
        if (valid_reason) {
            choice_R_reason = 0;
            for (size_t i = 0; i < input_R_reason.length(); i++) {
                choice_R_reason = choice_R_reason * 10 + (input_R_reason[i] - '0');
            }
            if (choice_R_reason < 1 || choice_R_reason > 7) valid_reason = false;
        }
        if (!valid_reason) cout << "Invalid choice. Enter between 1 and 7." << endl;
    } while (!valid_reason);

    identity_refund_reason();
    clear_screen();

    cout << endl
         << "-------- Refund Confirmation --------" << endl
         << " Name          : " << cust_R_name << endl
         << " Phone number  : " << cust_R_phone << endl
         << " Product       : " << refund_product << endl
         << " Price         : RM " << fixed << setprecision(2) << refundprice << endl
         << " Reason        : " << refund_reason << endl
         << endl
         << "Confirm information (Y/N) : ";
    
    cin >> confirm_refund;

    while (confirm_refund != 'Y' && confirm_refund != 'y' && confirm_refund != 'N' && confirm_refund != 'n') {
        cout << "Invalid choice. Enter again : ";
        cin >> confirm_refund;
    }

    if (confirm_refund == 'Y' || confirm_refund == 'y') {
        cout << "Refund request submitted successfully!" << endl;
        receipt_refund();
    }
    else {
        cout << endl << "Back to main page..." << endl << endl;
        return;  // to return to menu()
    }
}

void receipt_refund() {
    get_current_time();
    cout << setw(40) << "Receipt" << endl;
    cout << setw(40) << "---------------------" << endl;
    cout << "Invoice No : " << invoicenum + 1 << setw(30) << day << "/" << month << "/" << year << endl;
    cout << "Product    : " << refund_product << endl;
    cout << "Reason     : " << refund_reason << endl << endl;
    cout << "Result will be notified within 3 days via WhatsApp!" << endl << endl;
    refundnum++;
    invoicenum++;
}

void warranty() {
    get_current_time();
    cout << "Enter your name : ";
    cin.ignore();
    getline(cin, cust_name);

    bool phonedigit;
    do {
        cout << "Enter phone number without '-' : ";
        cin >> cust_phone;
        phonedigit = true;
        for (size_t i = 0; i < cust_phone.length(); i++) {
            if (!isdigit(cust_phone[i])) phonedigit = false;
        }
        if (!phonedigit) cout << "Invalid input, numbers only." << endl;
    } while (!phonedigit);

    cout << "Enter name of product for warranty : ";
    cin.ignore();
    getline(cin, warranty_product);
    cout << endl;

    cout << "Select warranty reason:" << endl;
    cout << "\t1.  Manufacturing defect." << endl;
    cout << "\t2.  Hardware failure." << endl;
    cout << "\t3.  Software issue." << endl;
    cout << "\t4.  Improper usage." << endl;
    cout << "\t5.  Normal wear and tear." << endl;
    cout << "\t6.  External factor." << endl;
    cout << "\t7.  Other." << endl;

    bool valid_reason;
    do {
        cout << "\nEnter reason number (1-7) : ";
        cin >> input_reason;
        valid_reason = true;
        for (size_t i = 0; i < input_reason.length(); i++) {
            if (!isdigit(input_reason[i])) valid_reason = false;
        }
        if (valid_reason) {
            choice_reason = input_reason[0] - '0';
            if (choice_reason < 1 || choice_reason > 7) valid_reason = false;
        }
        if (!valid_reason) cout << "Invalid choice. Enter between 1 and 7." << endl;
    } while (!valid_reason);

    identity_warranty_reason();

    bool digit;
    do {
        cout << "Enter warranty expiry date (YYYY MM DD separated by space): ";
        cin >> inputyear >> inputmonth >> inputdate;
        digit = true;
        for (size_t i = 0; i < inputyear.length(); i++) {
            if (!isdigit(inputyear[i])) digit = false;
        }
        for (size_t i = 0; i < inputmonth.length(); i++) {
            if (!isdigit(inputmonth[i])) digit = false;
        }
        for (size_t i = 0; i < inputdate.length(); i++) {
            if (!isdigit(inputdate[i])) digit = false;
        }
        if (!digit) cout << "Invalid input, numbers only." << endl;
    } while (!digit);

    W_year = 0; 
    for (size_t i = 0; i < inputyear.length(); i++) 
        W_year = W_year * 10 + (inputyear[i] - '0');

    W_month = 0; 
    for (size_t i = 0; i < inputmonth.length(); i++) 
        W_month = W_month * 10 + (inputmonth[i] - '0');

    W_date = 0; 
    for (size_t i = 0; i < inputdate.length(); i++) 
        W_date = W_date * 10 + (inputdate[i] - '0');

    if (!compare_warranty_date()) {
        return;
    }
    clear_screen();

    cout << "-------- Warranty Confirmation --------" << endl
         << " Name          : " << cust_name << endl
         << " Phone number  : " << cust_phone << endl
         << " Product       : " << warranty_product << endl
         << " Reason        : " << warranty_reason << endl
         << " Expiry Date   : " << W_date << "/" << W_month << "/" << W_year << endl
         << endl
         << " Confirm information (Y/N) : ";
    
    cin >> confirm_warranty;

    while (confirm_warranty != 'Y' && confirm_warranty != 'y' && confirm_warranty != 'N' && confirm_warranty != 'n') {
        cout << "Invalid choice. Enter again : ";
        cin >> confirm_warranty;
    }

    if (confirm_warranty == 'Y' || confirm_warranty == 'y') {
        cout << "Warranty request submitted successfully!" << endl;
        receipt_warranty();
    }
    else {
        cout << endl << "Back to main page..." << endl << endl;
        return;  // to return to menu()
    }
}

void receipt_warranty() {
    cout << endl << setw(40) << "Receipt" << endl;
    cout << setw(40) << "---------------------" << endl;
    cout << " Invoice No : " << invoicenum + 1 << setw(30) << day << "/" << month << "/" << year << endl;
    cout << " Item       : " << warranty_product << endl;
    cout << " Reason     : " << warranty_reason << endl << endl;
    cout << " Result will be notified within 3 days via WhatsApp!" << endl << endl;
    warrantynum++;
    invoicenum++;
}