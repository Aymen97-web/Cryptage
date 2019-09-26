#include "include/fenetreprincipale.h"
#include "include/codage.h"
#include "include/RSA.h"



// Ouvre la fenêtre d'ouverture de fichier et retourne le chemin du fichier sélectionné
QString FenetrePrincipale::ouvrirFichierChemin()
{
    return QFileDialog::getOpenFileName(widgetCentral, "Choississez votre fichier texte", QDir::homePath(), "Texte (*);;All(*.*)");
}

/* Ouvre la fenêtre d'ouverture de fichier si le chemin en argument est vide
 * et retourne le texte du fichier sélectionné */
QString FenetrePrincipale::ouvrirFichierTexte(QString chemin)
{
    if(chemin.isEmpty())
    {
        // On demande à l'utilisateur le fichier qu'il souhaite charger
        chemin = ouvrirFichierChemin();
    }

    QString texte;
    // On vérifie que le chemin du fichier n'est pas vide
    if(!chemin.isEmpty())
    {
        QFile fichier(chemin);

        // Ouverture du fichier en lecture seule en tant que texte
        if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream fluxFichier(&fichier);

            // On vérifie le codec du texte
            QTextCodec::ConverterState state;
            QTextCodec *codec = QTextCodec::codecForName("UTF-8");
            codec->toUnicode(fichier.readAll(), fichier.size(), &state);

            // On revient au début du fichier texte
            fichier.seek(0);

            // Texte en UTF 8
            if (state.invalidChars <= 0)
            {
                // On récupère le texte du fichier
                texte = fichier.readAll();
            }
            // Autre type de texte (ANSI etc...)
            else
            {
                // On récupère le texte du fichier
                texte = fluxFichier.readAll();
            }

            // Fermeture du fichier
            fichier.close();
        }
        // Si le fichier n'a pas pu s'ouvrir
        else
        {
            // On affiche une fenêtre de dialogue d'erreur
            QMessageBox::critical(this, "Erreur d'ouverture de fichier", "Impossible d'ouvrir ce fichier !");
           }
    }

    // On retourne le texte
    return texte;
}




// Slots Qt


// Interaction dans le menu principal

// Chargement d'un fichier texte non crypté
void FenetrePrincipale::chargerNonCrypte()
{
    // On demande à l'utilisateur son fichier et on récupère le texte de celui-ci
    QString texteNonCrypte = ouvrirFichierTexte();

    // Si le fichier n'est pas vide
    if(!texteNonCrypte.isEmpty())
    {
        // On place le texte dans la zone de texte non cryptée
        zoneTexteNonCrypte->setText(texteNonCrypte);

        // Alignement du texte en justifié
        zoneTexteNonCrypte->setAlignment(Qt::AlignJustify);
    }
}

// Chargement d'un fichier texte crypté
void FenetrePrincipale::chargerCrypte()
{
    // On demande à l'utilisateur son fichier et on récupère le texte de celui-ci
    QString texteCrypte = ouvrirFichierTexte();

    // Si le fichier n'est pas vide
    if(!texteCrypte.isEmpty())
    {
        // On place le texte dans la zone de texte cryptée
        zoneTexteCrypte->setText(texteCrypte);

        // Alignement du texte en justifié
        zoneTexteCrypte->setAlignment(Qt::AlignJustify);
    }
}

// Enregistrement du fichier texte non crypté
void FenetrePrincipale::enregistrerNonCrypte()
{
    // Demande à l'utilisateur où enregister son texte
    QString chemin(QFileDialog::getSaveFileName(widgetCentral, "Enregistrer votre fichier texte", QDir::homePath(), "Texte (*.txt);;All(*.*)"));

    // On vérifie que le chemin indiqué n'est pas vide
    if(!chemin.isEmpty())
    {
        QFile fichier(chemin);

        // Ouverture du fichier en lecture/écriture en tant que texte
        if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            // On écrit dans le fichier tout ce qui est contenu dans la zone de texte de gauche
            QTextStream fluxFichier(&fichier);
            fluxFichier << zoneTexteNonCrypte->toPlainText();

            // On ferme le fichier
            fichier.close();
        }
        // Si le fichier à écrire n'a pas pu s'ouvrir
        else
        {
            // On affiche une fenêtre de dialogue d'erreur
            QMessageBox::critical(this, "Erreur d'enregistrement du texte", "Impossible d'enregistrer le texte !");
        }
    }
}

