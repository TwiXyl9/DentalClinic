#pragma once
#include "PatientInfoForm.h"
#include "AddPatientForm.h"
#include "AddPatientForm.h"
#include "PatientCardDAO.h"
#include "PatientСard.h"
#include <string>

namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class PatientBaseForm : public System::Windows::Forms::Form
	{
	public:
		PatientBaseForm(void)
		{
			InitializeComponent();
			patientCardDAO = new PatientCardDAO();
			patientCardDAO->LoadPatientCards();
			ShowData();
			
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;

	public: PatientCardDAO* patientCardDAO;
	public:
		void ShowData() {
			for (int i = 0; i < patientCardDAO->PatientCards.size(); i++)
			{				
				String^ Name = gcnew String(patientCardDAO->PatientCards[i].Name.c_str());
				String^ Surname = gcnew String(patientCardDAO->PatientCards[i].Surname.c_str());
				dataGridView1->Rows->Add(i+1, Name, Surname);
			}
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PatientBaseForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ AddPatient_Button;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PatientBaseForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->AddPatient_Button = (gcnew System::Windows::Forms::Button());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID, this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(44, 165);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(405, 334);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PatientBaseForm::dataGridView1_CellContentClick);
			// 
			// AddPatient_Button
			// 
			this->AddPatient_Button->Location = System::Drawing::Point(44, 82);
			this->AddPatient_Button->Name = L"AddPatient_Button";
			this->AddPatient_Button->Size = System::Drawing::Size(405, 43);
			this->AddPatient_Button->TabIndex = 1;
			this->AddPatient_Button->Text = L"Добавить";
			this->AddPatient_Button->UseVisualStyleBackColor = true;
			this->AddPatient_Button->Click += gcnew System::EventHandler(this, &PatientBaseForm::AddPatient_Button_Click);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			this->ID->Width = 125;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Имя:";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Фамилия:";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// PatientBaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 592);
			this->Controls->Add(this->AddPatient_Button);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PatientBaseForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void AddPatient_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		AddPatientForm addPatientForm;
		addPatientForm.ShowDialog();

	}
};
}
 