BEGIN TRANSACTION 


SELECT SUM(Prix_TTC) AS [Valeur_stock]
FROM
 (SELECT ID, ((prix_HT + (taux_TVA_produit/100))*quantite_stock) AS [Prix_TTC] FROM ProjetPOO.dbo.Produit) AS pdt


COMMIT