// Application Qt
#include <QApplication>

// Fenêtre principale du programme
#include "include/fenetreprincipale.h"
// Fonction principale
int main(int argc, char** argv)
{
    // Initialisation de l'application Qt
    QApplication app(argc, argv);
    app.setApplicationName("Cryptage & Décryptage");
    app.setWindowIcon(QIcon(":/images/ladybug_002.png"));


    // Initialisation de la fenêtre principale
    FenetrePrincipale fMain;

    // Affichage de la fenêtre principale
    fMain.show();

    // Exécution de l'application Qt
    return app.exec();
}
