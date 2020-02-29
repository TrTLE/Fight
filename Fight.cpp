// Fight.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Character.h"
#include "Monster.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    //initialise le chemin du fichier de sauvegarde
    char buffer[_MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    string::size_type pos = string(buffer).rfind("\\Fight\\");
    string const fileName = string(buffer).substr(0, pos) + "\\Fight\\savefile.txt";

    //une partie variable utiles à une partie
    bool play = true;
    char action;
    Character player = Character("Link", 100, 10, 0, 1);

    //ouverture du fichier de sauvegarde et récupération des stats du joueur
    ifstream myInStream(fileName.c_str());

    if (myInStream)
    {
        string playerName, playerLevel, playerExperience, playerLife, playerDamage;
        getline(myInStream, playerName);
        getline(myInStream, playerLevel);
        getline(myInStream, playerExperience);
        getline(myInStream, playerLife);
        getline(myInStream, playerDamage);

        player = Character(playerName, stoi(playerLife), stoi(playerDamage), stoi(playerExperience), stoi(playerLevel));

        myInStream.close();
    }
    else
    {
        cout << "Erreur: Impossible d'ouvrir le fichier de sauvegarde." << endl << endl;
    }

    //Lancement du jeu
    while (play)
    {
        //initialisation des personnages
        Monster monster = Monster("Korbo", 30, 2, 50);
        
        //affiche le nom et les stats du joueur
        cout << endl;
        cout << player.getName() << " vos stats sont" << endl;
        player.showStat();

        cout << "Debut de la partie" << endl << endl;

        while (monster.isAlive())
        {
            do
            {
                cout << "ATTAQUER - a" << endl;
                cin >> action;

                if (action != 'a')
                {
                    cout << "Veuillez entrer la valeur attendue" << endl << endl;
                }
            } while (action != 'a');

            cout << endl << endl;

            player.attack(monster);

            cout << endl << "Il reste " << monster.getLife() << " points de vie au monstre" << endl << endl;
        }//Fin Tour

        cout << "Bravo vous avez tuer un " << monster.getName() << endl << endl;

        player.winExperience(monster);
        player.levelUp();

        bool wrongEnter = false;

        do
        {
            
            if (wrongEnter)
            {
                cout << "Vous n'avez pas saisie o ou n" << endl << endl;
                cout << "Entrer 'o' pour recommencer ou 'n' pour arreter" << endl;
            }
            else
            {
                cout << "Une nouvelle partie ? o - n" << endl;
                wrongEnter = true;
            }
            cin >> action;

        } while ((action != 'o') && (action != 'n'));

        if (action == 'o')
        {
            cout << "OK. Bonne chance pour cette nouvelle partie" << endl;

        }
        else
        {
            cout << ":( c'est votre choix. AU REVOIR" << endl;
            play = false;
        }

    }//Fin Partie

    //sauvegarde des stats du joueur
    ofstream myStream(fileName.c_str());

    if (myStream)
    {
        myStream << player.getName() << endl;
        myStream << player.getLevel() << endl;
        myStream << player.getExperience() << endl;
        myStream << player.getLife() << endl;
        myStream << player.getDamage() << endl;

        myStream.close();
    }
    else
    {
        cout << "Erreur: Impossible d'ouvrir le fichier de sauvegarde." << endl << endl;
    }

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
