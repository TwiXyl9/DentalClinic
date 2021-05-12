#pragma once
#include "PatientCardDAO.h"
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PatientInfoForm
	/// </summary>
	public ref class PatientInfoForm : public System::Windows::Forms::Form
	{
	public: int ID;
	public:
		PatientInfoForm(int id)
		{

			InitializeComponent();

			patientCardDAO = new PatientCardDAO();
			patientCardDAO->LoadPatientCards();
			ID = id;
			ShowInfo();
			//
			//TODO: добавьте код конструктора
			//
		}
		 
	public: PatientCardDAO* patientCardDAO;
	public: 
		void ShowInfo() {
			IDBox->Text = gcnew String(ID.ToString());
			NameBox->Text = gcnew String(patientCardDAO->PatientCards[ID].Name.c_str());
			SurnameBox->Text = gcnew String(patientCardDAO->PatientCards[ID].Surname.c_str());
			BirthBox->Text = gcnew String(patientCardDAO->PatientCards[ID].DateOfBirth.ToString().c_str());
			PhoneBox->Text = gcnew String(patientCardDAO->PatientCards[ID].Phone.c_str());
			EmailBox->Text = gcnew String(patientCardDAO->PatientCards[ID].Email.c_str());
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PatientInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ListBox^ TicketsListBox;


	private: System::Windows::Forms::TextBox^ IDBox;
	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::TextBox^ SurnameBox;
	private: System::Windows::Forms::TextBox^ BirthBox;
	private: System::Windows::Forms::TextBox^ PhoneBox;
	private: System::Windows::Forms::TextBox^ EmailBox;
	private: System::Windows::Forms::TextBox^ RegistrationBox;
	private: System::Windows::Forms::Button^ SaveButton;










	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PatientInfoForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TicketsListBox = (gcnew System::Windows::Forms::ListBox());
			this->IDBox = (gcnew System::Windows::Forms::TextBox());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->SurnameBox = (gcnew System::Windows::Forms::TextBox());
			this->BirthBox = (gcnew System::Windows::Forms::TextBox());
			this->PhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->EmailBox = (gcnew System::Windows::Forms::TextBox());
			this->RegistrationBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(122, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(106, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Имя:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(71, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Фамилия:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(30, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Дата рождения:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(73, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Телефон:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(99, 166);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Email:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 193);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 17);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Дата регистрации:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(28, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 17);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Список талонов:";
			// 
			// TicketsListBox
			// 
			this->TicketsListBox->FormattingEnabled = true;
			this->TicketsListBox->ItemHeight = 16;
			this->TicketsListBox->Location = System::Drawing::Point(151, 226);
			this->TicketsListBox->Name = L"TicketsListBox";
			this->TicketsListBox->Size = System::Drawing::Size(187, 100);
			this->TicketsListBox->TabIndex = 8;
			// 
			// IDBox
			// 
			this->IDBox->Location = System::Drawing::Point(151, 23);
			this->IDBox->Name = L"IDBox";
			this->IDBox->Size = System::Drawing::Size(187, 22);
			this->IDBox->TabIndex = 9;
			// 
			// NameBox
			// 
			this->NameBox->Location = System::Drawing::Point(151, 51);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(187, 22);
			this->NameBox->TabIndex = 10;
			// 
			// SurnameBox
			// 
			this->SurnameBox->Location = System::Drawing::Point(151, 79);
			this->SurnameBox->Name = L"SurnameBox";
			this->SurnameBox->Size = System::Drawing::Size(187, 22);
			this->SurnameBox->TabIndex = 11;
			// 
			// BirthBox
			// 
			this->BirthBox->Location = System::Drawing::Point(151, 108);
			this->BirthBox->Name = L"BirthBox";
			this->BirthBox->Size = System::Drawing::Size(187, 22);
			this->BirthBox->TabIndex = 12;
			// 
			// PhoneBox
			// 
			this->PhoneBox->Location = System::Drawing::Point(151, 138);
			this->PhoneBox->Name = L"PhoneBox";
			this->PhoneBox->Size = System::Drawing::Size(187, 22);
			this->PhoneBox->TabIndex = 13;
			// 
			// EmailBox
			// 
			this->EmailBox->Location = System::Drawing::Point(151, 166);
			this->EmailBox->Name = L"EmailBox";
			this->EmailBox->Size = System::Drawing::Size(187, 22);
			this->EmailBox->TabIndex = 14;
			// 
			// RegistrationBox
			// 
			this->RegistrationBox->Location = System::Drawing::Point(151, 194);
			this->RegistrationBox->Name = L"RegistrationBox";
			this->RegistrationBox->Size = System::Drawing::Size(187, 22);
			this->RegistrationBox->TabIndex = 15;
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(172, 390);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(124, 41);
			this->SaveButton->TabIndex = 16;
			this->SaveButton->Text = L"Сохранить";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &PatientInfoForm::button1_Click);
			// 
			// PatientInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(431, 490);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->RegistrationBox);
			this->Controls->Add(this->EmailBox);
			this->Controls->Add(this->PhoneBox);
			this->Controls->Add(this->BirthBox);
			this->Controls->Add(this->SurnameBox);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->IDBox);
			this->Controls->Add(this->TicketsListBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PatientInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
