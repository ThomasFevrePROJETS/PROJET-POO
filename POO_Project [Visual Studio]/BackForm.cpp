#include "BackForm.h"

using namespace BackForm;

System::Void BackForm::Form::Form_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Set Maximum to the total number of files to copy.
	this->progressBar1->Maximum = 2;

	// Set the initial value of the ProgressBar.
	this->progressBar1->Minimum = 1;
	this->progressBar1->Value = 1;

	// Set the Step property to a value of 1 to represent each file being copied.
	this->progressBar1->Step = 1;

}
void BackForm::Form::activatebuttons()
{
	this->tableLayoutPanel2->Enabled = true;
	this->tableLayoutPanel3->Enabled = true;
	this->button_afficher->Enabled = true;
}

void BackForm::Form::textBoxToGrid(System::Windows::Forms::TextBox^ textBox_test, int index_cell) {
	for (int i = 0; i < (this->dataGridView1->RowCount) - 1; i++) {
		if (textBox_test->Text == this->dataGridView1->Rows[i]->Cells[index_cell]->Value->ToString()) {
			this->dataGridView1->Rows[i]->Selected = true;
			showData(i);
		}
	}
}

void BackForm::Form::ONprogresBar(int max) {

	this->tableLayoutPanel8->Visible = true;
	int i = this->progressBar1->Value;
	while (i <= max) {
		this->progressBar1->PerformStep();
		i++;
	}
	if (this->progressBar1->Value == 2) {
		Sleep(1000);
		this->label_OK->Text = "Tâche Effectuée !";
	}
}

void BackForm::Form::showData(int index) {

	if (this->tableLayoutPanel4->Visible == true)
	{
		this->textBox_nom->Text = this->dataGridView1->Rows[index]->Cells[1]->Value->ToString();
		this->textBox_prenom->Text = this->dataGridView1->Rows[index]->Cells[2]->Value->ToString();
		this->textBox_date_embauche->Text = this->dataGridView1->Rows[index]->Cells[3]->Value->ToString();
		this->textBox_poste->Text = this->dataGridView1->Rows[index]->Cells[4]->Value->ToString();
		this->textBox_adresse->Text = this->dataGridView1->Rows[index]->Cells[6]->Value->ToString();
		this->textBox_ville->Text = this->dataGridView1->Rows[index]->Cells[7]->Value->ToString();
		this->textBox_cp->Text = this->dataGridView1->Rows[index]->Cells[8]->Value->ToString();
	}
	else if (this->tableLayoutPanel5->Visible == true)
	{
		this->textBox_c_nom->Text = this->dataGridView1->Rows[index]->Cells[1]->Value->ToString();
		this->textBox_c_prenom->Text = this->dataGridView1->Rows[index]->Cells[2]->Value->ToString();
		this->textBox_c_date->Text = this->dataGridView1->Rows[index]->Cells[3]->Value->ToString();
		this->textBox_c_nbcommande->Text = this->dataGridView1->Rows[index]->Cells[4]->Value->ToString();
		this->textBox_c_adrfact->Text = this->dataGridView1->Rows[index]->Cells[6]->Value->ToString();
		this->textBox_c_villefact->Text = this->dataGridView1->Rows[index]->Cells[7]->Value->ToString();
		this->textBox_c_cpfact->Text = this->dataGridView1->Rows[index]->Cells[8]->Value->ToString();
		this->textBox_c_adrliv->Text = this->dataGridView1->Rows[index]->Cells[10]->Value->ToString();
		this->textBox_c_villeliv->Text = this->dataGridView1->Rows[index]->Cells[11]->Value->ToString();
		this->textBox1_c_cpliv->Text = this->dataGridView1->Rows[index]->Cells[12]->Value->ToString();
	}
	else if (this->tableLayoutPanel6->Visible == true)
	{
		this->textBox_d_ref->Text = this->dataGridView1->Rows[index]->Cells[1]->Value->ToString();
		this->textBox_d_valide->Text = this->dataGridView1->Rows[index]->Cells[2]->Value->ToString();
		this->textBox_d_envoi->Text = this->dataGridView1->Rows[index]->Cells[3]->Value->ToString();
		this->textBox_d_paiement->Text = this->dataGridView1->Rows[index]->Cells[4]->Value->ToString();
		this->textBox_d_moyen->Text = this->dataGridView1->Rows[index]->Cells[5]->Value->ToString();
		this->textBox_d_total->Text = this->dataGridView1->Rows[index]->Cells[6]->Value->ToString();
		this->textBox_d_produits->Text = this->dataGridView1->Rows[index]->Cells[8]->Value->ToString();
		this->textBox_d_qtes->Text = this->dataGridView1->Rows[index]->Cells[9]->Value->ToString();
	}
	else if (this->tableLayoutPanel7->Visible == true)
	{
		this->textBox_p_desi->Text = this->dataGridView1->Rows[index]->Cells[1]->Value->ToString();
		this->textBox_p_pht->Text = this->dataGridView1->Rows[index]->Cells[2]->Value->ToString();
		this->textBox_p_qte->Text = this->dataGridView1->Rows[index]->Cells[3]->Value->ToString();
		this->textBox_p_seuil->Text = this->dataGridView1->Rows[index]->Cells[4]->Value->ToString();
		this->textBox_p_tva->Text = this->dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	}
}
System::Void BackForm::Form::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Employe^ TableEmploye = gcnew Employe;
	DataSet^ DS = TableEmploye->afficher();
	this->tableLayoutPanel8->Visible = false;

	this->dataGridView1->Visible = true;
	this->dataGridView1->DataSource = DS;
	this->dataGridView1->DataMember = "Employe";
	this->dataGridView1->Columns[0]->Visible = false;
	this->dataGridView1->Columns[5]->Visible = false;
	this->dataGridView1->Rows[0]->Selected = true;

	activatebuttons();

	this->tableLayoutPanel2->Visible = true;
	this->tableLayoutPanel2->Enabled = true;
	this->tableLayoutPanel3->Visible = true;
	this->tableLayoutPanel3->Enabled = true;
	this->button_afficher->Visible = true;
	this->button_afficher->Enabled = true;
	this->tableLayoutPanel4->Visible = true;
	this->tableLayoutPanel4->Enabled = true;
	this->tableLayoutPanel5->Visible = false;
	this->tableLayoutPanel5->Enabled = false;
	this->tableLayoutPanel6->Visible = false;
	this->tableLayoutPanel6->Enabled = false;
	this->tableLayoutPanel7->Visible = false;
	this->tableLayoutPanel7->Enabled = false;
	this->tableLayoutPanel9->Visible = false;
	this->tableLayoutPanel9->Enabled = false;
}

