
BEGIN TRANSACTION

DELETE FROM ProjetPOO.dbo.specifier
WHERE ID_Adresse = @ID_fact OR ID_Adresse = @ID_liv;

DELETE FROM ProjetPOO.dbo.situer
WHERE ID_Adresse = @ID_liv OR ID_Adresse = @ID_fact;

DELETE FROM ProjetPOO.dbo.Client
WHERE ID = @ID_client;

DELETE FROM ProjetPOO.dbo.Adresse
WHERE ID = @ID_fact OR ID = @ID_liv;

COMMIT