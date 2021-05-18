#pragma once
#include "PatientBaseForm.h"
#include "ServicesForm.h"
#include "PatientCardDAO.h"
#include "DataRepository.h"
#include "AddTicketForm.h"
#include "PatientСard.h"
#include "Service.h"

namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
			DataRepository::patientCardDAO.LoadPatientCards();
			DataRepository::serviceDAO.LoadServices();
			DataRepository::ticketDAO.LoadTickets();
			ShowData();
			//
			//TODO: добавьте код конструктора
			//
		}


	public:
		void ShowData() {
			PatientGridView->Rows->Clear();
			DateAndTime chooseDate = DateAndTime::ToDateAndTime(dateTimePicker->Value);

			for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
			{
				if (DataRepository::ticketDAO.Tickets[i].DateTime.Years==chooseDate.Years && DataRepository::ticketDAO.Tickets[i].DateTime.Months == chooseDate.Months && DataRepository::ticketDAO.Tickets[i].DateTime.Days == chooseDate.Days)
				{
					PatientCard patientCard;
					for (int j = 0; j < DataRepository::patientCardDAO.PatientCards.size(); j++)
					{
						if (DataRepository::patientCardDAO.PatientCards[j].Id == DataRepository::ticketDAO.Tickets[i].PatientCardId)
						{
							patientCard = DataRepository::patientCardDAO.PatientCards[j];
							break;
						}
					}


					Service service;
					for (int j = 0; j < DataRepository::serviceDAO.Services.size(); j++)
					{
						if (DataRepository::serviceDAO.Services[j].Id == DataRepository::ticketDAO.Tickets[i].ServiceId)
						{
							service = DataRepository::serviceDAO.Services[j];
							break;
						}
					}


					String^ id = gcnew String(to_string(DataRepository::ticketDAO.Tickets[i].Id).c_str());
					String^ Name = gcnew String(patientCard.Name.c_str());
					String^ Surname = gcnew String(patientCard.Surname.c_str());
					String^ Status = gcnew String(to_string(DataRepository::ticketDAO.Tickets[i].IsUsed).c_str());
					String^ time = gcnew String(DataRepository::ticketDAO.Tickets[i].DateTime.TimeToString().c_str());
					String^ serv = gcnew String(service.Title.c_str());
					PatientGridView->Rows->Add(id, Name, Surname, serv, time ,Status);
				}
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
/// 
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	protected:







	private: System::Windows::Forms::DataGridView^ PatientGridView;










	private: System::Windows::Forms::Button^ PatientBase_Button;
	private: System::Windows::Forms::Button^ ServicesList_Button;



	private: System::Windows::Forms::Button^ addTicket;
	private: System::Windows::Forms::Button^ removeTicket;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdColum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ServiceColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;






























	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->PatientGridView = (gcnew System::Windows::Forms::DataGridView());
			this->PatientBase_Button = (gcnew System::Windows::Forms::Button());
			this->ServicesList_Button = (gcnew System::Windows::Forms::Button());
			this->addTicket = (gcnew System::Windows::Forms::Button());
			this->removeTicket = (gcnew System::Windows::Forms::Button());
			this->IdColum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ServiceColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PatientGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(34, 200);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(179, 22);
			this->dateTimePicker->TabIndex = 5;
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &MenuForm::dateTimePicker_ValueChanged);
			// 
			// PatientGridView
			// 
			this->PatientGridView->AllowUserToAddRows = false;
			this->PatientGridView->AllowUserToDeleteRows = false;
			this->PatientGridView->AllowUserToResizeColumns = false;
			this->PatientGridView->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->PatientGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->PatientGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PatientGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->IdColum,
					this->Column1, this->Column3, this->ServiceColumn, this->TimeColumn, this->Column2
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->PatientGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->PatientGridView->Location = System::Drawing::Point(34, 250);
			this->PatientGridView->Name = L"PatientGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->PatientGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->PatientGridView->RowHeadersWidth = 51;
			this->PatientGridView->RowTemplate->Height = 24;
			this->PatientGridView->Size = System::Drawing::Size(492, 424);
			this->PatientGridView->TabIndex = 7;
			// 
			// PatientBase_Button
			// 
			this->PatientBase_Button->Location = System::Drawing::Point(34, 33);
			this->PatientBase_Button->Name = L"PatientBase_Button";
			this->PatientBase_Button->Size = System::Drawing::Size(492, 53);
			this->PatientBase_Button->TabIndex = 10;
			this->PatientBase_Button->Text = L"Patients Base";
			this->PatientBase_Button->UseVisualStyleBackColor = true;
			this->PatientBase_Button->Click += gcnew System::EventHandler(this, &MenuForm::PatientBase_Button_Click_1);
			// 
			// ServicesList_Button
			// 
			this->ServicesList_Button->Location = System::Drawing::Point(34, 107);
			this->ServicesList_Button->Name = L"ServicesList_Button";
			this->ServicesList_Button->Size = System::Drawing::Size(492, 55);
			this->ServicesList_Button->TabIndex = 11;
			this->ServicesList_Button->Text = L"List of Services";
			this->ServicesList_Button->UseVisualStyleBackColor = true;
			this->ServicesList_Button->Click += gcnew System::EventHandler(this, &MenuForm::ServicesList_Button_Click);
			// 
			// addTicket
			// 
			this->addTicket->Location = System::Drawing::Point(34, 680);
			this->addTicket->Name = L"addTicket";
			this->addTicket->Size = System::Drawing::Size(179, 53);
			this->addTicket->TabIndex = 12;
			this->addTicket->Text = L"Add Ticket";
			this->addTicket->UseVisualStyleBackColor = true;
			this->addTicket->Click += gcnew System::EventHandler(this, &MenuForm::addTicket_Click);
			// 
			// removeTicket
			// 
			this->removeTicket->Location = System::Drawing::Point(347, 680);
			this->removeTicket->Name = L"removeTicket";
			this->removeTicket->Size = System::Drawing::Size(179, 53);
			this->removeTicket->TabIndex = 13;
			this->removeTicket->Text = L"Remove Ticket";
			this->removeTicket->UseVisualStyleBackColor = true;
			this->removeTicket->Click += gcnew System::EventHandler(this, &MenuForm::removeTicket_Click);
			// 
			// IdColum
			// 
			this->IdColum->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->IdColum->HeaderText = L"Ticket Id";
			this->IdColum->MinimumWidth = 6;
			this->IdColum->Name = L"IdColum";
			this->IdColum->ReadOnly = true;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Name";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Surname";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// ServiceColumn
			// 
			this->ServiceColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ServiceColumn->HeaderText = L"Service";
			this->ServiceColumn->MinimumWidth = 6;
			this->ServiceColumn->Name = L"ServiceColumn";
			this->ServiceColumn->ReadOnly = true;
			// 
			// TimeColumn
			// 
			this->TimeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->TimeColumn->HeaderText = L"Time";
			this->TimeColumn->MinimumWidth = 6;
			this->TimeColumn->Name = L"TimeColumn";
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Status";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 770);
			this->Controls->Add(this->removeTicket);
			this->Controls->Add(this->addTicket);
			this->Controls->Add(this->ServicesList_Button);
			this->Controls->Add(this->PatientBase_Button);
			this->Controls->Add(this->PatientGridView);
			this->Controls->Add(this->dateTimePicker);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PatientGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void PatientBase_Button_Click_1(System::Object^ sender, System::EventArgs^ e) {
		PatientBaseForm patientBaseForm;
		this->Hide();
		patientBaseForm.ShowDialog();
		this->Show();
	}
	private: System::Void ServicesList_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		ServicesForm servicesForm;
		this->Hide();
		servicesForm.ShowDialog();
		this->Show();
	}
private: System::Void addTicket_Click(System::Object^ sender, System::EventArgs^ e) {
	AddTicketForm().ShowDialog();
	ShowData();
}
private: System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	ShowData();
}
private: System::Void removeTicket_Click(System::Object^ sender, System::EventArgs^ e) {
	int ticketId = stoi(msclr::interop::marshal_as<std::string>(PatientGridView->SelectedRows[0]->Cells[0]->Value->ToString()));
	int idForDel = 0;
	for (size_t i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
	{
		if (DataRepository::ticketDAO.Tickets[i].Id == ticketId) 
		{
			idForDel = i;
			break;
		}
	}
	DataRepository::ticketDAO.Tickets.erase(DataRepository::ticketDAO.Tickets.begin() + idForDel);
	DataRepository::ticketDAO.SaveTickets();
	ShowData();

}
};
}