// Enregistrement du fichier texte crypté
void FenetrePrincipale::enregistrerCrypte()
{
    // Demande à l'utilisateur où enregister son texte
    QString chemin(QFileDialog::getSaveFileName(widgetCentral, "Enregistrer votre fichier texte", QDir::homePath(), "Texte (*.txt);;All(*.*)"));

    // On vérifie que le chemin indiqué n'est pas vide
    if(!chemin.isEmpty())
    {
        QFile fichier(chemin);

        // Ouverture du fichier en lecture/écriture en tant que texte
        if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            // On écrit dans le fichier tout ce qui est contenu dans la zone de texte de droite
            QTextStream fluxFichier(&fichier);
            fluxFichier << zoneTexteCrypte->toPlainText();

            // On ferme le fichier
            fichier.close();
        }
        // Si le fichier à écrire n'a pas pu s'ouvrir
        else
        {
            // On affiche une fenêtre de dialogue d'erreur
            QMessageBox::critical(this, "Erreur d'enregistrement du texte", "Impossible d'enregistrer le texte !");
        }
    }
}

// Fenêtre de dialogue affichant les crédits
void FenetrePrincipale::aPropos()
{
    QMessageBox::about(this, "À propos...", "<p><b>Cryptage & Décryptage</b><br/>"
                                            "<b>Version :</b> 1.0<br/>"
                                            "<b>Développé par :</b> oussema yengui & aymen nsira<br/>"
                                            "<b>Librairie utilisée :</b> Qt 5<br/>"
                                            "<b>Logo : </b>Coccinelle"
                                            "<p>Codé dans le cadre d'un stage d'été à l'<a href='http://www.ensi-uma.tn/'>ENSI</a></p>"
                                            "<p><a href='http://www.ensi-uma.tn/'><img style='display: block; margin: auto; width 100%;' src=':/images/menu/aide/ensi.png'/></a></p>");
}
void FenetrePrincipale::aboutqt()
{
    QMessageBox::aboutQt(this);
}


