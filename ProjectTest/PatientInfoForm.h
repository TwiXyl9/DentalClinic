#pragma once
#include "PatientCardDAO.h"
#include "TicketDAO.h"
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
	/// ������ ��� PatientInfoForm
	/// </summary>
	public ref class PatientInfoForm : public System::Windows::Forms::Form
	{
	public: int ID;
	public:
		PatientInfoForm(int id)
		{

			InitializeComponent();
			ID = id;
			ShowInfo();
			//
			//TODO: �������� ��� ������������
			//
		}
		 
	public: 
		void ShowInfo() {
			IDBox->Text = gcnew String(to_string(DataRepository::patientCardDAO.PatientCards[ID].Id).c_str());
			NameBox->Text = gcnew String(DataRepository::patientCardDAO.PatientCards[ID].Name.c_str());
			SurnameBox->Text = gcnew String(DataRepository::patientCardDAO.PatientCards[ID].Surname.c_str());
			BirthPicker->Value = DateTime(DataRepository::patientCardDAO.PatientCards[ID].DateOfBirth.Years,
				DataRepository::patientCardDAO.PatientCards[ID].DateOfBirth.Months,
				DataRepository::patientCardDAO.PatientCards[ID].DateOfBirth.Days);
			PhoneBox->Text = gcnew String(DataRepository::patientCardDAO.PatientCards[ID].Phone.c_str());
			EmailBox->Text = gcnew String(DataRepository::patientCardDAO.PatientCards[ID].Email.c_str());
			RegistrationBox->Text = gcnew String(DataRepository::patientCardDAO.PatientCards[ID].DateOfRegistartion.ToString().c_str());

			for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
			{
				if (DataRepository::ticketDAO.Tickets[i].PatientCardId == ID) {
					TicketsListBox->Items->Add(gcnew String(DataRepository::ticketDAO.Tickets[i].DateTime.ToString().c_str()));
				}
			}
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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

	private: System::Windows::Forms::TextBox^ PhoneBox;
	private: System::Windows::Forms::TextBox^ EmailBox;

	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::DateTimePicker^ BirthPicker;
	private: System::Windows::Forms::TextBox^ RegistrationBox;











	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->PhoneBox = (gcnew System::Windows::Forms::TextBox());
			this->EmailBox = (gcnew System::Windows::Forms::TextBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->BirthPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->RegistrationBox = (gcnew System::Windows::Forms::TextBox());
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
			this->label2->Text = L"���:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(71, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"�������:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(30, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"���� ��������:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(73, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"�������:";
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
			this->label7->Text = L"���� �����������:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(28, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 17);
			this->label8->TabIndex = 7;
			this->label8->Text = L"������ �������:";
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
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(172, 390);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(124, 41);
			this->SaveButton->TabIndex = 16;
			this->SaveButton->Text = L"���������";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &PatientInfoForm::button1_Click);
			// 
			// BirthPicker
			// 
			this->BirthPicker->Location = System::Drawing::Point(151, 108);
			this->BirthPicker->Name = L"BirthPicker";
			this->BirthPicker->Size = System::Drawing::Size(186, 22);
			this->BirthPicker->TabIndex = 17;
			// 
			// RegistrationBox
			// 
			this->RegistrationBox->Enabled = false;
			this->RegistrationBox->Location = System::Drawing::Point(151, 194);
			this->RegistrationBox->Name = L"RegistrationBox";
			this->RegistrationBox->Size = System::Drawing::Size(187, 22);
			this->RegistrationBox->TabIndex = 15;
			// 
			// PatientInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(431, 490);
			this->Controls->Add(this->BirthPicker);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->RegistrationBox);
			this->Controls->Add(this->EmailBox);
			this->Controls->Add(this->PhoneBox);
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

	String^ f_name = NameBox->Text;
	String^ l_name = SurnameBox->Text;
	DateTime birth = BirthPicker->Value;
	String^ phoneNumber = PhoneBox->Text;
	String^ email = EmailBox->Text;
	DateTime date;
	DateTime registrationDate = date.Now;
	if (f_name->Length < 2) {
		ExceptionBoxForm exceptionBox("��� ������� �����������!");
		exceptionBox.ShowDialog();
	}
	else if (l_name->Length < 3) {
		ExceptionBoxForm exceptionBox("������� ������� �����������!");
		exceptionBox.ShowDialog();
	}
	else if (phoneNumber->Length < 7) {
		ExceptionBoxForm exceptionBox("����� �������� ����� �����������!");
		exceptionBox.ShowDialog();
	}
	else if (email->Length < 9 && !email->Contains("@")) {
		ExceptionBoxForm exceptionBox("Email ����� �����������!");
		exceptionBox.ShowDialog();
	}
	else {
		PatientCard new_card;

		new_card.Id = DataRepository::patientCardDAO.GetNewId();
		new_card.Name = msclr::interop::marshal_as<std::string>(f_name);
		new_card.Surname = msclr::interop::marshal_as<std::string>(l_name);
		new_card.Phone = msclr::interop::marshal_as<std::string>(phoneNumber);
		new_card.Email = msclr::interop::marshal_as<std::string>(email);
		DateAndTime new_birth = DateAndTime::ToDateAndTime(birth);
		new_card.DateOfBirth = new_birth;
		DateAndTime new_reg = new_birth.ToDateAndTime(registrationDate);
		new_card.DateOfRegistartion = new_reg;
		DataRepository::patientCardDAO.PatientCards[ID] = new_card;
		DataRepository::patientCardDAO.SavePatientCards();
		this->Hide();
	}
}
};
}
