#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#pragma managed(push,off)
#include <opencv2/opencv.hpp>
#pragma managed(pop)
namespace btvn2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	IplImage* img = NULL;
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
	private: System::Windows::Forms::Button^  OpenImage;
	private: System::Windows::Forms::Button^  Exit;
	protected:

	private: System::Windows::Forms::PictureBox^  pictureBox1;



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
			this->OpenImage = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// OpenImage
			// 
			this->OpenImage->Location = System::Drawing::Point(137, 31);
			this->OpenImage->Name = L"OpenImage";
			this->OpenImage->Size = System::Drawing::Size(75, 23);
			this->OpenImage->TabIndex = 0;
			this->OpenImage->Text = L"Open Image";
			this->OpenImage->UseVisualStyleBackColor = true;
			this->OpenImage->Click += gcnew System::EventHandler(this, &MyForm::OpenImage_Click);
			// 
			// Exit
			// 
			this->Exit->Location = System::Drawing::Point(275, 31);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(75, 23);
			this->Exit->TabIndex = 1;
			this->Exit->Text = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(114, 76);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(304, 211);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 339);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->OpenImage);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OpenImage_Click(System::Object^  sender, System::EventArgs^  e) {
		img = cvLoadImage("e:/re.jpg");//đường dẫn ảnh
		pictureBox1->Image = gcnew //replacement of	cvShowImage
			System::Drawing::Bitmap(img->width, img->height, img -> widthStep,System::Drawing::Imaging::PixelFormat::Format24bppRgb,
(System::IntPtr) img->imageData);
		pictureBox1->Refresh();
	}
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e) {
		cvReleaseImage(&img);
		this->Close();
	}
	
};
}
