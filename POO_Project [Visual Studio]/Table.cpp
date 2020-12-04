#include "Table.h"
#include "BackForm.h"

using namespace System::IO;
using namespace BackForm;


Table::Table() 
{
	this->connectionString = "Data Source=.;Initial Catalog=ProjetPOO;Integrated Security=True";
	this->connection = gcnew System::Data::SqlClient::SqlConnection(connectionString);
}


System::Data::DataSet^ Table::ExecuteAdapter(System::Data::SqlClient::SqlDataAdapter^ adapter, System::String^ SourceTable) 
{
	System::Data::DataSet^ dataset = gcnew System::Data::DataSet();

	try
	{
		this->connection->Open();
		adapter->Fill(dataset, SourceTable);
		this->connection->Close();

		return dataset;

	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return dataset;
	}
}

void Table::ExecuteCommand(System::Data::SqlClient::SqlCommand^ command) 
{
	try
	{
		this->connection->Open();
		command->ExecuteNonQuery();
		this->connection->Close();
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

System::Data::DataSet^ Table::afficher(System::String^ NomTable) 
{
	System::String^ querystring = "SELECT * FROM [ProjetPOO].[dbo].[" + NomTable + "];";

	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, connection);

	return this->ExecuteAdapter(adapter, NomTable);
}

System::Data::DataSet^ Table::afficherStat(System::String^ path)
{
	System::String^ querystring = File::ReadAllText(path);

	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, connection);

	return this->ExecuteAdapter(adapter, "Produit");
}

System::Data::DataSet^ Table::afficherSimu(System::String^ marge, System::String^ remise, System::String^ demarque, System::String^ simutva)
{
	System::String^ querystring = File::ReadAllText("StatSimuScript.sql");

	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter(querystring, connection);

	adapter->SelectCommand->Parameters->AddWithValue("@marge", System::Convert::ToInt32(marge));
	adapter->SelectCommand->Parameters->AddWithValue("@remise", System::Convert::ToInt32(remise));
	adapter->SelectCommand->Parameters->AddWithValue("@demarque", System::Convert::ToInt32(demarque));
	adapter->SelectCommand->Parameters->AddWithValue("@simutva", System::Convert::ToInt32(simutva));

	return this->ExecuteAdapter(adapter, "Simulation");
}

System::Data::DataSet^ Table::afficherCA(System::String^ path, System::String^ month , System::String^ year)
{
	System::String^ querystring = File::ReadAllText(path);

	
	System::Data::SqlClient::SqlCommand^ command = gcnew System::Data::SqlClient::SqlCommand(querystring, this->connection);

	command->Parameters->AddWithValue("@month", System::Convert::ToInt32(month));
	command->Parameters->AddWithValue("@year", System::Convert::ToInt32(year));
	

	System::Data::SqlClient::SqlDataAdapter^ adapter = gcnew System::Data::SqlClient::SqlDataAdapter();
	adapter->SelectCommand = command;
	
	return this->ExecuteAdapter(adapter, "Date");
}