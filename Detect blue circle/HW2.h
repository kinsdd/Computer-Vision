#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	Mat img;Mat dst;
	IplImage* iplimg; IplImage* iplimg1; IplImage* iplimgt;
	IplImage* iplimgt1;
	/// <summary>
	/// Summary for HW2
	/// </summary>
	public ref class HW2 : public System::Windows::Forms::Form
	{
	public:
		HW2(void)
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
		~HW2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Button1;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->Button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// Button1
			// 
			this->Button1->Location = System::Drawing::Point(156, 53);
			this->Button1->Name = L"Button1";
			this->Button1->Size = System::Drawing::Size(75, 23);
			this->Button1->TabIndex = 0;
			this->Button1->Text = L"Button1";
			this->Button1->UseVisualStyleBackColor = true;
			this->Button1->Click += gcnew System::EventHandler(this, &HW2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(584, 53);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HW2::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 118);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(356, 303);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(433, 118);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(356, 303);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(144, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"Median Filter";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(574, 92);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"Detect blue object";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// HW2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 439);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Button1);
			this->Name = L"HW2";
			this->Text = L"HW2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		/* Chương trình ngắt của button1 */
		/* LỌC NHIỄU */
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		img = imread("e:/hw.jpg");
		medianBlur(img, dst, 5); // lọc median
		iplimg = cvCloneImage(&(IplImage)dst); //chuyển Mat sang IplImage
		iplimgt = cvCreateImage(cvSize((int)(iplimg->width*0.5),(int)(iplimg->height*0.5)), iplimg->depth, iplimg -> nChannels); //Resize image
		cvResize(iplimg, iplimgt);
		pictureBox1->Image = gcnew System::Drawing::Bitmap(iplimgt -> width, iplimgt->height, iplimgt->widthStep,System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) iplimgt->imageData);
		pictureBox1->Refresh();
	}

		 /* Chương trình ngắt của button1 */
		 /*	LOẠI BỎ CÁC MÀU KHÁC  */
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat orig_image = dst.clone();
		Mat hsv_image; 	Mat blue;
		Mat fin_img;
		cvtColor(dst, hsv_image, COLOR_BGR2HSV); // chuyển ảnh rgb sang hsv
		inRange(hsv_image, Scalar(100, 150, 0), Scalar(140, 255, 255), blue);
		bitwise_and(hsv_image, hsv_image, fin_img, blue); // loại bỏ các màu khác
		cvtColor(fin_img, fin_img, COLOR_HSV2BGR);
		iplimg1 = cvCloneImage(&(IplImage)fin_img); //chuyển Mat sang IplImage
		iplimgt1 = cvCreateImage(cvSize((int)(iplimg1->width*0.5), (int)(iplimg1->height*0.5)), iplimg1->depth, iplimg1->nChannels); //Resize image
		cvResize(iplimg1, iplimgt1);
		pictureBox2->Image = gcnew System::Drawing::Bitmap(iplimgt1->width, iplimgt1->height, iplimgt1->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) iplimgt1->imageData);
		pictureBox2->Refresh();
	}
};
}
