// Programming-Assignment-2-Week-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // library for the transform function that we use to change from lowercase to uppercase

using namespace std;

int main()
{
    //Declare variables

    string item;
    double shippingCost;
    string destination;
    double orderTotal;
    string welcome;
    string fragility;
    double totalShippingCost;

    // format welcome message 

    welcome = "ITCS 2530 - Programming Assignment for week #3";

    cout << left << setfill('.') << setw(welcome.length()) << "" << endl; //Use welcome.length() to fill asterisks to the same length as welcome
    cout << welcome << endl;
    cout << left << setfill('.') << setw(welcome.length()) << "" << endl;
    cout << endl;
    cout << endl;

    // Take inputs and format
    
    //Item input 

    cout << left << "Please enter the item name (no spaces)" << setfill('.') << setw(12) << right << ":"; 
    cin >> item;
   
    //Fragility input

    cout << left << "Is the item fragile? (y=yes/n=no)" << setfill('.') << setw(17) << right << ":";
    cin >> fragility; // Make decision structure here to exit program if they input something other than yes/no for fragility? 

    if (fragility != "y" && fragility != "Y" && fragility != "n" && fragility != "N") {
        cout << endl;
        cout << "Invalid entry, exiting";
        exit(0);
    }

    //Order total input 
    cout << fixed << setprecision(2);
    cout << left << "Please enter your order total" << setfill('.') << setw(21) << right << ":";
    cin >> orderTotal;

    //Destination input 
    cout << left << "Please enter destination. (usa/can/aus)" << setfill('.') << setw(11) << right << ":";
    cin >> destination; // Make decision structure here to exit program if they input something other than yes/no for destination
    if (destination != "usa" && destination != "can" && destination != "aus") {
        cout << endl;
        cout << "Invalid entry, exiting";
        exit(0);
    }

    cout << endl;

    // Print Item Output and Change from LowerCase to uppercase
    transform(item.begin(), item.end(), item.begin(), ::toupper);
    cout << left << "Your item is" << setfill('.') << setw(28) << right << "" << item << endl;

    // Begin Nested Decision Structures to determine shipping costs

    if (fragility == "y" || fragility == "Y") { //this will add $2 to each of the shipping costs for each country at each order price

        if (orderTotal < 50.00) { 

            if (destination == "usa") {
                shippingCost = (8);
            } else if (destination == "can") {
                shippingCost = (10);
            } else if (destination == "aus") {
                shippingCost = (12);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else if (orderTotal > 50 && orderTotal <= 100) {

            if (destination == "usa") {
                shippingCost = (11);
            } else if (destination == "can") {
                shippingCost = (14);
            } else if (destination == "aus") {
                shippingCost = (16);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else if (orderTotal > 100 && orderTotal <= 150) {

            if (destination == "usa") {
                shippingCost = (14);
            } else if (destination == "can") {
                shippingCost = (17);
            } else if (destination == "aus") {
                shippingCost = (19);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else {
            shippingCost = 0.00;
        }

    } else if (fragility == "n" || fragility == "N") { // this removes the $2.00 added shipping cost

        if (orderTotal < 50.00) {

            if (destination == "usa") {
                shippingCost = (6);
            } else if (destination == "can") {
                shippingCost = (8);
            } else if (destination == "aus") {
                shippingCost = (10);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else if (orderTotal > 50 && orderTotal <= 100) {

            if (destination == "usa") {
                shippingCost = (9);
            } else if (destination == "can") {
                shippingCost = (12);
            } else if (destination == "aus") {
                shippingCost = (14);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else if (orderTotal > 100 && orderTotal <= 150) {

            if (destination == "usa") {
                shippingCost = (12);
            } else if (destination == "can") {
                shippingCost = (15);
            } else if (destination == "aus") {
                shippingCost = (17);
            } else {
                cout << "Invalid Entry, exiting" << endl;
            }

        } else {
            shippingCost = 0.00;
        }

    } else {

        cout << "Invalid Entry, exiting" << endl;
    }
    
    
    //Output result of Nested Decision Structure for shipping cost
    cout << fixed << setprecision(2);
    cout << left << "Your shipping cost is" << setfill('.') << setw(20) << right << "$" << shippingCost << endl;

    //Change destination to uppercase using transform function then output destination
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    cout << left << "You are shipping to" << setfill('.') << setw(21) << right << "" << destination << endl;

    // Calculate total shipping cost and Output total

    totalShippingCost = shippingCost + orderTotal;
    cout << left << "Your total shipping costs are" << setfill('.') << setw(12) << right << "$" << totalShippingCost << endl;
    cout << endl;

    // Output Thank you line

    cout << left << setfill('-') << setw(40) << right << "" << "Thank you!" << endl;

    return 0;
}

