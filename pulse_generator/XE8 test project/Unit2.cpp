//---------------------------------------------------------------------------
#define  uchar  unsigned char
#include <vcl.h>
#include <string>
#pragma hdrstop
              #include <dir.h>

#include "Unit2.h"
#include "hidlibrary.h"
#include "usbconfig.h"

char  vendorName[]  = {USB_CFG_VENDOR_NAME, 0};
char  productName[] = {USB_CFG_DEVICE_NAME, 0};

struct dataexchange_t           // �������� ��������� ��� �������� ������
{
   uchar b1;
   uchar b2;
};


struct dataexchange_t pdata = {0, 0};

HIDLibrary <dataexchange_t> hid; // ������� ��������� ������ � ����� ����� ���������

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

int connect()  // ���� �������� ����� ������������ � ����������
{
   int i, n, res=0;
   string exampleDeviceName = "";

   exampleDeviceName += vendorName;
   exampleDeviceName += " ";
   exampleDeviceName += productName;
   bool a=hid.IsAvailableLib();
 ///  auto s=hid.IsConnectedDevice();
   n = hid.EnumerateHIDDevices(); // ������ ��� Hid ���������� vid_16c0&pid_05df
								  // vid � pid ������� � hidlibrary.h ���������� idstring

   for (i=0; i<n; i++)            // ���� ����� ��� ����
   {
	  bool a= hid.Connect(i);

	  // GetConnectedDeviceName() ���������� string,
      // ��� ����� ������ ������� vendor � product Name.
	  // ����������, ���� ������� - ������� ���������� ����
	  string tmp = hid.GetConnectedDeviceName();
	  string t =a?"+":"-";
	  Form2->Memo1->Lines->Add(t.c_str());
	  if ( hid.GetConnectedDeviceName() == exampleDeviceName )
	  {
		 res = 1;
         break;
      }
   }
   return res;
}
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if ( 1 == connect() )
   {
      hid.ReceiveData(&pdata);           // ������ ������ � ����������

      if (pdata.b1)
         CheckBox1->Checked = true;
      else
         CheckBox1->Checked = false;

      if (pdata.b2)
         CheckBox2->Checked = true;
      else
		 CheckBox2->Checked = false;
   }
   else
   {
      AnsiString s = "";
      s += vendorName;
      s += " ";
      s += productName;
      s += " �� ����������.";
      ShowMessage(s);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
    if ( 1 == connect() )
   {
      if (CheckBox1->Checked)
         pdata.b1 = 1;
      else
         pdata.b1 = 0;

      if (CheckBox2->Checked)
         pdata.b2 = 1;
      else
         pdata.b2 = 0;

      hid.SendData(&pdata);           // ���������� ������ ����������
   }
   else
   {
      AnsiString s = "";
      s += vendorName;
      s += " ";
      s += productName;
	  s += " �� ����������.";
      ShowMessage(s);
   }
}
//---------------------------------------------------------------------------

