#include "include/fenetreprincipale.h"
void FenetrePrincipale::fonction1()
{
    if (choixCryptage->currentText()== "Fichier texte")
    {
        layoutNonCrypte->addWidget(optionCryptage,3, 0, 1, 2);}
    else layoutNonCrypte->removeWidget(optionCryptage);
}
void FenetrePrincipale::fonction2()
{
   switch(choixCryptage2->currentIndex())
   {case 1: layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
           optionCryptageLayout2->setCurrentIndex(1);
           break;
   case 2: layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
           optionCryptageLayout2->setCurrentIndex(2);
           break;
   case 3: layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
           optionCryptageLayout2->setCurrentIndex(1);
           break;
   case 4:layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
       optionCryptageLayout2->setCurrentIndex(1);
       break;
   case 6:
       layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
       optionCryptageLayout2->setCurrentIndex(1);
       break;
   case 7:
       layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
       optionCryptageLayout2->setCurrentIndex(3);
       break;
   case 8:
       layoutNonCrypte->addWidget(optionCryptage2,5, 0, 1, 2);
       optionCryptageLayout2->setCurrentIndex(4);
       break;

   case 5:optionCryptageLayout2->setCurrentIndex(0);
   case 0: layoutNonCrypte->removeWidget(optionCryptage2);


}}
void FenetrePrincipale::fonction3()
{
    if (choixDecryptage->currentText()== "Fichier texte")
    {
        layoutCrypte->addWidget(optionDecryptage,3, 0, 1, 2);}
    else layoutCrypte->removeWidget(optionDecryptage);
}
void FenetrePrincipale::fonction4()
{
   switch(choixDecryptage2->currentIndex())
   {case 1: layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
           optionDecryptageLayout2->setCurrentIndex(1);
           break;
   case 2: layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
           optionDecryptageLayout2->setCurrentIndex(2);
           break;
   case 3: layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
           optionDecryptageLayout2->setCurrentIndex(1);
           break;
   case 4:layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
       optionDecryptageLayout2->setCurrentIndex(1);
       break;
   case 6:layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
       optionDecryptageLayout2->setCurrentIndex(1);
       break;
   case 7:layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
       optionDecryptageLayout2->setCurrentIndex(3);
       break;
   case 8:layoutCrypte->addWidget(optionDecryptage2,5, 0, 1, 2);
       optionDecryptageLayout2->setCurrentIndex(4);
       break;
   case 5:optionDecryptageLayout2->setCurrentIndex(0);

   case 0: layoutCrypte->removeWidget(optionDecryptage2);


}}

