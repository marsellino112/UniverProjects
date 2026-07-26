#pragma once

namespace BD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OleDb;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->MaximizeBox = false;
			this->conn = gcnew OleDbConnection();
			conn->ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=IS.accdb;";
			try {
				conn->Open();
			}
			catch (OleDbException^ e) {
				MessageBox::Show(e->Message);
				Close();
			}
			auto query = gcnew OleDbCommand(
				"CREATE TABLE student (" +
				"name VARCHAR," +
				"birthday date," +
				"math INT," +
				"info INT," +
				"engl INT"
				");", conn
			);
			//query->ExecuteNonQuery();
			select();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::TextBox^ birthday;
	private: System::Windows::Forms::TextBox^ math;
	private: System::Windows::Forms::TextBox^ info;
	private: System::Windows::Forms::TextBox^ engl;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
		   OleDbConnection^ conn;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->birthday = (gcnew System::Windows::Forms::TextBox());
			this->math = (gcnew System::Windows::Forms::TextBox());
			this->info = (gcnew System::Windows::Forms::TextBox());
			this->engl = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(13, 23);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(729, 491);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 62);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 138);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 28);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Фамилия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"День рожденья";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Математика";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Информатика";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 180);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Английский";
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(124, 24);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(100, 22);
			this->name->TabIndex = 8;
			// 
			// birthday
			// 
			this->birthday->Location = System::Drawing::Point(124, 59);
			this->birthday->Name = L"birthday";
			this->birthday->Size = System::Drawing::Size(100, 22);
			this->birthday->TabIndex = 9;
			// 
			// math
			// 
			this->math->Location = System::Drawing::Point(124, 97);
			this->math->Name = L"math";
			this->math->Size = System::Drawing::Size(100, 22);
			this->math->TabIndex = 10;
			// 
			// info
			// 
			this->info->Location = System::Drawing::Point(124, 135);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(100, 22);
			this->info->TabIndex = 11;
			// 
			// engl
			// 
			this->engl->Location = System::Drawing::Point(124, 174);
			this->engl->Name = L"engl";
			this->engl->Size = System::Drawing::Size(100, 22);
			this->engl->TabIndex = 12;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(13, 100);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 31);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Измененить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(11, 173);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 26);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Сортировать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(11, 21);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(111, 88);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Студенты с указанием фамилии и даты рождения";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(11, 115);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 59);
			this->button6->TabIndex = 16;
			this->button6->Text = L"Отличники по математике";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 180);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(110, 23);
			this->button7->TabIndex = 17;
			this->button7->Text = L"Отличники";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(12, 209);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(110, 61);
			this->button8->TabIndex = 18;
			this->button8->Text = L"Студенты старше 20 лет";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(13, 26);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(111, 29);
			this->button9->TabIndex = 19;
			this->button9->Text = L"Обновить";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->name);
			this->groupBox1->Controls->Add(this->birthday);
			this->groupBox1->Controls->Add(this->math);
			this->groupBox1->Controls->Add(this->engl);
			this->groupBox1->Controls->Add(this->info);
			this->groupBox1->Location = System::Drawing::Point(884, 23);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(231, 205);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поля для ввода";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Location = System::Drawing::Point(749, 23);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(131, 205);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Команды";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->button8);
			this->groupBox3->Location = System::Drawing::Point(749, 234);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(131, 280);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Запросы";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox4->Controls->Add(this->richTextBox1);
			this->groupBox4->Location = System::Drawing::Point(886, 234);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(229, 280);
			this->groupBox4->TabIndex = 23;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Справка";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(6, 21);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(216, 249);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->ClientSize = System::Drawing::Size(1125, 522);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"База данных студентов";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		DataSet^ select() {
			auto adapter = gcnew OleDbDataAdapter("Select * from student", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}
		DataSet^ add() {
			String^ Name = name->Text->ToString();
			String^ Birthday = birthday->Text->ToString();
			String^ Math = math->Text->ToString();
			String^ Info = info->Text->ToString();
			String^ Engl = engl->Text->ToString();

			if (Name != "" && Birthday != "" && Math != "" && Info != "" && Engl != "") {
				auto adapter = gcnew OleDbDataAdapter("INSERT INTO student VALUES ('" + Name + "',#" + Birthday + "#," + Math + "," + Info + "," + Engl + "); ", conn);
				auto ds = gcnew DataSet();
				adapter->Fill(ds);
				name->Clear();
				birthday->Clear();
				math->Clear();
				info->Clear();
				engl->Clear();
				return ds;
			}
			else {
				MessageBox::Show("Заполните все поля перед добавлением!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			
		}
		DataSet^ set() {
			String^ Name = name->Text->ToString();
			String^ Birthday = birthday->Text->ToString();
			String^ Math = math->Text->ToString();
			String^ Info = info->Text->ToString();
			String^ Engl = engl->Text->ToString();
			String^ curname = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
			if (Name != "" && Birthday != "" && Math != "" && Info != "" && Engl != "") {
				auto adapter = gcnew OleDbDataAdapter("update student set name='" + Name + "', birthday=#" + Birthday + "#, math=" + Math + ", info=" + Info + ", engl=" + Engl + " where name='" + curname + "'", conn);
				auto ds = gcnew DataSet();
				adapter->Fill(ds);
				name->Clear();
				birthday->Clear();
				math->Clear();
				info->Clear();
				engl->Clear();
				return ds;
			}
			else {
				MessageBox::Show("Заполните все поля перед изменением!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		DataSet^ del() {
			
				String^ s = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
				auto adapter = gcnew OleDbDataAdapter("DELETE FROM student where name='" + s + "'", conn);
				auto ds = gcnew DataSet();
				adapter->Fill(ds);
				return ds;
		}
		DataSet^ sort() {
			String^ Name = name->Text->ToString();
			String^ Birthday = birthday->Text->ToString();
			auto adapter = gcnew OleDbDataAdapter("SELECT * FROM student ORDER BY name", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}
		DataSet^ stud_name_birth() {
			String^ Name = name->Text->ToString();
			String^ Birthday = birthday->Text->ToString();
			auto adapter = gcnew OleDbDataAdapter("Select * from student where name='"+Name+"' and birthday=#"+Birthday+"#", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}
		DataSet^ math5() {
			auto adapter = gcnew OleDbDataAdapter("SELECT * FROM student where math=5", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}
		DataSet^ all5() {
			auto adapter = gcnew OleDbDataAdapter("SELECT * FROM student where math=5 and info=5 and engl=5", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}
		DataSet^ older20() {
			auto adapter = gcnew OleDbDataAdapter("SELECT * FROM student where year(date())-year(birthday)>=20", conn);
			auto ds = gcnew DataSet();
			adapter->Fill(ds);
			this->dataGridView1->DataSource = ds->Tables[0];
			return ds;
		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		add();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->RowCount > 1) {
			del();
		}
		else {
			MessageBox::Show("В таблице нет записей для удаления!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (name->Text != "" && birthday->Text != "") {
			stud_name_birth();
		}
		else{
			MessageBox::Show("Введите в текстовые поля фамилию и дату рождения!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		select();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			sort();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
			math5();
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
			all5();
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
			older20();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dataGridView1->RowCount > 1) {
			set();
		}
		else {
			MessageBox::Show("В таблице нет записей для изменения!", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};

}
