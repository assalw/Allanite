//
// Created by Wadie Assal on 25-12-17.
//

#include "../include/Model.h"

Model::Model(GLuint vaoID, int vertexCount)
{
    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
}

GLuint Model::getVaoID() const
{
    return vaoID;
}

void Model::setVaoID(GLuint vaoID)
{
    Model::vaoID = vaoID;
}

int Model::getVertexCount() const
{
    return vertexCount;
}

void Model::setVertexCount(int vertexCount)
{
    Model::vertexCount = vertexCount;
}

Model::~Model()
{

}
