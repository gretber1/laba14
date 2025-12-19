#include "Tariff.h"

Tariff::Tariff(String^ name, double price, double discount)
{
    Name = name;
    Price = price;
    Discount = discount;
}

double Tariff::FinalPrice()
{
    return Price * (1.0 - Discount / 100.0);
}
