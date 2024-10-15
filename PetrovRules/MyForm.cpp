#include "MyForm.h"
#include <random>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	PetrovRules::MyForm form;
	Application::Run(% form);
}

bool nextSet(std::vector<int>& a)
{
	int n = a.size();
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false; // больше перестановок нет 
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	std::swap(a[j], a[k]);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности 
	while (l < r)
		std::swap(a[l++], a[r--]);
	return true;
}

System::Void PetrovRules::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	ShowData();
	ShowParams();
	ShowSeqs();

	PaintDiagram(panel_draw);

	int idleTimeBefore = pt->getMachineIdleTime();
	int waitTimeBefore = pt->getWaitTime();
	label_tprBefore->Text = "Tpr = " + idleTimeBefore;
	label_tozBefore->Text = "Toz = " + waitTimeBefore;
	label_finishBefore->Text = "FTime = " + pt->getFinishTime();

	// Min time in petrov rules + SPZ
	int minTime = pt->getFinishTime(), zeroOrderTime = minTime, minId = -1;
	for (int i = 0; i < pt->seqs.size(); i++) {
		pt->setSeq(i);
		if (pt->getFinishTime() < minTime) {
			minTime = pt->getFinishTime();
			minId = i;
		}
	}

	// Full enum
	std::vector<int> order(pt->data.size(), 0), minOrder;
	for (int i = 0; i < order.size(); i++) order[i] = i;
	minOrder = order;

	while (nextSet(order)) {
		pt->setSeq(order);
		if (pt->getFinishTime() < zeroOrderTime) {
			zeroOrderTime = pt->getFinishTime();
			minOrder = order;
		}
	}

	for (int i = 0; i < minOrder.size(); i++) {
		dgv_seqs->Rows[i]->Cells[5]->Value = minOrder[i];
	}
	pt->setSeq(minOrder);

	label_rTpr->Text = "Tpr = " + pt->getMachineIdleTime();
	label_rToz->Text = "Toz = " + pt->getWaitTime();
	label_rFinish->Text = "FTime = " + pt->getFinishTime();

	pt->setSeq(minId);

	int idleTimeAfter = pt->getMachineIdleTime();
	int waitTimeAfter = pt->getWaitTime();

	label_tprAfter->Text = "Tpr = " + idleTimeAfter;
	label_tozAfter->Text = "Toz = " + waitTimeAfter;
	label_finishAfter->Text = "FTime = " + pt->getFinishTime();

	dgv_seqs->Columns[minId]->DefaultCellStyle->BackColor = Color::Yellow;
	ShowDataAfter();

	PaintDiagram(panel_draw2);
}

const int columnWidth = 25;
void PetrovRules::MyForm::ShowData()
{
	DataGridView^ dgv = dgv_data;
	dgv->RowCount = pt->data.size();
	for (int i = 0; i < pt->data[0].size(); i++) {
		DataGridViewTextBoxColumn^ c0 = gcnew DataGridViewTextBoxColumn();
		c0->HeaderText = "" + i;
		c0->SortMode = DataGridViewColumnSortMode::NotSortable();
		c0->Width = columnWidth;
		dgv->Columns->Add(c0);
	}

	for (int i = 0; i < pt->data.size(); i++) {
		dgv->Rows[i]->Cells[0]->Value = i;
		for (int j = 1; j <= pt->data[0].size(); j++) {
			dgv->Rows[i]->Cells[j]->Value = pt->data[i][j - 1];
		}
	}

	dgv->Height = (dgv->RowCount  + 1) * dgv->Rows[0]->Height + 20;
	dgv->Width = (dgv->ColumnCount + 1) * columnWidth;
}

void PetrovRules::MyForm::ShowDataAfter()
{
	DataGridView^ dgv = dgv_data2;
	dgv->RowCount = pt->data.size();
	for (int i = 0; i < pt->data[0].size(); i++) {
		DataGridViewTextBoxColumn^ c0 = gcnew DataGridViewTextBoxColumn();
		c0->HeaderText = "" + i;
		c0->SortMode = DataGridViewColumnSortMode::NotSortable();
		c0->Width = columnWidth;
		dgv->Columns->Add(c0);
	}

	for (int i = 0; i < pt->data.size(); i++) {
		int id = pt->getOrderID(i);
		dgv->Rows[i]->Cells[0]->Value = id;
		for (int j = 1; j <= pt->data[0].size(); j++) {
			dgv->Rows[i]->Cells[j]->Value = pt->data[id][j - 1];
		}
	}

	dgv->Height = (dgv->RowCount + 1) * dgv->Rows[0]->Height + 20;
	dgv->Width = (dgv->ColumnCount + 1) * columnWidth;
}

