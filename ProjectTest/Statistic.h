#pragma once
#include <vector>
#include "DataRepository.h"

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
			
			vector<int> months = {0,0,0,0,0,0,0,0,0,0,0,0};

			for (int i = 0; i < DataRepository::ticketDAO.Tickets.size(); i++) {
				months[DataRepository::ticketDAO.Tickets[i].DateTime.Months - 1]++;
			}


			chart1->Series["Months"]->Points->AddY((double)months[0]);
			chart1->Series["Months"]->Points->AddY((double)months[1]);
			chart1->Series["Months"]->Points->AddY((double)months[2]);
			chart1->Series["Months"]->Points->AddY((double)months[3]);
			chart1->Series["Months"]->Points->AddY((double)months[4]);
			chart1->Series["Months"]->Points->AddY((double)months[5]);
			chart1->Series["Months"]->Points->AddY((double)months[6]);
			chart1->Series["Months"]->Points->AddY((double)months[7]);
			chart1->Series["Months"]->Points->AddY((double)months[8]);
			chart1->Series["Months"]->Points->AddY((double)months[9]);
			chart1->Series["Months"]->Points->AddY((double)months[10]);
			chart1->Series["Months"]->Points->AddY((double)months[11]);

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
			series1->Legend = L"Legend1";
			series1->Name = L"Months";
			series1->YValuesPerPoint = 2;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(983, 416);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// Statistic
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1007, 573);
			this->Controls->Add(this->chart1);
			this->Name = L"Statistic";
			this->Text = L"Statistic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
