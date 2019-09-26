#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include<bits/stdc++.h>
using namespace std ;
// Application Qt
#include <QApplication>
    #include<QKeySequence>
    #include<QTextEdit>
    #include<QTextCursor>

// Interface graphique

    // Conteneur
    #include <QMainWindow> // Fenêtre principale
    #include <QMenuBar> // // Menu de la fenêtre principale
        #include <QActionGroup> // Regoupe plusieurs actions dans une seule classe
    #include <QWidget> // Conteneur de base
    #include <QTabWidget> // Conteneur sous forme d'onglets
    #include <QSplitter> // Conteneur scindé à taille variable
    #include <QStackedLayout> // Conteneur de widget qui ne peut afficher qu'un seul des widgets qu'il contient à la fois
    #include <QToolBar> // Barre d'outils
    #include <QMessageBox> // Crée des fenêtres délivrant des messages d'informations
    // Layout
    #include <QVBoxLayout> // Layout vertical
    #include <QHBoxLayout> // Layout horizontal

    // Interaction avec l'utilisateur
    #include <QAction> // Actions Qt
    #include <QTextEdit> // Bloc de texte
    #include <QLineEdit> // Ligne de texte
    #include <QFileDialog> // Fenêtre d'ouverture / enregistrement de fichier
    #include <QPushButton> // Bouton à appuyer
    #include <QCheckBox> // Case à choix multiple à cocher/décocher
    #include <QComboBox> // Liste déroulante

    // Décoration
    #include <QLabel> // Affiche du texte ou des images
    #include <QFrame> // Permet de créer des bordures / lignes de séparation / etc pour les widgets



// Structure Qt
#include <QDir> // Gestion de dossier
#include <QFile> // Gestion de fichier
#include <QString> // Chaîne de caractère de Qt
#include <QTextStream> // Flux de texte
#include <QTextCodec> // Codec de texte


class FenetrePrincipale;
#include <qmath.h> // Classe mathématique de Qt




