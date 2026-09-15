// get all variables and functions from source.h
#include "source.h"

// global variables
char menuchoice;
int day, month, year;

char accessory, itembuy, addon_order;
double priceitem = 0;
string itemname = "";
string inputqty = "";
int qty = 0;

char A_accessory, A_itembuy;
double A_priceitem = 0;
string A_itemname = "";
string A_inputqty = "";
int A_qty = 0;

double total = 0, discountrate = 0, afterdiscount = 0, chargerate = 0, taxrate = 0, final_total = 0;
double A_total = 0, AA_total = 0;
int AA_qty = 0;
char payment = ' ';
string payment_method = "";
double amount = 0, change = 0;
int invoicenum = 0;
int custnum = 0;

char cust_choice = ' ';
string cust_name = "", cust_phone = "", warranty_product = "", warranty_reason = "";
string input_reason = "";
int choice_reason = 0;
string inputdate = "", inputmonth = "", inputyear = "";
int W_date = 0, W_month = 0, W_year = 0;
char confirm_warranty = ' ';
int warrantynum = 0;

string cust_R_name = "", cust_R_phone = "", refund_product = "", refund_reason = "";
string input_R_reason = "";
int choice_R_reason = 0;
char confirm_refund = ' ';
double refundprice = 0;
int refundnum = 0;

// initialize admin id
string admin_id = "";  
string admin_ids[] = { "admin123", "kelvinlcc" };

/* local storage, 1d-array for stock management */
// phone category product stock
Product phoneProducts[6] = {
    {"XIAOMI Fast Charge USB-C Cable", 50.99, 40},
    {"XIAOMI Normal USB-C Cable", 25.99, 80},
    {"XIAOMI Fast Charge Lightning Cable", 60.99, 50},
    {"XIAOMI Normal Lightning Cable", 30.99, 40},
    {"XIAOMI TWS Bluetooth Earbuds", 40.99, 70},
    {"XIAOMI Neckband Bluetooth Earphone", 50.99, 50}
};
// computer category product stock
Product computerProducts[6] = {
    {"SanDisk USB Flash Drive 16GB", 25.99, 60},
    {"Kingston USB Flash Drive 64GB", 30.99, 60},
    {"WD 1TB External Hard Drive", 250.99, 30},
    {"Seagate 512GB External Hard Drive", 180.99, 40},
    {"XIAOMI Wireless Mouse", 20.99, 50},
    {"XIAOMI Wired Mouse", 30.99, 50}
};

// cls func
void clear_screen() {
    system("cls");
}

// get current time func
void get_current_time() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    day = ltm.tm_mday;
    month = ltm.tm_mon + 1;
    year = 1900 + ltm.tm_year;
}

// identify item price & name func
void identity_price_name() {
    int index = -1;
    if (itembuy >= 'A' && itembuy <= 'F') index = itembuy - 'A';
    else if (itembuy >= 'a' && itembuy <= 'f') index = itembuy - 'a';

    if (index != -1) {
        if (accessory == 'A' || accessory == 'a') {
            itemname = phoneProducts[index].name;
            priceitem = phoneProducts[index].price;
        }
        else if (accessory == 'B' || accessory == 'b') {
            itemname = computerProducts[index].name;
            priceitem = computerProducts[index].price;
        }
    }
}
// identify add-on item price & name func
void identity_addon_price_name() {
    int index = -1;
    if (A_itembuy >= 'A' && A_itembuy <= 'F') index = A_itembuy - 'A';
    else if (A_itembuy >= 'a' && A_itembuy <= 'f') index = A_itembuy - 'a';

    if (index != -1) {
        if (A_accessory == 'A' || A_accessory == 'a') {
            A_itemname = phoneProducts[index].name;
            A_priceitem = phoneProducts[index].price;
        }
        else if (A_accessory == 'B' || A_accessory == 'b') {
            A_itemname = computerProducts[index].name;
            A_priceitem = computerProducts[index].price;
        }
    }
}
// identify payment method func
void identity_payment() {
    switch (payment) {
        case 'A': 
        case 'a': 
            payment_method = "E - Wallet"; 
            break;

        case 'B': 
        case 'b': 
            payment_method = "Credit Card"; 
            break;

        case 'C': 
        case 'c': 
            payment_method = "Debit Card";
            break;

        case 'D': 
        case 'd': 
            payment_method = "Cash"; 
            break;
    }
}
// identify warranty reason func
void identity_warranty_reason() {
    switch (choice_reason) {
        case 1: 
            warranty_reason = "Manufacturing defect."; 
            break;
        case 2: 
            warranty_reason = "Hardware failure."; 
            break;
        case 3: 
            warranty_reason = "Software issue."; 
            break;
        case 4: 
            warranty_reason = "Improper usage."; 
            break;
        case 5: 
            warranty_reason = "Normal wear and tear."; 
            break;
        case 6: 
            warranty_reason = "External factor."; 
            break;
        case 7:
            cin.ignore();
            cout << "Please describe your reason : ";
            getline(cin, warranty_reason);
            break;
    }
}
// validate warranty date func
void identity_warranty_date() {
    while (W_month < 1 || W_month > 12) {
        cout << "Invalid month... Please enter again : ";
        cin >> W_month;
    }
    switch (W_month) {
        // month with 31 days
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12:
            while (W_date < 1 || W_date > 31) { 
                cout << "Invalid date... Enter again : "; 
                cin >> W_date; 
            }
            break;

		// month with 30 days
        case 4: case 6: case 9: case 11:
            while (W_date < 1 || W_date > 30) { 
                cout << "Invalid date... Enter again : "; 
                cin >> W_date; 
            }
            break;

		// feb with 28 or 29 days
        case 2:
            if ((W_year % 4 == 0 && W_year % 100 != 0) || W_year % 400 == 0) {
                while (W_date < 1 || W_date > 29) { 
                    cout << "Invalid date (Leap year)... Enter again : ";
                    cin >> W_date; 
                }
            }
            else {
                while (W_date < 1 || W_date > 28) { 
                    cout << "Invalid date... Enter again : "; 
                    cin >> W_date; 
                }
            }
            break;
    }
}

// compare the warranty date func
bool compare_warranty_date() {
    get_current_time();
    identity_warranty_date();
    if (W_year < year || (W_year == year && W_month < month) || (W_year == year && W_month == month && W_date < day)) {
        cout << endl << "Warranty has expired... Back to main page..." << endl << endl;
        return false;  // warranty has expired
    }
    return true;  // warranty is still valid
}

// identify the refund reason func
void identity_refund_reason() {
    switch (choice_R_reason) {
        case 1: 
            refund_reason = "Product is not working."; 
            break;

        case 2: 
            refund_reason = "Received wrong model/color."; 
            break;

        case 3: 
            refund_reason = "Physical damage upon opening."; 
            break;

        case 4: 
            refund_reason = "Battery issue."; 
            break;

        case 5: 
            refund_reason = "Not compatible with device."; 
            break;

        case 6: 
            refund_reason = "Wrong quantity received."; 
            break;

        case 7:
            cin.ignore();
            cout << "Please describe your reason : ";
            getline(cin, refund_reason);
            break;
    }
}