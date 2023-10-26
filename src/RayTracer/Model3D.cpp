#include "Model3D.h"
#include <iostream>
#include <fstream>

void Model3D::Load(const std::string_view &file_name) {
    FILE* file = fopen(file_name.data(), "r");
    if (!file) {
        std::cerr << "Error: failed open file: " << file_name << "\n";
        return;
    }

    while (1) {
        float x, y, z;
        if (fscanf(file, "v %f %f %f \n", &x, &y, &z) != 3) break;
        vertices.push_back({x, y, z});
    }

    while (1) {
        float a, b;
        if (fscanf(file, " %f %f \n", &a, &b) != 2) break;
    }

    while (1) {
        float a, b, c;
        if (fscanf(file, "vn %f %f %f \n", &a, &b, &c) != 3) break;
    }

    while (1) {
        int id1, id2, id3, id4;

        int cnt = fscanf(file, "f %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d", &id1, &id2, &id3, &id4);
        if (cnt < 3) {
            break;
        }

        fscanf(file, " %*d/%*d/%*d ");
        fscanf(file, " %*d/%*d/%*d \n");

        if (cnt == 4) {
            indexes.push_back(id1);
            indexes.push_back(id2);
            indexes.push_back(id4);

            indexes.push_back(id2);
            indexes.push_back(id3);
            indexes.push_back(id4);
        } else {
            indexes.push_back(id1);
            indexes.push_back(id2);
            indexes.push_back(id3);
        }
    }

    std::cout << indexes.size() << "\n";
    exit(0);

    // for (const auto& u: indexes) {
    //     std::cout << u << " ";
    // }

    fclose(file);
}

float Model3D::RayIntersect(const Vector3 &orig, const Vector3 &dir) {
    
}
