#include "TariffsFunctions.h"
#include <fstream>

using namespace System::IO;

TariffsFunctions::TariffsFunctions()
{
    tariffs = gcnew List<Tariff^>();
}

List<Tariff^>^ TariffsFunctions::GetTariffs()
{
    return tariffs;
}

void TariffsFunctions::Add(String^ name, double price, double discount)
{
    tariffs->Add(gcnew Tariff(name, price, discount));
}

void TariffsFunctions::Edit(int index, double price, double discount)
{
    tariffs[index]->Price = price;
    tariffs[index]->Discount = discount;
}

void TariffsFunctions::Delete(int index)
{
    tariffs->RemoveAt(index);
}

Tariff^ TariffsFunctions::FindMin()
{
    if (tariffs->Count == 0) return nullptr;

    Tariff^ min = tariffs[0];
    for each (Tariff ^ t in tariffs)
        if (t->FinalPrice() < min->FinalPrice())
            min = t;
    return min;
}

void TariffsFunctions::SaveToFile(String^ file)
{
    StreamWriter^ sw = gcnew StreamWriter(file);
    for each (Tariff ^ t in tariffs)
        sw->WriteLine(t->Name + ";" + t->Price + ";" + t->Discount);
    sw->Close();
}

void TariffsFunctions::LoadFromFile(String^ file)
{
    tariffs->Clear();
    if (!File::Exists(file)) return;

    for each (String ^ line in File::ReadAllLines(file))
    {   
        array<String^>^ p = line->Split(';');

        if (p->Length < 3)
            continue; // пропускаем битую строку

        double price, coef;
        if (!Double::TryParse(p[1], price)) continue;
        if (!Double::TryParse(p[2], coef)) continue;

        tariffs->Add(gcnew Tariff(p[0], price, coef));
    }
}
