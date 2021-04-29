#pragma once
#include "PatientBaseForm.h"

namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ PatientBase_Button;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->PatientBase_Button = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// PatientBase_Button
			// 
			this->PatientBase_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PatientBase_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PatientBase_Button->Location = System::Drawing::Point(12, 70);
			this->PatientBase_Button->Name = L"PatientBase_Button";
			this->PatientBase_Button->Size = System::Drawing::Size(150, 35);
			this->PatientBase_Button->TabIndex = 1;
			this->PatientBase_Button->Text = L"Patient Base";
			this->PatientBase_Button->UseVisualStyleBackColor = true;
			this->PatientBase_Button->Click += gcnew System::EventHandler(this, &MenuForm::PatientBase_Button_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(168, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(324, 71);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 35);
			this->button3->TabIndex = 3;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 122);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(834, 404);
			this->listBox1->TabIndex = 4;
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(858, 553);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->PatientBase_Button);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PatientBase_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		PatientBaseForm patientBaseForm;
		this->Hide();
		patientBaseForm.ShowDialog();
		this->Show();
	}
};
}
