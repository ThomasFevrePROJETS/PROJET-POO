/*------------------------------------------------------------
*        Script SQLSERVER
------------------------------------------------------------*/

BEGIN TRANSACTION initialize;

/*------------------------------------------------------------
-- Table: Client
------------------------------------------------------------*/
CREATE TABLE Client(
	ID                 INT IDENTITY (1,1) NOT NULL ,
	nom                VARCHAR (128) NOT NULL ,
	prenom             VARCHAR (128) NOT NULL ,
	date_naissance     DATETIME NOT NULL ,
	nombre_commandes   INT  NOT NULL  ,
	CONSTRAINT Client_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: Commande
------------------------------------------------------------*/
CREATE TABLE Commande(
	ID                       INT IDENTITY (1,1) NOT NULL ,
	reference                VARCHAR (50) NOT NULL ,
	paiement_valide          bit  NOT NULL ,
	date_envois              DATETIME NOT NULL ,
	date_paiement            DATETIME NOT NULL ,
	moyen_paiement           VARCHAR (50) NOT NULL ,
	total_articles_achetes   INT  NOT NULL ,
	ID_Client                INT  NOT NULL  ,
	CONSTRAINT Commande_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: Produit
------------------------------------------------------------*/
CREATE TABLE Produit(
	ID                                INT IDENTITY (1,1) NOT NULL ,
	designation                       VARCHAR (128) NOT NULL ,
	prix_HT                           MONEY  NOT NULL ,
	quantite_stock                    INT  NOT NULL ,
	seuil_reaprovisionement_produit   INT  NOT NULL ,
	taux_TVA_produit                  FLOAT  NOT NULL  ,
	CONSTRAINT Produit_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: Adresse
------------------------------------------------------------*/
CREATE TABLE Adresse(
	ID        INT IDENTITY (1,1) NOT NULL ,
	adresse   VARCHAR (256) NOT NULL ,
	ville     VARCHAR (12) NOT NULL ,
	cp        INT  NOT NULL  ,
	CONSTRAINT Adresse_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: Type
------------------------------------------------------------*/
CREATE TABLE Type(
	ID            INT IDENTITY (1,1) NOT NULL ,
	designation   VARCHAR (50) NOT NULL  ,
	CONSTRAINT Type_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: concerner
------------------------------------------------------------*/
CREATE TABLE concerner(
	ID_Produit         INT  NOT NULL ,
	ID_Commande        INT  NOT NULL ,
	quantite_produit   INT  NOT NULL  ,
	CONSTRAINT concerner_PK PRIMARY KEY (ID_Produit,ID_Commande)
);


/*------------------------------------------------------------
-- Table: situer
------------------------------------------------------------*/
CREATE TABLE situer(
	ID_Client    INT  NOT NULL ,
	ID_Adresse   INT  NOT NULL  ,
	CONSTRAINT situer_PK PRIMARY KEY (ID_Client,ID_Adresse)
);


/*------------------------------------------------------------
-- Table: spécifier
------------------------------------------------------------*/
CREATE TABLE specifier(
	ID_Type      INT  NOT NULL ,
	ID_Adresse   INT  NOT NULL  ,
	CONSTRAINT specifier_PK PRIMARY KEY (ID_Type,ID_Adresse)
);


/*------------------------------------------------------------
-- Table: Employe
------------------------------------------------------------*/
CREATE TABLE Employe(
	ID              INT IDENTITY (1,1) NOT NULL ,
	nom             VARCHAR (40) NOT NULL ,
	prenom          VARCHAR (40) NOT NULL ,
	date_embauche   DATETIME NOT NULL ,
	poste           VARCHAR (50) NOT NULL ,
	ID_Employe      INT  NOT NULL ,
	ID_Adresse      INT  NOT NULL  ,
	CONSTRAINT Employe_PK PRIMARY KEY (ID)
);


/*------------------------------------------------------------
-- Table: gerer
------------------------------------------------------------*/
CREATE TABLE gerer(
	ID_Employe   INT  NOT NULL ,
	ID_Produit   INT  NOT NULL  ,
	CONSTRAINT gerer_PK PRIMARY KEY (ID_Employe,ID_Produit)
);


/*------------------------------------------------------------
-- Table: régir
------------------------------------------------------------*/
CREATE TABLE regir(
	ID_Employe  INT  NOT NULL ,
	ID_Client   INT  NOT NULL  ,
	CONSTRAINT regir_PK PRIMARY KEY (ID_Employe,ID_Client)
);


/*------------------------------------------------------------
-- Table: superviser
------------------------------------------------------------*/
CREATE TABLE superviser(
	ID_Commande  INT  NOT NULL ,
	ID_Employe   INT  NOT NULL  ,
	CONSTRAINT superviser_PK PRIMARY KEY (ID_Commande,ID_Employe)
);




ALTER TABLE Commande
	ADD CONSTRAINT Commande_Client_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID);

ALTER TABLE concerner
	ADD CONSTRAINT concerner_Produit_FK
	FOREIGN KEY (ID_Produit)
	REFERENCES Produit(ID);

ALTER TABLE concerner
	ADD CONSTRAINT concerner_Commande_FK
	FOREIGN KEY (ID_Commande)
	REFERENCES Commande(ID);

ALTER TABLE situer
	ADD CONSTRAINT situer_Client_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID);

ALTER TABLE situer
	ADD CONSTRAINT situer_Adresse_FK
	FOREIGN KEY (ID_Adresse)
	REFERENCES Adresse(ID);

ALTER TABLE specifier
	ADD CONSTRAINT specifier_Type_FK
	FOREIGN KEY (ID_Type)
	REFERENCES Type(ID);

ALTER TABLE specifier
	ADD CONSTRAINT specifier_Adresse_FK
	FOREIGN KEY (ID_Adresse)
	REFERENCES Adresse(ID);

ALTER TABLE Employe
	ADD CONSTRAINT Employe_Employe_FK
	FOREIGN KEY (ID_Employe)
	REFERENCES Employe(ID);

ALTER TABLE Employe
	ADD CONSTRAINT Employe_Adresse_FK
	FOREIGN KEY (ID_Adresse)
	REFERENCES Adresse(ID);

ALTER TABLE gerer
	ADD CONSTRAINT gerer_Employe_FK
	FOREIGN KEY (ID_Employe)
	REFERENCES Employe(ID);

ALTER TABLE gerer
	ADD CONSTRAINT gerer_Produit_FK
	FOREIGN KEY (ID_Produit)
	REFERENCES Produit(ID);

ALTER TABLE regir
	ADD CONSTRAINT regir_Employe_FK
	FOREIGN KEY (ID_Employe)
	REFERENCES Employe(ID);

ALTER TABLE regir
	ADD CONSTRAINT regir_Client_FK
	FOREIGN KEY (ID_Client)
	REFERENCES Client(ID);

ALTER TABLE superviser
	ADD CONSTRAINT superviser_Commande_FK
	FOREIGN KEY (ID_Commande)
	REFERENCES Commande(ID);

ALTER TABLE superviser
	ADD CONSTRAINT superviser_Employe_FK
	FOREIGN KEY (ID_Employe)
	REFERENCES Employe(ID);


COMMIT TRANSACTION initialize;