System::Void BackForm::Form::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Client^ TableClient = gcnew Client;
	DataSet^ DS = TableClient->afficher();
	this->tableLayoutPanel8->Visible = false;

	this->dataGridView1->Visible = true;
	this->dataGridView1->DataSource = DS;
	this->dataGridView1->DataMember = "Client";
	this->dataGridView1->Columns[0]->Visible = false;
	this->dataGridView1->Columns[5]->Visible = false;
	this->dataGridView1->Columns[9]->Visible = false;
	this->dataGridView1->Rows[0]->Selected = true;

	activatebuttons();

	this->tableLayoutPanel2->Visible = true;
	this->tableLayoutPanel2->Enabled = true;
	this->tableLayoutPanel3->Visible = true;
	this->tableLayoutPanel3->Enabled = true;
	this->button_afficher->Visible = true;
	this->button_afficher->Enabled = true;
	this->tableLayoutPanel4->Visible = false;
	this->tableLayoutPanel4->Enabled = false;
	this->tableLayoutPanel5->Visible = true;
	this->tableLayoutPanel5->Enabled = true;
	this->tableLayoutPanel6->Visible = false;
	this->tableLayoutPanel6->Enabled = false;
	this->tableLayoutPanel7->Visible = false;
	this->tableLayoutPanel7->Enabled = false;
	this->tableLayoutPanel9->Visible = false;
	this->tableLayoutPanel9->Enabled = false;
}

System::Void BackForm::Form::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Commande^ TableCommande = gcnew Commande;
	DataSet^ DS = TableCommande->afficher();
	this->tableLayoutPanel8->Visible = false;

	activatebuttons();

	this->dataGridView1->Visible = true;
	this->dataGridView1->DataSource = DS;
	this->dataGridView1->DataMember = "Commande";
	this->dataGridView1->Columns[0]->Visible = false;
	this->dataGridView1->Columns[7]->Visible = false;

	this->tableLayoutPanel2->Visible = true;
	this->tableLayoutPanel2->Enabled = true;
	this->tableLayoutPanel3->Visible = true;
	this->tableLayoutPanel3->Enabled = true;
	this->button_afficher->Visible = true;
	this->button_afficher->Enabled = true;
	this->tableLayoutPanel4->Visible = false;
	this->tableLayoutPanel4->Enabled = false;
	this->tableLayoutPanel5->Visible = false;
	this->tableLayoutPanel5->Enabled = false;
	this->tableLayoutPanel6->Visible = true;
	this->tableLayoutPanel6->Enabled = true;
	this->tableLayoutPanel7->Visible = false;
	this->tableLayoutPanel7->Enabled = false;
	this->tableLayoutPanel9->Visible = false;
	this->tableLayoutPanel9->Enabled = false;

}