// Crypte le texte de la zone de gauche
void FenetrePrincipale::crypter()
{
    QString srcCryptageTexte;
    QString texteACrypter = zoneTexteNonCrypte->toPlainText();

    if(choixCryptage->currentText() == "Fichier texte")
    {
    if(cheminCrypterSrcTexte->text().isEmpty())
        {
            QMessageBox::warning(this, "Warning !", "Indiquez le chemin d'un fichier texte pour pouvoir crypter votre texte !");
            coulErreurSrcCheminCrypter();
        }
        else
        {
            QString srcCryptageTexte = ouvrirFichierTexte(cheminCrypterSrcTexte->text());

            if(!srcCryptageTexte.isEmpty())
            {       switch(choixCryptage2->currentIndex())
                {case 0:{QMessageBox::warning(this, "Warning!", "Indiquez le type de crypatge pour pouvoir crypter votre texte !");
                        break;}
                case 1:{chiffredecesar chif=chiffredecesar(atoi(cleCryptage->text().toUtf8().constData()),srcCryptageTexte.toUtf8().constData());
                            chif.crypter();
                            zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                            break;}
                 case 2:{chiffredecesar chif=chiffredecesar(13,srcCryptageTexte.toUtf8().constData());
                            chif.crypter();
                            zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                            break;}
                case 3:{chiffredevigenere chif=chiffredevigenere(cleCryptage->text().toUtf8().constData(),srcCryptageTexte.toUtf8().constData());
                          chif.crypter();
                          zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                          break;}
                case 4:{chiffreduche chif=chiffreduche(cleCryptage->text().toUtf8().constData(),srcCryptageTexte.toUtf8().constData());
                          chif.crypter();
                          zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                          break;}
                case 5:{chiffredemorse chif=chiffredemorse(srcCryptageTexte.toUtf8().constData());
                            chif.crypter();
                            zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                            break;}
                case 6:{chiffredeplayfair chif=chiffredeplayfair(cleCryptage->text().toUtf8().constData(),srcCryptageTexte.toUtf8().constData());
                            chif.crypter();
                            zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                            break;}
                case 7:{RSA chif;
                    chif.cle_public(atoi(clep->text().toUtf8().constData()),atoi(cleq->text().toUtf8().constData()),atoi(clee->text().toUtf8().constData()),atoi(bloc->text().toUtf8().constData()));
                    switch (chif.condition_RSA()) {
                    case 0:
                           {  chif.cle_privee();
                              chif.getcle();
                              chif.settexte(srcCryptageTexte.toUtf8().constData());
                              chif.crypter();
                              zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                              break;}
                    case 1:{QMessageBox::warning(this, "Condition RSA non verifié!", "p n'est pas premier !");
                              break;}
                    case 2:{QMessageBox::warning(this, "Condition RSA non verifié!", "q n'est pas premier !");
                              break;}
                    case 3:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre comprise entre max(p,q) et phi(n) !");
                              break;}
                    case 4:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre premier avec phi(n) !");
                              break;}
                    case 5:{QMessageBox::warning(this, "Condition RSA non verifié!", "risque d'erreur si le message dépasse n !");
                              break;}

                    }break;}

                //case 8:


                }

            }
        }
    }
    else if(choixCryptage->currentText() == "Le texte lui-même")
    {
        srcCryptageTexte = zoneTexteNonCrypte->toPlainText();
        switch(choixCryptage2->currentIndex())
                     {
                      case 0:{QMessageBox::warning(this, "Warning!", "Indiquez le type de crypatge pour pouvoir crypter votre texte !");
                                break;}
                      case 1:{chiffredecesar chif=chiffredecesar(atoi(cleCryptage->text().toUtf8().constData()),texteACrypter.toUtf8().constData());
                                 chif.crypter();
                                 zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                 break;}
                      case 2:{chiffredecesar chif=chiffredecesar(13,texteACrypter.toUtf8().constData());
                                chif.crypter();
                                zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 3:{chiffredevigenere chif=chiffredevigenere(cleCryptage->text().toUtf8().constData(),texteACrypter.toUtf8().constData());
                                chif.crypter();
                                zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 4:{chiffreduche chif=chiffreduche(cleCryptage->text().toUtf8().constData(),texteACrypter.toUtf8().constData());
                                chif.crypter();
                                zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 5:{chiffredemorse chif=chiffredemorse(texteACrypter.toUtf8().constData());
                                chif.crypter();
                                zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 6:{chiffredeplayfair chif=chiffredeplayfair(cleCryptage->text().toUtf8().constData(),texteACrypter.toUtf8().constData());
                                chif.crypter();
                                zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 7:{RSA chif;
                                 chif.cle_public(atoi(clep->text().toUtf8().constData()),atoi(cleq->text().toUtf8().constData()),atoi(clee->text().toUtf8().constData()),atoi(bloc->text().toUtf8().constData()));
                                 switch (chif.condition_RSA()) {
                                 case 0:
                                        {  chif.cle_privee();
                                           chif.getcle();
                                           chif.settexte(texteACrypter.toUtf8().constData());
                                           chif.crypter();
                                           zoneTexteCrypte->setText(QString::fromStdString(chif.gettexte()));
                                           break;}
                                 case 1:{QMessageBox::warning(this, "Condition RSA non verifié!", "p n'est pas premier !");
                                           break;}
                                 case 2:{QMessageBox::warning(this, "Condition RSA non verifié!", "q n'est pas premier !");
                                           break;}
                                 case 3:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre comprise entre max(p,q) et phi(n) !");
                                           break;}
                                 case 4:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre premier avec phi(n) !");
                                           break;}
                                 case 5:{QMessageBox::warning(this, "Condition RSA non verifié!", "risque d'erreur si le message dépasse n !");
                                           break;}
                                 }break;
                               }

                      //case 8:

                      };

        }
                     }

// Décrypte le texte de la zone de droite
void FenetrePrincipale::decrypter()
{ QString srcDecryptageTexte;
    QString texteADecrypter = zoneTexteCrypte->toPlainText();

    if(choixDecryptage->currentText() == "Fichier texte")
    {
    if(cheminDecrypterSrcTexte->text().isEmpty())
        {
            QMessageBox::warning(this, "Indiquez un fichier texte !", "Indiquez le chemin d'un fichier texte pour pouvoir crypter votre texte !");
            coulErreurSrcCheminCrypter();
        }
        else
        {
            QString srcDecryptageTexte = ouvrirFichierTexte(cheminDecrypterSrcTexte->text());

            if(!srcDecryptageTexte.isEmpty())
            {       switch(choixDecryptage2->currentIndex())
                {case 0:{QMessageBox::warning(this, "Warning!", "Indiquez le nom de crypatge pour pouvoir decrypter votre texte !");
                    break;}
                case 1:{chiffredecesar chif=chiffredecesar(atoi(cleDecryptage->text().toUtf8().constData()),srcDecryptageTexte.toUtf8().constData());
                            chif.decrypter();
                            zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                            break;}
                 case 2:{chiffredecesar chif=chiffredecesar(13,srcDecryptageTexte.toUtf8().constData());
                            chif.decrypter();
                            zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                    break;}
                case 3:{chiffredevigenere chif=chiffredevigenere(cleDecryptage->text().toUtf8().constData(),srcDecryptageTexte.toUtf8().constData());
                          chif.decrypter();
                          zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                          break;}
                case 4:{chiffreduche chif=chiffreduche(cleDecryptage->text().toUtf8().constData(),srcDecryptageTexte.toUtf8().constData());
                          chif.decrypter();
                          zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                          break;}
                case 5:{chiffredemorse chif=chiffredemorse(srcDecryptageTexte.toUtf8().constData());
                          chif.decrypter();
                          zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                          break;}

                case 6:{chiffredeplayfair chif=chiffredeplayfair(cleDecryptage->text().toUtf8().constData(),srcDecryptageTexte.toUtf8().constData());
                         /* chif.decrypter();
                          zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));*/
                          break;}
                case 7:{RSA chif;
                           chif.cle_public(atoi(clep2->text().toUtf8().constData()),atoi(cleq2->text().toUtf8().constData()),atoi(clee2->text().toUtf8().constData()),atoi(bloc2->text().toUtf8().constData()));
                           switch (chif.condition_RSA()) {
                           case 0:
                                  {  chif.cle_privee();
                                     chif.getcle();
                                     chif.settexte(srcDecryptageTexte.toUtf8().constData());
                                     chif.decrypter();
                                     zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                     break;}
                           case 1:{QMessageBox::warning(this, "Condition RSA non verifié!", "p n'est pas premier !");
                                     break;}
                           case 2:{QMessageBox::warning(this, "Condition RSA non verifié!", "q n'est pas premier !");
                                     break;}
                           case 3:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre comprise entre max(p,q) et phi(n) !");
                                     break;}
                           case 4:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre premier avec phi(n) !");
                                     break;}
                           case 5:{QMessageBox::warning(this, "Condition RSA non verifié!", "risque d'erreur si le message dépasse n !");
                                     break;}

                           }
                            break;}

                //case 8:
                }

            }
        }
    }
    else if(choixDecryptage->currentText() == "Le texte lui-même")
    {
        srcDecryptageTexte = zoneTexteCrypte->toPlainText();
        switch(choixDecryptage2->currentIndex())
                     {case 0:{QMessageBox::warning(this, "Warning!", "Indiquez le nom de crypatge pour pouvoir decrypter votre texte !");
                                 break;}
                      case 1:{chiffredecesar chif=chiffredecesar(atoi(cleDecryptage->text().toUtf8().constData()),texteADecrypter.toUtf8().constData());
                                 chif.decrypter();
                                 zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                 break;}
                      case 2:{chiffredecesar chif=chiffredecesar(13,texteADecrypter.toUtf8().constData());
                                 chif.decrypter();
                                 zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                 break;}
                      case 3:{chiffredevigenere chif=chiffredevigenere(cleDecryptage->text().toUtf8().constData(),texteADecrypter.toUtf8().constData());
                                chif.decrypter();
                                zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 4:{chiffreduche chif=chiffreduche(cleDecryptage->text().toUtf8().constData(),texteADecrypter.toUtf8().constData());
                                chif.decrypter();
                                zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 5:{chiffredemorse chif=chiffredemorse(texteADecrypter.toUtf8().constData());
                                chif.decrypter();
                                zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                break;}
                      case 6:{chiffredeplayfair chif=chiffredeplayfair(cleDecryptage->text().toUtf8().constData(),texteADecrypter.toUtf8().constData());
                               /* chif.decrypter();
                                zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));*/
                                break;}
                      case 7:{RSA chif;
                                chif.cle_public(atoi(clep2->text().toUtf8().constData()),atoi(cleq2->text().toUtf8().constData()),atoi(clee2->text().toUtf8().constData()),atoi(bloc2->text().toUtf8().constData()));
                                switch (chif.condition_RSA()) {
                                case 0:
                                       {  chif.cle_privee();
                                          chif.getcle();
                                          chif.settexte(texteADecrypter.toUtf8().constData());
                                          chif.decrypter();
                                          zoneTexteNonCrypte->setText(QString::fromStdString(chif.gettexte()));
                                          break;}
                                case 1:{QMessageBox::warning(this, "Condition RSA non verifié!", "p n'est pas premier !");
                                          break;}
                                case 2:{QMessageBox::warning(this, "Condition RSA non verifié!", "q n'est pas premier !");
                                          break;}
                                case 3:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre comprise entre max(p,q) et phi(n) !");
                                          break;}
                                case 4:{QMessageBox::warning(this, "Condition RSA non verifié!", "e doit étre premier avec phi(n) !");
                                          break;}
                                case 5:{QMessageBox::warning(this, "Condition RSA non verifié!", "risque d'erreur si le message dépasse n !");
                                          break;}
                                }
                                break;}


                                }
                    //case 8:

        }}
void FenetrePrincipale::ouvrirSrcTexteCrypter()
{
    cheminCrypterSrcTexte->setText(ouvrirFichierChemin());
}

// Sélectionne le dictionnaire utilisé pour décrypter
void FenetrePrincipale::ouvrirSrcTexteDecrypter()
{
    cheminDecrypterSrcTexte->setText(ouvrirFichierChemin());
}


// Colorie en rouge le chemin indiquant le texte pour crypter
void FenetrePrincipale::coulErreurSrcCheminCrypter()
{
    cheminCrypterSrcTexte->setStyleSheet("border : 1px solid red; padding: 1px; ");
}

// Colorie en rouge le chemin indiquant le texte pour décrypter
void FenetrePrincipale::coulErreurSrcCheminDecrypter()
{
    cheminDecrypterSrcTexte->setStyleSheet("border : 1px solid red; padding: 1px;");
}

// Rétablit la couleur d'origine du chemin indiquant le texte pour crypter
void FenetrePrincipale::coulInitSrcCheminCrypter()
{
    cheminCrypterSrcTexte->setStyleSheet("");
}

// Rétablit la couleur d'origine du chemin indiquant le texte pour décrypter
void FenetrePrincipale::coulInitSrcCheminDecrypter()
{
    cheminDecrypterSrcTexte->setStyleSheet("");

}
void FenetrePrincipale::copierAction()
{
  /* QTextCursor cursor=this->cursor();
    //QTextCursor cursor=zoneTexteNonCrypte->textCursor();
    if(cursor.selectedText()!="")
    edition=cursor.selectedText();*/

}
void FenetrePrincipale::collerAction()
{
     /*QTextCursor cursor=this->cursor();
    // QTextCursor cursor=zoneTexteCrypte->textCursor();
      cursor.beginEditBlock();
      cursor.insertText(edition);
      cursor.endEditBlock();*/

}
void FenetrePrincipale::couperAction()
{

    /*QTextCursor cursor0=zoneTexteNonCrypte->textCursor();
    edition=cursor0.selectedText();
   cursor0.deleteChar();*/

}
