#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <string_view>
#pragma once

class Texture2D {
  public:
    unsigned int ID;
    int width, height;
    Texture2D(std::string_view filePath);
    ~Texture2D();

    void bind(unsigned int slot = 0) const;
};

#endif // TEXTURE_H_
