#pragma once
#include "ExceptionBoxForm.h"
#include <msclr\marshal_cppstd.h>
#include "PatientСard.h"
#include "PatientCardDAO.h"
#include "DataRepository.h"
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddPatientForm
	/// </summary>
	public ref class AddPatientForm : public System::Windows::Forms::Form
	{

	public: PatientCardDAO* patientCardDAO;
	public:
		AddPatientForm()
		{
			InitializeComponent();
			
			
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddPatientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SavePatient_Button;
	protected:


	protected:

	private: System::Windows::Forms::TextBox^ Email_textBox;

	private: System::Windows::Forms::TextBox^ PhoneNumber_textBox;



	private: System::Windows::Forms::TextBox^ LastName_textBox;
	private: System::Windows::Forms::TextBox^ FirstName_textBox;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DateTimePicker^ Birth_dateTimePicker;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddPatientForm::typeid));
			this->SavePatient_Button = (gcnew System::Windows::Forms::Button());
			this->Email_textBox = (gcnew System::Windows::Forms::TextBox());
			this->PhoneNumber_textBox = (gcnew System::Windows::Forms::TextBox());
			this->LastName_textBox = (gcnew System::Windows::Forms::TextBox());
			this->FirstName_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Birth_dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// SavePatient_Button
			// 
			this->SavePatient_Button->Location = System::Drawing::Point(201, 268);
			this->SavePatient_Button->Name = L"SavePatient_Button";
			this->SavePatient_Button->Size = System::Drawing::Size(124, 41);
			this->SavePatient_Button->TabIndex = 33;
			this->SavePatient_Button->Text = L"Save";
			this->SavePatient_Button->UseVisualStyleBackColor = true;
			this->SavePatient_Button->Click += gcnew System::EventHandler(this, &AddPatientForm::SavePatient_Button_Click);
			// 
			// Email_textBox
			// 
			this->Email_textBox->Location = System::Drawing::Point(186, 214);
			this->Email_textBox->Name = L"Email_textBox";
			this->Email_textBox->Size = System::Drawing::Size(200, 22);
			this->Email_textBox->TabIndex = 31;
			// 
			// PhoneNumber_textBox
			// 
			this->PhoneNumber_textBox->Location = System::Drawing::Point(186, 168);
			this->PhoneNumber_textBox->Name = L"PhoneNumber_textBox";
			this->PhoneNumber_textBox->Size = System::Drawing::Size(200, 22);
			this->PhoneNumber_textBox->TabIndex = 30;
			// 
			// LastName_textBox
			// 
			this->LastName_textBox->Location = System::Drawing::Point(186, 75);
			this->LastName_textBox->Name = L"LastName_textBox";
			this->LastName_textBox->Size = System::Drawing::Size(200, 22);
			this->LastName_textBox->TabIndex = 28;
			// 
			// FirstName_textBox
			// 
			this->FirstName_textBox->Location = System::Drawing::Point(186, 31);
			this->FirstName_textBox->Name = L"FirstName_textBox";
			this->FirstName_textBox->Size = System::Drawing::Size(200, 22);
			this->FirstName_textBox->TabIndex = 27;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(134, 217);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Email:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(122, 171);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 17);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Phone:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(111, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 17);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Birthday:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(106, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 17);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Surname:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(122, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 17);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Name:";
			// 
			// Birth_dateTimePicker
			// 
			this->Birth_dateTimePicker->Location = System::Drawing::Point(186, 126);
			this->Birth_dateTimePicker->Name = L"Birth_dateTimePicker";
			this->Birth_dateTimePicker->Size = System::Drawing::Size(200, 22);
			this->Birth_dateTimePicker->TabIndex = 34;
			// 
			// AddPatientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(512, 377);
			this->Controls->Add(this->Birth_dateTimePicker);
			this->Controls->Add(this->SavePatient_Button);
			this->Controls->Add(this->Email_textBox);
			this->Controls->Add(this->PhoneNumber_textBox);
			this->Controls->Add(this->LastName_textBox);
			this->Controls->Add(this->FirstName_textBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddPatientForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void SavePatient_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ f_name = FirstName_textBox->Text;
	String^ l_name = LastName_textBox->Text;
	DateTime birth = Birth_dateTimePicker->Value;
	String^ phoneNumber = PhoneNumber_textBox->Text;
	String^ email = Email_textBox->Text;
	DateTime date;
	DateTime registrationDate = date.Now;
	if (f_name->Length<2) {
		ExceptionBoxForm exceptionBox("Имя введено некорректно!");
		exceptionBox.ShowDialog();
	}
	else if (l_name->Length<3) {
		ExceptionBoxForm exceptionBox("Фамилия введена некорректно!");
		exceptionBox.ShowDialog();
	}
	else if (phoneNumber->Length<7) {
		ExceptionBoxForm exceptionBox("Номер телефона введён некорректно!");
		exceptionBox.ShowDialog();
	}
	else if (email->Length<9 && !email->Contains("@")) {
		ExceptionBoxForm exceptionBox("Email введён некорректно!");
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
		DataRepository::patientCardDAO.PatientCards.push_back(new_card);
		DataRepository::patientCardDAO.SavePatientCards();
		this->Hide();
	}

}
};
}
