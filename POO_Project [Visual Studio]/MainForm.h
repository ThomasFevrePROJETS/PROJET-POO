#pragma once

#include "BackForm.h"

namespace POOProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_bienvenue;
	private: System::Windows::Forms::Label^ label_prenom;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label_nom;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ button_connecter;

	private: System::Windows::Forms::Label^ label_datetime;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label_date;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label_bienvenue = (gcnew System::Windows::Forms::Label());
			this->label_prenom = (gcnew System::Windows::Forms::Label());
			this->label_nom = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button_connecter = (gcnew System::Windows::Forms::Button());
			this->label_datetime = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label_date = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_bienvenue
			// 
			this->label_bienvenue->BackColor = System::Drawing::Color::Transparent;
			this->label_bienvenue->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_bienvenue->Font = (gcnew System::Drawing::Font(L"Cuprum", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_bienvenue->ForeColor = System::Drawing::Color::White;
			this->label_bienvenue->Location = System::Drawing::Point(3, 0);
			this->label_bienvenue->Name = L"label_bienvenue";
			this->label_bienvenue->Size = System::Drawing::Size(612, 50);
			this->label_bienvenue->TabIndex = 0;
			this->label_bienvenue->Text = L"Bienvenue";
			this->label_bienvenue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_prenom
			// 
			this->label_prenom->AutoSize = true;
			this->label_prenom->BackColor = System::Drawing::Color::Transparent;
			this->label_prenom->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_prenom->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_prenom->ForeColor = System::Drawing::Color::White;
			this->label_prenom->Location = System::Drawing::Point(188, 0);
			this->label_prenom->Name = L"label_prenom";
			this->label_prenom->Size = System::Drawing::Size(179, 45);
			this->label_prenom->TabIndex = 1;
			this->label_prenom->Text = L"Prénom";
			this->label_prenom->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_nom
			// 
			this->label_nom->AutoSize = true;
			this->label_nom->BackColor = System::Drawing::Color::Transparent;
			this->label_nom->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_nom->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_nom->ForeColor = System::Drawing::Color::White;
			this->label_nom->Location = System::Drawing::Point(3, 0);
			this->label_nom->Name = L"label_nom";
			this->label_nom->Size = System::Drawing::Size(179, 45);
			this->label_nom->TabIndex = 2;
			this->label_nom->Text = L"Nom";
			this->label_nom->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Black;
			this->richTextBox1->Location = System::Drawing::Point(188, 48);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(179, 49);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"Pernaut";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->ForeColor = System::Drawing::Color::Black;
			this->richTextBox2->Location = System::Drawing::Point(3, 48);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(179, 49);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"Jean-Pierre";
			// 
			// button_connecter
			// 
			this->button_connecter->BackColor = System::Drawing::Color::MidnightBlue;
			this->button_connecter->Cursor = System::Windows::Forms::Cursors::Default;
			this->button_connecter->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button_connecter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_connecter->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_connecter->ForeColor = System::Drawing::Color::White;
			this->button_connecter->Location = System::Drawing::Point(244, 253);
			this->button_connecter->Name = L"button_connecter";
			this->button_connecter->Size = System::Drawing::Size(123, 33);
			this->button_connecter->TabIndex = 5;
			this->button_connecter->Text = L"Connection";
			this->button_connecter->UseVisualStyleBackColor = false;
			this->button_connecter->Click += gcnew System::EventHandler(this, &MyForm::button_connecter_Click);
			// 
			// label_datetime
			// 
			this->label_datetime->AutoSize = true;
			this->label_datetime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_datetime->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_datetime->ForeColor = System::Drawing::Color::White;
			this->label_datetime->Location = System::Drawing::Point(3, 50);
			this->label_datetime->Name = L"label_datetime";
			this->label_datetime->Size = System::Drawing::Size(612, 50);
			this->label_datetime->TabIndex = 6;
			this->label_datetime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::LightSkyBlue;
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.7F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox3->ForeColor = System::Drawing::Color::Black;
			this->richTextBox3->Location = System::Drawing::Point(373, 48);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(180, 49);
			this->richTextBox3->TabIndex = 7;
			this->richTextBox3->Text = L"maitre du monde cryptilien";
			// 
			// label_date
			// 
			this->label_date->AutoSize = true;
			this->label_date->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_date->Font = (gcnew System::Drawing::Font(L"Cuprum", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_date->ForeColor = System::Drawing::Color::White;
			this->label_date->Location = System::Drawing::Point(373, 0);
			this->label_date->Name = L"label_date";
			this->label_date->Size = System::Drawing::Size(180, 45);
			this->label_date->TabIndex = 8;
			this->label_date->Text = L"Poste";
			this->label_date->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->label_nom, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_date, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_prenom, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox1, 1, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(33, 106);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(556, 100);
			this->tableLayoutPanel1->TabIndex = 10;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->label_datetime, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label_bienvenue, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(618, 100);
			this->tableLayoutPanel2->TabIndex = 11;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(618, 317);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button_connecter);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_connecter_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ connectionString = "Data Source=.;Initial Catalog=ProjetPOO;Integrated Security=True";
		System::String^ querystring = "SELECT * FROM [ProjetPOO].[dbo].[Employe] WHERE nom = @checknom AND prenom = @checkprenom AND poste = @checkposte;";

		System::Data::SqlClient::SqlConnection^ connection = gcnew System::Data::SqlClient::SqlConnection(connectionString);
		System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, connection);
		
		command->Parameters->AddWithValue("@checknom", this->richTextBox1->Text);
		command->Parameters->AddWithValue("@checkprenom", this->richTextBox2->Text);
		command->Parameters->AddWithValue("@checkposte", this->richTextBox3->Text);
		
		System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter();
		adapter->SelectCommand = command;

		DataSet^ dataset = gcnew DataSet();
		connection->Open();
		adapter-> Fill(dataset, "Employe");
		connection->Close();

		if (dataset->Tables[0]->Rows->Count == 0)
		{
			MessageBox::Show("You are not registered.", "Error");
		}
		else
		{
			this->Hide();
			// Create a new instance of the form.
			BackForm::Form^ BackForm = gcnew BackForm::Form;
			BackForm->ShowDialog();
			this->Show();
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->label_datetime->Text = Convert::ToString(System::DateTime::Now);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		this->label_datetime->Text = Convert::ToString(System::DateTime::Now);
	}
};
}

