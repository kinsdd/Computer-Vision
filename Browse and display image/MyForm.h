#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#pragma managed(push,off)
#include <opencv2/opencv.hpp>
#pragma managed(pop)

namespace BrowserImage {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	Mat img; Mat gray;
	IplImage* iplgray;
	IplImage* iplimg; IplImage* iplimggr; IplImage* iplimgt;
	IplImage* iplimgt1;
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pbsrc;
	protected:

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

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
			this->pbsrc = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbsrc))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(87, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Browser";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pbsrc
			// 
			this->pbsrc->Location = System::Drawing::Point(204, 88);
			this->pbsrc->Name = L"pbsrc";
			this->pbsrc->Size = System::Drawing::Size(372, 233);
			this->pbsrc->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbsrc->TabIndex = 1;
			this->pbsrc->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(345, 48);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Gray";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(613, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 344);
			this->Controls->Add(this->pbsrc);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbsrc))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog^ dgopen = gcnew OpenFileDialog();
		dgopen->Filter = "Image (*.bmp;*.jpg|*.bmp;*.jpg|All Files(*.* | *.* || ))";
		if (dgopen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}
		img = imread(convertstring2char(dgopen->FileName));
		if (img.empty()) exit;
		iplimg = cvCloneImage(&(IplImage)img); //Mat to IplImage
		iplimgt = cvCreateImage(cvSize((int)(iplimg->width*0.5), (int)(iplimg->height*0.5)), iplimg->depth, iplimg->nChannels); //Resize image 
		cvResize(iplimg, iplimgt);
		pbsrc->Image = gcnew 
			System::Drawing::Bitmap(iplimgt->width, iplimgt->height, iplimgt->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) iplimgt->imageData);
		pbsrc->Refresh();
	};
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat gray;
		cvtColor(img, gray, CV_BGR2GRAY);
		cvtColor(gray, gray, CV_GRAY2BGR);
		iplimggr = cvCloneImage(&(IplImage)gray);
		iplimgt = cvCreateImage(cvSize((int)(iplimggr->width*0.5), (int)(iplimggr->height*0.5)), iplimggr->depth, iplimggr->nChannels);
		cvResize(iplimggr, iplimgt);
		pbsrc->Image = gcnew System::Drawing::Bitmap(iplimgt->width, iplimgt->height, iplimgt->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) iplimgt->imageData);
		pbsrc->Refresh();
	};
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		cvReleaseImage(&iplimg); cvReleaseImage(&iplimggr);
		destroyAllWindows();
		this->Close();
	};
	private: char* convertstring2char(System::String^ str)
	{
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}
	};
}




