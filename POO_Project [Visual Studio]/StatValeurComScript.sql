BEGIN TRANSACTION 


SELECT SUM(Prix_TTC) AS [Valeur_stock]
FROM
 (SELECT ID, (prix_HT *quantite_stock) AS [Prix_TTC] FROM ProjetPOO.dbo.Produit) AS pdt


COMMIT