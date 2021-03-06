//
// Created by mathi on 2/7/2020.
//

#include "CharacterCreator.h"
#include "NameValidator.h"
#include "Formater.h"
#include "Attack.h"
#include <iostream>
#include <utility>


using std::cout;
using std::cin;
using std::endl;


Character* CharacterCreator::createPlayer() {
    std::string characterName = decidePlayerName();
    playableClass characterClass = decidePlayerClass();
    return createPlayerClass(characterClass, characterName);
}


std::string CharacterCreator::decidePlayerName() {
    bool nameIsNotDecided = true;
    std::string name;

    while (nameIsNotDecided) {
        cout << "Choose a character name." << endl;
        cin >> name;
        Formater::clear();
        if (NameValidator::isNameTaken(name, names))
            cout << "That name is already used. Try a different name." << endl;
        else {
            cout << "Your name is " << name
                 << ". It cannot be changed later. Are you sure you want to use that name? (y/n)" << endl;
            std::string response;
            cin >> response;
            if (response == "y")
                nameIsNotDecided = false;
        }
    }
    names.insert(name);
    return name;
}

playableClass CharacterCreator::decidePlayerClass() {
    bool classIsNotDecided = true;
    playableClass chosenClass;

    while (classIsNotDecided) {
        Formater::clear();
        cout << endl << "You can choose a class now. What would you like to player?" << endl;
        int pickedClass;
        cout << "(0) Wizard " << " | (1) Orc" << " | (2) Warrior" << " | (3) Rouge"<< endl;
        cin >> pickedClass;
        cout << typeid(pickedClass).name();
        ///TODO: validate input
        Formater::clear();
        cout << "You choose to be a";

        switch (pickedClass) {
            case 0:
                chosenClass = Wizard;
                break;
            case 1:
                cout <<"n";
                chosenClass = Orc;
                break;
            case 2:
                chosenClass = Warrior;
                break;
            case 3:
                chosenClass = Rouge;
                break;
            default:
                cout << " out of bounds Class, nice try :)";
                exit(0);
        }
        cout << " " << playableClassAsString[chosenClass] << ". You cannot change class later, are you sure? (y/n)" << endl;
        std::string response;
        cin >> response;

        if(response == "y"){
            classIsNotDecided = false;
        }


    }

    return chosenClass;


}

Character* CharacterCreator::createPlayerClass(playableClass characterClass, std::string characterName) {
    Character * character;
    switch (characterClass){
        case Wizard: {
            character = new Character(100, 5, std::move(characterName), "Wizard");
            character->addAttack(new Attack(100, 3, "Fire ball"));
            character->addAttack(new Attack(50, 1, "Water blast"));
            character->addAttack(new Attack(80, 1, "Tangling roots"));
            character->addAttack(new Attack(20, 0, "Air burst"));
            return character;
        }

        case Orc: {
            character = new Character(300, 20, std::move(characterName), "Orc");
            character->addAttack(new Attack(50, 1, "Cleave"));
            character->addAttack(new Attack(80, 3, "Blood lust"));
            character->addAttack(new Attack(40, 1, "Axe throw"));
            character->addAttack(new Attack(15, 0, "Crush"));
            return character;
        }
        case Warrior: {
            character = new Character(200, 30, std::move(characterName), "Warrior");
            character->addAttack(new Attack(80, 4, "Slash"));
            character->addAttack(new Attack(50, 2, "Stab"));
            character->addAttack(new Attack(30, 1, "Kick"));
            character->addAttack(new Attack(10, 0, "Punch"));
            return character;
            }
        case Rouge: {
            character = new Character(100, 40, std::move(characterName), "Rouge");
            character->addAttack(new Attack(50, 2, "Backstab"));
            character->addAttack(new Attack(80, 3, "Blade fury"));
            character->addAttack(new Attack(60, 3, "Bow shot"));
            character->addAttack(new Attack(25, 0, "Sneak strike"));

            return character;
        }
    }
}

