//
// Created by mathi on 2/7/2020.
//

#include "NameValidator.h"

///doesnt work for some reason
bool NameValidator::isNameTaken(const std::string& name, const std::set<std::string>& names) {
    return names.find(name) != names.end();



}
