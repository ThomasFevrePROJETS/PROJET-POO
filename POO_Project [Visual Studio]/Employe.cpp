#include "Employe.h"

using namespace System::IO;

System::Data::DataSet^ Employe::afficher()
{
	System::String^ querystring = File::ReadAllText("afficherEmployeScript.sql");
	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, this->connection);

	System::Data::DataSet^ dataset = gcnew System::Data::DataSet();

	return this->ExecuteAdapter(adapter, "Employe");
}

void Employe::ajouter(System::String^ nom, System::String^ prenom, System::String^ date, System::String^ poste, System::String^ adresse, System::String^ ville, System::String^ cp) {
	
	System::String^ querystring = File::ReadAllText("ajouterEmployeScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@nom", nom);
	command->Parameters->AddWithValue("@prenom", prenom);
	command->Parameters->AddWithValue("@date_embauche", System::Convert::ToDateTime(date));
	command->Parameters->AddWithValue("@poste", poste);
	command->Parameters->AddWithValue("@adresse", adresse);
	command->Parameters->AddWithValue("@ville", ville);
	command->Parameters->AddWithValue("@cp", System::Convert::ToInt32(cp));

	this->ExecuteCommand(command);
}

void Employe::modifier(System::String^ ID, System::String^ nom, System::String^ prenom, System::String^ date, System::String^ poste, System::String^ adresse, System::String^ ville, System::String^ cp) {
	
	System::String^ querystring = File::ReadAllText("modifierEmployeScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@ID", System::Convert::ToInt32(ID));

	command->Parameters->AddWithValue("@nom", nom);
	command->Parameters->AddWithValue("@prenom", prenom);
	command->Parameters->AddWithValue("@date_embauche", System::Convert::ToDateTime(date));
	command->Parameters->AddWithValue("@poste", poste);
	
	command->Parameters->AddWithValue("@adresse", adresse);
	command->Parameters->AddWithValue("@ville", ville);
	command->Parameters->AddWithValue("@cp", System::Convert::ToInt32(cp));

	this->ExecuteCommand(command);
}

void Employe::supprimer(System::String^ ID, System::String^ ID_Adresse) {
	
	System::String^ querystring = File::ReadAllText("supprimerEmployeScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@ID", System::Convert::ToInt32(ID));
	command->Parameters->AddWithValue("@ID_Adresse", System::Convert::ToInt32(ID_Adresse));


	this->ExecuteCommand(command);
}