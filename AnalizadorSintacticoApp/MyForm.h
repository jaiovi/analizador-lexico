#pragma once
#include <string>
#include <vector>
#include "Scanner.h"
#include "Token.h"

#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;

namespace AnalizadorSintacticoApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(397, 602);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsTab = true;
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Ubuntu", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(25, 78);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(391, 497);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->AcceptsTab = true;
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(614, 581);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(226, 44);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Ubuntu", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(449, 78);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(391, 497);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(872, 656);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void appendText(RichTextBox^ box, String^ text, Color color)
	{
		box->SelectionStart = box->TextLength;
		box->SelectionLength = 0;

		box->SelectionColor = color;
		box->AppendText(text);
		box->SelectionColor = box->ForeColor;
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		std::string codigo = marshal_as<std::string>(textBox1->Text);
		Scanner scan = Scanner(codigo);

		std::vector<Token> tabla_simbolos = scan.escanear();
		std::string str;

		richTextBox1->Clear();

		for (Token tk : tabla_simbolos) {
			str = tk.cadena() + " ";

			if (tk.tipo() == "tk_program" || 
				tk.tipo() == "tk_variable" ||
				tk.tipo() == "tk_begin" ||
				tk.tipo() == "tk_end" ||
				tk.tipo() == "tk_write" ||
				tk.tipo() == "tk_read") {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::DarkViolet);

			} else if (
				tk.tipo() == "tk_int" ||
				tk.tipo() == "tk_float") {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::MediumVioletRed);

			} else if (
				tk.tipo() == "tk_suma" ||
				tk.tipo() == "tk_resta" ||
				tk.tipo() == "tk_mult" ||
				tk.tipo() == "tk_div") {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::PaleVioletRed);

			} else if (
				tk.tipo() == "tk_dos_puntos" ||
				tk.tipo() == "tk_punto_coma" ||
				tk.tipo() == "tk_coma" ||
				tk.tipo() == "tk_asign") {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::SaddleBrown);

			} else if (
				tk.tipo() == "tk_numero_flotante" ||
				tk.tipo() == "tk_numero_entero") {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::Black);

			} else {

				appendText(richTextBox1, gcnew String(str.c_str()), System::Drawing::Color::Orange);

			}
		}

	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}