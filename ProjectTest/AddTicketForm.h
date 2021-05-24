#pragma once
#include "DataRepository.h"
#include "String"
#include "ExceptionBoxForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Ticket.h"
#include "PatientСard.h"
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddTicketForm
	/// </summary>
	public ref class AddTicketForm : public System::Windows::Forms::Form
	{
	public:
		AddTicketForm(void)
		{
			InitializeComponent();
			FillTime();
			FillPatients(DataRepository::patientCardDAO.PatientCards);
			SetMinDate();
			FillServices();
			//
			//TODO: добавьте код конструктора
			//
		}

	public:
		void FillTime() {

			for (int i = 9; i < 19; i++) {
				HoursCb->Items->Add(i);
			}

			MinutesCb->Items->Add("00");
			MinutesCb->Items->Add("30");

		}


	public:
		void FillServices() {

			for (int i = 0; i < DataRepository::serviceDAO.Services.size(); i++) {
				string service = DataRepository::serviceDAO.Services[i].Title;
				comboBoxServices->Items->Add(gcnew String(service.c_str()));
			}
		}


	public:
		void SetMinDate() {

			dateTimePicker->MinDate = DateTime().Now;
		}

	public:
		void FillPatients(vector<PatientCard> patients) {

			dataGridViewPatients->Rows->Clear();

			for (int i = 0; i < patients.size(); i++)
			{
				String^ Name = gcnew String(patients[i].Name.c_str());
				String^ Surname = gcnew String(patients[i].Surname.c_str());
				String^ Id = gcnew String(to_string(patients[i].Id).c_str());
				String^ BirthDay = gcnew String((patients[i].DateOfBirth.ToString()).c_str());
				String^ Phone = gcnew String((patients[i].Phone).c_str());
				dataGridViewPatients->Rows->Add(Id, Name, Surname, BirthDay, Phone);
			}
		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddTicketForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ HoursCb;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ MinutesCb;


	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dataGridViewPatients;





	private: System::Windows::Forms::Button^ Save;




	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBoxServices;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BirthDay;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ PriceLabel;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TextBox^ textBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddTicketForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HoursCb = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MinutesCb = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewPatients = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BirthDay = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxServices = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPatients))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(101, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Hours:";
			// 
			// HoursCb
			// 
			this->HoursCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->HoursCb->FormattingEnabled = true;
			this->HoursCb->Location = System::Drawing::Point(160, 80);
			this->HoursCb->Name = L"HoursCb";
			this->HoursCb->Size = System::Drawing::Size(62, 24);
			this->HoursCb->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(247, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Minutes:";
			// 
			// MinutesCb
			// 
			this->MinutesCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->MinutesCb->FormattingEnabled = true;
			this->MinutesCb->Location = System::Drawing::Point(323, 77);
			this->MinutesCb->Name = L"MinutesCb";
			this->MinutesCb->Size = System::Drawing::Size(62, 24);
			this->MinutesCb->TabIndex = 3;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(171, 22);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(214, 22);
			this->dateTimePicker->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(101, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Date:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Patients:";
			// 
			// dataGridViewPatients
			// 
			this->dataGridViewPatients->AllowUserToAddRows = false;
			this->dataGridViewPatients->AllowUserToDeleteRows = false;
			this->dataGridViewPatients->AllowUserToOrderColumns = true;
			this->dataGridViewPatients->AllowUserToResizeColumns = false;
			this->dataGridViewPatients->AllowUserToResizeRows = false;
			this->dataGridViewPatients->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewPatients->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewPatients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPatients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Id,
					this->NameColumn, this->Surname, this->BirthDay, this->Phone
			});
			this->dataGridViewPatients->Location = System::Drawing::Point(15, 258);
			this->dataGridViewPatients->Name = L"dataGridViewPatients";
			this->dataGridViewPatients->RowHeadersWidth = 51;
			this->dataGridViewPatients->RowTemplate->Height = 24;
			this->dataGridViewPatients->Size = System::Drawing::Size(478, 205);
			this->dataGridViewPatients->TabIndex = 7;
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->MinimumWidth = 6;
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			// 
			// NameColumn
			// 
			this->NameColumn->HeaderText = L"Name";
			this->NameColumn->MinimumWidth = 6;
			this->NameColumn->Name = L"NameColumn";
			this->NameColumn->ReadOnly = true;
			// 
			// Surname
			// 
			this->Surname->HeaderText = L"Surname";
			this->Surname->MinimumWidth = 6;
			this->Surname->Name = L"Surname";
			this->Surname->ReadOnly = true;
			// 
			// BirthDay
			// 
			this->BirthDay->HeaderText = L"BirthDay";
			this->BirthDay->MinimumWidth = 6;
			this->BirthDay->Name = L"BirthDay";
			this->BirthDay->ReadOnly = true;
			// 
			// Phone
			// 
			this->Phone->HeaderText = L"Phone";
			this->Phone->MinimumWidth = 6;
			this->Phone->Name = L"Phone";
			this->Phone->ReadOnly = true;
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(171, 498);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(146, 46);
			this->Save->TabIndex = 8;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &AddTicketForm::Save_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(85, 135);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Services:";
			// 
			// comboBoxServices
			// 
			this->comboBoxServices->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxServices->FormattingEnabled = true;
			this->comboBoxServices->Location = System::Drawing::Point(171, 135);
			this->comboBoxServices->Name = L"comboBoxServices";
			this->comboBoxServices->Size = System::Drawing::Size(214, 24);
			this->comboBoxServices->TabIndex = 10;
			this->comboBoxServices->SelectedIndexChanged += gcnew System::EventHandler(this, &AddTicketForm::comboBoxServices_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(107, 187);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Price:";
			// 
			// PriceLabel
			// 
			this->PriceLabel->AutoSize = true;
			this->PriceLabel->Location = System::Drawing::Point(171, 187);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(16, 17);
			this->PriceLabel->TabIndex = 12;
			this->PriceLabel->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(225, 233);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(116, 17);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Search surname:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(342, 230);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 22);
			this->textBox1->TabIndex = 14;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AddTicketForm::textBox1_TextChanged);
			// 
			// AddTicketForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(505, 565);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->PriceLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBoxServices);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->dataGridViewPatients);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->MinutesCb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->HoursCb);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddTicketForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPatients))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {

		if (HoursCb->Text == "" || MinutesCb->Text == "" || comboBoxServices->Text == "" || dataGridViewPatients->SelectedRows->Count == 0)
		{
			ExceptionBoxForm("Fill all fields!").ShowDialog();
		}
		else if (dateTimePicker->Value.Date == DateTime::Now.Date && 
			(DateTime::Now.Hour > stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text)) || 
				(DateTime::Now.Hour == stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text)) && 
					DateTime::Now.Minute > stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text)))))
		{
			ExceptionBoxForm("Input correct time!").ShowDialog();
		}
		else {
			DateTime selectedDate = dateTimePicker->Value;
			DateAndTime ticketDate = DateAndTime::ToDateAndTime(selectedDate);

			ticketDate.Hours = stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text));
			ticketDate.Minutes = stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text));
			ticketDate.Seconds = 0;

			for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
			{
				if (DataRepository::ticketDAO.Tickets[i].DateTime.Years == ticketDate.Years && DataRepository::ticketDAO.Tickets[i].DateTime.Months == ticketDate.Months && DataRepository::ticketDAO.Tickets[i].DateTime.Days == ticketDate.Days)
				{
					if (DataRepository::ticketDAO.Tickets[i].DateTime.Hours == ticketDate.Hours && DataRepository::ticketDAO.Tickets[i].DateTime.Minutes == ticketDate.Minutes) {
						ExceptionBoxForm("This time is already busy!").ShowDialog();
						return;
					}
				}
			}

			

			int serviceId;
			string serviceString = msclr::interop::marshal_as<std::string>(comboBoxServices->Text);
			for (int i = 0; i < DataRepository::serviceDAO.Services.size(); i++) {
				if (serviceString == DataRepository::serviceDAO.Services[i].Title) {
					serviceId = DataRepository::serviceDAO.Services[i].Id;
					break;
				}
			}


			int patientId = stoi(msclr::interop::marshal_as<std::string>(dataGridViewPatients->SelectedRows[0]->Cells[0]->Value->ToString()));

			Ticket ticket;
			ticket.Id = DataRepository::ticketDAO.GetNewId();
			ticket.PatientCardId = patientId;
			ticket.ServiceId = serviceId;
			ticket.DateTime = ticketDate;
			ticket.Status = Ticket::Stat::Wait;
			
			DataRepository::ticketDAO.Tickets.push_back(ticket);
			DataRepository::ticketDAO.SaveTickets();
			this->Hide();
		}
	}
private: System::Void comboBoxServices_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	string serviceString = msclr::interop::marshal_as<std::string>(comboBoxServices->Text);
	for (int i = 0; i < DataRepository::serviceDAO.Services.size(); i++) {
		if (serviceString == DataRepository::serviceDAO.Services[i].Title) {

			PriceLabel->Text = gcnew String(to_string(DataRepository::serviceDAO.Services[i].Price).c_str());
			PriceLabel->Text += " b.r.";
			break;
		}
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vector<PatientCard> search_cards;
	for (int i = 0; i < DataRepository::patientCardDAO.PatientCards.size(); i++)
	{
		if ((gcnew String(DataRepository::patientCardDAO.PatientCards[i].Surname.c_str()))->ToLower()->Contains(textBox1->Text->ToLower())) {
			search_cards.push_back(DataRepository::patientCardDAO.PatientCards[i]);
		}
	}
	FillPatients(search_cards);
}
};
}