// Constructeur
FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QMainWindow(parent)
{
    // On définit la taille minimale de la fenêtre
    this->setMinimumSize(600,300);
    // On définit sa taille à son ouverture
    this->resize(800,500);




    // Menu "Fichier"
    menuFichier = menuBar()->addMenu("Fichier");
        // Sous-menu "Charger un texte non crypté"
        actionChargerNonCrypte = new QAction(QIcon(":/images/menu/fichier/charger.ico"),"&Charger un texte non crypté", this);
        QObject::connect(actionChargerNonCrypte, SIGNAL(triggered()), this, SLOT(chargerNonCrypte()));

    menuFichier->addAction(actionChargerNonCrypte);

        // Sous-menu "Charger un texte crypté"
        actionChargerCrypte = new QAction(QIcon(":/images/menu/fichier/charger.ico"),"&Charger un texte crypté", this);
        QObject::connect(actionChargerCrypte, SIGNAL(triggered()), this, SLOT(chargerCrypte()));

    menuFichier->addAction(actionChargerCrypte);
    menuFichier->addSeparator();

        // Sous-menu "Enregistrer le texte non crypté sous..."
        actionEnregistrerNonCrypte = new QAction(QIcon(":/images/menu/fichier/enregistrer.ico"),"&Enregistrer le texte non crypté sous...", this);
        QObject::connect(actionEnregistrerNonCrypte, SIGNAL(triggered()), this, SLOT(enregistrerNonCrypte()));

    menuFichier->addAction(actionEnregistrerNonCrypte);

        // Sous-menu "Enregistrer le fichier texte crypté sous..."
        actionEnregistrerCrypte = new QAction(QIcon(":/images/menu/fichier/enregistrer.ico"),"&Enregistrer le fichier texte crypté sous...", this);
        QObject::connect(actionEnregistrerCrypte, SIGNAL(triggered()), this, SLOT(enregistrerCrypte()));

    menuFichier->addAction(actionEnregistrerCrypte);
    menuFichier->addSeparator();

        // Sous-menu "Quitter"
        actionQuitter = new QAction(QIcon(":/images/menu/fichier/quitter.ico") ,"&Quitter", this);
        QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
        menuFichier->addAction(actionQuitter);
    //Menu "Edition"
        menuEdition = menuBar()->addMenu("Edition");
            copier= new QAction(QIcon(":/images/menu/edition/copy.png"),"&copier", this);
            QObject::connect(copier, SIGNAL(triggered()), this,SLOT(copierAction()));
            copier->setShortcut(tr("Ctrl+C"));

        menuEdition->addAction(copier);
        couper= new QAction(QIcon(":/images/menu/edition/couper.png"),"&couper", this);
        QObject::connect(couper, SIGNAL(triggered()), this, SLOT(couperAction()));
        copier->setShortcut(tr("Ctrl+X"));
         menuEdition->addAction(couper);
        coller= new QAction(QIcon(":/images/menu/edition/paste.png"),"&coller", this);
        QObject::connect(coller, SIGNAL(triggered()), this, SLOT(collerAction()));
        coller->setShortcut(tr("Ctrl+V"));
         menuEdition->addAction(coller);


    // Menu "Aide"
    menuAide = menuBar()->addMenu("Aide");
        actionAPropos = new QAction(QIcon(":/images/menu/aide/apropos.ico"), "À propos...", this);
        QObject::connect(actionAPropos, SIGNAL(triggered(bool)), this, SLOT(aPropos()));

    menuAide->addAction(actionAPropos);
    actionaboutqt = new QAction(QIcon(":/images/menu/aide/Qt.png"), "About Qt", this);
    QObject::connect(actionaboutqt, SIGNAL(triggered(bool)), this, SLOT(aboutqt()));

menuAide->addAction(actionaboutqt);



    // Widget centrale de la fenêtre principale
    widgetCentral = new QWidget(this);
    setCentralWidget(widgetCentral);

        // Layout du widget centrale
        layoutCentral = new QVBoxLayout(widgetCentral);
        layoutCentral->setContentsMargins(10,10,10,10);

            // Widget à onglet
            widgetOnglet = new QWidget(widgetCentral);

        layoutCentral->addWidget(widgetOnglet);






                    // Layout vertical pour l'onglet de texte
                    layoutTexte= new QVBoxLayout(widgetOnglet);
                    layoutTexte->setContentsMargins(10,10,10,10);

                        // Création d'un splitter contenant les deux zones de texte
                        splitterTexte = new QSplitter(widgetOnglet);

                    layoutTexte->addWidget(splitterTexte);

                            // Widget de la zone non cryptée
                            widgetNonCrypte = new QWidget(splitterTexte);

                        splitterTexte->addWidget(widgetNonCrypte);

                                // Layout en grille pour le widget de la zone non cryptée
                                layoutNonCrypte = new QGridLayout(widgetNonCrypte);
                                layoutNonCrypte->setContentsMargins(0,0,5,0);

                                    // Champ de texte en bloc contenant le texte non cryptée
                                    zoneTexteNonCrypte =  new QTextEdit(widgetNonCrypte);
                                    zoneTexteNonCrypte->setAcceptRichText(false);
                                    zoneTexteNonCrypte->setAlignment(Qt::AlignJustify);


                                layoutNonCrypte->addWidget(zoneTexteNonCrypte, 0, 0, 1, 2);

                                   // Bouton pour crypter le texte qui se trouve au dessus de lui
                                    boutonCrypter = new QPushButton(QIcon(":/images/texte/crypter.ico"), "Crypter", widgetNonCrypte);
                                    connect(boutonCrypter, SIGNAL(clicked()), this, SLOT(crypter()));
                                layoutNonCrypte->addWidget(boutonCrypter, 1, 0, 1, 2, Qt::AlignTop);




                                    optionCryptage = new QWidget(widgetNonCrypte);
                                    optionCryptage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                                   // layoutNonCrypte->addWidget(optionCryptage,3, 0, 1, 2);







                                        // Layout pour le bloc d'option de cryptage
                                        optionCryptageLayout = new QStackedLayout(optionCryptage);

                                            // Widget de la page d'option de cryptage à partir d'un fichier texte
                                            optionCryptTexte = new QWidget(optionCryptage);

                                                // Layout en grille pour le widget contenant les options de cryptage à partir d'un fichier
                                                optionCryptTexteLayout = new QGridLayout(optionCryptTexte);
                                                optionCryptTexteLayout->setContentsMargins(20,0,20,0);

                                                    // Chemin du texte utilisé pour le cryptage
                                                    cheminCrypterSrcTexte = new QLineEdit(optionCryptTexte);
                                                    connect(cheminCrypterSrcTexte, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));

                                                optionCryptTexteLayout->addWidget(cheminCrypterSrcTexte, 0, 0, 1, 1);

                                                    // Bouton pour parcourir ses fichiers à la recherche d'un texte de source de cryptage
                                                    parcourirCrypterSrcTexte = new QPushButton("...", optionCryptTexte);
                                                    parcourirCrypterSrcTexte->setFixedWidth(40);
                                                    connect(parcourirCrypterSrcTexte, SIGNAL(clicked()), this, SLOT(ouvrirSrcTexteCrypter()));

                                                optionCryptTexteLayout->addWidget(parcourirCrypterSrcTexte, 0, 1, 1, 1);


                                         vide1 = new QWidget(optionCryptage);
                                         vide1->setFixedSize(0,0);
                                         optionCryptageLayout->addWidget(vide1);
                                         optionCryptageLayout->addWidget(optionCryptTexte);



                                    labelChoixCryptage = new QLabel("Source du cryptage :",widgetNonCrypte);
                                    labelChoixCryptage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                                layoutNonCrypte->addWidget(labelChoixCryptage, 2, 0, 1, 1);

                                    // Liste déroulante permettant de sélectionner la source de cryptage
                                    choixCryptage = new QComboBox(widgetNonCrypte);
                                    choixCryptage->addItem("Le texte lui-même");
                                    choixCryptage->addItem("Fichier texte");


                                   connect(choixCryptage,SIGNAL(activated(int)),this, SLOT(fonction1()));
                                   connect(choixCryptage, SIGNAL(activated(int)), optionCryptageLayout, SLOT(setCurrentIndex(int)));


                                layoutNonCrypte->addWidget(choixCryptage, 2, 1, 1, 1);

                                optionCryptage2= new QWidget(widgetNonCrypte);
                                optionCryptage2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);




                                    // Layout pour le bloc d'option de cryptage
                                   optionCryptageLayout2 = new QStackedLayout(optionCryptage2);

                                        // Widget de la page d'option de cryptage à partir d'un fichier texte
                                        optionCryptage21 = new QWidget(optionCryptage2);

                                            // Layout en grille pour le widget contenant les options de cryptage à partir d'un fichier
                                            optionCryptTexteLayout2 = new QGridLayout(optionCryptage21);
                                            optionCryptTexteLayout2->setContentsMargins(0,0,0,0);

                                                clelabelCryptage = new QLabel("Cle de Cryptage :       ",optionCryptage21);
                                                clelabelCryptage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                                                optionCryptTexteLayout2->addWidget(clelabelCryptage, 0, 0, 1, 1);
                                                cleCryptage = new QLineEdit(optionCryptage21);
                                                connect(cleCryptage, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));

                                            optionCryptTexteLayout2->addWidget(cleCryptage, 0, 1, 1, 1);
                                            optionCryptage20 = new QWidget(optionCryptage2);
                                            optionCryptage20->setFixedSize(0,0);
                                            optionCryptageLayout2->addWidget(optionCryptage20);
                                            optionCryptageLayout2->addWidget(optionCryptage21);

                                            QLabel* optionCryptage22 =new QLabel("Cle de Cryptage :       13");
                                             optionCryptageLayout2->addWidget(optionCryptage22);

                                             optionCryptage23 = new QWidget(optionCryptage2);

                                                 // Layout en grille pour le widget contenant les options de cryptage à partir d'un fichier
                                                 rsaCryptageLayout = new QGridLayout(optionCryptage23);
                                                 rsaCryptageLayout->setContentsMargins(0,0,0,0);

                                                     labelp = new QLabel("p=",optionCryptage23);
                                                     labelp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                     rsaCryptageLayout->addWidget(labelp,0,0,1,1);
                                                     clep = new QLineEdit(optionCryptage23);
                                                     connect(clep, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                     rsaCryptageLayout->addWidget(clep,0,1,1,1);
                                                     labelq = new QLabel("q=",optionCryptage23);
                                                     labelq->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                     rsaCryptageLayout->addWidget(labelq,0,2,1,1);
                                                     cleq = new QLineEdit(optionCryptage23);
                                                     connect(cleq, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                     rsaCryptageLayout->addWidget(cleq,0,3,1,1);
                                                     labele = new QLabel("e=",optionCryptage23);
                                                     labele->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                     rsaCryptageLayout->addWidget(labele);
                                                     clee = new QLineEdit(optionCryptage23);
                                                     connect(clee, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                     rsaCryptageLayout->addWidget(clee);
                                                     labelbloc = new QLabel("bloc=",optionCryptage23);
                                                     labelbloc->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                     rsaCryptageLayout->addWidget(labelbloc);
                                                     bloc = new QLineEdit(optionCryptage23);
                                                     connect(bloc, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                     rsaCryptageLayout->addWidget(bloc);

                                                     optionCryptageLayout2->addWidget(optionCryptage23);

                                // Texte placer à gauche de la liste déroulante permettant de sélectionner la source de cryptage
                                labelChoixCryptage2 = new QLabel("Nom du cryptage :",widgetNonCrypte);
                                labelChoixCryptage2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                            layoutNonCrypte->addWidget(labelChoixCryptage2, 4, 0, 1, 1);

                                // Liste déroulante permettant de sélectionner la source de cryptage
                            choixCryptage2 = new QComboBox(widgetNonCrypte);
                            choixCryptage2->addItem("Vide");
                            choixCryptage2->addItem("César");
                            choixCryptage2->addItem("ROT13");
                            choixCryptage2->addItem("Viginere");
                            choixCryptage2->addItem("Che");
                            choixCryptage2->addItem("Morse");
                            choixCryptage2->addItem("Playfair");
                            choixCryptage2->addItem("RSA");
                            choixCryptage2->addItem("Huffman");

                               connect(choixCryptage2, SIGNAL(activated(int)), optionCryptageLayout2, SLOT(setCurrentIndex(int)));
                               connect(choixCryptage2,SIGNAL(activated(int)),this, SLOT(fonction2()));

                            layoutNonCrypte->addWidget(choixCryptage2, 4, 1, 1, 1);

                            // Widget de la zone cryptée
                            widgetCrypte = new QWidget(splitterTexte);

                        splitterTexte->addWidget(widgetCrypte);

                                // Layout de la zone cryptée
                                layoutCrypte = new QGridLayout(widgetCrypte);
                                layoutCrypte->setContentsMargins(5,0,0,0);

                                    // Champ de texte en bloc contenant le texte crypté
                                    zoneTexteCrypte = new QTextEdit(widgetCrypte);
                                    zoneTexteCrypte->setAcceptRichText(false);
                                    zoneTexteCrypte->setAlignment(Qt::AlignJustify);

                                layoutCrypte->addWidget(zoneTexteCrypte, 0, 0, 1, 2);

                                    // Bouton permettant de décrypter le texte au dessus de lui
                                    boutonDecrypter = new QPushButton(QIcon(":/images/texte/decrypter.ico"), "Décrypter", widgetCrypte);
                                    connect(boutonDecrypter, SIGNAL(clicked(bool)), this, SLOT(decrypter()));

                                layoutCrypte->addWidget(boutonDecrypter, 1, 0, 1 , 2, Qt::AlignTop);

                                    // Bloc d'option de décryptage
                                   optionDecryptage = new QWidget(widgetCrypte);
                                    optionDecryptage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


                                        // Layout pour le bloc d'option de décryptage
                                        optionDecryptageLayout = new QStackedLayout(optionDecryptage);

                                            // Widget de la page d'option de décryptage à partir d'un fichier texte
                                            optionDecryptTexte = new QWidget(optionDecryptage);

                                                // Layout en grille pour le widget contenant les options de décryptage à partir d'un fichier
                                                optionDecryptTexteLayout = new QGridLayout(optionDecryptTexte);
                                                optionDecryptTexteLayout->setContentsMargins(20,0,20,0);

                                                    // Chemin du texte utilisé pour le décryptage
                                                    cheminDecrypterSrcTexte = new QLineEdit(optionDecryptTexte);
                                                    connect(cheminDecrypterSrcTexte, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));

                                                optionDecryptTexteLayout->addWidget(cheminDecrypterSrcTexte, 0, 0, 1, 1);

                                                    // Bouton pour parcourir ses fichiers à la recherche d'un texte de source de décryptage
                                                    parcourirDecrypterSrcTexte = new QPushButton("...", optionDecryptTexte);
                                                    parcourirDecrypterSrcTexte->setFixedWidth(40);
                                                    connect(parcourirDecrypterSrcTexte, SIGNAL(clicked()), this, SLOT(ouvrirSrcTexteDecrypter()));

                                                optionDecryptTexteLayout->addWidget(parcourirDecrypterSrcTexte, 0, 1, 1, 1);
                                                vide2 = new QWidget(optionDecryptage);
                                                vide2->setFixedSize(0,0);

                                            optionDecryptageLayout->addWidget(vide2);

                                        optionDecryptageLayout->addWidget(optionDecryptTexte);

                                    // Texte placer à gauche de la liste déroulante permettant de sélectionner la source de cryptage
                                    labelChoixDecryptage = new QLabel("Source du décryptage :", widgetCrypte);
                                    labelChoixDecryptage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                                layoutCrypte->addWidget(labelChoixDecryptage, 2, 0, 1, 1);

                                    // Liste déroulante permettant de sélectionner la source de cryptage
                                    choixDecryptage = new QComboBox(widgetCrypte);
                                    choixDecryptage->addItem("Le texte lui-même");
                                    choixDecryptage->addItem("Fichier texte");

                                    connect(choixDecryptage, SIGNAL(activated(int)), optionDecryptageLayout, SLOT(setCurrentIndex(int)));
                                    connect(choixDecryptage,SIGNAL(activated(int)),this, SLOT(fonction3()));

                                layoutCrypte->addWidget(choixDecryptage, 2, 1, 1, 1);

                                optionDecryptage2= new QWidget(widgetCrypte);
                                optionDecryptage2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                                    // Layout pour le bloc d'option de cryptage

                                    optionDecryptageLayout2 = new QStackedLayout(optionDecryptage2);

                                        // Widget de la page d'option de cryptage à partir d'un fichier texte
                                        optionDecryptage21 = new QWidget(optionDecryptage2);

                                            // Layout en grille pour le widget contenant les options de cryptage à partir d'un fichier
                                            optionDecryptTexteLayout2 = new QGridLayout(optionDecryptage21);
                                            optionDecryptTexteLayout2->setContentsMargins(20,0,20,0);

                                                clelabelDecryptage= new QLabel("Cle de Decryptage :",optionDecryptage21);
                                                clelabelDecryptage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                                                optionDecryptTexteLayout2->addWidget(clelabelDecryptage, 0, 0, 1, 1);
                                                cleDecryptage = new QLineEdit(optionDecryptage21);
                                                connect(cleDecryptage, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));

                                            optionDecryptTexteLayout2->addWidget(cleDecryptage, 0, 1, 1, 1);
                                            optionDecryptage20 = new QWidget(optionDecryptage2);
                                            optionDecryptage20->setFixedSize(0,0);
                                            optionDecryptageLayout2->addWidget(optionDecryptage20);
                                            optionDecryptageLayout2->addWidget(optionDecryptage21);


                                            QLabel* optionDecryptage22 =new QLabel("Cle de Decryptage :       13");
                                             optionDecryptageLayout2->addWidget(optionDecryptage22);

                                              optionDecryptage23 = new QWidget(optionDecryptage2);

                                                  // Layout en grille pour le widget contenant les options de cryptage à partir d'un fichier
                                                  rsaDecryptageLayout = new QGridLayout(optionDecryptage23);
                                                  rsaDecryptageLayout->setContentsMargins(0,0,0,0);

                                                      labelp2 = new QLabel("p=",optionDecryptage23);
                                                      labelp2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                      rsaDecryptageLayout->addWidget(labelp2, 0, 0, 1, 1);
                                                      clep2 = new QLineEdit(optionDecryptage23);
                                                      connect(clep2, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                      rsaDecryptageLayout->addWidget(clep2, 0, 1, 1, 1);
                                                      labelq2 = new QLabel("q=",optionDecryptage23);
                                                      labelq2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                      rsaDecryptageLayout->addWidget(labelq2, 0, 2, 1, 1);
                                                      cleq2 = new QLineEdit(optionDecryptage23);
                                                      connect(cleq2, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                      rsaDecryptageLayout->addWidget(cleq2, 0, 3, 1, 1);
                                                      //************************
                                                      labele2 = new QLabel("e=",optionDecryptage23);
                                                      labele2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                      rsaDecryptageLayout->addWidget(labele2);
                                                      clee2 = new QLineEdit(optionDecryptage23);
                                                      connect(clee2, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                      rsaDecryptageLayout->addWidget(clee2);
                                                      labelbloc2 = new QLabel("bloc=",optionDecryptage23);
                                                      labelbloc2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                                                      rsaDecryptageLayout->addWidget(labelbloc2);
                                                      bloc2 = new QLineEdit(optionDecryptage23);
                                                      connect(bloc2, SIGNAL(textChanged(QString)), this, SLOT(coulInitSrcCheminCrypter()));
                                                      rsaDecryptageLayout->addWidget(bloc2);
                                                      optionDecryptageLayout2->addWidget(optionDecryptage23);

                                                      optionDecryptage24=new QPushButton(QIcon(":/images/texte/crypter.ico"), "visualiser l'arbre de Huffman", optionDecryptage2);
                                                      //connect(optionCryptage24, SIGNAL(clicked()), this, SLOT(crypter()));
                                                      optionDecryptageLayout2->addWidget(optionDecryptage24);

                                // Texte placer à gauche de la liste déroulante permettant de sélectionner la source de cryptage
                                labelChoixDecryptage2 = new QLabel("Nom du cryptage :",widgetCrypte);
                                labelChoixDecryptage2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

                            layoutCrypte->addWidget(labelChoixDecryptage2, 4, 0, 1, 1);

                                // Liste déroulante permettant de sélectionner la source de cryptage
                            choixDecryptage2 = new QComboBox(widgetCrypte);
                            choixDecryptage2->addItem("Vide");
                            choixDecryptage2->addItem("César");
                            choixDecryptage2->addItem("ROT13");
                            choixDecryptage2->addItem("Viginere");
                            choixDecryptage2->addItem("Che");
                            choixDecryptage2->addItem("Morse");
                            choixDecryptage2->addItem("Playfair");
                            choixDecryptage2->addItem("RSA");
                            choixDecryptage2->addItem("Huffman");

                               connect(choixDecryptage2, SIGNAL(activated(int)), optionDecryptageLayout2, SLOT(setCurrentIndex(int)));
                               connect(choixDecryptage2,SIGNAL(activated(int)),this, SLOT(fonction4()));

                            layoutCrypte->addWidget(choixDecryptage2, 4, 1, 1, 1);


                            // Rajoute une barre entre les deux zones du splitter
                            QSplitterHandle *handleSplitterTexte = splitterTexte->handle(1);
                            QHBoxLayout *layoutHandleSplitterTexte = new QHBoxLayout(handleSplitterTexte);
                            layoutHandleSplitterTexte->setContentsMargins(QMargins(0,5,0,5));
                            QFrame *lineHandleSplitterTexte = new QFrame(splitterTexte);
                            lineHandleSplitterTexte->setFrameShape(QFrame::VLine);
                            lineHandleSplitterTexte->setFrameShadow(QFrame::Raised);
                            layoutHandleSplitterTexte->addWidget(lineHandleSplitterTexte);




                      }


