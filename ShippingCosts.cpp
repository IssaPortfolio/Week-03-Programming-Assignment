/*//////////////////////////////////////////////////////////////////////////////////////////////////////////
/                                                                                                          /
/       Write a Item Shipping Calculator program that does the following :                                 /
/                                                                                                          /
/       Prompt and retrieve the following input from the user(through the console) :                       /
/           Item name                                                                                      / 
/           Is the item fragile(add in $2.00 if the item is fragile)                                       / 
/           The order total(without shipping)                                                              /
/           The destination to which the item will be shipped(USA, Canada, Australia)                      /
/                                                                                                          /
/       Use the following table to determine the calculations to perform:                                  /
/                                                                                                          /
/            ----------------------------------------------------------------------------                  /
/            |    Order Total:    | Ship to USA: | Ship to Canada: | Ship to Australia: |                  /
/            |--------------------|--------------|-----------------|--------------------|                  /
/            | Less Than $50.00   | $6.00        | $8.00           | $10.00             |                  /
/            |--------------------|--------------|-----------------|--------------------|                  /
/            | $50.01 to $100.00  | $9.00        | $12.00          | $14.00             |                  /
/            |--------------------|--------------|-----------------|--------------------|                  /
/            | $100.01 to $150.00 | $12.00       | $15.00          | $17.00             |                  /
/            |--------------------|--------------|-----------------|--------------------|                  /
/            | Over $150.00       | Free         | Free            | Free               |                  /
/            ----------------------------------------------------------------------------                  /
/                                                                                                          /
/           If the item is fragile add $2.00 to the shipping cost.                                         /
/                                                                                                          /
////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB */


#include <iostream>     // GIVES "cin" AND "cout"
#include <iomanip>      // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
#include <string>       // GIVES DATA TYPE "string"
#include <algorithm>    // USED TO MANIPULATE STRINGS (UPPERCASE, LOWERCASE, ETC...)
#include <fstream>      // OUTPUT TO A FILE
using namespace std;    // SO NO NEED TO DO "std::cout" OR "std::cin"