// Fenêtre principale du programme
class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

    // Attributs
    private :


        // Menu de la fenêtre
        QMenu *menuFichier;
            QAction* actionChargerNonCrypte;
            QAction* actionChargerCrypte;
            QAction* actionEnregistrerNonCrypte;
            QAction* actionEnregistrerCrypte;
            QAction* actionQuitter;
        QMenu* menuEdition;
            QAction* copier;
            QAction* couper;
            QAction* coller;
        QMenu* menuAide;
            QAction* actionAPropos;
            QAction* actionaboutqt;
            QString edition;
        // Widgets
        QWidget* widgetCentral;
            QVBoxLayout* layoutCentral;
                QWidget* widgetOnglet;
                         QVBoxLayout* layoutTexte;
                            QSplitter* splitterTexte;
                                QWidget* widgetNonCrypte;
                                    QGridLayout* layoutNonCrypte;
                                        QTextEdit* zoneTexteNonCrypte;
                                        QPushButton* boutonCrypter;
                                        QLabel* labelChoixCryptage;
                                        QComboBox* choixCryptage;
                                        QWidget* optionCryptage;
                                            QStackedLayout* optionCryptageLayout;
                                                QWidget* vide1;
                                                QWidget* optionCryptTexte;
                                                    QGridLayout* optionCryptTexteLayout;
                                                        QLineEdit* cheminCrypterSrcTexte;
                                                        QPushButton* parcourirCrypterSrcTexte;
                                        QLabel* labelChoixCryptage2;
                                        QComboBox* choixCryptage2;
                                        QWidget* optionCryptage2;
                                            QStackedLayout* optionCryptageLayout2;
                                                QWidget* optionCryptage20;
                                                QWidget* optionCryptage21;
                                                    QGridLayout* optionCryptTexteLayout2;
                                                        QLabel* clelabelCryptage;
                                                        QLineEdit* cleCryptage;
                                                QLabel* optionCryptage22;
                                                QWidget* optionCryptage23;
                                                    QGridLayout* rsaCryptageLayout;
                                                        QLabel* labelp;
                                                        QLineEdit* clep;
                                                        QLabel* labelq;
                                                        QLineEdit* cleq;
                                                        QLabel* labele;
                                                        QLineEdit* clee;
                                                        QLabel* labelbloc;
                                                        QLineEdit* bloc;
                                                QPushButton* optionCryptage24;

                                QWidget* widgetCrypte;
                                    QGridLayout* layoutCrypte;
                                        QTextEdit* zoneTexteCrypte;
                                        QPushButton* boutonDecrypter;
                                        QLabel* labelChoixDecryptage;
                                        QComboBox* choixDecryptage;
                                        QWidget* optionDecryptage;
                                            QStackedLayout* optionDecryptageLayout;
                                                QWidget* vide2;
                                                QWidget* optionDecryptTexte;
                                                    QGridLayout* optionDecryptTexteLayout;
                                                        QLineEdit* cheminDecrypterSrcTexte;
                                                        QPushButton* parcourirDecrypterSrcTexte;
                                                        QLabel* labelChoixDecryptage2;
                                                        QComboBox* choixDecryptage2;
                                                        QWidget* optionDecryptage2;
                                                            QStackedLayout* optionDecryptageLayout2;
                                                                QWidget* optionDecryptage20;
                                                                QWidget* optionDecryptage21;
                                                                    QGridLayout* optionDecryptTexteLayout2;
                                                                        QLabel* clelabelDecryptage;
                                                                        QLineEdit* cleDecryptage;
                                                                QLabel* optionDecryptage22;
                                                                QWidget* optionDecryptage23;
                                                                    QGridLayout* rsaDecryptageLayout;
                                                                        QLabel* labelp2;
                                                                        QLineEdit* clep2;
                                                                        QLabel* labelq2;
                                                                        QLineEdit* cleq2;
                                                                        QLabel* labele2;
                                                                        QLineEdit* clee2;
                                                                        QLabel* labelbloc2;
                                                                        QLineEdit* bloc2;
                                                                QPushButton* optionDecryptage24;



    // Constructeur
    public :
        FenetrePrincipale(QWidget *parent = 0);

    // Destructeur

       public :
        // Ouvre la fenêtre d'ouverture de fichier et retourne le chemin du fichier sélectionné
        QString ouvrirFichierChemin();
        // Ouvre la fenêtre d'ouverture de fichier et retourne le texte du fichier sélectionné
        QString ouvrirFichierTexte(QString chemin = QString());

    // Slots Qt
    public slots :

        // Interaction dans le menu principal
            // Chargement d'un fichier texte non crypté
            void chargerNonCrypte();
            // Chargement d'un fichier texte crypté
            void chargerCrypte();
            // Enregistrement du fichier texte non crypté
            void enregistrerNonCrypte();
            // Enregistrement du fichier texte crypté
            void enregistrerCrypte();
            // Fenêtre de dialogue affichant les crédits
            void aPropos();
            void aboutqt();
            void copierAction();
            void collerAction();
            void couperAction();


        // Interaction dans l'onglet "Texte"
            // Crypte le texte de la zone de gauche
            void crypter();
            // Décrypte le texte de la zone de droite
            void decrypter();
            // Sélectionne le texte utilisé pour crypter
            void ouvrirSrcTexteCrypter();
            // Sélectionne le texte utilisé pour décrypter
            void ouvrirSrcTexteDecrypter();

          // Changement de couleur dù à des erreurs dans les deux onglets
            // Colorie en rouge le chemin indiquant le texte pour crypter
            void coulErreurSrcCheminCrypter();
            // Colorie en rouge le chemin indiquant le texte pour décrypter
            void coulErreurSrcCheminDecrypter();
            // Rétablit la couleur d'origine du chemin indiquant le texte pour crypter
            void coulInitSrcCheminCrypter();
            // Rétablit la couleur d'origine du chemin indiquant le texte pour décrypter
            void coulInitSrcCheminDecrypter();
            void fonction1();
            void fonction2();
            void fonction3();
            void fonction4();

};



#endif // FENETREPRINCIPALE_H