void PetrovRules::MyForm::ShowParams()
{
	DataGridView^ dgv = dgv_params;
	dgv->RowCount = pt->params.size();

	for (int i = 0; i < pt->params.size(); i++) {
		for (int j = 0; j < pt->params[0].size(); j++) {
			dgv->Rows[i]->Cells[j]->Value = pt->params[i][j];
		}
	}

	dgv->Height = (dgv->RowCount + 1) * dgv->Rows[0]->Height + 20;
	dgv->Location = Point(dgv_data->Location.X + dgv_data->Width - 20, dgv_data->Location.Y);
}

void PetrovRules::MyForm::ShowSeqs()
{
	DataGridView^ dgv = dgv_seqs;
	dgv->RowCount = pt->seqs[0].size();

	for (int i = 0; i < pt->seqs.size(); i++) {
		for (int j = 0; j < pt->seqs[0].size(); j++) {
			dgv->Rows[j]->Cells[i]->Value = pt->seqs[i][j];
		}
	}

	dgv->Height = (dgv->RowCount + 1) * dgv->Rows[0]->Height + 20;
	dgv->Location = Point(dgv_params->Location.X + dgv_params->Width, dgv_params->Location.Y);
}

const int pbXoffset = 5;
const int sizePictureBox = 7;
const int xDefault = 10;
const int yDefault = 50;
const int yOffset = 35;

void PetrovRules::MyForm::PaintDiagram(Panel^ panel)
{
	int totalTime = 0;
	int	numDetails = pt->data.size();
	int numMachines = pt->data[0].size();

	panel->Controls->Clear();
	int x = xDefault, y = yDefault;

	// machines
	for (int i = 0; i < numMachines; i++) {
		int seq = 0, idleSeq = 0;
		// detail
		for (int j = 0; j < numDetails; j++) {
			int detailID = pt->getOrderID(j);
			int idle = pt->getIdleTime(i, j);
			DrawStrip(x, y, idle, "idle", idleSeq, panel);

			int num = pt->data[detailID][i];
			DrawStrip(x, y, num, "" + num, seq, panel);
		}
		y += yOffset;
		x = xDefault;
	}
}

void PetrovRules::MyForm::DrawStrip(int& startX, int startY, int num, String^ ch, int& numInSeq, Panel^ panel)
{
	array<Color>^ colors = { Color::Red, Color::Blue, Color::Green, Color::Orange, Color::Purple, Color::LightBlue, Color::Silver };
	Color currColor = ch == "idle" ? Color::Yellow : colors[numInSeq % colors->Length];
	String^ lb = ch == "idle" ? ("" + num) : ch;
	if (num >= 0) numInSeq++;
	int middle = num / 2;
	while (num-- > 0) {
		if (num == middle) createLb(startX, startY, lb, panel);
		createPB(startX, startY, currColor, panel);
		startX += sizePictureBox + pbXoffset;
	}
}

void PetrovRules::MyForm::createPB(int x, int y, Color color, Panel^ panel)
{
	PictureBox^ pb = gcnew PictureBox();
	pb->Size = Drawing::Size(sizePictureBox, sizePictureBox);
	pb->Location = Drawing::Point(x, y);
	pb->BackColor = color;
	panel->Controls->Add(pb);
}

void PetrovRules::MyForm::createLb(int x, int y, String^ str, Panel^ panel)
{
	Label^ lb = gcnew Label();
	lb->Text = str;
	lb->Size = Drawing::Size(25, 20);
	lb->Font = gcnew Drawing::Font("Microsoft Sans Serif", 9);
	lb->Location = Drawing::Point(x - 5, y - 20);
	panel->Controls->Add(lb);
}

