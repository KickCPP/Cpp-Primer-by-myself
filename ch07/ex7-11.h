#ifndef EX_7_11_H
#define EX_7_11_H
#include <string>
#include <iostream>

struct Sales_data {
    Sales_data() = default;
    Sales_data(std::istream &is);
    Sales_data(const std::string s, unsigned n, double p):
        bookNO(s), units_sold(n), revenue(n*p) {}
    Sales_data(const std::string s): bookNO(s) {}

    std::string isbn() const { return bookNO; }
    Sales_data& combine(const Sales_data& rsd);
    double avg_price() const;

    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rsd) {
    units_sold += rsd.units_sold;
    revenue += rsd.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data &item) {
    double price = 0;
    is >> item.bookNO >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}

#endif // EX_7_11_H
