#pragma once
#include <vector>
#include "maze.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	std::vector<std::pair<int, int>>BFSPath;
	std::vector<std::pair<int, int>>DFSPath;
	std::vector<std::pair<int, int>>DijkstraPath;
	Maze maze;

	//////////////////////////////////////////////////////////////////////////Board[y][x]  .....y>>down....x>>right
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			int x = 50, y = 50;

			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					Point p;

					p.Y = (x + i * 39);
					p.X = (y + j * 40);
					Board[i, j] = gcnew Button();
					Board[i, j]->Location = p;
					Board[i, j]->Width = 40;
					Board[i, j]->Height = 40;
					Board[i, j]->Enabled =true;
					Board[i, j]->Font = gcnew Drawing::Font(Board[i, j]->Font->FontFamily, 15);
					Board[i, j]->FlatStyle = FlatStyle::Flat;
					Board[i, j]->FlatAppearance->BorderColor = Color::Black;
						Board[i, j]->BackColor = Color::White;
						

					this->Controls->Add(Board[i, j]);

				}
			}
			Board[2, 0]->BackColor = Color::Black;
			Board[0, 3]->BackColor = Color::Black;
			Board[0, 15]->BackColor = Color::Black;
			Board[0, 16]->BackColor = Color::Black;
			Board[1, 0]->BackColor = Color::Black;
			Board[1, 1]->BackColor = Color::Black;
			Board[1, 2]->BackColor = Color::Black;
			Board[1, 3]->BackColor = Color::Black;
			Board[1, 4]->BackColor = Color::Black;
			Board[1, 5]->BackColor = Color::Black;
			Board[1, 6]->BackColor = Color::Black;
			Board[1, 7]->BackColor = Color::Black;
			Board[0, 2]->BackColor = Color::Black;
			Board[2, 2]->BackColor = Color::Black;
			Board[2, 1]->BackColor = Color::Black;
			Board[2, 6]->BackColor = Color::Black;
			Board[3, 6]->BackColor = Color::Black;
			Board[4, 6]->BackColor = Color::Black;
			Board[5, 6]->BackColor = Color::Black;
			Board[6, 6]->BackColor = Color::Black;
			Board[7, 6]->BackColor = Color::Black;


			Board[3, 1]->BackColor = Color::Black;
			Board[3, 2]->BackColor = Color::Black;
			Board[3, 3]->BackColor = Color::Black;
			Board[4, 1]->BackColor = Color::Black;
			Board[4, 2]->BackColor = Color::Black;
			Board[4, 3]->BackColor = Color::Black;
			Board[4, 7]->BackColor = Color::Black;
			Board[4, 8]->BackColor = Color::Black;
			Board[5, 7]->BackColor = Color::Black;
			Board[5, 8]->BackColor = Color::Black;
			//Board[6, 2]->BackColor = Color::Black;
			Board[6, 7]->BackColor = Color::Black;
			Board[6, 8]->BackColor = Color::Black;
			Board[7, 0]->BackColor = Color::Black;
			Board[7, 1]->BackColor = Color::Black;
			Board[7, 2]->BackColor = Color::Black;
			Board[7, 3]->BackColor = Color::Black;
			Board[7, 4]->BackColor = Color::Black;
			Board[6, 12]->BackColor = Color::Black;
			Board[6, 13]->BackColor = Color::Black;
			Board[6 ,14]->BackColor = Color::Black;
			Board[6, 15]->BackColor = Color::Black;
			Board[6, 16]->BackColor = Color::Black;
			Board[6, 17]->BackColor = Color::Black;
			Board[6, 18]->BackColor = Color::Black;
			Board[8, 8]->BackColor = Color::Black;
			Board[9, 8]->BackColor = Color::Black;
			Board[10, 8]->BackColor = Color::Black;
			Board[11, 8]->BackColor = Color::Black;
			Board[12, 8]->BackColor = Color::Black;
			Board[10, 6]->BackColor = Color::Black;
			Board[10, 7]->BackColor = Color::Black;
			Board[10, 8]->BackColor = Color::Black;
			Board[10, 9]->BackColor = Color::Black;
			Board[10, 10]->BackColor = Color::Black;
			Board[10, 13]->BackColor = Color::Black;
			Board[10, 14]->BackColor = Color::Black;
			
			Board[13, 2]->BackColor = Color::Black;
			Board[4, 6]->BackColor = Color::Black;
			Board[4, 6]->BackColor = Color::Black;
			Board[4, 6]->BackColor = Color::Black;
			Board[4, 6]->BackColor = Color::Black;

			Board[16, 0]->BackColor = Color::Black;
			Board[16, 1]->BackColor = Color::Black;
			Board[16, 2]->BackColor = Color::Black;
			Board[17, 0]->BackColor = Color::Black;
			Board[17, 1]->BackColor = Color::Black;
			Board[17, 2]->BackColor = Color::Black;
			Board[18, 0]->BackColor = Color::Black;
			Board[19, 0]->BackColor = Color::Black;
			Board[18, 17]->BackColor = Color::Black;
			Board[18, 18]->BackColor = Color::Black;
			Board[18, 19]->BackColor = Color::Black;
			Board[19, 17]->BackColor = Color::Black;
			Board[19, 18]->BackColor = Color::Black;
			Board[19, 19]->BackColor = Color::Black;



			for (int l = 13; l < 15; l++)
			{
				for (int p = 10; p < 15; p++)
				{
					Board[p, l]->BackColor = Color::Black;


				}

			}
			for (int p = 10; p < 17; p++)
			{
				Board[p, 19]->BackColor = Color::Black;


			}
			for (int p = 12; p < 20; p++)
			{
				Board[p, 16]->BackColor = Color::Black;


			}
			for (int l = 12; l < 19; l++)
			{
				for (int p = 2; p < 5; p++)
				{
					Board[p, l]->BackColor = Color::Black;


				}

			}
			for (int l = 8; l < 11; l++)
			{
				for (int p = 17; p < 20; p++)
				{
					Board[p, l]->BackColor = Color::Black;


				}

			}

			for (int l = 4; l < 6; l++)
			{
				for (int p = 17; p < 20; p++)
				{
					Board[p, l]->BackColor = Color::Black;


				}

			}



			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;

			this->Width = 980;
			this->Height = 950;


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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		//VectorWrapper vw;
		/// </summary>


		cli::array<Button^, 2>^ Board = gcnew cli::array<Button^, 2>(20, 20);
		Int32 lastI = 0;
		Int32 lastJ = 0;
		Int32 cnt = 0;
		bool valid_inits = false;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  speedTxtbox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  xValue;
	private: System::Windows::Forms::TextBox^  yValue;
	private: System::Windows::Forms::Button^  valueBttn;
	private: System::Windows::Forms::Label^  Xlbl;
	private: System::Windows::Forms::Label^  Ylbl;
	private: System::Windows::Forms::Button^  exitBttn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  startX;


