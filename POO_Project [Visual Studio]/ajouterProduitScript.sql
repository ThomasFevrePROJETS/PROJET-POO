
BEGIN TRANSACTION;

INSERT INTO ProjetPOO.dbo.Produit (designation, prix_HT, quantite_stock, seuil_reaprovisionement_produit, taux_TVA_produit)
VALUES (@desi, @pht, @qte, @seuil, @tva);

COMMIT;