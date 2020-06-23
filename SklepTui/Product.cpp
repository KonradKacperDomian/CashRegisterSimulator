#include "Product.h"
#include <iostream>
#include <iomanip> 

void Product::display(bool displayLegend)
{
    if(displayLegend)
        std::cout << "ID   Price   PTU    Name" << std::endl;
    
        std::cout << std::setw(2) << this->productID << std::setw(8) << this->price << std::setw(5) << this->PTU << "    " << this->productName << std::endl;

}
