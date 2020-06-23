#include "Product.h"
#include <iostream>
#include <iomanip> 
#include <string>

void Product::display(bool displayLegend)
{
    if(displayLegend)
        std::cout << "ID   Price   PTU    Name" << std::endl;
    
        std::cout << std::setw(2) << this->productID << std::setw(8) << this->price << std::setw(5) << this->PTU << "    " << this->productName << std::endl;

}

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
