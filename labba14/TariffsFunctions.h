#pragma once
#include "Tariff.h"

using namespace System::Collections::Generic;

public ref class TariffsFunctions
{
private:
    List<Tariff^>^ tariffs;

public:
    TariffsFunctions();

    List<Tariff^>^ GetTariffs();

    void Add(String^ name, double price, double discount);
    void Edit(int index, double price, double discount);
    void Delete(int index);

    Tariff^ FindMin();

    void SaveToFile(String^ file);
    void LoadFromFile(String^ file);
};
