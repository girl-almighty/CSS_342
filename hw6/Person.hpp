//
//  Person.hpp
//  hw5
//
//  Created by Iris Favoreal on 11/24/17.
//  Copyright © 2017 Iris Favoreal. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
public:
    Person();
    ~Person();
    void setName(string nm);
    string getName();
};

#endif /* Person_hpp */
