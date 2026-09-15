# CSG Gadget Shop System

A simple console-based C++ application for managing gadget shop operations, product stock, customer service, and admin reports.

## Features

* **Product Menu & Ordering:** Customers can view phone and computer accessories, check stock, and place orders with automated inventory updates.
* **Add-on Items:** Allows users to add more items to their cart before checkout.
* **Calculations:** Automatically calculates discounts, service charges (6%), and taxes (6%).
* **Customer Service:** Handles product returns (refunds) and warranty claims with date validations.
* **Admin Login & Reports:** Secure admin login to view daily sales reports and export them into `.txt` files.

## Project Structure

* `main.cpp` - Main menu and program execution.
* `order.cpp` - Product menus, shopping cart, and invoice generation.
* `service.cpp` - Customer service, refunds, and warranty checks.
* `report.cpp` - Admin sales reporting and file export.
* `admin.cpp` - Admin authentication and credential management.
* `utility.cpp` - Helper functions and global variables.
* `source.h` - Header file containing libraries, structs, and function prototypes.

## How to Run

1. Clone or download this repository.
2. Open the project in your C++ IDE (such as Visual Studio or Code::Blocks).
3. Compile and run `main.cpp`.
