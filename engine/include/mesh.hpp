#ifndef MESH_H_
#define MESH_H_
#include <vector>

class Mesh2D {
  private:
    unsigned int VAO, VBO;
    int vertexCount;

  public:
    Mesh2D(const std::vector<float> &vertices);
    ~Mesh2D();

    void draw() const;
};

#endif // MESH_H_
