#pragma once
#include "DataRepository.h"
#include "ExceptionBoxForm.h"
#include "Ticket.h"
#include <msclr\marshal_cppstd.h>
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TicketInfoForm
	/// </summary>
	public ref class TicketInfoForm : public System::Windows::Forms::Form
	{
	public: Ticket* ticket;
	public:
		TicketInfoForm(int ticket_id)
		{
			InitializeComponent();
			FindTicket(ticket_id);
			ShowData();
			//
			//TODO: добавьте код конструктора
			//
		}
	public: void FindTicket(int id) {
		for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
		{
			if (DataRepository::ticketDAO.Tickets[i].Id == id) {
				ticket = &DataRepository::ticketDAO.Tickets[i];
				break;
			}
		}
	}
	public: void FillTime() {
		for (int i = 9; i < 19; i++) {
			HoursCb->Items->Add(i);
		}
		MinutesCb->Items->Add("00");
		MinutesCb->Items->Add("30");
		HoursCb->Text = gcnew String(to_string(ticket->DateTime.Hours).c_str());
		if (ticket->DateTime.Minutes == 0) {
			string minutes = "00";
			MinutesCb->Text = gcnew String(minutes.c_str());
		}
		else {
			MinutesCb->Text = gcnew String(to_string(ticket->DateTime.Minutes).c_str());
		}
	}


	public: void FillServices() {
		Service service;
		comboBoxServices->Items->Clear();
			for (int i = 0; i < DataRepository::serviceDAO.Services.size(); i++) {
				string service_title = DataRepository::serviceDAO.Services[i].Title;
				comboBoxServices->Items->Add(gcnew String(service_title.c_str()));
				if (ticket->ServiceId == DataRepository::serviceDAO.Services[i].Id) service= DataRepository::serviceDAO.Services[i];
			}
			comboBoxServices->Text= gcnew String(service.Title.c_str());
			PriceLabel->Text = gcnew String(to_string(service.Price).c_str());
		}


	public: void SetMinDate() {
		    dateTimePicker->MinDate = DateTime(ticket->DateTime.Years, ticket->DateTime.Months, ticket->DateTime.Days);
			dateTimePicker->Value = DateTime(ticket->DateTime.Years, ticket->DateTime.Months, ticket->DateTime.Days);
		}

	public: void FillStatus() {
		DateTime date = dateTimePicker->Value;
		StatusComboBox->Items->Clear();
		if (date.Date < DateTime::Now ||
			(date.Date == DateTime::Now && stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text)) < DateTime::Now.Hour) ||
			(date.Date == DateTime::Now && stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text)) == DateTime::Now.Hour && stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text)) < DateTime::Now.Minute))
		{
			StatusComboBox->Items->Add(gcnew String(Ticket::StatusToString(Ticket::Stat::Done).c_str()));
			StatusComboBox->Items->Add(gcnew String(Ticket::StatusToString(Ticket::Stat::Overdue).c_str()));
			StatusComboBox->Text = gcnew String(gcnew String(Ticket::StatusToString(Ticket::Stat::Overdue).c_str()));
		}
		else if (DateTime::Now.Hour == stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text)) &&
			DateTime::Now.Minute <= stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text)) + 29 &&
			DateTime::Now.Minute >= stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text)))
		{
			StatusComboBox->Items->Add(gcnew String(Ticket::StatusToString(Ticket::Stat::Processing).c_str()));
			StatusComboBox->Text = gcnew String(gcnew String(Ticket::StatusToString(Ticket::Stat::Processing).c_str()));
		}
		else
		{
			StatusComboBox->Items->Add(gcnew String(Ticket::StatusToString(Ticket::Stat::Wait).c_str()));
			StatusComboBox->Text = gcnew String(gcnew String(Ticket::StatusToString(Ticket::Stat::Wait).c_str()));
		}

	}
	public: void FillPatient() {
		int patient_id = ticket->PatientCardId;
		dataGridViewPatients->Rows->Clear();
		PatientCard patient;
		for (int i = 0; i < DataRepository::patientCardDAO.PatientCards.size(); i++)
		{
			if (DataRepository::patientCardDAO.PatientCards[i].Id == patient_id) {
				patient = DataRepository::patientCardDAO.PatientCards[i];
				break;
			}
		}
		String^ Name = gcnew String(patient.Name.c_str());
		String^ Surname = gcnew String(patient.Surname.c_str());
		String^ Id = gcnew String(to_string(patient.Id).c_str());
		String^ BirthDay = gcnew String((patient.DateOfBirth.ToString()).c_str());
		String^ Phone = gcnew String((patient.Phone).c_str());
		dataGridViewPatients->Rows->Add(Id, Name, Surname, BirthDay, Phone);
		
	}

	public: void ShowData() {
		
		SetMinDate();
		FillTime();
		FillServices();
		FillStatus();
		FillPatient();
	}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TicketInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ PriceLabel;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBoxServices;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dataGridViewPatients;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BirthDay;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::ComboBox^ MinutesCb;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ HoursCb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::ComboBox^ StatusComboBox;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TicketInfoForm::typeid));
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxServices = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewPatients = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BirthDay = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->MinutesCb = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->HoursCb = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->StatusComboBox = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPatients))->BeginInit();
			this->SuspendLayout();
			// 
			// PriceLabel
			// 
			this->PriceLabel->AutoSize = true;
			this->PriceLabel->Location = System::Drawing::Point(187, 209);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(16, 17);
			this->PriceLabel->TabIndex = 26;
			this->PriceLabel->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(123, 209);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 17);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Price:";
			// 
			// comboBoxServices
			// 
			this->comboBoxServices->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxServices->FormattingEnabled = true;
			this->comboBoxServices->Location = System::Drawing::Point(187, 157);
			this->comboBoxServices->Name = L"comboBoxServices";
			this->comboBoxServices->Size = System::Drawing::Size(214, 24);
			this->comboBoxServices->TabIndex = 24;
			this->comboBoxServices->SelectedIndexChanged += gcnew System::EventHandler(this, &TicketInfoForm::comboBoxServices_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(101, 157);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 17);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Services:";
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
			this->dataGridViewPatients->Location = System::Drawing::Point(34, 360);
			this->dataGridViewPatients->Name = L"dataGridViewPatients";
			this->dataGridViewPatients->RowHeadersWidth = 51;
			this->dataGridViewPatients->RowTemplate->Height = 24;
			this->dataGridViewPatients->Size = System::Drawing::Size(478, 80);
			this->dataGridViewPatients->TabIndex = 22;
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
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 340);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 17);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Patients:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(117, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 17);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Date:";
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(187, 44);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(214, 22);
			this->dateTimePicker->TabIndex = 19;
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &TicketInfoForm::dateTimePicker_ValueChanged);
			// 
			// MinutesCb
			// 
			this->MinutesCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->MinutesCb->FormattingEnabled = true;
			this->MinutesCb->Location = System::Drawing::Point(339, 99);
			this->MinutesCb->Name = L"MinutesCb";
			this->MinutesCb->Size = System::Drawing::Size(62, 24);
			this->MinutesCb->TabIndex = 18;
			this->MinutesCb->SelectedIndexChanged += gcnew System::EventHandler(this, &TicketInfoForm::MinutesCb_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(263, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 17);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Minutes:";
			// 
			// HoursCb
			// 
			this->HoursCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->HoursCb->FormattingEnabled = true;
			this->HoursCb->Location = System::Drawing::Point(187, 99);
			this->HoursCb->Name = L"HoursCb";
			this->HoursCb->Size = System::Drawing::Size(62, 24);
			this->HoursCb->TabIndex = 16;
			this->HoursCb->SelectedIndexChanged += gcnew System::EventHandler(this, &TicketInfoForm::HoursCb_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(117, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 17);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Hours:";
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(207, 516);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(146, 46);
			this->Save->TabIndex = 27;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &TicketInfoForm::Save_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(115, 244);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 17);
			this->label7->TabIndex = 28;
			this->label7->Text = L"Status:";
			// 
			// StatusComboBox
			// 
			this->StatusComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->StatusComboBox->FormattingEnabled = true;
			this->StatusComboBox->Location = System::Drawing::Point(187, 244);
			this->StatusComboBox->Name = L"StatusComboBox";
			this->StatusComboBox->Size = System::Drawing::Size(214, 24);
			this->StatusComboBox->TabIndex = 29;
			// 
			// TicketInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 586);
			this->Controls->Add(this->StatusComboBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->PriceLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBoxServices);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridViewPatients);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->MinutesCb);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->HoursCb);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TicketInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPatients))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