System::Void BackForm::Form::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ NT = "Produit";
	Produit^ TableProduit = gcnew Produit;
	DataSet^ DS = TableProduit->afficher(NT);
	this->tableLayoutPanel8->Visible = false;

	activatebuttons();

	this->dataGridView1->Visible = true;
	this->dataGridView1->DataSource = DS;
	this->dataGridView1->DataMember = NT;
	this->dataGridView1->Columns[0]->Visible = false;

	this->tableLayoutPanel2->Visible = true;
	this->tableLayoutPanel2->Enabled = true;
	this->tableLayoutPanel3->Visible = true;
	this->tableLayoutPanel3->Enabled = true;
	this->button_afficher->Visible = true;
	this->button_afficher->Enabled = true;
	this->tableLayoutPanel4->Visible = false;
	this->tableLayoutPanel4->Enabled = false;
	this->tableLayoutPanel5->Visible = false;
	this->tableLayoutPanel5->Enabled = false;
	this->tableLayoutPanel6->Visible = false;
	this->tableLayoutPanel6->Enabled = false;
	this->tableLayoutPanel7->Visible = true;
	this->tableLayoutPanel7->Enabled = true;
	this->tableLayoutPanel9->Visible = false;
	this->tableLayoutPanel9->Enabled = false;
}

System::Void BackForm::Form::button5_Click(System::Object^ sender, System::EventArgs^ e)
{

	// Statistiques
	this->dataGridView1->Visible = false;

	this->tableLayoutPanel4->Visible = false;
	this->tableLayoutPanel4->Enabled = false;
	this->tableLayoutPanel5->Visible = false;
	this->tableLayoutPanel5->Enabled = false;
	this->tableLayoutPanel6->Visible = false;
	this->tableLayoutPanel6->Enabled = false;
	this->tableLayoutPanel7->Visible = false;
	this->tableLayoutPanel7->Enabled = false;
	this->tableLayoutPanel9->Visible = true;
	this->tableLayoutPanel9->Enabled = true;
	this->tableLayoutPanel2->Visible = false;
	this->tableLayoutPanel2->Enabled = false;
	this->tableLayoutPanel3->Visible = false;
	this->tableLayoutPanel3->Enabled = false;
	this->button_afficher->Visible = false;
	this->button_afficher->Enabled = false;

}
System::Void BackForm::Form::button__first_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->dataGridView1->Rows[0]->Selected = true;

	showData(0);
}

System::Void BackForm::Form::button_previous_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < (this->dataGridView1->RowCount) - 1; i++) {
		if (this->dataGridView1->Rows[i]->Selected == true) {
			Index = i;
		}
	}

	if (this->dataGridView1->Rows[0]->Selected == true) {
		Index = (this->dataGridView1->RowCount) - 1;
		this->dataGridView1->Rows[0]->Selected = false;
	}

	else {
		this->dataGridView1->Rows[Index]->Selected = false;
	}


	this->dataGridView1->Rows[Index - 1]->Selected = true;

	showData(Index - 1);
}

System::Void BackForm::Form::button_next_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < (this->dataGridView1->RowCount) - 1; i++) {
		if (this->dataGridView1->Rows[i]->Selected == true) {
			Index = i;
		}
	}

	if (this->dataGridView1->Rows[(this->dataGridView1->RowCount) - 2]->Selected == true) {
		Index = -1;
		this->dataGridView1->Rows[(this->dataGridView1->RowCount) - 2]->Selected = false;
	}

	else {
		this->dataGridView1->Rows[Index]->Selected = false;
	}

	this->dataGridView1->Rows[Index + 1]->Selected = true;

	showData(Index + 1);
}

