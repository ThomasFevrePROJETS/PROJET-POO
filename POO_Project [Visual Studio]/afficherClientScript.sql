
SELECT situer.ID_Client, nom AS [Nom], prenom AS [Prénom], date_naissance AS [Date de naissance], nombre_commandes AS [Nombre de commandes], 
adrfact.ID AS [ID_fact], adrfact.adresse AS [Adresse de facturation], adrfact.ville, adrfact.cp AS [Code postal], 
T1.ID_liv AS ID_liv,T1.adresse AS [Adresse de livraison], T1.ville AS [Ville], T1.cp AS [Code Postal]
FROM ProjetPOO.dbo.situer

INNER JOIN (
	SELECT * FROM ProjetPOO.dbo.Adresse AS adr1 
	INNER JOIN ProjetPOO.dbo.specifier as spec1 
	ON (adr1.ID = spec1.ID_Adresse)

	WHERE ID_Type = 1
) AS adrfact 
ON (situer.ID_Adresse = adrfact.ID)

LEFT JOIN ProjetPOO.dbo.Client AS clt
ON (situer.ID_Client = clt.ID)

LEFT JOIN ( 
	SELECT ID_Client, adrliv.ID AS [ID_liv], adrliv.adresse, adrliv.ville, adrliv.cp FROM ProjetPoo.dbo.situer
	INNER JOIN (
	SELECT * FROM ProjetPOO.dbo.Adresse AS adr2
	INNER JOIN ProjetPOO.dbo.specifier as spec2
	ON (adr2.ID = spec2.ID_Adresse)

	WHERE ID_Type = 2
	) AS adrliv

	ON (situer.ID_Adresse = adrliv.ID)

	INNER JOIN ProjetPOO.dbo.Client AS clt
	ON (situer.ID_Client = clt.ID)
) AS T1
ON (situer.ID_Client = T1.ID_Client);
