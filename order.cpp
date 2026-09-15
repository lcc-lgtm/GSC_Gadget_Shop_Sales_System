// get all variables and functions from source.h
#include "source.h"

void phone_menu() {
    cout << "+-------------------------------------------------------------------+" << endl
         << "|********************* Phone Accessories Menu: *********************|" << endl
         << "+-------------------------------------------------------------------+" << endl
         << "|                Product                | Unit price (RM) |  Stock  |" << endl
         << "+-------------------------------------------------------------------+" << endl
         << "| A. XIAOMI Fast Charge USB-C Cable     |      50.99      |   " << phoneProducts[0].stock << "   |" << endl
         << "| B. XIAOMI Normal USB-C Cable          |      25.99      |   " << phoneProducts[1].stock << "   |" << endl
         << "| C. XIAOMI Fast Charge Lightning Cable |      60.99      |   " << phoneProducts[2].stock << "   |" << endl
         << "| D. XIAOMI Normal Lightning Cable      |      30.99      |   " << phoneProducts[3].stock << "   |" << endl
         << "| E. XIAOMI TWS Bluetooth Earbuds       |      40.99      |   " << phoneProducts[4].stock << "   |" << endl
         << "| F. XIAOMI Neckband Bluetooth Earphone |      50.99      |   " << phoneProducts[5].stock << "   |" << endl
         << "+-------------------------------------------------------------------+" << endl;
}

void computer_menu() {
    cout << "+-------------------------------------------------------------------+" << endl
         << "|******************* Computer Accessories Menu: ********************|" << endl
         << "+-------------------------------------------------------------------+" << endl
         << "|                Product                | Unit price (RM) |  Stock  |" << endl
         << "+-------------------------------------------------------------------+" << endl
         << "| A. SanDisk USB Flash Drive 16GB       |      25.99      |   " << computerProducts[0].stock << "   |" << endl
         << "| B. Kingston USB Flash Drive 64GB      |      30.99      |   " << computerProducts[1].stock << "   |" << endl
         << "| C. WD 1TB External Hard Drive         |     250.99      |   " << computerProducts[2].stock << "   |" << endl
         << "| D. Seagate 512GB External Hard Drive  |     180.99      |   " << computerProducts[3].stock << "   |" << endl
         << "| E. XIAOMI Wireless Mouse              |      20.99      |   " << computerProducts[4].stock << "   |" << endl
         << "| F. XIAOMI Wired Mouse                 |      30.99      |   " << computerProducts[5].stock << "   |" << endl
         << "+-------------------------------------------------------------------+" << endl;
}

// check and process product quantity with stock validation
void process_item_purchase(char acc_type, char item_choice, int& out_qty, double& out_total, string& out_name, double& out_price) {
    int index = -1;
    if (item_choice >= 'A' && item_choice <= 'F') index = item_choice - 'A';
    else if (item_choice >= 'a' && item_choice <= 'f') index = item_choice - 'a';

    if (index == -1) return;

    Product* selectedProduct = nullptr;
    if (acc_type == 'A' || acc_type == 'a') {
        selectedProduct = &phoneProducts[index];
    }
    else {
        selectedProduct = &computerProducts[index];
    }

    out_name = selectedProduct->name;
    out_price = selectedProduct->price;

    bool digit;
    string qty_str;
    do {
        cout << "Quantity x ";
        cin >> qty_str;
        digit = true;
        for (size_t i = 0; i < qty_str.length(); i++) {
            if (!isdigit(qty_str[i])) digit = false;
        }
        if (!digit) cout << "Invalid input, enter a number." << endl;
    } while (!digit);

    out_qty = 0;
    for (size_t i = 0; i < qty_str.length(); i++) {
        out_qty = out_qty * 10 + (qty_str[i] - '0');
    }

    // stock validation
    while (out_qty <= 0 || out_qty > selectedProduct->stock) {
        if (out_qty <= 0) {
            cout << "Invalid quantity. Please enter a positive number." << endl;
        }
        else {
            cout << "Insufficient stock! Available stock is only " << selectedProduct->stock << "." << endl;
        }
        cout << "Please enter a smaller quantity: ";

        cin >> out_qty;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            out_qty = -1;
        }
    }

    // deduct stock
    selectedProduct->stock -= out_qty;
    out_total = out_price * out_qty;
}

void addon_order_menu() {
    char continue_addon = 'Y';
    AA_total = total;
    AA_qty = qty;

    // multiple add-ons loop
    while (continue_addon == 'Y' || continue_addon == 'y') {
        clear_screen();
        get_current_time();
        cout << endl << "--- ADD-ON ORDER MENU ---" << endl;
        cout << "Please choose an accessory category (A-PHONE / B-COMPUTER) : ";
        cin >> A_accessory;

        while (A_accessory != 'A' && A_accessory != 'a' && A_accessory != 'B' && A_accessory != 'b') {
            cout << "Invalid choice. Enter again : ";
            cin >> A_accessory;
        }

        if (A_accessory == 'A' || A_accessory == 'a') {
            phone_menu();
        }
        else {
            computer_menu();
        }

        cout << "Enter your item choice (A-F) : ";
        cin >> A_itembuy;

        while (A_itembuy < 'A' || (A_itembuy > 'F' && A_itembuy < 'a') || A_itembuy > 'f') {
            cout << "Invalid choice. Enter again : ";
            cin >> A_itembuy;
        }

        process_item_purchase(A_accessory, A_itembuy, A_qty, A_total, A_itemname, A_priceitem);

        AA_total += A_total;
        AA_qty += A_qty;

        cout << "Added successfully! Current cart total items: " << AA_qty << endl;
        cout << "Would you like to add on another item? (Y/N) : ";
        cin >> continue_addon;
    }
}

