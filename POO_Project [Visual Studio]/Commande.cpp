#include "Commande.h"

using namespace System::IO;

System::Data::DataSet^ Commande::afficher()
{
	System::String^ querystring = File::ReadAllText("afficherCommandeScript.sql");
	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, this->connection);

	return this->ExecuteAdapter(adapter, "Commande");
}

void Commande::ajouter(System::String^ ref, System::String^ valide, System::String^ envoi, System::String^ paiement, System::String^ moyen, System::String^ total, System::String^ produit, System::String^ qte, System::String^ ID_Client) {

	System::String^ querystring = File::ReadAllText("ajouterCommandeScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@ref", ref);
	command->Parameters->AddWithValue("@valide", System::Convert::ToBoolean(valide));
	command->Parameters->AddWithValue("@envoi", System::Convert::ToDateTime(envoi));
	command->Parameters->AddWithValue("@paiement", System::Convert::ToDateTime(paiement));
	command->Parameters->AddWithValue("@moyen", moyen);
	command->Parameters->AddWithValue("@total", total);
	command->Parameters->AddWithValue("@produit", produit);
	command->Parameters->AddWithValue("@qte", System::Convert::ToInt32(qte));
	command->Parameters->AddWithValue("@ID_Client", System::Convert::ToInt32(ID_Client));

	this->ExecuteCommand(command);
}

void Commande::modifier(System::String^ ID, System::String^ ref, System::String^ valide, System::String^ envoi, System::String^ paiement, System::String^ moyen, System::String^ total, System::String^ produit, System::String^ qte) {

	System::String^ querystring = File::ReadAllText("modifierCommandeScript.sql");
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@ID", System::Convert::ToInt32(ID));

	command->Parameters->AddWithValue("@ref", ref);
	command->Parameters->AddWithValue("@valide", System::Convert::ToBoolean(valide));
	command->Parameters->AddWithValue("@envoi", System::Convert::ToDateTime(envoi));
	command->Parameters->AddWithValue("@paiement", System::Convert::ToDateTime(paiement));
	command->Parameters->AddWithValue("@moyen", moyen);
	command->Parameters->AddWithValue("@total", total);

	command->Parameters->AddWithValue("@produit", produit);
	command->Parameters->AddWithValue("@qte", System::Convert::ToInt32(qte));

	this->ExecuteCommand(command);
}

void Commande::supprimer(System::String^ ID) {

	System::String^ querystring = File::ReadAllText("supprimerCommandeScript.sql");

	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@ID", System::Convert::ToInt32(ID));

	this->ExecuteCommand(command);
}