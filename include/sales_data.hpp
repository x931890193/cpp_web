//
// Created by sato on 2021/8/25.
//

#ifndef CPP_WEB_SALES_DATA_HPP
#define CPP_WEB_SALES_DATA_HPP

#include <iostream>

typedef double my_double;

struct Sales_data {
    std::string BookNo;
    unsigned unit_sold = 0;
    my_double venue = 0.0;
public:
    Sales_data (){
       this->BookNo = "001";
       this->unit_sold = 0;
       this->venue = 0.0;
    }
};

#endif //CPP_WEB_SALES_DATA_HPP
