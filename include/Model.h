//
// Created by Wadie Assal on 25-12-17.
//

#ifndef ALLANITE_MODEL_H
#define ALLANITE_MODEL_H

#include <SDL_opengl.h>

class Model
{
private:
    GLuint vaoID;
    int vertexCount;

public:
    Model(GLuint vaoID, int vertexCount);

    GLuint getVaoID() const;
    void setVaoID(GLuint vaoID);

    int getVertexCount() const;
    void setVertexCount(int vertexCount);

    ~Model();
};

#endif //ALLANITE_MODEL_H
