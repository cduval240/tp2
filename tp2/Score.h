#ifndef _SCORE_H_
#define _SCORE_H_

#include <string>

class Score{

  private:
    long numPartie;
    std::string login;
    long score;

  public:
    Score(long numPartie,std::string login, long score){
      this->numPartie=numPartie;
      this->login=login;
      this->score=score;
    }

    Score(){
       this->numPartie=0;
      this->login="";
      this->score=0;
    }

    void setNumPartie(long numPartie){this->numPartie=numPartie;}
    void setLogin(std::string login){ this->login=login;}
    void setScore(long score) {this->score=score;}

    long getNumPartie()const {return this->numPartie;}
    std::string getLogin()const {return this->login;}
    long getScore()const {return this->score;}

    bool operator<(const Score& autre_score) const {
      if (this->score > autre_score.score) return true;
      return false;
    }


};

#endif