void order_menu() {
    clear_screen();
    get_current_time();
    // reset temp order values
    qty = 0; total = 0; A_qty = 0; A_total = 0;

    cout << "Welcome to CSG Gadget Shop!" << endl;
    cout << "Please choose an accessory category (A-PHONE / B-COMPUTER) : ";
    cin >> accessory;

    while (accessory != 'A' && accessory != 'a' && accessory != 'B' && accessory != 'b') {
        cout << "Invalid choice. Please enter again : ";
        cin >> accessory;
    }

    if (accessory == 'A' || accessory == 'a') {
        phone_menu();
    }
    else {
        computer_menu();
    }

    cout << "Enter your item choice (A-F) : ";
    cin >> itembuy;

    while (itembuy < 'A' || (itembuy > 'F' && itembuy < 'a') || itembuy > 'f') {
        cout << "Invalid choice. Please enter again : ";
        cin >> itembuy;
    }

    process_item_purchase(accessory, itembuy, qty, total, itemname, priceitem);

    cout << "Your choice: " << itemname << " | Price: RM " << fixed << setprecision(2) << priceitem << endl;
    cout << "Subtotal for this item : RM " << fixed << setprecision(2) << total << endl;

    cout << "Would you like to add on items? (Y/N) : ";
    cin >> addon_order;

    while (addon_order != 'Y' && addon_order != 'y' && addon_order != 'N' && addon_order != 'n') {
        cout << "Invalid choice. Enter again : ";
        cin >> addon_order;
    }

    if (addon_order == 'Y' || addon_order == 'y') {
        addon_order_menu();
    }

    identity_payment();
    cout << endl << "Thank you! Proceeding to invoice..." << endl << endl;
    invoice();

    cout << "Select payment method (A:E-Wallet / B:Credit Card / C:Debit Card / D:Cash) : ";
    cin >> payment;
    while (payment != 'A' && payment != 'a' && payment != 'b' && payment != 'B' && payment != 'c' && payment != 'C' && payment != 'd' && payment != 'D') {
        cout << "Invalid payment method. Choose again : ";
        cin >> payment;
    }
    receipt();
}

void invoice() {
    clear_screen();
    get_current_time();

    cout << setw(57) << "CSG Gadget Shop" << endl;
    cout << setw(67) << "====================================" << endl;
    cout << setw(57) << "Tel: 012-3456789" << endl << endl;
    cout << "Invoice No: " << invoicenum + 1 << setw(70) << day << "/" << month << "/" << year << endl << endl;
    cout << left << setw(30) << "Quantity" << left << setw(52) << "Item" << left << setw(35) << "Price(RM)" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;

    // display primary item
    cout << right << setw(4) << qty << setw(13) << "" << left << setw(62) << itemname << right << setw(10) << fixed << setprecision(2) << total << endl;

    double calc_subtotal = total;
    int calc_qty = qty;

    if (addon_order == 'Y' || addon_order == 'y') {
        calc_subtotal = AA_total;
        calc_qty = AA_qty;
        cout << right << setw(4) << A_qty << setw(13) << "" << left << setw(62) << A_itemname << right << setw(10) << fixed << setprecision(2) << A_total << endl;
    }

    // calc part
    if (calc_subtotal >= 100.00) {
        cout << endl << "Congratulations! You got a 20% discount for spending over RM 100.00!!" << endl << endl;
        discountrate = calc_subtotal * DISCOUNT_RATE;
        afterdiscount = calc_subtotal - discountrate;
        chargerate = afterdiscount * SERVICE_CHARGE_RATE;
        taxrate = afterdiscount * TAX_RATE;
        final_total = afterdiscount + chargerate + taxrate;
    }
    else {
        discountrate = 0.0;
        afterdiscount = calc_subtotal;
        chargerate = calc_subtotal * SERVICE_CHARGE_RATE;
        taxrate = calc_subtotal * TAX_RATE;
        final_total = calc_subtotal + chargerate + taxrate;
    }

    cout << endl;
    cout << "Subtotal" << setw(78) << "RM " << fixed << setprecision(2) << calc_subtotal << endl;
    cout << "Discount" << setw(78) << "-RM " << fixed << setprecision(2) << discountrate << endl;
    cout << "Service Charge (6%)" << setw(67) << "RM " << fixed << setprecision(2) << chargerate << endl;
    cout << "Tax (6%)" << setw(78) << "RM " << fixed << setprecision(2) << taxrate << endl << endl;
    cout << "Total items" << setw(73) << calc_qty << endl;
    cout << "Net Total" << setw(77) << "RM " << fixed << setprecision(2) << final_total << endl;
}

void receipt() {
    identity_payment();
    get_current_time();
    cout << endl << endl;
    cout << left << setw(83) << "Payment Method" << payment_method << endl;
    cout << left << setw(83) << "Paid Amount" << "RM ";
    cin >> amount;

    double current_final = final_total;

    while (amount < current_final) {
        cout << endl << "Insufficient amount. Pay again..." << endl;
        cout << "New Paid Amount : RM ";
        cin >> amount;
    }
    change = amount - current_final;

    cout << left << setw(83) << "Change" << "RM " << fixed << setprecision(2) << change << endl;
    invoicenum++;
    custnum++;
    cout << endl;
}