private: System::Windows::Forms::TextBox^  startY;

private: System::Windows::Forms::Label^  label5;



private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::TextBox^  finishX;
private: System::Windows::Forms::TextBox^  finishY;
private: System::Windows::Forms::Button^  BFS;
private: System::Windows::Forms::Button^  DFS;
private: System::Windows::Forms::Button^  Dijkstra;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label4;

private: System::Windows::Forms::Label^  label10;



private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;


private: System::Windows::Forms::Label^  label15;

private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Button^  clear;






	private: System::Windows::Forms::Timer^  timer1;


#pragma region Windows Form Designer generated code
			 ///DO NOT TOUCH!!!
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
		void InitializeComponent(void)
		{
			this->startX = (gcnew System::Windows::Forms::TextBox());
			this->startY = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->finishX = (gcnew System::Windows::Forms::TextBox());
			this->finishY = (gcnew System::Windows::Forms::TextBox());
			this->BFS = (gcnew System::Windows::Forms::Button());
			this->DFS = (gcnew System::Windows::Forms::Button());
			this->Dijkstra = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// startX
			// 
			this->startX->Location = System::Drawing::Point(1054, 69);
			this->startX->Name = L"startX";
			this->startX->Size = System::Drawing::Size(112, 22);
			this->startX->TabIndex = 0;
			this->startX->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// startY
			// 
			this->startY->Location = System::Drawing::Point(1054, 110);
			this->startY->Name = L"startY";
			this->startY->Size = System::Drawing::Size(112, 22);
			this->startY->TabIndex = 2;
			this->startY->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Minion Pro", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(984, 69);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 23);
			this->label5->TabIndex = 3;
			this->label5->Text = L"x axis";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Mistral", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(1069, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 46);
			this->button2->TabIndex = 7;
			this->button2->Text = L"ok";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// finishX
			// 
			this->finishX->Location = System::Drawing::Point(1054, 216);
			this->finishX->Name = L"finishX";
			this->finishX->Size = System::Drawing::Size(112, 22);
			this->finishX->TabIndex = 8;
			this->finishX->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// finishY
			// 
			this->finishY->Location = System::Drawing::Point(1054, 263);
			this->finishY->Name = L"finishY";
			this->finishY->Size = System::Drawing::Size(112, 22);
			this->finishY->TabIndex = 9;
			this->finishY->TextChanged += gcnew System::EventHandler(this, &MyForm::finishY_TextChanged);
			// 
			// BFS
			// 
			this->BFS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->BFS->Font = (gcnew System::Drawing::Font(L"Mistral", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BFS->Location = System::Drawing::Point(1041, 364);
			this->BFS->Name = L"BFS";
			this->BFS->Size = System::Drawing::Size(125, 41);
			this->BFS->TabIndex = 10;
			this->BFS->Text = L"BFS";
			this->BFS->UseVisualStyleBackColor = false;
			this->BFS->Click += gcnew System::EventHandler(this, &MyForm::BFS_Click);
			// 
			// DFS
			// 
			this->DFS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->DFS->Font = (gcnew System::Drawing::Font(L"Mistral", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DFS->Location = System::Drawing::Point(1041, 431);
			this->DFS->Name = L"DFS";
			this->DFS->Size = System::Drawing::Size(125, 41);
			this->DFS->TabIndex = 11;
			this->DFS->Text = L"DFS";
			this->DFS->UseVisualStyleBackColor = false;
			this->DFS->Click += gcnew System::EventHandler(this, &MyForm::DFS_Click);
			// 
			// Dijkstra
			// 
			this->Dijkstra->BackColor = System::Drawing::Color::PowderBlue;
			this->Dijkstra->Font = (gcnew System::Drawing::Font(L"Mistral", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Dijkstra->Location = System::Drawing::Point(1041, 495);
			this->Dijkstra->Name = L"Dijkstra";
			this->Dijkstra->Size = System::Drawing::Size(125, 41);
			this->Dijkstra->TabIndex = 12;
			this->Dijkstra->Text = L"Dijkstra";
			this->Dijkstra->UseVisualStyleBackColor = false;
			this->Dijkstra->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Papyrus", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1033, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(149, 48);
			this->label9->TabIndex = 13;
			this->label9->Text = L"start point";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Minion Pro", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(984, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 23);
			this->label4->TabIndex = 14;
			this->label4->Text = L"y axis";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Papyrus", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(1018, 153);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(170, 48);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Finish point";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Minion Pro", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(984, 263);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 23);
			this->label7->TabIndex = 20;
			this->label7->Text = L"y axis";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Minion Pro", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(984, 216);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 23);
			this->label8->TabIndex = 21;
			this->label8->Text = L"x axis";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(54, 28);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(784, 17);
			this->label15->TabIndex = 67;
			this->label15->Text = L"  0        1        2       3        4        5        6        7        8       "
				L" 9       10       11      12      13      14     15      16      17      18     "
				L" 19";
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(172, 140);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(25, 101);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(16, 17);
			this->label11->TabIndex = 17;
			this->label11->Text = L"1";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(25, 140);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(16, 17);
			this->label12->TabIndex = 18;
			this->label12->Text = L"2";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(25, 59);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(16, 17);
			this->label13->TabIndex = 19;
			this->label13->Text = L"0";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(17, 692);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(24, 17);
			this->label20->TabIndex = 27;
			this->label20->Text = L"16";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(17, 611);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(24, 17);
			this->label18->TabIndex = 29;
			this->label18->Text = L"14";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(25, 300);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(16, 17);
			this->label22->TabIndex = 33;
			this->label22->Text = L"6";
			this->label22->Click += gcnew System::EventHandler(this, &MyForm::label22_Click);
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(17, 570);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(24, 17);
			this->label53->TabIndex = 46;
			this->label53->Text = L"13";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(17, 495);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(24, 17);
			this->label52->TabIndex = 47;
			this->label52->Text = L"11";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(17, 530);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(24, 17);
			this->label51->TabIndex = 48;
			this->label51->Text = L"12";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(25, 380);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(16, 17);
			this->label50->TabIndex = 49;
			this->label50->Text = L"8";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(17, 732);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(24, 17);
			this->label48->TabIndex = 51;
			this->label48->Text = L"17";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(17, 805);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(24, 17);
			this->label47->TabIndex = 52;
			this->label47->Text = L"19";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(17, 654);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(24, 17);
			this->label46->TabIndex = 53;
			this->label46->Text = L"15";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(25, 222);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(16, 17);
			this->label44->TabIndex = 55;
			this->label44->Text = L"4";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(17, 767);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(24, 17);
			this->label42->TabIndex = 57;
			this->label42->Text = L"18";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(25, 338);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(16, 17);
			this->label37->TabIndex = 62;
			this->label37->Text = L"7";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(17, 455);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(24, 17);
			this->label36->TabIndex = 63;
			this->label36->Text = L"10";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(25, 415);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(16, 17);
			this->label35->TabIndex = 64;
			this->label35->Text = L"9";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(25, 263);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(16, 17);
			this->label34->TabIndex = 65;
			this->label34->Text = L"5";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(25, 184);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(16, 17);
			this->label14->TabIndex = 66;
			this->label14->Text = L"3";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::OrangeRed;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->button3->Location = System::Drawing::Point(1030, 571);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(136, 57);
			this->button3->TabIndex = 68;
			this->button3->Text = L"Kick me !!";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Pristina", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(938, 692);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(223, 88);
			this->label16->TabIndex = 69;
			this->label16->Text = L" Eshagh Moutabi\r\n 9331573";
			this->label16->Click += gcnew System::EventHandler(this, &MyForm::label16_Click);
			// 
			// clear
			// 
			this->clear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->clear->Font = (gcnew System::Drawing::Font(L"Mistral", 18, System::Drawing::FontStyle::Italic));
			this->clear->Location = System::Drawing::Point(964, 300);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(83, 46);
			this->clear->TabIndex = 70;
			this->clear->Text = L"clear";
			this->clear->UseVisualStyleBackColor = false;
			this->clear->Click += gcnew System::EventHandler(this, &MyForm::clear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(1200, 1045);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->label42);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->label46);
			this->Controls->Add(this->label47);
			this->Controls->Add(this->label48);
			this->Controls->Add(this->label50);
			this->Controls->Add(this->label51);
			this->Controls->Add(this->label52);
			this->Controls->Add(this->label53);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Dijkstra);
			this->Controls->Add(this->DFS);
			this->Controls->Add(this->BFS);
			this->Controls->Add(this->finishY);
			this->Controls->Add(this->finishX);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->startY);
			this->Controls->Add(this->startX);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	

private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 bool b;
			 b = maze.Readingfile();
			 if (b == true)
			 {
				 String^ x1Text = this->startX->Text;
				 String^ y1Text = this->startY->Text;
				 String^ x2Text = this->finishX->Text;
				 String^ y2Text = this->finishY->Text;
				 int init_x1 = Convert::ToInt32(x1Text);
				 int init_y1 = Convert::ToInt32(y1Text);
				 int init_x2 = Convert::ToInt32(x2Text);
				 int init_y2 = Convert::ToInt32(y2Text);

				 if (x1Text == "" || y1Text == "" || x2Text == "" || y2Text == ""){
					 MessageBox::Show("Please enter number !.");
				 }
				 else if (init_x1<0 || init_x1>19 || init_y1<0 || init_y1>19 || init_x2<0 || init_x2>19 || init_y2<0 || init_y2>19){
					 MessageBox::Show("Invalid Range!\n");
				 }
				 else {
					 if (maze.Board[init_y1][init_x1] == 1 || maze.Board[init_y2][init_x2] == 1)
					 {
						 MessageBox::Show("it's a wall !");

					 } 
					 else
					 {
						 pair<int, int>start;
						 pair<int, int>finish;

						 start.first = init_y1;
						 start.second = init_x1;
						 finish.first = init_y2;
						 finish.second = init_x2;

						 // valid_inits = true;
						 maze.setdes(start, finish);
						 Board[start.first, start.second]->BackColor = Color::LightBlue;
						 Board[finish.first, finish.second]->BackColor = Color::LightGreen;

						 // Board[start.second, start.first]->Text =
						 /* this->button1->Enabled = true;
						  this->speedTxtbox->Enabled = true;
						  this->label1->Enabled = true;
						  this->label3->Enabled = true;
						  */
					 }
				 }
					 
			 }
			 else{
				 MessageBox::Show("can't Read file");
			 }

}



private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void finishY_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void BFS_Click(System::Object^  sender, System::EventArgs^  e) {
				 bool b;
				 b = maze.Readingfile();
				 if (b == true)
				 {
					 String^ x1Text = this->startX->Text;
					 String^ y1Text = this->startY->Text;
					 String^ x2Text = this->finishX->Text;
					 String^ y2Text = this->finishY->Text;
					 int init_x1 = Convert::ToInt32(x1Text);
					 int init_y1 = Convert::ToInt32(y1Text);
					 int init_x2 = Convert::ToInt32(x2Text);
					 int init_y2 = Convert::ToInt32(y2Text);
					 if (x1Text == "" || y1Text == "" || x2Text == "" || y2Text == ""){
						 MessageBox::Show("Please enter number !.");
					 }
					 else if (init_x1<0 || init_x1>19 || init_y1<0 || init_y1>19 || init_x2<0 || init_x2>19 || init_y2<0 || init_y2>19){
						 MessageBox::Show("Invalid Range!\n");
					 }
					 else {
						 if (maze.Board[init_y1][init_x1] == 1 || maze.Board[init_y2][init_x2] == 1)
						 {
							 MessageBox::Show("it's a wall !");

						 }
						 else
						 {
							 pair<int, int>start;
							 pair<int, int>finish;

							 start.first = init_y1;
							 start.second = init_x1;
							 finish.first = init_y2;
							 finish.second = init_x2;

							 DFSPath = maze.DFS(start, finish);
							 DijkstraPath = maze.Dijkstra(start, finish);
							 BFSPath = maze.BFS(start, finish);
							 for (int i = 0; i < DijkstraPath.size(); i++)
							 {
								 Board[DijkstraPath[i].first, DijkstraPath[i].second]->BackColor = Color::White;
							 }
							 for (int i = 0; i < DFSPath.size(); i++)
							 {
								 Board[DFSPath[i].first, DFSPath[i].second]->BackColor = Color::White;
							 }
							 for (int i = 0; i < BFSPath.size(); i++)
							 {
								 Board[BFSPath[i].first, BFSPath[i].second]->BackColor = Color::LightPink;
							 }
							 Board[start.first, start.second]->BackColor = Color::LightBlue;
							 Board[finish.first, finish.second]->BackColor = Color::LightGreen;
						 }
						 }
				 }
				 else{
					 MessageBox::Show("can't Read file");
				 }

	}
	
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 bool b;
			 b = maze.Readingfile();
			 if (b == true)
			 {
				 String^ x1Text = this->startX->Text;
				 String^ y1Text = this->startY->Text;
				 String^ x2Text = this->finishX->Text;
				 String^ y2Text = this->finishY->Text;
				 int init_x1 = Convert::ToInt32(x1Text);
				 int init_y1 = Convert::ToInt32(y1Text);
				 int init_x2 = Convert::ToInt32(x2Text);
				 int init_y2 = Convert::ToInt32(y2Text);
				 if (x1Text == "" || y1Text == "" || x2Text == "" || y2Text == ""){
					 MessageBox::Show("Please enter number !");
				 }
				 else if (init_x1<0 || init_x1>19 || init_y1<0 || init_y1>19 || init_x2<0 || init_x2>19 || init_y2<0 || init_y2>19){
					 MessageBox::Show("Invalid Range!\n");
				 }
				 else {
					 if (maze.Board[init_y1][init_x1] == 1 || maze.Board[init_y2][init_x2] == 1)
					 {
						 MessageBox::Show("it's a wall !");

					 }
					 else
					 {
						 pair<int, int>start;
						 pair<int, int>finish;

						 start.first = init_y1;
						 start.second = init_x1;
						 finish.first = init_y2;
						 finish.second = init_x2;

						 DFSPath = maze.DFS(start, finish);
						 DijkstraPath = maze.Dijkstra(start, finish);
						 BFSPath = maze.BFS(start, finish);

						 for (int i = 0; i < DFSPath.size(); i++)
						 {
							 Board[DFSPath[i].first, DFSPath[i].second]->BackColor = Color::White;
						 }
						 for (int i = 0; i < BFSPath.size(); i++)
						 {
							 Board[BFSPath[i].first, BFSPath[i].second]->BackColor = Color::White;
						 }
						 for (int i = 0; i < DijkstraPath.size(); i++)
						 {
							 Board[DijkstraPath[i].first, DijkstraPath[i].second]->BackColor = Color::LightPink;
						 }
						 Board[start.first, start.second]->BackColor = Color::LightBlue;
						 Board[finish.first, finish.second]->BackColor = Color::LightGreen;
					 }
					 }
			 }
			 else{
				  MessageBox::Show("can't Read file");
			  }



}
private: System::Void DFS_Click(System::Object^  sender, System::EventArgs^  e) {
			 bool b;
			 b = maze.Readingfile();
			 if (b == true)
			 {
				 String^ x1Text = this->startX->Text;
				 String^ y1Text = this->startY->Text;
				 String^ x2Text = this->finishX->Text;
				 String^ y2Text = this->finishY->Text;
				 int init_x1 = Convert::ToInt32(x1Text);
				 int init_y1 = Convert::ToInt32(y1Text);
				 int init_x2 = Convert::ToInt32(x2Text);
				 int init_y2 = Convert::ToInt32(y2Text);
				 if (x1Text == "" || y1Text == "" || x2Text == "" || y2Text == ""){
					 MessageBox::Show("Please enter number !.");
				 }
				 else if (init_x1<0 || init_x1>19 || init_y1<0 || init_y1>19 || init_x2<0 || init_x2>19 || init_y2<0 || init_y2>19){
					 MessageBox::Show("Invalid Range!\n");
				 }
				 else {
					 pair<int, int>start;
					 pair<int, int>finish;

					 start.first = init_y1;
					 start.second = init_x1;
					 finish.first = init_y2;
					 finish.second = init_x2;

					 DFSPath = maze.DFS(start, finish);
					 DijkstraPath = maze.Dijkstra(start, finish);
					 BFSPath = maze.BFS(start, finish);

					 for (int i = 0; i < DijkstraPath.size(); i++)
					 {
						 Board[DijkstraPath[i].first, DijkstraPath[i].second]->BackColor = Color::White;
					 }
					 for (int i = 0; i < BFSPath.size(); i++)
					 {
						 Board[BFSPath[i].first, BFSPath[i].second]->BackColor = Color::White;
					 }
					 for (int i = 0; i < DFSPath.size(); i++)
					 {
						 Board[DFSPath[i].first, DFSPath[i].second]->BackColor = Color::LightPink;
					 }
					 Board[start.first, start.second]->BackColor = Color::LightBlue;
					 Board[finish.first, finish.second]->BackColor = Color::LightGreen;
				 }
			 }
			 else{
				  MessageBox::Show("can't Read file");
			  }


}
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label22_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {

			 MessageBox::Show("Eshagh moutabi 9331573....finally...finished..... Thank you :D ");
}
private: System::Void label16_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ x1Text = this->startX->Text;
			 String^ y1Text = this->startY->Text;
			 String^ x2Text = this->finishX->Text;
			 String^ y2Text = this->finishY->Text;
			 int init_x1 = Convert::ToInt32(x1Text);
			 int init_y1 = Convert::ToInt32(y1Text);
			 int init_x2 = Convert::ToInt32(x2Text);
			 int init_y2 = Convert::ToInt32(y2Text);
			 pair<int, int>start;
			 pair<int, int>finish;

			 start.first = init_y1;
			 start.second = init_x1;
			 finish.first = init_y2;
			 finish.second = init_x2;
			 for (int i = 0; i < BFSPath.size(); i++)
			 {
				 Board[BFSPath[i].first, BFSPath[i].second]->BackColor = Color::White;
			 }
			 for (int i = 0; i < DFSPath.size(); i++)
			 {
				 Board[DFSPath[i].first, DFSPath[i].second]->BackColor = Color::White;
			 }
			 Board[start.first, start.second]->BackColor = Color::White;
			 Board[finish.first, finish.second]->BackColor = Color::White;
			 for (int i = 0; i < DijkstraPath.size(); i++)
			 {
				 Board[DijkstraPath[i].first, DijkstraPath[i].second]->BackColor = Color::White;
			 }
}
		 
};
}