
BEGIN TRANSACTION

DELETE FROM ProjetPOO.dbo.specifier
WHERE ID_Adresse = @ID_Adresse;


DELETE FROM ProjetPOO.dbo.Employe 
WHERE ID = @ID;

DELETE FROM ProjetPOO.dbo.Adresse
WHERE ID = @ID_Adresse;

COMMIT