// Programming-Assignment-2-Week-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> // library for the transform function that we use to change from lowercase to uppercase
#include <fstream>

using namespace std;

int main()
{
    //Declare variables

    string item;
    double shippingCost;
    string destination;
    double orderTotal;
    string welcome;
    char fragility;
    double totalShippingCost;
    ofstream outData;

    // Create constant values to remove magic numbers 
    const double lowerLimit = 50.00;
    const double midLimit = 100.00;
    const double upperLimit = 150.00;

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

    if (fragility != 'y' && fragility != 'Y' && fragility != 'n' && fragility != 'N') {
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

    // Open Text File, Print Item Output and Change from LowerCase to uppercase

    outData.open("Order.txt");
    transform(item.begin(), item.end(), item.begin(), ::toupper);
    cout << left << "Your item is" << setfill('.') << setw(28) << right << "" << item << endl;
    outData << left << "Your item is" << setfill('.') << setw(28) << right << "" << item << endl; // send output to file

    // Begin Nested Decision Structures to determine shipping costs

    if (orderTotal < lowerLimit) { //if the order is under $50

        if (destination == "usa") {
            shippingCost = (6);
        }
        else if (destination == "can") {
            shippingCost = (8);
        }
        else if (destination == "aus") {
            shippingCost = (10);
        }
        else {
            cout << "Invalid Entry, exiting" << endl;
        }
        //if the order is greater than $50 and less than or equal to $100
    }
    else if (orderTotal > lowerLimit && orderTotal <= midLimit) {

        if (destination == "usa") {
            shippingCost = (9);
        }
        else if (destination == "can") {
            shippingCost = (12);
        }
        else if (destination == "aus") {
            shippingCost = (14);
        }
        else {
            cout << "Invalid Entry, exiting" << endl;
        }
        //if the order is between $100 and $150
    }
    else if (orderTotal > midLimit && orderTotal <= upperLimit) {

        if (destination == "usa") {
            shippingCost = (12);
        }
        else if (destination == "can") {
            shippingCost = (15);
        }
        else if (destination == "aus") {
            shippingCost = (17);
        }
        else {
            cout << "Invalid Entry, exiting" << endl;
        }
        //if the order is over $150
    }
    else {
        shippingCost = 0.00;
    }
    // Decision structure to apply upcharge if order is fragile
    if (fragility == 'y' || fragility == 'Y') {
        shippingCost += 2.00;
    }

    //Output result of Nested Decision Structure for shipping cost to console and Order.txt
    cout << fixed << setprecision(2);
    outData << fixed << setprecision(2);
    cout << left << "Your shipping cost is" << setfill('.') << setw(20) << right << "$" << shippingCost << endl;
    outData << left << "Your shipping cost is" << setfill('.') << setw(20) << right << "$" << shippingCost << endl;
    

    //Change destination to uppercase using transform function then output destination
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    cout << left << "You are shipping to" << setfill('.') << setw(21) << right << "" << destination << endl;
    outData << left << "You are shipping to" << setfill('.') << setw(21) << right << "" << destination << endl;


    // Calculate total shipping cost and Output total

    totalShippingCost = shippingCost + orderTotal;
    cout << left << "Your total shipping costs are" << setfill('.') << setw(12) << right << "$" << totalShippingCost << endl;
    outData << left << "Your total shipping costs are" << setfill('.') << setw(12) << right << "$" << totalShippingCost << endl;
    cout << endl;
    outData << endl;

    // Output Thank you line

    cout << left << setfill('-') << setw(40) << right << "" << "Thank you!" << endl;
    outData << left << setfill('-') << setw(40) << right << "" << "Thank you!" << endl;

    outData.close(); // close txt file

    return 0;
}