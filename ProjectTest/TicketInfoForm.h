#pragma once

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
	private: int ticket_ID=0;
	public:
		TicketInfoForm(int ticket_id)
		{
			InitializeComponent();
			ticket_ID = ticket_id;
			//
			//TODO: добавьте код конструктора
			//
		}
	public: void ShowData() {
		//
		dateTimePicker->Value = DateTime(DataRepository::ticketDAO.Tickets[ticket_ID].DateTime.Years, DataRepository::ticketDAO.Tickets[ticket_ID].DateTime.Months, DataRepository::ticketDAO.Tickets[ticket_ID].DateTime.Days);
		//
		
		// 
		//
		int patient_id = DataRepository::ticketDAO.Tickets[ticket_ID].PatientCardId;
		int service_id = DataRepository::ticketDAO.Tickets[ticket_ID].ServiceId;
		String^ id = gcnew String(to_string(DataRepository::ticketDAO.Tickets[ticket_ID].Id).c_str());
		String^ Name = gcnew String(DataRepository::patientCardDAO.PatientCards[patient_id].Name.c_str());
		String^ Surname = gcnew String(DataRepository::patientCardDAO.PatientCards[patient_id].Surname.c_str());
		String^ Status = gcnew String(DataRepository::ticketDAO.Tickets[ticket_ID].StatusToString().c_str());
		String^ time = gcnew String(DataRepository::ticketDAO.Tickets[ticket_ID].DateTime.TimeToString().c_str());
		String^ serv = gcnew String(DataRepository::serviceDAO.Services[service_id].Title.c_str());
		dataGridViewPatients->Rows->Add(id, Name, Surname, serv, time, Status);
		//
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
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			// 
			// MinutesCb
			// 
			this->MinutesCb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->MinutesCb->FormattingEnabled = true;
			this->MinutesCb->Location = System::Drawing::Point(339, 99);
			this->MinutesCb->Name = L"MinutesCb";
			this->MinutesCb->Size = System::Drawing::Size(62, 24);
			this->MinutesCb->TabIndex = 18;
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
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(187, 244);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(214, 24);
			this->comboBox1->TabIndex = 29;
			// 
			// TicketInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 586);
			this->Controls->Add(this->comboBox1);
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
};
}
