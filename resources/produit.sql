--------------------------------------------------------
--  Fichier créé - mercredi-juillet-17-2024   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "AZIZ"."PRODUIT" 
   (	"REF" NUMBER(*,0), 
	"NOM" VARCHAR2(20 BYTE), 
	"CATEGORIE" VARCHAR2(20 BYTE), 
	"QUANTITE" NUMBER(*,0), 
	"FOURNISSEUR" VARCHAR2(20 BYTE), 
	"PRIX" FLOAT(126)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into AZIZ.PRODUIT
SET DEFINE OFF;
Insert into AZIZ.PRODUIT (REF,NOM,CATEGORIE,QUANTITE,FOURNISSEUR,PRIX) values ('123','Bracelets','Accessoires','20','HP','4');
Insert into AZIZ.PRODUIT (REF,NOM,CATEGORIE,QUANTITE,FOURNISSEUR,PRIX) values ('991','rrr','Nourriture','10','HP','100');
Insert into AZIZ.PRODUIT (REF,NOM,CATEGORIE,QUANTITE,FOURNISSEUR,PRIX) values ('999','mekla','Nourriture','100','HP','2000');
Insert into AZIZ.PRODUIT (REF,NOM,CATEGORIE,QUANTITE,FOURNISSEUR,PRIX) values ('789','eee','Electro-menager','50','HP','500');
Insert into AZIZ.PRODUIT (REF,NOM,CATEGORIE,QUANTITE,FOURNISSEUR,PRIX) values ('78945','air jordan bleu','Vetements','8','HP','540');
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "AZIZ"."PRODUIT_PK" ON "AZIZ"."PRODUIT" ("REF") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "AZIZ"."PRODUIT" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("REF")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "AZIZ"."PRODUIT" MODIFY ("REF" NOT NULL ENABLE);
 
  ALTER TABLE "AZIZ"."PRODUIT" MODIFY ("QUANTITE" NOT NULL ENABLE);
 
  ALTER TABLE "AZIZ"."PRODUIT" MODIFY ("PRIX" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "AZIZ"."PRODUIT" ADD CONSTRAINT "FK_FOURNISSEUR" FOREIGN KEY ("FOURNISSEUR")
	  REFERENCES "AZIZ"."FOURNISSEUR" ("ID") ENABLE;
