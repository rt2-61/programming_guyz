//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Memo1->Lines->Add("Kolesnichenko");
	Memo1->Lines->Add("Parmenov");
	Memo1->Lines->Add("Masneva");
	Memo1->Lines->Add("Murzin");
	Memo1->Lines->Add("Popov");
	Memo1->Lines->Add("Kugashov");
	Memo1->Lines->Add("Sibircev4");
	Memo1->Lines->Add("Osipov4");
	Memo1->Lines->Add("Kuzurman");
	Memo1->Lines->Add("PopovNEW");
	Memo1->Lines->Add("KolesnichenkoNEW");
	Memo1->Lines->Add("MasnevaNEW");
Memo1->Lines->Add("Zhuravlev");
	Memo1->Lines->Add("Masnevamycomp");
	Memo1->Lines->Add("Kugashovmycomp");
}
//---------------------------------------------------------------------------
