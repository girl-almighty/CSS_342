//
//  Student.hpp
//  hw5
//
//  Created by Iris Favoreal on 11/27/17.
//  Copyright © 2017 Iris Favoreal. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include "Person.hpp"

class Student : public Person
{
public:
    void trackMe();
};

#endif /* Student_hpp */
