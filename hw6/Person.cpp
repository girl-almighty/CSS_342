//
//  Person.cpp
//  hw5
//
//  Created by Iris Favoreal on 11/24/17.
//  Copyright © 2017 Iris Favoreal. All rights reserved.
//

#include "Person.hpp"

Person::Person() {}
Person::~Person() {}

void Person::setName(string nm)
{
    name = nm;
}

string Person::getName()
{
    return name;
}
