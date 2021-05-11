#pragma once

namespace OMSuppliers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//
	//Data to be filled to the stock
	//
	class StockItem {
	public: char* item, * code;
	public:int purchase, sales, balance;
	public:float rate;

	public:
		StockItem(char* item, char* code, int purchase, int sales, float rate, int balance) {
			this->copy(&this->item, item);
			this->copy(&this->code, code);
			this->purchase = purchase;
			this->rate = rate;
			this->balance = balance;
			this->sales = sales;
		}

		//
	//copy data of one char* to another char*
	//
	public:void copy(char** a, char* b) {
		int x = 0;
		while (b[x] != '\0') {
			x++;
		}
		*a = new char[x];
		for (int i = 0; i <= x; i++) {
			(*a)[i] = b[i];
		}
	}

	public:char* getItem() {
		return this->item;
	}
	public:char* getCode() {
		return this->code;
	}

	public:int getPurchase() {
		return this->purchase;
	}

	public:int getSales() {
		return this->sales;
	}
	public: int getBalance() {
		return this->balance;
	}
	public: float getRate() {
		return this->rate;
	}
		  friend ref class MainApplication;
	};

	/// <summary>
	/// Summary for MainApplication
	/// </summary>
	public ref class MainApplication : public System::Windows::Forms::Form
	{
	public:
		MainApplication(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainApplication()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int x = 100;
	private: System::Windows::Forms::Label^ ClientCompany;
	private: System::Windows::Forms::Label^ Category;
	private: System::Windows::Forms::Panel^ topPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ menuPanel;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ Balance;

	private: System::Windows::Forms::Label^ Sales;
	private: System::Windows::Forms::Label^ rate;
	private: System::Windows::Forms::Label^ Purchase;
	private: System::Windows::Forms::Label^ greet;
	private: System::Windows::Forms::Label^ Code;
	private: System::Windows::Forms::Label^ ItemName;
	private: System::Windows::Forms::Label^ Serial;
	private: static System::Windows::Forms::FlowLayoutPanel^ dataPanel;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Panel^ rightPanel;
	private: System::Windows::Forms::Panel^ bottomLinePanel_DataPanel;
	private: array<System::Windows::Forms::Button^>^ menuButtons = gcnew array<System::Windows::Forms::Button^>(6);
	private: static int tabIndex;
	private: static int stockDataRowCount = 0;
		   //
		   //    Class whose instance will represent a row in dataPanel
		   //
	protected:
		ref class StockDataRow {
		public: int i;
		private: StockItem* stockItem;
		private: StockDataRow^ nextStockDataRow;
		public: System::Windows::Forms::TextBox^ serialNumber;
		public: System::Windows::Forms::TextBox^ particularsData;
		public: System::Windows::Forms::TextBox^ codeData;
		public: System::Windows::Forms::TextBox^ purchaseQTYData;
		public: System::Windows::Forms::TextBox^ SalesQTYData;
		public: System::Windows::Forms::TextBox^ rateData;
		public: System::Windows::Forms::TextBox^ textBox7;
		public: System::Windows::Forms::TextBox^ balanceData;
		public: StockDataRow(StockItem& stockItem) {
			i = stockDataRowCount;
			this->stockItem = new StockItem(stockItem);
			componentsInitializer();
			attributesProvider();
			dataAdder();
			controlsProvider();
			nextStockDataRow = nullptr;
		}

		private: void componentsInitializer() {
			this->serialNumber = (gcnew System::Windows::Forms::TextBox());
			this->balanceData = (gcnew System::Windows::Forms::TextBox());
			this->rateData = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->SalesQTYData = (gcnew System::Windows::Forms::TextBox());
			this->purchaseQTYData = (gcnew System::Windows::Forms::TextBox());
			this->codeData = (gcnew System::Windows::Forms::TextBox());
			this->particularsData = (gcnew System::Windows::Forms::TextBox());
		}

		private: void attributesProvider() {

			this->serialNumber->BackColor = System::Drawing::Color::White;
			this->serialNumber->Font = (gcnew System::Drawing::Font(L"Verdana", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serialNumber->Location = System::Drawing::Point(0, 3);
			this->serialNumber->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->serialNumber->Name = L"serialNumber" + i.ToString();
			this->serialNumber->Text = (i + 1).ToString();
			this->serialNumber->Size = System::Drawing::Size(45, 34);
			this->serialNumber->Enabled = false;
			//
			// particularsData
			//
			this->particularsData->BackColor = System::Drawing::Color::White;
			this->particularsData->Font = (gcnew System::Drawing::Font(L"Verdana", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->particularsData->Location = System::Drawing::Point(0, 3);
			this->particularsData->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->particularsData->Name = L"particularsData" + i.ToString();
			this->particularsData->Size = System::Drawing::Size(360, 34);
			this->particularsData->TabIndex = tabIndex++;
			//
			// balanceData
			//
			this->balanceData->BackColor = System::Drawing::Color::White;
			this->balanceData->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Bold));
			this->balanceData->Location = System::Drawing::Point(894, 3);
			this->balanceData->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->balanceData->Name = L"balanceData" + i.ToString();
			this->balanceData->Size = System::Drawing::Size(120, 33);
			this->balanceData->TabIndex = tabIndex++;
			//
			// rateData
			//
			this->rateData->BackColor = System::Drawing::Color::White;
			this->rateData->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Bold));
			this->rateData->Location = System::Drawing::Point(767, 3);
			this->rateData->Margin = System::Windows::Forms::Padding(0, 3, 2, 3);
			this->rateData->Name = L"rateData" + i.ToString();
			this->rateData->Size = System::Drawing::Size(123, 33);
			this->rateData->TabIndex = tabIndex++;
			//
			// textBox7
			//
			this->textBox7->BackColor = System::Drawing::Color::White;
			this->textBox7->Enabled = false;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11));
			this->textBox7->Location = System::Drawing::Point(744, 3);
			this->textBox7->Margin = System::Windows::Forms::Padding(2, 3, 0, 3);
			this->textBox7->Name = L"textBox7" + i.ToString();
			this->textBox7->Size = System::Drawing::Size(23, 33);
			this->textBox7->TabIndex = tabIndex++;
			this->textBox7->Text = L"Rs";
			//
			// SalesQTYData
			//
			this->SalesQTYData->BackColor = System::Drawing::Color::White;
			this->SalesQTYData->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11));
			this->SalesQTYData->Location = System::Drawing::Point(616, 3);
			this->SalesQTYData->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->SalesQTYData->Name = L"SalesQTYData" + i.ToString();
			this->SalesQTYData->Size = System::Drawing::Size(124, 33);
			this->SalesQTYData->TabIndex = tabIndex++;
			//
			// purchaseQTYData
			//
			this->purchaseQTYData->BackColor = System::Drawing::Color::White;
			this->purchaseQTYData->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11));
			this->purchaseQTYData->Location = System::Drawing::Point(478, 3);
			this->purchaseQTYData->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->purchaseQTYData->Name = L"purchaseQTYData" + i.ToString();
			this->purchaseQTYData->Size = System::Drawing::Size(134, 33);
			this->purchaseQTYData->TabIndex = tabIndex++;
			//
			// codeData
			//
			this->codeData->BackColor = System::Drawing::Color::White;
			this->codeData->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->codeData->Location = System::Drawing::Point(415, 3);
			this->codeData->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->codeData->Name = L"codeData" + i.ToString();
			this->codeData->Size = System::Drawing::Size(59, 33);
			this->codeData->TabIndex = tabIndex++;
		}
		private: void controlsProvider() {
			dataPanel->Controls->Add(this->serialNumber);
			dataPanel->Controls->Add(this->particularsData);
			dataPanel->Controls->Add(this->codeData);
			dataPanel->Controls->Add(this->purchaseQTYData);
			dataPanel->Controls->Add(this->SalesQTYData);
			dataPanel->Controls->Add(this->textBox7);
			dataPanel->Controls->Add(this->rateData);
			dataPanel->Controls->Add(this->balanceData);
		}
		public: void snatchControls() {
			dataPanel->Controls->Remove(this->serialNumber);
			dataPanel->Controls->Remove(this->particularsData);
			dataPanel->Controls->Remove(this->codeData);
			dataPanel->Controls->Remove(this->purchaseQTYData);
			dataPanel->Controls->Remove(this->SalesQTYData);
			dataPanel->Controls->Remove(this->textBox7);
			dataPanel->Controls->Remove(this->rateData);
			dataPanel->Controls->Remove(this->balanceData);
		}

		private: void dataAdder() {
			delete this->particularsData->Text;
			delete this->codeData->Text;
			delete this->purchaseQTYData->Text;
			delete this->SalesQTYData->Text;
			delete this->rateData->Text;
			delete this->balanceData->Text;
			this->particularsData->Text = gcnew String(this->stockItem->getItem());
			this->codeData->Text = gcnew String(this->stockItem->getCode());
			this->purchaseQTYData->Text = this->stockItem->getPurchase().ToString();
			this->SalesQTYData->Text = this->stockItem->getSales().ToString();
			this->rateData->Text = this->stockItem->getRate().ToString();
			this->balanceData->Text = this->stockItem->getBalance().ToString();;
		}

		public: StockDataRow^ getNextStockDataRow() {
			return this->nextStockDataRow;
		}

		public: void setNextStockDataRow(StockDataRow^ stockDataRow) {
			this->nextStockDataRow = stockDataRow;
		}

		protected: ~StockDataRow() {
			delete this->serialNumber;
			delete this->balanceData;
			delete this->particularsData;
			delete this->codeData;
			delete this->rateData;
			delete this->purchaseQTYData;
			delete this->SalesQTYData;
			delete this->textBox7;
			delete stockItem;
		}
		};
		/// <summary>
		/// Stock Data Row Manager Class
		/// </summary>
	protected: ref class StockDataManager {
	private:StockDataRow^ headStockRow, ^ tempStockRow;
	protected:StockDataRow^ presentStockRow;
	public:StockDataManager() {
		presentStockRow = nullptr;
		tempStockRow = nullptr;
		headStockRow = nullptr;
	}

	public: StockDataRow^ get(int i) {
		tempStockRow = headStockRow;
		do {
			if (this->tempStockRow->i == i) {
				return this->tempStockRow;
			}
			this->tempStockRow = this->tempStockRow->getNextStockDataRow();
		} while (tempStockRow != nullptr);
		return nullptr;
	}

	public: void removeStockRow(int i) {
		if (headStockRow != nullptr) {
			if (headStockRow->i == i) {
				this->tempStockRow = this->headStockRow;
				this->headStockRow = this->headStockRow->getNextStockDataRow();
				this->tempStockRow->snatchControls();
				delete this->tempStockRow;
			}
		}
	}

	public:void addStockDataRow(StockItem& stockItem) {
		if (headStockRow == nullptr) {
			headStockRow = gcnew StockDataRow(stockItem);
			presentStockRow = headStockRow;
		}
		else {
			presentStockRow->setNextStockDataRow(gcnew StockDataRow(stockItem));
			presentStockRow = presentStockRow->getNextStockDataRow();
		}
		stockDataRowCount++;
	}
	public: StockDataRow^ getPresentStockRow() {
		return this->presentStockRow;
	}
	protected: ~StockDataManager() {
		if (!(headStockRow == nullptr)) {
			tempStockRow = headStockRow;
			do {
				presentStockRow = tempStockRow;
				tempStockRow = presentStockRow->getNextStockDataRow();
				delete presentStockRow;
			} while (tempStockRow != nullptr);
		}
	}
	};

	private: StockDataManager^ stockDataManager;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabIndex = 0;
			this->ClientCompany = (gcnew System::Windows::Forms::Label());
			this->Category = (gcnew System::Windows::Forms::Label());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->menuPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Balance = (gcnew System::Windows::Forms::Label());
			this->Sales = (gcnew System::Windows::Forms::Label());
			this->rate = (gcnew System::Windows::Forms::Label());
			this->Purchase = (gcnew System::Windows::Forms::Label());
			this->Code = (gcnew System::Windows::Forms::Label());
			this->ItemName = (gcnew System::Windows::Forms::Label());
			this->greet = gcnew System::Windows::Forms::Label();
			this->Serial = (gcnew System::Windows::Forms::Label());
			this->stockDataManager = gcnew StockDataManager();
			for (int i = 0; i < 6; i++) {
				this->menuButtons[i] = (gcnew System::Windows::Forms::Button());
			}
			this->dataPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->bottomLinePanel_DataPanel = (gcnew System::Windows::Forms::Panel());
			this->rightPanel = (gcnew System::Windows::Forms::Panel());
			this->topPanel->SuspendLayout();
			this->dataPanel->SuspendLayout();
			this->SuspendLayout();


			// 
			// ClientCompany
			// 
			this->ClientCompany->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19, System::Drawing::FontStyle::Bold));
			this->ClientCompany->ForeColor = System::Drawing::Color::Black;
			this->ClientCompany->Location = System::Drawing::Point(2, 1);
			this->ClientCompany->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ClientCompany->Name = L"ClientCompany";
			this->ClientCompany->Padding = System::Windows::Forms::Padding(6, 8, 0, 0);
			this->ClientCompany->Size = System::Drawing::Size(195, 49);
			this->ClientCompany->TabIndex = tabIndex++;
			this->ClientCompany->Text = L"OM Suppliers";
			this->ClientCompany->Click += gcnew System::EventHandler(this, &MainApplication::ClientCompany_Click);
			// 
			// Category
			// 
			this->Category->BackColor = System::Drawing::Color::GhostWhite;
			this->Category->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Category->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21, System::Drawing::FontStyle::Bold));
			this->Category->ForeColor = System::Drawing::Color::Firebrick;
			this->Category->Location = System::Drawing::Point(196, 0);
			this->Category->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Category->Name = L"Category";
			this->Category->Padding = System::Windows::Forms::Padding(490, 3, 0, 0);
			this->Category->Size = System::Drawing::Size(1084, 51);
			this->Category->TabIndex = tabIndex++;
			this->Category->Text = L"STOCK";
			this->Category->Click += gcnew System::EventHandler(this, &MainApplication::Category_Click);
			// 
			// topPanel
			// 
			this->topPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->topPanel->Controls->Add(this->Exit);
			this->topPanel->Controls->Add(this->Category);
			this->topPanel->Controls->Add(this->ClientCompany);
			this->topPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->topPanel->Location = System::Drawing::Point(0, 0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(1280, 53);
			this->topPanel->TabIndex = tabIndex++;
			this->topPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainApplication::topPanel_Paint_1);

			// 
			// panel1
			// 
			this->menuPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->menuPanel->Location = System::Drawing::Point(0, 53);
			this->menuPanel->Name = L"panel1";
			this->menuPanel->Controls->Add(this->greet);
			for (int i = 0; i < 6; i++) {
				this->menuPanel->Controls->Add(this->menuButtons[i]);
			}
			this->menuPanel->Size = System::Drawing::Size(197, 626);
			this->menuPanel->TabIndex = tabIndex++;


			//
			//maintaining greeting
			//
			this->greet->BackColor = this->menuPanel->BackColor;
			this->greet->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(103)));
			this->greet->Font = (gcnew System::Drawing::Font(L"Verdana", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->greet->Text = L"Goodafternoon  sir";
			this->greet->Size = System::Drawing::Size(this->dataPanel->Width - 6, 34);
			this->greet->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->greet->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

			this->greet->Margin = System::Windows::Forms::Padding(20, 30, 2, 15);
			//
			// Adding Attributes to Menu Buttons
			//

			for (int i = 0; i < 6; i++) {
				this->menuButtons[i]->BackColor = this->menuPanel->BackColor;
				this->menuButtons[i]->Font = (gcnew System::Drawing::Font(L"Verdana", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->menuButtons[i]->Location = System::Drawing::Point(0, 3);
				this->menuButtons[i]->Margin = System::Windows::Forms::Padding(2, 5, 2, 5);
				this->menuButtons[i]->Name = L"Button" + i.ToString();
				this->menuButtons[i]->Size = System::Drawing::Size(this->dataPanel->Width - 6, 40);
				this->menuButtons[i]->TabIndex = tabIndex++;
				this->menuButtons[i]->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
					static_cast<System::Int32>(static_cast<System::Byte>(103)));
				this->menuButtons[i]->UseVisualStyleBackColor = false;
				this->menuButtons[i]->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &OMSuppliers::MainApplication::menuButtonClicked);
				this->menuButtons[i]->MouseHover += gcnew System::EventHandler(this, &MainApplication::menuButton_MouseHover);
			}
			this->menuButtons[0]->Text = L"STOCK";
			this->menuButtons[1]->Text = L"SALES";
			this->menuButtons[2]->Text = L"PURCHASES";
			this->menuButtons[3]->Text = L"Button 4";
			this->menuButtons[4]->Text = L"Button 5";
			this->menuButtons[5]->Text = L"Button 6";

			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->panel3->Location = System::Drawing::Point(198, 625);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1082, 54);
			this->panel3->TabIndex = tabIndex++;
			//
			// Serial
			// 
			this->Serial->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->Serial->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Serial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->Serial->ForeColor = System::Drawing::Color::Gray;
			this->Serial->Location = System::Drawing::Point(232, 72);
			this->Serial->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Serial->Name = L"Serial";
			this->Serial->Text = L"S.N";
			this->Serial->Size = System::Drawing::Size(45, 28);
			this->Serial->TabIndex = tabIndex++;
			// 
			// Balance
			// 
			this->Balance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->Balance->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->Balance->ForeColor = System::Drawing::Color::Gray;
			this->Balance->Location = System::Drawing::Point(1124, 72);
			this->Balance->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Balance->Name = L"Balance";
			this->Balance->Size = System::Drawing::Size(118, 28);
			this->Balance->TabIndex = tabIndex++;
			this->Balance->Text = L"Balance";
			// 
			// Sales
			// 
			this->Sales->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->Sales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Sales->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->Sales->ForeColor = System::Drawing::Color::Gray;
			this->Sales->Location = System::Drawing::Point(848, 72);
			this->Sales->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Sales->Name = L"Sales";
			this->Sales->Size = System::Drawing::Size(122, 28);
			this->Sales->TabIndex = tabIndex++;
			this->Sales->Text = L"Sales QTY";
			// 
			// rate
			// 
			this->rate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->rate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->rate->ForeColor = System::Drawing::Color::Gray;
			this->rate->Location = System::Drawing::Point(974, 73);
			this->rate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rate->Name = L"rate";
			this->rate->Size = System::Drawing::Size(146, 28);
			this->rate->TabIndex = tabIndex++;
			this->rate->Text = L"Rate";
			// 
			// Purchase
			// 
			this->Purchase->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->Purchase->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Purchase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->Purchase->ForeColor = System::Drawing::Color::Gray;
			this->Purchase->Location = System::Drawing::Point(710, 72);
			this->Purchase->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Purchase->Name = L"Purchase";
			this->Purchase->Size = System::Drawing::Size(134, 28);
			this->Purchase->TabIndex = tabIndex++;
			this->Purchase->Text = L"Purch. QTY";
			// 
			// Code
			// 
			this->Code->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->Code->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->Code->ForeColor = System::Drawing::Color::Gray;
			this->Code->Location = System::Drawing::Point(647, 72);
			this->Code->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Code->Name = L"Code";
			this->Code->Size = System::Drawing::Size(59, 28);
			this->Code->TabIndex = tabIndex++;
			this->Code->Text = L"Code";
			// 
			// ItemName
			// 
			this->ItemName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(214)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ItemName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ItemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold));
			this->ItemName->ForeColor = System::Drawing::Color::Gray;
			this->ItemName->Location = System::Drawing::Point(282, 72);
			this->ItemName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ItemName->Name = L"ItemName";
			this->ItemName->Size = System::Drawing::Size(360, 28);
			this->ItemName->TabIndex = tabIndex++;
			this->ItemName->Text = L"Item Name";
			// 
			// dataPanel
			// 
			this->dataPanel->AutoScroll = true;
			this->dataPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(171)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->dataPanel->Controls->Add(this->bottomLinePanel_DataPanel);
			this->dataPanel->Location = System::Drawing::Point(231, 110);
			this->dataPanel->Margin = System::Windows::Forms::Padding(0);
			this->dataPanel->Name = L"dataPanel";
			this->dataPanel->Size = System::Drawing::Size(1040, 557);
			this->dataPanel->TabIndex = tabIndex++;
			this->dataPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainApplication::dataPanel_Paint);
			// 
			// bottomLinePanel_DataPanel
			// 
			this->bottomLinePanel_DataPanel->BackColor = System::Drawing::Color::White;
			this->bottomLinePanel_DataPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bottomLinePanel_DataPanel->Location = System::Drawing::Point(3, 43);
			this->bottomLinePanel_DataPanel->Name = L"bottomLinePanel_DataPanel";
			this->bottomLinePanel_DataPanel->Size = System::Drawing::Size(1011, 5);
			this->bottomLinePanel_DataPanel->TabIndex = tabIndex++;
			// 
			// leftPanel
			// 
			this->rightPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->rightPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->rightPanel->Location = System::Drawing::Point(1270, 53);
			this->rightPanel->Name = L"rightPanel";
			this->rightPanel->Size = System::Drawing::Size(10, 626);
			this->rightPanel->TabIndex = tabIndex++;
			// 
			// Exit
			// 
			this->Exit->BackColor = System::Drawing::Color::Red;
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Exit->ForeColor = System::Drawing::Color::White;
			this->Exit->Location = System::Drawing::Point(1243, 0);
			this->Exit->Margin = System::Windows::Forms::Padding(4);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(37, 37);
			this->Exit->TabIndex = tabIndex++;
			this->Exit->Text = L"X";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::Exit_MouseClick);
			this->Exit->MouseLeave += gcnew System::EventHandler(this, &MainApplication::Exit_MouseLeave);
			this->Exit->MouseHover += gcnew System::EventHandler(this, &MainApplication::Exit_MouseHover);
			// 
			// MainApplication
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->ClientSize = System::Drawing::Size(1280, 679);
			this->Controls->Add(this->rightPanel);
			this->Controls->Add(this->Serial);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->dataPanel);
			this->Controls->Add(this->topPanel);
			this->Controls->Add(this->menuPanel);
			this->Controls->Add(this->ItemName);
			this->Controls->Add(this->Code);
			this->Controls->Add(this->Purchase);
			this->Controls->Add(this->rate);
			this->Controls->Add(this->Sales);
			this->Controls->Add(this->Balance);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainApplication";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"OM Suppliers Private Limited";
			this->Load += gcnew System::EventHandler(this, &MainApplication::MainApplication_Load);
			this->topPanel->ResumeLayout(false);
			this->dataPanel->ResumeLayout(false);
			this->dataPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainApplication_Load(System::Object^ sender, System::EventArgs^ e) {
		this->menuButtons[0]->Focus();
	}
	private: System::Void topPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void ClientCompany_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainApplication_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	}
	private: System::Void dataPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void topPanel_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Exit_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void Exit_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->Exit->BackColor = System::Drawing::Color::Red;
		this->Exit->ForeColor = System::Drawing::Color::White;
	}
	private: System::Void Exit_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->Exit->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Exit->BackColor = System::Drawing::Color::Red;
		this->Exit->ForeColor = System::Drawing::Color::GhostWhite;
	}
	private: System::Void Category_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void serialNumber_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void changeStockData(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (MessageBox::Show("Do you really want to change stock data?", "OM Suppliers", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		}
		else {
			System::Windows::Forms::TextBox^ rateDataTemp = safe_cast<System::Windows::Forms::TextBox^>(sender);
			rateDataTemp->Parent->Focus();
		}
	}


	private: System::Void OnKeyPress_AllowFloat(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		System::Windows::Forms::TextBox^ textBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
		if (e->KeyChar == '.') {
			//to check if a . sign is already present
			if (textBox->Text->Contains(".")) {
				e->Handled = true;

				MessageBox::Show("A number cannot have two '.' symbols", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		// Allow negative numbers
		else if (e->KeyChar == '-') {
			if (textBox->Text->Contains("-")) {
				e->Handled = true;
				MessageBox::Show("A number cannot contain two '-' symbols", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			textBox->Text = "-" + textBox->Text;
			e->Handled = true;
		}
		//Return focus to parent when enter key is pressed
		else if (e->KeyChar == 13) {
			textBox->Parent->Focus();
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			MessageBox::Show("Not a number", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			e->Handled = true;
		}
		//
	}

	private: System::Void OnKeyPress_AllowIntegers(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		System::Windows::Forms::TextBox^ textBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
		if (e->KeyChar == '.') {
			MessageBox::Show("This field cannot have float values", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			e->Handled = true;
		}
		// Allow negative numbers
		else if (e->KeyChar == '-') {
			
			MessageBox::Show("This field cannot have negative values", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			e->Handled = true;
		}
		//Return focus to parent when enter key is pressed
		else if (e->KeyChar == 13) {
			textBox->Parent->Focus();
		}
		// Accept only digits ".", "-" and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			MessageBox::Show("Not a number", "OM Suppliers", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			e->Handled = true;
		}
		//
	}

	private: System::Void rateData_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// Accept only digits and the Backspace character
	}
	private: System::Void balanceData_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void purchaseQTYData_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void rateData_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void particularsData_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void menuButton_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Button^ btn = safe_cast<Button^>(sender);
		delete btn->Text;
		btn->Text = L"Hovered";
	}

	private: System::Void menuButtonClicked(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		System::Windows::Forms::Button^ button = safe_cast<System::Windows::Forms::Button^>(sender);
		if(button->Name==L"Button0"){}
		else if(button->Name==L"Button1"){}
		else if(button->Name==L"Button2"){}
		else if(button->Name==L"Button3"){}
	}

	public:void addData(StockItem stockItem) {
		this->dataPanel->Controls->Remove(this->bottomLinePanel_DataPanel);
		this->stockDataManager->addStockDataRow(stockItem);
		(this->stockDataManager->getPresentStockRow())->particularsData->TextChanged += gcnew System::EventHandler(this, &MainApplication::particularsData_TextChanged);
		(this->stockDataManager->getPresentStockRow())->rateData->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OMSuppliers::MainApplication::OnKeyPress_AllowFloat);
		(this->stockDataManager->getPresentStockRow())->rateData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		(this->stockDataManager->getPresentStockRow())->SalesQTYData->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OMSuppliers::MainApplication::OnKeyPress_AllowIntegers);
		(this->stockDataManager->getPresentStockRow())->SalesQTYData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		(this->stockDataManager->getPresentStockRow())->purchaseQTYData->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OMSuppliers::MainApplication::OnKeyPress_AllowIntegers);
		(this->stockDataManager->getPresentStockRow())->purchaseQTYData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		(this->stockDataManager->getPresentStockRow())->balanceData->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &OMSuppliers::MainApplication::OnKeyPress_AllowIntegers);
		(this->stockDataManager->getPresentStockRow())->balanceData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		(this->stockDataManager->getPresentStockRow())->particularsData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		(this->stockDataManager->getPresentStockRow())->codeData->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainApplication::changeStockData);
		this->dataPanel->Controls->Add(this->bottomLinePanel_DataPanel);
	}
	};
}
