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


using namespace std;

const string OUTFILESTREAM = "Order.txt";


int main()
{

    ofstream fOutStream;
    fOutStream.open(OUTFILESTREAM);


    // EVERY TIME WE USE "setw(int)" THEN THE WHITESPACE WILL BE FILLED WITH '.'
    cout << setfill('.') << fixed << setprecision(2);
    fOutStream << setfill('.') << fixed << setprecision(2);

    //// INTRODUCTION ////
    cout << setw(51) << "\n"
         << "ITCS 2530 - Programming Assignment for week #3\n" 
         << setw(51) << "\n" << "\n" << endl;

    fOutStream << setw(51) << "\n"
               << "ITCS 2530 - Programming Assignment for week #3\n"
               << setw(51) << "\n" << "\n" << endl;

    // CONST STRING USED FOR INVALID INPUT (ERROR MESSAGE)
    const string INVALID_INPUT_SENTENCE = "Invalid entry, exiting";

    ////////////////////// INPUTS /////////////////////////////

    //// NAME OF ITEM ////
    const string ITEM_NAME_SENTENCE = "Please enter the item name (no spaces)";
    cout << right << setw(49) << left << ITEM_NAME_SENTENCE << ":";
    string item_name_input;
    cin >> item_name_input;
    fOutStream << right << setw(49) << left << ITEM_NAME_SENTENCE << ":" << item_name_input << endl;


    //// IF FRAGILE ////
    const string  IS_FRAGILE_SENTENCE= "Is the item fragile? (y=yes/n=no)";
    cout << right << setw(49) << left << IS_FRAGILE_SENTENCE << ":";
    char fragile_input;
    cin >> fragile_input;
    fOutStream << right << setw(49) << left << IS_FRAGILE_SENTENCE << ":" << fragile_input << endl;
    // CHECKS IF INPUT IS VALID
    if ((fragile_input != 'y' && fragile_input != 'Y') && (fragile_input != 'n' && fragile_input != 'N'))
    { 
        cout << "\n" << INVALID_INPUT_SENTENCE << endl;
        system("pause");
        return 1;
    }


    //// ORDER TOTAL (BEFORE SHIPPING) ////
    const string  ORDER_TOTAL_SENTENCE= "Please enter your order total";
    cout << right << setw(49) << left << ORDER_TOTAL_SENTENCE << ":";
    double subtotal_input;
    cin >> subtotal_input;
    fOutStream << right << setw(49) << left << ORDER_TOTAL_SENTENCE << ":" << subtotal_input << endl;


    //// DESTINATION ////
    const string DESTINATION_SENTENCE= "Please enter destination. (usa/can/aus)";
    cout << right << setw(49) << left << DESTINATION_SENTENCE << ":";
    string destination_input;
    cin >> destination_input;
    fOutStream << right << setw(49) << left << DESTINATION_SENTENCE << ":" << destination_input << endl;
    if ((destination_input != "usa") && (destination_input != "can") && (destination_input != "aus"))
    {
        cout << "\n" << INVALID_INPUT_SENTENCE << endl;
        system("pause");
        return 1;
    }

    cout << endl;
    fOutStream << endl;


    ////////////////////// OUTPUTS ////////////////////////////

    //// NAME OF ITEM ////
    const string ITEM_SENTENCE = "Your item is";
    // MAKES STRING "item_name_input" ALL UPPERCASE
    transform(item_name_input.begin(), item_name_input.end(), item_name_input.begin(), toupper);
    cout << right << setw(40) << left << ITEM_SENTENCE << item_name_input << endl;
    fOutStream << right << setw(40) << left << ITEM_SENTENCE << item_name_input << endl;


    //// SHIPPING COST ////
    double shipping_cost = 0.00;

    // USA SHIPPING COST
    if (destination_input == "usa")
    {
        if (subtotal_input >= 0 && subtotal_input < 50)
            shipping_cost += 6.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 9.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 12.00;
        else if (subtotal_input > 150)
            shipping_cost += 0.00;
    }

    // CANADA SHIPPING COST
    else if (destination_input == "can")
    {
        if (subtotal_input >= 0 && subtotal_input < 50)
            shipping_cost += 8.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 12.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 15.00;
        else
            shipping_cost += 0.00;
    }

    // AUSTRALIA SHIPPING COST
    else if (destination_input == "aus")
    {
        if (subtotal_input >= 0 && subtotal_input < 50)
            shipping_cost += 10.00;
        else if (subtotal_input >= 50 && subtotal_input <= 100)
            shipping_cost += 14.00;
        else if (subtotal_input >= 100.01 && subtotal_input <= 150)
            shipping_cost += 17.00;
        else
            shipping_cost += 0.00;
    }

    // FRAGILE FEE
    if (fragile_input == 'y' || fragile_input == 'Y')
        shipping_cost += 2.00;
    else
        shipping_cost += 0;

    const string SHIPPING_COST_SENTENCE = "Your shipping cost is";
    cout << right << setw(40) << left << SHIPPING_COST_SENTENCE << '$' << shipping_cost << endl;
    fOutStream << right << setw(40) << left << SHIPPING_COST_SENTENCE << '$' << shipping_cost << endl;


    //// SHIPPING TO ////
    const string SHIPPING_TO_SENTENCE = "You are shipping to";
    transform(destination_input.begin(), destination_input.end(), destination_input.begin(), toupper);
    cout << right << setw(40) << left << SHIPPING_TO_SENTENCE << destination_input <<endl;
    fOutStream << right << setw(40) << left << SHIPPING_TO_SENTENCE << destination_input << endl;


    //// SHIPPING TOTAL ////
    double total_cost = subtotal_input + shipping_cost;
    const string TOTAL_SHIPPING_COST_SENTENCE = "Your total shipping costs are.";
    cout << right << setw(40) << left << TOTAL_SHIPPING_COST_SENTENCE << '$' << total_cost << endl;
    fOutStream << right << setw(40) << left << TOTAL_SHIPPING_COST_SENTENCE << '$' << total_cost << endl;


    //// THANK YOU MESSAGE ////
    cout << "\n" << left << setfill('-') << setw(50) << endl << right << "Thank You!" << endl;
    fOutStream << "\n" << left << setfill('-') << setw(50) << endl << right << "Thank You!" << endl;

   
    fOutStream.close();


    // PAUSES COMMAND LINE RATHER THAN CLOSING
    system("pause");

    // RETURNS INT 0 TO THE FUNCTION MAIN
    return 0;
}


/*



*/