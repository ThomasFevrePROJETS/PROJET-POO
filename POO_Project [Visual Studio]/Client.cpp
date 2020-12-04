#include "Client.h"

using namespace System::IO;

System::Data::DataSet^ Client::afficher()
{
	System::String^ querystring = File::ReadAllText("afficherClientScript.sql");
	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, connection);

	System::Data::DataSet^ dataset = gcnew System::Data::DataSet();

	return ExecuteAdapter(adapter, "Client");
}

void Client::ajouter(System::String^ nom, System::String^ prenom, System::String^ date_naissance, System::String^ nombre_commandes, System::String^ adrfact, System::String^ villefact, System::String^ cpfact, System::String^ adrliv, System::String^ villeliv, System::String^ cpliv) {
	
	System::String^ querystring = File::ReadAllText("ajouterClientScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, connection);

	command->Parameters->AddWithValue("@nom", nom);
	command->Parameters->AddWithValue("@prenom", prenom);
	command->Parameters->AddWithValue("@date_naissance", System::Convert::ToDateTime(date_naissance));
	command->Parameters->AddWithValue("@nombre_commandes", System::Convert::ToInt32(nombre_commandes));
	command->Parameters->AddWithValue("@adrfact", adrfact);
	command->Parameters->AddWithValue("@villefact", villefact);
	command->Parameters->AddWithValue("@cpfact", System::Convert::ToInt32(cpfact));
	command->Parameters->AddWithValue("@adrliv", adrliv);
	command->Parameters->AddWithValue("@villeliv", villeliv);
	command->Parameters->AddWithValue("@cpliv", System::Convert::ToInt32(cpliv));

	ExecuteCommand(command);
}

void Client::modifier(System::String^ ID_client, System::String^ ID_fact, System::String^ ID_liv, System::String^ nom, System::String^ prenom, System::String^ date, System::String^ nbcommandes, System::String^ adrfact, System::String^ villefact, System::String^ cpfact, System::String^ adrliv, System::String^ villeliv, System::String^ cpliv) {

	System::String^ querystring = File::ReadAllText("modifierClientScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, connection);

	command->Parameters->AddWithValue("@ID_client", System::Convert::ToInt32(ID_client));
	command->Parameters->AddWithValue("@ID_fact", System::Convert::ToInt32(ID_fact));
	command->Parameters->AddWithValue("@ID_liv", System::Convert::ToInt32(ID_liv));

	command->Parameters->AddWithValue("@nom", nom);
	command->Parameters->AddWithValue("@prenom", prenom);
	command->Parameters->AddWithValue("@date_naissance", System::Convert::ToDateTime(date));
	command->Parameters->AddWithValue("@nombre_commandes", System::Convert::ToInt32(nbcommandes));

	command->Parameters->AddWithValue("@adrfact", adrfact);
	command->Parameters->AddWithValue("@villefact", villefact);
	command->Parameters->AddWithValue("@cpfact", System::Convert::ToInt32(cpfact));

	command->Parameters->AddWithValue("@adrliv", adrliv);
	command->Parameters->AddWithValue("@villeliv", villeliv);
	command->Parameters->AddWithValue("@cpliv", System::Convert::ToInt32(cpliv));

	ExecuteCommand(command);
}

void Client::supprimer(System::String^ ID_client, System::String^ ID_fact, System::String^ ID_liv) {

	System::String^ querystring = File::ReadAllText("supprimerClientScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, connection);

	command->Parameters->AddWithValue("@ID_client", System::Convert::ToInt32(ID_client));
	command->Parameters->AddWithValue("@ID_fact", System::Convert::ToInt32(ID_fact));
	command->Parameters->AddWithValue("@ID_liv", System::Convert::ToInt32(ID_liv));

	ExecuteCommand(command);
}