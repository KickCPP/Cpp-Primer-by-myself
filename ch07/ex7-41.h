#ifndef EX_7_41_H
#define EX_7_41_H
#include <string>
#include <iostream>

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream& read(std::istream& is, Sales_data&);
    friend std::ostream& print(std::ostream& os, const Sales_data&);
public:
    Sales_data(const std::string s, unsigned n, double p):
        bookNO(s), units_sold(n), revenue(n*p) {std::cout << "Initialized in Sales_data(const std::string s, unsigned n, double p)\n";}
    Sales_data(): Sales_data("",0,0) {std::cout << "Initialized in Sales_data()\n";}
    Sales_data(const std::string s): Sales_data(s,0,0) {std::cout << "Initialized in Sales_data(const std::string s)\n";}
    Sales_data(std::istream &is);

    std::string isbn() const { return bookNO; }
    Sales_data& combine(const Sales_data& rsd);

private:
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

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
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

Sales_data::Sales_data(std::istream& is): Sales_data() {
    read(is, *this);
    std::cout << "Initialized in Sales_data(std::istream& is)\n";
}

#endif // EX_7_41_H

