//
//  movie.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "movie.h"
#include "nodedata.h"
using namespace std;

Movie *Movie::getType(genre){
    if(genre =='F'){
        return new Comedy(); //.create();
    }else if(genre== 'D'){
        return new Drama();
    }else if(genre == 'C'){
        return new Classic();
    }
    
}
