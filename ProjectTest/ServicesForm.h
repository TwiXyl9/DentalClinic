#pragma once
#include "AddServiceForm.h"
#include "DataRepository.h"
#include "ServiceInfoForm.h"

namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ServicesForm
	/// </summary>
	public ref class ServicesForm : public System::Windows::Forms::Form
	{
	public:
		ServicesForm(void)
		{
			InitializeComponent();
			ShowData();
			//
			//TODO: добавьте код конструктора
			//
		}


	public:
		void ShowData() {

			dataGridView1->Rows->Clear();

			for (int i = 0; i < DataRepository::serviceDAO.Services.size(); i++)
			{
				String^ Title = gcnew String(DataRepository::serviceDAO.Services[i].Title.c_str());
				String^ Price = gcnew String(to_string(DataRepository::serviceDAO.Services[i].Price).c_str());
				dataGridView1->Rows->Add(Title, Price);
			}
		}


		/*String^ Title = gcnew String(DataRepository::serviceDAO.Services[i].Title.c_str());
		String^ Price = gcnew String(to_string(DataRepository::serviceDAO.Services[i].Price).c_str());
		dataGridView1->Rows->Add(Title, Price);*/
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ServicesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private: System::Windows::Forms::Button^ AddService_Button;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServicesForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->AddService_Button = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(36, 124);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(503, 282);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ServicesForm::dataGridView1_CellContentClick);
			// 
			// AddService_Button
			// 
			this->AddService_Button->Location = System::Drawing::Point(36, 41);
			this->AddService_Button->Name = L"AddService_Button";
			this->AddService_Button->Size = System::Drawing::Size(503, 49);
			this->AddService_Button->TabIndex = 2;
			this->AddService_Button->Text = L"Add";
			this->AddService_Button->UseVisualStyleBackColor = true;
			this->AddService_Button->Click += gcnew System::EventHandler(this, &ServicesForm::AddService_Button_Click);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Title:";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Price (b.r.):";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// ServicesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 502);
			this->Controls->Add(this->AddService_Button);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ServicesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AddService_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		AddServiceForm addServiceForm;
		addServiceForm.ShowDialog();
		ShowData();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	ServiceInfoForm(e->RowIndex).ShowDialog();
	ShowData();
}
};
}
