//
// Created by sato on 2021/8/25.
//

#include "sales_data.hpp"

void compare() {
    Sales_data salesData1, salesData2;
    unsigned unit_sold;
    my_double venue;
    if (salesData1.BookNo == salesData2.BookNo) {
        unit_sold = salesData1.unit_sold + salesData2.unit_sold;
        venue = salesData1.venue + salesData2.venue;
    }
    std::cout << unit_sold << "\t" << venue << std::endl;
}