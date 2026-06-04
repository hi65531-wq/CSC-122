//Programmer: Christopher Hercules
//Purpose: Creating a class that represents a hero

#include <iostream>
using namespace std;

class Hero
{
    private:
    string name;
    int strength;
    int courage;

    public:
    Hero(string heroName)
    {
        name = heroName;
        strength = rand() % 100 + 1; // random strength between 1 and 100
        courage = rand() % 100 + 1; // random courage between 1 and 100
    }

    //getters for the hero's attributes
    string getName()
    {
        return name;
    }

    int getStrenght()
    {
        return strength;
    }

    int getCourage()
    {
        return courage;
    }

    // methods to train and attend therapy
    void attendTraining(int time)
    {
        strength += time * 2;

        cout << name << " trained for " << time << " hours and increased strength to " << strength << endl;
    }

    void setCourage(int newCourage)
    {
        courage = newCourage;
    }

    void attendTherapy()
    {
        int boostCourage = rand() % 20 + 1; // random boost between 1 and 20
        courage += boostCourage;

        cout << name << " gained " << boostCourage << " courage from therapy and now has " << courage << " courage" << endl;
    }

};

// sending heros on quests and calculating results 
void sendOnQuest(Hero& hero)
{
    int strength = hero.getStrenght();

    int chanceOfSuccess = strength;
    if (chanceOfSuccess > 80)
    {
        chanceOfSuccess = 80;
    }

    int roll = rand() % 100;
    string result;
    if (roll < chanceOfSuccess)
    {
        result = "Successful";
        hero.setCourage(hero.getCourage() - 5);    
    }
    else if (roll < chanceOfSuccess + 10)
    {
        result = "Neutral";
        hero.setCourage(hero.getCourage() - 15);
    }
    else
    {
        result = "Failure";
        hero.setCourage(hero.getCourage() - 35);
    }

    if (hero.getCourage() < 0)
    {
        hero.setCourage(0);
    }

    cout << hero.getName() << " went on a quest: " << result << endl;
}

int main()
{
    srand(time(0));

    Hero hero1("Hercules");
    Hero hero2("Perseus");

    Hero heroes[] = {hero1, hero2};

    for (int i = 0; i <= 5; i++)
    {
        cout << "Round " << i << ":" << endl;
        
        for (Hero& hero : heroes)
        {
            hero.attendTraining(i);
            hero.attendTherapy();
            sendOnQuest(hero);

            cout << hero.getName() << " has strength: " << hero.getStrenght() << " and courage: " << hero.getCourage() << endl;
            cout << endl;
        }
    }

    return 0;
}