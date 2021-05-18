#pragma once
#include <msclr\marshal_cppstd.h>
#include "DataRepository.h"
#include "ExceptionBoxForm.h"
#include "Service.h"
namespace ProjectTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ AddServiceForm
	/// </summary>
	public ref class AddServiceForm : public System::Windows::Forms::Form
	{
	public:
		AddServiceForm(void)
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
		~AddServiceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ AddService_Button;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddServiceForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->AddService_Button = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(110, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TItle:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(105, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Price:";
			// 
			// AddService_Button
			// 
			this->AddService_Button->Location = System::Drawing::Point(157, 122);
			this->AddService_Button->Name = L"AddService_Button";
			this->AddService_Button->Size = System::Drawing::Size(94, 33);
			this->AddService_Button->TabIndex = 2;
			this->AddService_Button->Text = L"Add";
			this->AddService_Button->UseVisualStyleBackColor = true;
			this->AddService_Button->Click += gcnew System::EventHandler(this, &AddServiceForm::AddService_Button_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(172, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 22);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(172, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(79, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(258, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"б. р.";
			// 
			// AddServiceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(399, 181);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->AddService_Button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddServiceForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dental Clinic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void AddService_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	string title = msclr::interop::marshal_as<std::string>(textBox1->Text);
	float price;
	try {
		price = stof(msclr::interop::marshal_as<std::string>(textBox2->Text));
	}
	catch(exception ex) {
		ExceptionBoxForm("Enter correct price!").ShowDialog();
		return;
	}

	if (title.size() == 0)
	{
		ExceptionBoxForm("Enter correct title!").ShowDialog();
	}
	else if(price < 0)
	{
		ExceptionBoxForm("Enter correct price!").ShowDialog();
	}
	else
	{
		Service service;
		service.Price = price;
		service.Title = title;
		service.Id = DataRepository::serviceDAO.GetNewId();
		DataRepository::serviceDAO.Services.push_back(service);
		DataRepository::serviceDAO.SaveServices();
		this->Hide();
	}
	
}
};
}
