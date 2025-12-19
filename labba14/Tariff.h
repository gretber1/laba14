#pragma once
using namespace System;

public ref class Tariff
{
public:
    String^ Name;
    double Price;
    double Discount;

    Tariff(String^ n, double p, double d);

    double FinalPrice();
};
