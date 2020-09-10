#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include "Score.h"

int main() {

  std::set<Score> ArbreScore;
  std::string tampon;
  std::ifstream lecteur("hiscore.txt");

  Score nouveau;

//lecture, creation des objets score et stockage dans le set
  while(!lecteur.eof()) {

    lecteur>>tampon;
    nouveau.setNumPartie(std::stol(tampon));

    lecteur>>tampon;
    nouveau.setLogin(tampon);
   
    lecteur>>tampon;
    nouveau.setScore(std::stol(tampon));

    ArbreScore.insert(nouveau);
  }
  lecteur.close();

  //ecriture dans le deuxieme ficher texte
  std::ofstream fichier("asterostorm.txt");

  if (fichier.is_open()){
      std::set<Score>::iterator iterateur;
    for (iterateur = ArbreScore.begin() ; iterateur!=ArbreScore.end() ; iterateur++){
      fichier<<iterateur->getLogin()<<std::endl;
      fichier<<iterateur->getNumPartie()<<std::endl;
      fichier<<"Asterostorm="<<iterateur->getScore()<<std::endl;

    }
  }
  else{std::cout<<"Oups! le fichier n'est pas ouvert."<<std::endl;}

  fichier.close();
}



