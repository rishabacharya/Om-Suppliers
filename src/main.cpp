#include "Header.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String^>^ args)
{
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    OMSuppliers::MainApplication^ form = gcnew OMSuppliers::MainApplication();
    //To add data to the form follow procedure as shown in comment below
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    form->addData(OMSuppliers::StockItem("Nails 5mm", "44B7G", 14, 2, 120.5, 14 - 2));
    //OR
    //StockItem stockItem("Particulars name","CODE",purchaseQTY,salesQTY,Rate,Balance);
    // form->addData(stockItem);
    //

    form->Show();
    Application::Run();
    return 0;
}
