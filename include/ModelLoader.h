//
// Created by Wadie Assal on 25-12-17.
//

#ifndef ALLANITE_MODELLOADER_H
#define ALLANITE_MODELLOADER_H


#include "Model.h"

class ModelLoader
{
public:
    ModelLoader();

    Model loadModel(float vertices[], int size);

    virtual ~ModelLoader();

};

#endif //ALLANITE_MODELLOADER_H
