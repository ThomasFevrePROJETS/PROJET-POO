#pragma once

#include "Table.h"

ref class Employe : public Table
{
public :

	System::Data::DataSet^ afficher();
	void ajouter(System::String^, System::String^, System::String^, System::String^, System::String^, System::String^, System::String^);
	void modifier(System::String^, System::String^, System::String^, System::String^, System::String^, System::String^, System::String^, System::String^);
	void supprimer(System::String^, System::String^);
};

