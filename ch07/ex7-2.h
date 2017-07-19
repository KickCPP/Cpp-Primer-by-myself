#ifndef EX7_2_H
#define EX7_2_H

#include <string>

struct Sales_data {
    std::string isbn() const { return bookNO; }
    Sales_data& combine(const Sales_data& rsd);
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rsd) {
    units_sold += rsd.units_sold;
    revenue += rsd.revenue;
    return *this;
}
#endif // EX7_2_H
