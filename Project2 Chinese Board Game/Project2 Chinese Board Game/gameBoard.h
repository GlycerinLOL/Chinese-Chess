#pragma once

namespace Project2ChineseBoardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cli;

	/// <summary>
	/// gameBoard ���K�n
	/// </summary>
	public ref class gameBoard : public System::Windows::Forms::Form
	{
	public: 
		array<Button^, 2>^ btnGrid = gcnew array<Button^, 2>(10, 9);
		gameBoard(void)
		{
			
			InitializeComponent();
			generateButton();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

		void generateButton() {
			int buttonSize = chessBoard->Width / 9;
			// make board match size
			chessBoard->Width = chessBoard->Height * 0.9;

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 9; j++) {
					btnGrid[i, j] = gcnew Button();
					btnGrid[i, j]->Height = buttonSize;
					btnGrid[i, j]->Width = buttonSize;
					// add click event
					btnGrid[i, j]->Click += gcnew System::EventHandler(this, &gameBoard::Grid_btn_click);

					chessBoard->Controls->Add(btnGrid[i, j]);
					btnGrid[i, j]->Location = gcnew Point(i * buttonSize, j * buttonSize);
				}
			}
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~gameBoard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ chessBoard;


	protected:

	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->chessBoard = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// chessBoard
			// 
			this->chessBoard->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->chessBoard->Location = System::Drawing::Point(12, 12);
			this->chessBoard->Name = L"chessBoard";
			this->chessBoard->Size = System::Drawing::Size(720, 800);
			this->chessBoard->TabIndex = 0;
			// 
			// gameBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 824);
			this->Controls->Add(this->chessBoard);
			this->Name = L"gameBoard";
			this->Text = L"gameBoard";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Grid_btn_click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