int main()
{
    // FILE FOR OUTPUT (CREATES IT IF DOES NOT EXIST)
    const string OUTFILESTREAM = "Order.txt";
    ofstream fOutStream;
    fOutStream.open(OUTFILESTREAM);  // OPENS FILE TO OUTPUT TO


    // EVERY TIME WE USE "setw(int)" THEN THE WHITESPACE WILL BE FILLED WITH '.'
    // FIXED IS REAL NUMBER (NOT SCIENTIFIC NOTATION) AND SETPRECISION IS AMOUNT OF DECIMAL PLACES 
    cout << setfill('.') << fixed << setprecision(2);
    fOutStream << setfill('.') << fixed << setprecision(2);

    //// INTRODUCTION ////
    cout        << setw(51) << "\n"
                << "ITCS 2530 - Programming Assignment for week #3\n" 
                << setw(51) << "\n" << "\n" << endl;

    fOutStream  << setw(51) << "\n"
                << "ITCS 2530 - Programming Assignment for week #3\n"
                << setw(51) << "\n" << "\n" << endl;

    // CONST STRING USED FOR INVALID INPUT (ERROR MESSAGE)
    const string INVALID_INPUT_SENTENCE = "Invalid entry, exiting";

    ////////////////////// INPUTS /////////////////////////////

    //********* NAME OF ITEM *********//
    const string ITEM_NAME_SENTENCE = "Please enter the item name (no spaces)";
    cout << right << setw(49) << left << ITEM_NAME_SENTENCE << ":";
    string item_name_input;
    cin >> item_name_input;  // INPUT
    fOutStream << right << setw(49) << left << ITEM_NAME_SENTENCE << ":" << item_name_input << endl;
    transform(item_name_input.begin(), item_name_input.end(), item_name_input.begin(), toupper);  // MAKES STRING VARIABLE UPPERCASE


    //********* IF FRAGILE *********//
    const string  IS_FRAGILE_SENTENCE= "Is the item fragile? (y=yes/n=no)";
    cout << right << setw(49) << left << IS_FRAGILE_SENTENCE << ":";
    string fragile_input;
    cin >> fragile_input;  // INPUT
    fOutStream << right << setw(49) << left << IS_FRAGILE_SENTENCE << ":" << fragile_input << endl;
    // CHECKS IF INPUT IS VALID
    if ((fragile_input != "y" && fragile_input != "Y") && (fragile_input != "n" && fragile_input != "N"))
    { 
        cout << "\n" << INVALID_INPUT_SENTENCE << endl;
        system("pause");
        return 1;
    }


    //********* ORDER TOTAL (BEFORE SHIPPING) *********//
    const string  ORDER_TOTAL_SENTENCE= "Please enter your order total";
    cout << right << setw(49) << left << ORDER_TOTAL_SENTENCE << ":";
    double subtotal_input;
    cin >> subtotal_input;  // INPUT
    fOutStream << right << setw(49) << left << ORDER_TOTAL_SENTENCE << ":" << subtotal_input << endl;


    //********* DESTINATION *********//
    const string DESTINATION_SENTENCE= "Please enter destination. (usa/can/aus)";
    cout << right << setw(49) << left << DESTINATION_SENTENCE << ":";
    string destination_input;
    cin >> destination_input;  // INPUT
    fOutStream << right << setw(49) << left << DESTINATION_SENTENCE << ":" << destination_input << endl;
    transform(destination_input.begin(), destination_input.end(), destination_input.begin(), toupper);  // MAKES STRING VARIABLE UPPERCASE
    if ((destination_input != "USA") && (destination_input != "CAN") && (destination_input != "AUS"))
    {
        cout << "\n" << INVALID_INPUT_SENTENCE << endl;
        system("pause");
        return 1;
    }

    cout << endl;
    fOutStream << endl;


    ////////////////////// OUTPUTS ////////////////////////////

    //********* NAME OF ITEM *********//
    const string ITEM_SENTENCE = "Your item is";
    // MAKES STRING "item_name_input" ALL UPPERCASE
    cout << right << setw(40) << left << ITEM_SENTENCE << item_name_input << endl;
    fOutStream << right << setw(40) << left << ITEM_SENTENCE << item_name_input << endl;



    double shipping_cost = 0.00;  // DOUBLE VARIABLE (BEFORE SHIPPING COSTS ARE CALCULATED)

    // USA SHIPPING COST
    if (destination_input == "USA")
    {
        if (subtotal_input < 50)
            shipping_cost += 6.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 9.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 12.00;
        else if (subtotal_input > 150)
            shipping_cost += 0.00;
    }

    // CANADA SHIPPING COST
    else if (destination_input == "CAN")
    {
        if (subtotal_input < 50)
            shipping_cost += 8.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 12.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 15.00;
        if (subtotal_input > 150)
            shipping_cost += 0.00;
    }

    // AUSTRALIA SHIPPING COST
    else if (destination_input == "AUS")
    {
        if (subtotal_input < 50)
            shipping_cost += 10.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 14.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 17.00;
        if (subtotal_input > 150)
            shipping_cost += 0.00;
    }

    // FRAGILE FEE
    if (fragile_input == "y" || fragile_input == "Y")
        shipping_cost += 2.00;
    else
        shipping_cost += 0;

    //********* SHIPPING COST *********//
    const string SHIPPING_COST_SENTENCE = "Your shipping cost is";
    cout << right << setw(40) << left << SHIPPING_COST_SENTENCE << '$' << shipping_cost << endl;
    fOutStream << right << setw(40) << left << SHIPPING_COST_SENTENCE << '$' << shipping_cost << endl;


    //********* SHIPPING TO *********//
    const string SHIPPING_TO_SENTENCE = "You are shipping to";
    cout << right << setw(40) << left << SHIPPING_TO_SENTENCE << destination_input <<endl;
    fOutStream << right << setw(40) << left << SHIPPING_TO_SENTENCE << destination_input << endl;


    //********* SHIPPING TOTAL *********//
    double total_cost = subtotal_input + shipping_cost;
    const string TOTAL_SHIPPING_COST_SENTENCE = "Your total shipping costs are.";
    cout << right << setw(40) << left << TOTAL_SHIPPING_COST_SENTENCE << '$' << total_cost << endl;
    fOutStream << right << setw(40) << left << TOTAL_SHIPPING_COST_SENTENCE << '$' << total_cost << endl;


    //********* THANK YOU MESSAGE *********//
    cout << left << setfill('-') << setw(50) << endl << right << "Thank You!" << "\n" << endl;
    fOutStream << endl << endl << endl;  // DOES NOT HAVE THANK YOU MESSAGE 
   
    // CLOSES THE OUTPUT FILE
    fOutStream.close();

    // PAUSES COMMAND LINE RATHER THAN CLOSING
    system("pause");

    // RETURNS INT 0 TO THE FUNCTION MAIN
    return 0;
}


/*

    I did not have much trouble in this code. However, I did not know how to output to a file and 
    watched "I/O Demo 2" on Canvas.


    I believe the way I am outputting is not ideal, such as "cout << right << setw(40) << left <<" as it is repetitive 
    but I am not sure how else I could do it. I have tried putting "setw(int)" and such where I have my defaults for
    my output streams (line 48 and 49) but I could not get it to work properly. 


    This is where the shipping cost is calculated, the example below is for USA.

    if (destination_input == "USA")                                    We get what "destination_input" is because the user inputs it at line 101.
    {
        if (subtotal_input < 50)                                       A range (if subtotal_input is less than 50)
            shipping_cost += 6.00;                                     Adds 6 to double variable "subtotal_input" if conditional is true.
        else if (subtotal_input >= 50 && subtotal_input <= 100)        "else if" means if first conditional (line 219) was not true then it would get here
                                                                       but if it was true then it would ignore "else if" statements 
                                                                       (this leads to saving computer resources, or processing power).
            shipping_cost += 9.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 12.00;
        else if (subtotal_input > 150)
            shipping_cost += 0.00;
    }

*/