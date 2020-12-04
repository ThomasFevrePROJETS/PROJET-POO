#pragma once


ref class Table
{

protected :
	
	System::String^ connectionString;
	System::Data::SqlClient::SqlConnection^ connection;

public :
	
	Table();
	virtual System::Data::DataSet^ afficher(System::String^);
	System::Data::DataSet^ afficherStat(System::String^);
	System::Data::DataSet^ Table::afficherSimu(System::String^, System::String^, System::String^, System::String^);
	System::Data::DataSet^ afficherCA(System::String^, System::String^, System::String^);
	System::Data::DataSet^ ExecuteAdapter(System::Data::SqlClient::SqlDataAdapter^, System::String^);
	void ExecuteCommand(System::Data::SqlClient::SqlCommand^);
};

