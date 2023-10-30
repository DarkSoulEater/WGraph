#ifndef ___BROKENLINE_H___
#define ___BROKENLINE_H___

#include "Figure.h"
#include "Math/Vector2.h"
#include "Photoshop/Tool/Color.h"

class BrokenLine : public Figure {
public:
    BrokenLine() {}
    
    virtual void Draw(sf::RenderTarget& rt) override;

    sf::Vertex& GetLastVertex() { return vertexs_[vertexs_.size() - 1]; }

    void AddPoint(Vector2 point, Color color = Color::Red);
private:
    std::vector<sf::Vertex> vertexs_;
};

#endif // ___BROKENLINE_H___