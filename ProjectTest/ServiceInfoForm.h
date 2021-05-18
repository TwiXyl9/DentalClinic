#pragma once
#include "DataRepository.h"
#include <msclr\marshal_cppstd.h>
#include "ExceptionBoxForm.h"
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ServiceInfoForm
	/// </summary>
	public ref class ServiceInfoForm : public System::Windows::Forms::Form
	{
	public: int ID = 0;
	public:
		ServiceInfoForm(int id)
		{
			ID = id;
			InitializeComponent();
			ShowData();
			//
			//TODO: добавьте код конструктора
			//
		}
	public: void ShowData() {
		IDBox->Text = gcnew String(to_string(DataRepository::serviceDAO.Services[ID].Id).c_str());
		TitleBox->Text = gcnew String(DataRepository::serviceDAO.Services[ID].Title.c_str());
		PriceBox->Text = gcnew String(to_string(DataRepository::serviceDAO.Services[ID].Price).c_str());
	}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ServiceInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Save_Button;
	private: System::Windows::Forms::TextBox^ TitleBox;
	private: System::Windows::Forms::TextBox^ PriceBox;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ IDBox;
	private: System::Windows::Forms::Button^ DeleteButton;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServiceInfoForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Save_Button = (gcnew System::Windows::Forms::Button());
			this->TitleBox = (gcnew System::Windows::Forms::TextBox());
			this->PriceBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->IDBox = (gcnew System::Windows::Forms::TextBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Title:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Price:";
			// 
			// Save_Button
			// 
			this->Save_Button->Location = System::Drawing::Point(83, 168);
			this->Save_Button->Name = L"Save_Button";
			this->Save_Button->Size = System::Drawing::Size(169, 35);
			this->Save_Button->TabIndex = 2;
			this->Save_Button->Text = L"Save";
			this->Save_Button->UseVisualStyleBackColor = true;
			this->Save_Button->Click += gcnew System::EventHandler(this, &ServiceInfoForm::Save_Button_Click);
			// 
			// TitleBox
			// 
			this->TitleBox->Location = System::Drawing::Point(108, 65);
			this->TitleBox->Name = L"TitleBox";
			this->TitleBox->Size = System::Drawing::Size(127, 22);
			this->TitleBox->TabIndex = 3;
			// 
			// PriceBox
			// 
			this->PriceBox->Location = System::Drawing::Point(108, 112);
			this->PriceBox->Name = L"PriceBox";
			this->PriceBox->Size = System::Drawing::Size(127, 22);
			this->PriceBox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(64, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Id:";
			this->label3->Click += gcnew System::EventHandler(this, &ServiceInfoForm::label3_Click);
			// 
			// IDBox
			// 
			this->IDBox->Enabled = false;
			this->IDBox->Location = System::Drawing::Point(108, 27);
			this->IDBox->Name = L"IDBox";
			this->IDBox->Size = System::Drawing::Size(40, 22);
			this->IDBox->TabIndex = 6;
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(83, 219);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(169, 36);
			this->DeleteButton->TabIndex = 7;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ServiceInfoForm::DeleteButton_Click);
			// 
			// ServiceInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 288);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->IDBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PriceBox);
			this->Controls->Add(this->TitleBox);
			this->Controls->Add(this->Save_Button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ServiceInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Save_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	string title = msclr::interop::marshal_as<std::string>(TitleBox->Text);
	float price;
	try {
		price = stof(msclr::interop::marshal_as<std::string>(PriceBox->Text));
	}
	catch (exception ex) {
		ExceptionBoxForm("Enter correct price!").ShowDialog();
		return;
	}

	if (title.size() == 0)
	{
		ExceptionBoxForm("Enter correct title!").ShowDialog();
	}
	else if (price < 0)
	{
		ExceptionBoxForm("Enter correct price!").ShowDialog();
	}
	else
	{
		Service service;
		service.Price = price;
		service.Title = title;
		service.Id = DataRepository::serviceDAO.Services[ID].Id;
		DataRepository::serviceDAO.Services[ID] = service;
		DataRepository::serviceDAO.SaveServices();
		this->Hide();
	}
}
private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	DataRepository::serviceDAO.Services.erase(DataRepository::serviceDAO.Services.begin() + ID);
	DataRepository::serviceDAO.SaveServices();
	this->Hide();
}
};
}