System::Void BackForm::Form::button_last_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->dataGridView1->Rows[(this->dataGridView1->RowCount) - 2]->Selected = true;

	showData((this->dataGridView1->RowCount) - 2);
}
System::Void BackForm::Form::button_afficher_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Data::DataSet^ DS;

	if (this->tableLayoutPanel4->Visible == true) {

		Employe^ TableEmploye = gcnew Employe;
		DS = TableEmploye->afficher();
	}
	else if (this->tableLayoutPanel5->Visible == true) {

		Client^ TableClient = gcnew Client;
		DS = TableClient->afficher();
	}
	else if (this->tableLayoutPanel6->Visible == true) {

		Commande^ TableCommande = gcnew Commande;
		DS = TableCommande->afficher();
	}
	else if (this->tableLayoutPanel7->Visible == true) {

		String^ NT = "Produit";
		Produit^ TableProduit = gcnew Produit;
		DS = TableProduit->afficher(NT);
	}


	this->dataGridView1->DataSource = DS;
	this->dataGridView1->Rows[0]->Selected = true;
	showData(0);
}

System::Void BackForm::Form::button_ajouter_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->tableLayoutPanel4->Visible == true) {

		Employe^ emp = gcnew Employe;
		emp->ajouter(this->textBox_nom->Text, this->textBox_prenom->Text, this->textBox_date_embauche->Text, this->textBox_poste->Text, this->textBox_adresse->Text, this->textBox_ville->Text, this->textBox_cp->Text);
	}
	else if (this->tableLayoutPanel5->Visible == true) {

		Client^ clt = gcnew Client;
		clt->ajouter(this->textBox_c_nom->Text, this->textBox_c_prenom->Text, this->textBox_c_date->Text, this->textBox_c_nbcommande->Text, this->textBox_c_adrfact->Text, this->textBox_c_villefact->Text, this->textBox_c_cpfact->Text, this->textBox_c_adrliv->Text, this->textBox_c_villeliv->Text, this->textBox1_c_cpliv->Text);
	}
	else if (this->tableLayoutPanel6->Visible == true) {

		Commande^ cmd = gcnew Commande;

		cmd->ajouter(this->textBox_d_ref->Text, this->textBox_d_valide->Text, this->textBox_d_envoi->Text, this->textBox_d_paiement->Text, this->textBox_d_moyen->Text, this->textBox_d_total->Text, this->textBox_d_produits->Text, this->textBox_d_qtes->Text, this->ID_client_click);
	}
	else if (this->tableLayoutPanel7->Visible == true) {

		Produit^ pdt = gcnew Produit;
		pdt->ajouter(this->textBox_p_desi->Text, this->textBox_p_pht->Text, this->textBox_p_qte->Text, this->textBox_p_seuil->Text, this->textBox_p_tva->Text);
	}
	ONprogresBar(2);
}

System::Void BackForm::Form::button_modifier_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < (this->dataGridView1->RowCount) - 1; i++) {
		if (this->dataGridView1->Rows[i]->Selected == true) {
			Index = i;
		}
	}

	if (this->tableLayoutPanel4->Visible == true) {

		Employe^ emp = gcnew Employe;
		emp->modifier(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->textBox_nom->Text, this->textBox_prenom->Text, this->textBox_date_embauche->Text, this->textBox_poste->Text, this->textBox_adresse->Text, this->textBox_ville->Text, this->textBox_cp->Text);
	}
	else if (this->tableLayoutPanel5->Visible == true) {

		Client^ clt = gcnew Client;
		clt->modifier(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->dataGridView1->Rows[Index]->Cells[5]->Value->ToString(), this->dataGridView1->Rows[Index]->Cells[9]->Value->ToString(), this->textBox_c_nom->Text, this->textBox_c_prenom->Text, this->textBox_c_date->Text, this->textBox_c_nbcommande->Text, this->textBox_c_adrfact->Text, this->textBox_c_villefact->Text, this->textBox_c_cpfact->Text, this->textBox_c_adrliv->Text, this->textBox_c_villeliv->Text, this->textBox1_c_cpliv->Text);
	}
	else if (this->tableLayoutPanel6->Visible == true) {

		Commande^ cmd = gcnew Commande;
		cmd->modifier(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->textBox_d_ref->Text, this->textBox_d_valide->Text, this->textBox_d_envoi->Text, this->textBox_d_paiement->Text, this->textBox_d_moyen->Text, this->textBox_d_total->Text, this->textBox_d_produits->Text, this->textBox_d_qtes->Text);
	}
	else if (this->tableLayoutPanel7->Visible == true) {

		Produit^ pdt = gcnew Produit;
		pdt->modifier(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->textBox_p_desi->Text, this->textBox_p_pht->Text, this->textBox_p_qte->Text, this->textBox_p_seuil->Text, this->textBox_p_tva->Text);
	}
	ONprogresBar(3);
}

