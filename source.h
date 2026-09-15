#pragma once

#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cctype>
#include <fstream>

#define DISCOUNT_RATE 0.20
#define SERVICE_CHARGE_RATE 0.06
#define TAX_RATE 0.06

using namespace std;

// Product struct for stock management
struct Product {
    string name;
    double price;
    int stock;
};

/* global variables declaration using extern storage class */
// user menu input variable
extern char menuchoice;

// timing variable
extern int day, month, year;

// order part variables
extern char accessory, itembuy, addon_order;
extern double priceitem;
extern string itemname;
extern string inputqty;
extern int qty;

// add-on part variables
extern char A_accessory, A_itembuy;
extern double A_priceitem;
extern string A_itemname;
extern string A_inputqty;
extern int A_qty;

// invoice & payment part variables
extern double total, discountrate, afterdiscount, chargerate, taxrate, final_total;
extern double A_total, AA_total;
extern int AA_qty;
extern char payment;
extern string payment_method;
extern double amount, change;
extern int invoicenum;
extern int custnum;

// customer service part variable
extern char cust_choice;

// warranty part variables
extern string cust_name, cust_phone, warranty_product, warranty_reason;
extern string input_reason;
extern int choice_reason;
extern string inputdate, inputmonth, inputyear;
extern int W_date, W_month, W_year;
extern char confirm_warranty;
extern int warrantynum;

// refund part variables
extern string cust_R_name, cust_R_phone, refund_product, refund_reason;
extern string input_R_reason;
extern int choice_R_reason;
extern char confirm_refund;
extern double refundprice;
extern int refundnum;

// report part variables
extern string admin_id;
extern string admin_ids[];

// product stock management variables
extern Product phoneProducts[6];
extern Product computerProducts[6];

// cli prototype func
void clear_screen();
void get_current_time();
void identity_price_name();
void identity_addon_price_name();
void identity_payment();
void identity_warranty_reason();
void identity_refund_reason();
void identity_warranty_date();
bool compare_warranty_date();

// products' menu prototype func
void phone_menu();
void computer_menu();
void order_menu();
void addon_order_menu();

// invoice & payment prototype func
void invoice();
void receipt();

// customer service prototype func
void customer_service();
void refund();
void warranty();
void receipt_warranty();
void receipt_refund();

// system report & admin prototype func
void report();
void admin_login();
void menu();

#endif