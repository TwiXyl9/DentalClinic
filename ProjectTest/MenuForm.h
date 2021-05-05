#pragma once
#include "PatientBaseForm.h"
#include "ServicesForm.h"

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
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
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




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ PatientSearchBox;




	private: System::Windows::Forms::Button^ PatientBase_Button;
	private: System::Windows::Forms::Button^ ServicesList_Button;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PatientSearchBox = (gcnew System::Windows::Forms::TextBox());
			this->PatientBase_Button = (gcnew System::Windows::Forms::Button());
			this->ServicesList_Button = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PatientGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(34, 204);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(179, 22);
			this->dateTimePicker->TabIndex = 5;
			// 
			// PatientGridView
			// 
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
			this->PatientGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column3, this->Column2
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
			this->PatientGridView->Size = System::Drawing::Size(377, 424);
			this->PatientGridView->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(229, 209);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Поиск: ";
			// 
			// PatientSearchBox
			// 
			this->PatientSearchBox->Location = System::Drawing::Point(281, 206);
			this->PatientSearchBox->Name = L"PatientSearchBox";
			this->PatientSearchBox->Size = System::Drawing::Size(130, 22);
			this->PatientSearchBox->TabIndex = 9;
			this->PatientSearchBox->TextChanged += gcnew System::EventHandler(this, &MenuForm::PatientSearchBox_TextChanged);
			// 
			// PatientBase_Button
			// 
			this->PatientBase_Button->Location = System::Drawing::Point(34, 33);
			this->PatientBase_Button->Name = L"PatientBase_Button";
			this->PatientBase_Button->Size = System::Drawing::Size(377, 53);
			this->PatientBase_Button->TabIndex = 10;
			this->PatientBase_Button->Text = L"База Пользователей";
			this->PatientBase_Button->UseVisualStyleBackColor = true;
			this->PatientBase_Button->Click += gcnew System::EventHandler(this, &MenuForm::PatientBase_Button_Click_1);
			// 
			// ServicesList_Button
			// 
			this->ServicesList_Button->Location = System::Drawing::Point(34, 107);
			this->ServicesList_Button->Name = L"ServicesList_Button";
			this->ServicesList_Button->Size = System::Drawing::Size(377, 55);
			this->ServicesList_Button->TabIndex = 11;
			this->ServicesList_Button->Text = L"Список услуг";
			this->ServicesList_Button->UseVisualStyleBackColor = true;
			this->ServicesList_Button->Click += gcnew System::EventHandler(this, &MenuForm::ServicesList_Button_Click);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Имя";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Фамилия";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Статус";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 686);
			this->Controls->Add(this->ServicesList_Button);
			this->Controls->Add(this->PatientBase_Button);
			this->Controls->Add(this->PatientSearchBox);
			this->Controls->Add(this->label1);
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
			this->PerformLayout();

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
private: System::Void PatientSearchBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
};
}
