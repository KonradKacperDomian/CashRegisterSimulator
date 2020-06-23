#include "Product.h"
#include <iomanip> 
#include <string>



std::string Product::display()
{
    std::string displayText = std::to_string( this->productID );
    displayText += "      ";
    std::string toPaytext = std::to_string(this->price);
    int lenghtOfString = 0;
    while (toPaytext[lenghtOfString] != '.')
        lenghtOfString++;
    displayText += toPaytext.substr(0, lenghtOfString + 3);

    displayText += "       ";
    displayText += this->PTU;
    displayText += "       ";
    displayText += this->productName;
    displayText += "\n";
    return displayText;
}
