#pragma once

#include"..\mp2-lab4-queue\TQueue.h"
#include<string>
#include<msclr\marshal_cppstd.h>


namespace CppWinForm1 {

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
		double add;		// вероятность добавления элемента
		double del;		// вероятность удаления элемента
			
		int CountPush = 0;		// счетчик скольок мы положили в очередь
		int CountPop = 0;		// счетчик сколько мы удалили из очереди
		
		TQueue<int>* CircleQueue;

		int CenterX = 420;
		int CenterY = 150;
		int W = 150;
		int H = 150;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Timer^ timer1;

		Random^ rnd = gcnew Random();



		void Draw()
		{
			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetSizeNow() / CircleQueue->GetMaxSize();
			Pen^ MyDrawPen = gcnew Pen(Color::Turquoise);
			MyDrawPen->Width = 15.0F;
			Graphics^ gr = this->CreateGraphics();
			gr->DrawArc(MyDrawPen, CenterX, CenterY, W, H, Start, Finish);
		}


		void Clear()
		{
			Graphics^ gr = this->CreateGraphics();
			// Очищаем экран (устанавливаем фон в белый цвет)
			gr->Clear(Color::PeachPuff);  // или другой цвет фона, если нужно

			int Start = 360 * CircleQueue->GetHeadIndex() / CircleQueue->GetMaxSize();
			int Finish = 360 * CircleQueue->GetSizeNow() / CircleQueue->GetMaxSize();
			Pen^ MyClearPen = gcnew Pen(Color::PeachPuff);
			MyClearPen->Width = 10.0F;
			gr->DrawArc(MyClearPen, CenterX, CenterY, W, H, Start, Finish);
		}



	public:
		MyForm(void)
		{
			InitializeComponent();
			

		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(562, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(674, 47);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::PeachPuff;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 33);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Максимальная длина очереди:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(283, 33);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Вероятность добавления: ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 231);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(283, 33);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вероятность удаления:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(283, 33);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Добавлено элементов:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 321);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(283, 33);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Удалено элементов: ";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(298, 141);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(85, 33);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(298, 186);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(85, 33);
			this->textBox2->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(522, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(283, 33);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Элементов в очереди:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(298, 276);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 33);
			this->label6->TabIndex = 10;
			this->label6->Text = L" ";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(298, 321);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 33);
			this->label7->TabIndex = 11;
			this->label7->Text = L" ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(12, 455);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(300, 33);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Статус:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(298, 231);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(85, 33);
			this->textBox3->TabIndex = 13;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PeachPuff;
			this->ClientSize = System::Drawing::Size(910, 539);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	




	
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	int maxSize = Convert::ToInt32(textBox1->Text);
	add = Convert::ToDouble(textBox2->Text);
	del = Convert::ToDouble(textBox3->Text);

	// Инициализация очереди
	CircleQueue = new TQueue<int>(maxSize);

	// Сброс счетчиков
	CountPush = 0;
	CountPop = 0;

	// Обновление интерфейса
	label6->Text = CountPush.ToString();
	label7->Text = CountPop.ToString();

	// Очистка старого изображения (перерисовка фона)
	Clear();

	// Запуск таймера
	timer1->Interval = 100; // Частота обновления (мс)
	timer1->Enabled = true;

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	timer1->Enabled = false;
}



private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	// Генерация вероятностей
	double randAdd = rnd->NextDouble();
	double randDel = rnd->NextDouble();

	// Добавление элемента
	if (randAdd < add && CircleQueue->GetSizeNow() < CircleQueue->GetMaxSize())
	{
		CircleQueue->Push(1); // Добавляем любой элемент, например, 1
		CountPush++;
	}

	// Удаление элемента
	if (randDel < del && CircleQueue->GetSizeNow() > 0)
	{
		CircleQueue->Pop();
		CountPop++;
	}

	// Перерисовка
	Clear();  // Очистка предыдущего состояния
	Draw();   // Отрисовка текущего состояния

	// Обновление интерфейса
	label6->Text = CountPush.ToString();
	label7->Text = CountPop.ToString();
	label8->Text = CircleQueue->GetSizeNow().ToString();
	label9->Text = "Статус: добавление элементов";

	// Завершение, если очередь заполнена
	if (CircleQueue->GetSizeNow() == CircleQueue->GetMaxSize())
	{
		timer1->Enabled = false;
		label9->Text = "Статус: очередь заполнена";
	}


}
};
}
