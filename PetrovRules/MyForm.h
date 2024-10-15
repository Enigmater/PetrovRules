#pragma once
#include "Petrov.h"

namespace PetrovRules {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Petrov* pt;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			pt = new Petrov();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgv_data;
	private: System::Windows::Forms::DataGridView^ dgv_params;
	private: System::Windows::Forms::DataGridView^ dgv_seqs;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ p1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ p2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ lambda;
	private: System::Windows::Forms::Panel^ panel_draw;
	private: System::Windows::Forms::Panel^ panel_draw2;
	private: System::Windows::Forms::DataGridView^ dgv_data2;

	private: System::Windows::Forms::Label^ label_tprBefore;
	private: System::Windows::Forms::Label^ label_tozBefore;
	private: System::Windows::Forms::Label^ label_tozAfter;
	private: System::Windows::Forms::Label^ label_tprAfter;






	private: System::Windows::Forms::Label^ label_rToz;
	private: System::Windows::Forms::Label^ label_rTpr;
	private: System::Windows::Forms::Label^ label_finishBefore;
	private: System::Windows::Forms::Label^ label_rFinish;
	private: System::Windows::Forms::Label^ label_finishAfter;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dst;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ spz;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ r;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;



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
			this->dgv_data = (gcnew System::Windows::Forms::DataGridView());
			this->dgv_params = (gcnew System::Windows::Forms::DataGridView());
			this->p1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->p2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lambda = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgv_seqs = (gcnew System::Windows::Forms::DataGridView());
			this->panel_draw = (gcnew System::Windows::Forms::Panel());
			this->panel_draw2 = (gcnew System::Windows::Forms::Panel());
			this->dgv_data2 = (gcnew System::Windows::Forms::DataGridView());
			this->label_tprBefore = (gcnew System::Windows::Forms::Label());
			this->label_tozBefore = (gcnew System::Windows::Forms::Label());
			this->label_tozAfter = (gcnew System::Windows::Forms::Label());
			this->label_tprAfter = (gcnew System::Windows::Forms::Label());
			this->label_rToz = (gcnew System::Windows::Forms::Label());
			this->label_rTpr = (gcnew System::Windows::Forms::Label());
			this->label_finishBefore = (gcnew System::Windows::Forms::Label());
			this->label_rFinish = (gcnew System::Windows::Forms::Label());
			this->label_finishAfter = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dst = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->spz = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->r = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_data))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_params))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_seqs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_data2))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_data
			// 
			this->dgv_data->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_data->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_data->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_data->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dst });
			this->dgv_data->Location = System::Drawing::Point(32, 28);
			this->dgv_data->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_data->Name = L"dgv_data";
			this->dgv_data->RowHeadersVisible = false;
			this->dgv_data->Size = System::Drawing::Size(36, 161);
			this->dgv_data->TabIndex = 0;
			// 
			// dgv_params
			// 
			this->dgv_params->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_params->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_params->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_params->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->p1, this->p2,
					this->lambda
			});
			this->dgv_params->Location = System::Drawing::Point(247, 28);
			this->dgv_params->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_params->Name = L"dgv_params";
			this->dgv_params->RowHeadersVisible = false;
			this->dgv_params->Size = System::Drawing::Size(95, 106);
			this->dgv_params->TabIndex = 1;
			// 
			// p1
			// 
			this->p1->HeaderText = L"P1";
			this->p1->Name = L"p1";
			this->p1->Width = 30;
			// 
			// p2
			// 
			this->p2->HeaderText = L"P2";
			this->p2->Name = L"p2";
			this->p2->Width = 30;
			// 
			// lambda
			// 
			this->lambda->HeaderText = L"l";
			this->lambda->Name = L"lambda";
			this->lambda->Width = 30;
			// 
			// dgv_seqs
			// 
			this->dgv_seqs->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_seqs->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_seqs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_seqs->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->c1, this->c2,
					this->c3, this->c4, this->spz, this->r
			});
			this->dgv_seqs->Location = System::Drawing::Point(340, 28);
			this->dgv_seqs->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_seqs->Name = L"dgv_seqs";
			this->dgv_seqs->RowHeadersVisible = false;
			this->dgv_seqs->Size = System::Drawing::Size(167, 60);
			this->dgv_seqs->TabIndex = 2;
			// 
			// panel_draw
			// 
			this->panel_draw->BackColor = System::Drawing::Color::White;
			this->panel_draw->Location = System::Drawing::Point(13, 224);
			this->panel_draw->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel_draw->Name = L"panel_draw";
			this->panel_draw->Size = System::Drawing::Size(2361, 300);
			this->panel_draw->TabIndex = 3;
			// 
			// panel_draw2
			// 
			this->panel_draw2->BackColor = System::Drawing::Color::White;
			this->panel_draw2->Location = System::Drawing::Point(13, 545);
			this->panel_draw2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel_draw2->Name = L"panel_draw2";
			this->panel_draw2->Size = System::Drawing::Size(2361, 302);
			this->panel_draw2->TabIndex = 4;
			// 
			// dgv_data2
			// 
			this->dgv_data2->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dgv_data2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_data2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_data2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn9 });
			this->dgv_data2->Location = System::Drawing::Point(705, 28);
			this->dgv_data2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dgv_data2->Name = L"dgv_data2";
			this->dgv_data2->RowHeadersVisible = false;
			this->dgv_data2->Size = System::Drawing::Size(36, 161);
			this->dgv_data2->TabIndex = 5;
			// 
			// label_tprBefore
			// 
			this->label_tprBefore->AutoSize = true;
			this->label_tprBefore->Location = System::Drawing::Point(1200, 28);
			this->label_tprBefore->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tprBefore->Name = L"label_tprBefore";
			this->label_tprBefore->Size = System::Drawing::Size(44, 16);
			this->label_tprBefore->TabIndex = 8;
			this->label_tprBefore->Text = L"label2";
			// 
			// label_tozBefore
			// 
			this->label_tozBefore->AutoSize = true;
			this->label_tozBefore->Location = System::Drawing::Point(1303, 28);
			this->label_tozBefore->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tozBefore->Name = L"label_tozBefore";
			this->label_tozBefore->Size = System::Drawing::Size(44, 16);
			this->label_tozBefore->TabIndex = 9;
			this->label_tozBefore->Text = L"label3";
			// 
			// label_tozAfter
			// 
			this->label_tozAfter->AutoSize = true;
			this->label_tozAfter->Location = System::Drawing::Point(1303, 85);
			this->label_tozAfter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tozAfter->Name = L"label_tozAfter";
			this->label_tozAfter->Size = System::Drawing::Size(44, 16);
			this->label_tozAfter->TabIndex = 11;
			this->label_tozAfter->Text = L"label4";
			// 
			// label_tprAfter
			// 
			this->label_tprAfter->AutoSize = true;
			this->label_tprAfter->Location = System::Drawing::Point(1200, 85);
			this->label_tprAfter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tprAfter->Name = L"label_tprAfter";
			this->label_tprAfter->Size = System::Drawing::Size(44, 16);
			this->label_tprAfter->TabIndex = 10;
			this->label_tprAfter->Text = L"label5";
			// 
			// label_rToz
			// 
			this->label_rToz->AutoSize = true;
			this->label_rToz->Location = System::Drawing::Point(1303, 57);
			this->label_rToz->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_rToz->Name = L"label_rToz";
			this->label_rToz->Size = System::Drawing::Size(44, 16);
			this->label_rToz->TabIndex = 13;
			this->label_rToz->Text = L"label4";
			// 
			// label_rTpr
			// 
			this->label_rTpr->AutoSize = true;
			this->label_rTpr->Location = System::Drawing::Point(1200, 57);
			this->label_rTpr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_rTpr->Name = L"label_rTpr";
			this->label_rTpr->Size = System::Drawing::Size(44, 16);
			this->label_rTpr->TabIndex = 12;
			this->label_rTpr->Text = L"label5";
			// 
			// label_finishBefore
			// 
			this->label_finishBefore->AutoSize = true;
			this->label_finishBefore->Location = System::Drawing::Point(1411, 28);
			this->label_finishBefore->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_finishBefore->Name = L"label_finishBefore";
			this->label_finishBefore->Size = System::Drawing::Size(44, 16);
			this->label_finishBefore->TabIndex = 14;
			this->label_finishBefore->Text = L"label3";
			// 
			// label_rFinish
			// 
			this->label_rFinish->AutoSize = true;
			this->label_rFinish->Location = System::Drawing::Point(1411, 57);
			this->label_rFinish->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_rFinish->Name = L"label_rFinish";
			this->label_rFinish->Size = System::Drawing::Size(44, 16);
			this->label_rFinish->TabIndex = 15;
			this->label_rFinish->Text = L"label4";
			// 
			// label_finishAfter
			// 
			this->label_finishAfter->AutoSize = true;
			this->label_finishAfter->Location = System::Drawing::Point(1411, 85);
			this->label_finishAfter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_finishAfter->Name = L"label_finishAfter";
			this->label_finishAfter->Size = System::Drawing::Size(44, 16);
			this->label_finishAfter->TabIndex = 16;
			this->label_finishAfter->Text = L"label4";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1149, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 16);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Start:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1125, 57);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 16);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Random:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1132, 85);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 16);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Optimal:";
			// 
			// dst
			// 
			this->dst->HeaderText = L"";
			this->dst->Name = L"dst";
			this->dst->Width = 25;
			// 
			// c1
			// 
			this->c1->HeaderText = L"1";
			this->c1->Name = L"c1";
			this->c1->Width = 25;
			// 
			// c2
			// 
			this->c2->HeaderText = L"2";
			this->c2->Name = L"c2";
			this->c2->Width = 25;
			// 
			// c3
			// 
			this->c3->HeaderText = L"3";
			this->c3->Name = L"c3";
			this->c3->Width = 25;
			// 
			// c4
			// 
			this->c4->HeaderText = L"4";
			this->c4->Name = L"c4";
			this->c4->Width = 25;
			// 
			// spz
			// 
			this->spz->HeaderText = L"SPZ";
			this->spz->Name = L"spz";
			this->spz->Width = 40;
			// 
			// r
			// 
			this->r->HeaderText = L"R";
			this->r->Name = L"r";
			this->r->Width = 25;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->Width = 25;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 204);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 16);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Start:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 525);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 16);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Optimal:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 944);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_finishAfter);
			this->Controls->Add(this->label_rFinish);
			this->Controls->Add(this->label_finishBefore);
			this->Controls->Add(this->label_rToz);
			this->Controls->Add(this->label_rTpr);
			this->Controls->Add(this->label_tozAfter);
			this->Controls->Add(this->label_tprAfter);
			this->Controls->Add(this->label_tozBefore);
			this->Controls->Add(this->label_tprBefore);
			this->Controls->Add(this->dgv_data2);
			this->Controls->Add(this->panel_draw2);
			this->Controls->Add(this->panel_draw);
			this->Controls->Add(this->dgv_seqs);
			this->Controls->Add(this->dgv_params);
			this->Controls->Add(this->dgv_data);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_data))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_params))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_seqs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_data2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: void ShowData();
	private: void ShowDataAfter();
	private: void ShowParams();
	private: void ShowSeqs();
	private: void PaintDiagram(Panel^ panel);
	private: void DrawStrip(int &startX, int startY, int num, String^ ch, int &numInSeq, Panel^ panel);
	private: void createPB(int x, int y, Color color, Panel^ panel);
	private: void createLb(int x, int y, String^ str, Panel^ panel);
	};
}
