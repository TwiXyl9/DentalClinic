#pragma once
#include <vector>
#include "DataRepository.h"
#include "Ticket.h"
#include <algorithm>
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Statistic
	/// </summary>
	public ref class Statistic : public System::Windows::Forms::Form
	{
	public:
		Statistic(void)
		{
			InitializeComponent();
			ShowData();

		}
	public: void ShowData() {
		NumOfPatients_label->Text = DataRepository::patientCardDAO.PatientCards.size().ToString();
		AllTickets_label->Text = DataRepository::ticketDAO.Tickets.size().ToString();
		int numOfOverdue = 0;
		int numOfDone = 0;
		int numberOfWaiting = 0;
		for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
		{
			if (DataRepository::ticketDAO.Tickets[i].Status == Ticket::Stat::Done)numOfDone++;
			if (DataRepository::ticketDAO.Tickets[i].Status == Ticket::Stat::Overdue)numOfOverdue++;
			if (DataRepository::ticketDAO.Tickets[i].Status == Ticket::Stat::Wait)numberOfWaiting++;
		}
		DoneTIckets_label->Text = numOfDone.ToString();
		OverdueTickets_label->Text = numOfOverdue.ToString();
		WaitingTickets_lable->Text = numberOfWaiting.ToString();


		int maxMonth = GetMostPopularMonth();
		String^ maxMonthString = gcnew String(MonthToString(maxMonth).c_str());

		Month_label->Text = maxMonthString;
		 
	}


	public: int GetMostPopularMonth() {
		vector<int> months = { 0,0,0,0,0,0,0,0,0,0,0,0 };

		for each (auto ticket in DataRepository::ticketDAO.Tickets) {
			months[ticket.DateTime.Months-1]++;
		}

		int maxMonth = -1;
		int maxValue = 0;
		for (int i = 0; i < months.size(); i++) {
			if (months[i] > maxValue) {
				maxValue = months[i];
				maxMonth = i;
			}
		}

		return maxMonth;
	}

	/*public: vector<string> GetPopularMonths() {
		vector<int> months = { 0,0,0,0,0,0,0,0,0,0,0,0 };
		vector<string> popularMonths;
		for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++)
		{
			months[DataRepository::ticketDAO.Tickets[i].DateTime.Months]++;
		}
		int idOfMostPopular = 0;
		int countOfMostPopular = 0;
		for (int i = 0; i < months.size(); i++)
		{
			if (months[i] > countOfMostPopular) {
				countOfMostPopular = months[i];
				idOfMostPopular = i;
			}
		}
		return popularMonths;
	}*/
	public: string MonthToString(int id) {
		switch (id)
		{
		case 0: return "January";
		case 1: return "February";
		case 2: return "March";
		case 3: return "April";
		case 4: return "May";
		case 5: return "June";
		case 6: return "July";
		case 7: return "August";
		case 8: return "September";
		case 9: return "October";
		case 10: return "November";
		case 11: return "December";
		default:
			break;
		}
	}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Statistic()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ NumOfPatients_label;
	private: System::Windows::Forms::Label^ AllTickets_label;
	protected:


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ DoneTIckets_label;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ OverdueTickets_label;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ Month_label;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::Label^ WaitingTickets_lable;
private: System::Windows::Forms::Label^ label2;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Statistic::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NumOfPatients_label = (gcnew System::Windows::Forms::Label());
			this->AllTickets_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->DoneTIckets_label = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->OverdueTickets_label = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Month_label = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->WaitingTickets_lable = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(65, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Number of patients:";
			// 
			// NumOfPatients_label
			// 
			this->NumOfPatients_label->AutoSize = true;
			this->NumOfPatients_label->Location = System::Drawing::Point(203, 41);
			this->NumOfPatients_label->Name = L"NumOfPatients_label";
			this->NumOfPatients_label->Size = System::Drawing::Size(16, 17);
			this->NumOfPatients_label->TabIndex = 1;
			this->NumOfPatients_label->Text = L"0";
			// 
			// AllTickets_label
			// 
			this->AllTickets_label->AutoSize = true;
			this->AllTickets_label->Location = System::Drawing::Point(203, 79);
			this->AllTickets_label->Name = L"AllTickets_label";
			this->AllTickets_label->Size = System::Drawing::Size(16, 17);
			this->AllTickets_label->TabIndex = 3;
			this->AllTickets_label->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(156, 17);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Total number of tickets:";
			// 
			// DoneTIckets_label
			// 
			this->DoneTIckets_label->AutoSize = true;
			this->DoneTIckets_label->Location = System::Drawing::Point(203, 118);
			this->DoneTIckets_label->Name = L"DoneTIckets_label";
			this->DoneTIckets_label->Size = System::Drawing::Size(16, 17);
			this->DoneTIckets_label->TabIndex = 5;
			this->DoneTIckets_label->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(39, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(158, 17);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Number of done tickets:";
			// 
			// OverdueTickets_label
			// 
			this->OverdueTickets_label->AutoSize = true;
			this->OverdueTickets_label->Location = System::Drawing::Point(203, 154);
			this->OverdueTickets_label->Name = L"OverdueTickets_label";
			this->OverdueTickets_label->Size = System::Drawing::Size(16, 17);
			this->OverdueTickets_label->TabIndex = 7;
			this->OverdueTickets_label->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(19, 154);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(178, 17);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Number of overdue tickets:";
			// 
			// Month_label
			// 
			this->Month_label->AutoSize = true;
			this->Month_label->Location = System::Drawing::Point(203, 220);
			this->Month_label->Name = L"Month_label";
			this->Month_label->Size = System::Drawing::Size(16, 17);
			this->Month_label->TabIndex = 9;
			this->Month_label->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(31, 220);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(166, 17);
			this->label10->TabIndex = 8;
			this->label10->Text = L"The most popular month:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->WaitingTickets_lable);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->Month_label);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->NumOfPatients_label);
			this->groupBox1->Controls->Add(this->OverdueTickets_label);
			this->groupBox1->Controls->Add(this->AllTickets_label);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->DoneTIckets_label);
			this->groupBox1->Location = System::Drawing::Point(53, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(307, 270);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Statistic";
			// 
			// WaitingTickets_lable
			// 
			this->WaitingTickets_lable->AutoSize = true;
			this->WaitingTickets_lable->Location = System::Drawing::Point(203, 187);
			this->WaitingTickets_lable->Name = L"WaitingTickets_lable";
			this->WaitingTickets_lable->Size = System::Drawing::Size(16, 17);
			this->WaitingTickets_lable->TabIndex = 11;
			this->WaitingTickets_lable->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 187);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Number of waiting tickets:";
			// 
			// Statistic
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 387);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Statistic";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