private: System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	FillStatus();
}
private: System::Void HoursCb_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	FillStatus();
}
private: System::Void MinutesCb_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	FillStatus();
}
private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
	DateTime selectedDate = dateTimePicker->Value;
	DateAndTime ticketDate = DateAndTime::ToDateAndTime(selectedDate);

	ticketDate.Hours = stoi(msclr::interop::marshal_as<std::string>(HoursCb->Text));
	ticketDate.Minutes = stoi(msclr::interop::marshal_as<std::string>(MinutesCb->Text));
	ticketDate.Seconds = 0;

	for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
	{
		if (DataRepository::ticketDAO.Tickets[i].DateTime.Years == ticketDate.Years && DataRepository::ticketDAO.Tickets[i].DateTime.Days == ticketDate.Days)
		{
			if (DataRepository::ticketDAO.Tickets[i].Id != ticket->Id && DataRepository::ticketDAO.Tickets[i].DateTime.Hours == ticketDate.Hours && DataRepository::ticketDAO.Tickets[i].DateTime.Minutes == ticketDate.Minutes) {
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

	string status_str = msclr::interop::marshal_as<std::string>(StatusComboBox->Text);
	for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
	{
		if (DataRepository::ticketDAO.Tickets[i].Id == ticket->Id) {

			DataRepository::ticketDAO.Tickets[i].Id = DataRepository::ticketDAO.GetNewId();
			DataRepository::ticketDAO.Tickets[i].PatientCardId = ticket->PatientCardId;;
			DataRepository::ticketDAO.Tickets[i].ServiceId = serviceId;
			DataRepository::ticketDAO.Tickets[i].DateTime = ticketDate;
			DataRepository::ticketDAO.Tickets[i].Status = Ticket::StringToStatus(status_str);
			break;
		}
	}
	DataRepository::ticketDAO.SaveTickets();
	this->Hide();
}
};
}