System::Void BackForm::Form::button_supprimer_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < (this->dataGridView1->RowCount) - 1; i++) {
		if (this->dataGridView1->Rows[i]->Selected == true) {
			Index = i;
		}
	}

	if (this->tableLayoutPanel4->Visible == true) {

		Employe^ emp = gcnew Employe;
		emp->supprimer(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->dataGridView1->Rows[Index]->Cells[5]->Value->ToString());
	}
	else if (this->tableLayoutPanel5->Visible == true) {

		Client^ clt = gcnew Client;
		clt->supprimer(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString(), this->dataGridView1->Rows[Index]->Cells[5]->Value->ToString(), this->dataGridView1->Rows[Index]->Cells[9]->Value->ToString());
	}
	else if (this->tableLayoutPanel6->Visible == true) {

		Commande^ cmd = gcnew Commande;
		cmd->supprimer(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString());
	}
	else if (this->tableLayoutPanel7->Visible == true) {

		Produit^ pdt = gcnew Produit;
		pdt->supprimer(this->dataGridView1->Rows[Index]->Cells[0]->Value->ToString());
	}
	ONprogresBar(2);
}

System::Void BackForm::Form::textBox_nom_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_nom, 2);
}

System::Void BackForm::Form::textBox_prenom_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_prenom, 2);
}

System::Void BackForm::Form::textBox_d_ref_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_d_ref, 1);
}

System::Void BackForm::Form::textBox_p_desi_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_p_desi, 1);
}

System::Void BackForm::Form::textBox_c_nom_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_c_nom, 1);
}

System::Void BackForm::Form::textBox_c_prenom_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_c_prenom, 2);
}

System::Void BackForm::Form::textBox_c_date_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	textBoxToGrid(textBox_c_date, 3);
}

System::Void BackForm::Form::textBox_d_Client_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	this->dataGridView2->Enabled = true;
	this->dataGridView2->Visible = true;
	System::Data::DataSet^ DS;
	Client^ TableClient = gcnew Client;
	DS = TableClient->afficher();
	this->dataGridView2->DataSource = DS;
	this->dataGridView2->DataMember = "Client";
	for (int i = 0; i < (this->dataGridView2->RowCount) - 1; i++) {
		if (textBox_d_Client->Text == this->dataGridView2->Rows[i]->Cells[1]->Value->ToString()) {
			this->dataGridView2->Rows[i]->Selected = true;
		}
	}
}

System::Void BackForm::Form::button_s_panier_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("statPanierMoyenScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_seuil_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("StatProduitsSousSeuilScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_10moins_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("Stat10MoinsVendusScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_10plus_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("Stat10PlusVendusScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_com_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("StatValeurComScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_achat_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("StatValeurAchatScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_total_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {
		String^ NT = "Produit";
		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherStat("StatMontantClientScript.sql");

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = NT;
	}
}

System::Void BackForm::Form::button_s_ca_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tableLayoutPanel9->Visible == true) {

		Table^ TableProduit = gcnew Table;
		DataSet^ DS = TableProduit->afficherCA("StatCAScript.sql", this->textBox_month->Text, this->textBox_year->Text);

		this->dataGridView1->Visible = true;
		this->dataGridView1->DataSource = DS;
		this->dataGridView1->DataMember = "Date";
	}
}

System::Void BackForm::Form::dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	ID_client_click = System::Convert::ToString(this->dataGridView2->CurrentRow->Cells[0]->Value);
	this->dataGridView2->Visible = false;
	this->dataGridView2->Enabled = false;
}

System::Void BackForm::Form::button_s_simul_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->tableLayoutPanel10->Visible = true;
	this->tableLayoutPanel10->Enabled = true;
	this->button_l_simu->Enabled = true;

}

System::Void BackForm::Form::button_l_simu_Click(System::Object^ sender, System::EventArgs^ e)
{
	Table^ TableSimu = gcnew Table;
	DataSet^ DS = TableSimu->afficherSimu(this->textBox_marge->Text, this->textBox_remise->Text, this->textBox_demarque->Text, this->textBox_simutva->Text);

	this->dataGridView1->Visible = true;
	this->dataGridView1->DataSource = DS;
	this->dataGridView1->DataMember = "Simulation";
}

System::Void BackForm::Form::textBox_year_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->button_s_ca->Enabled = true;
}