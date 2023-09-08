#ifndef ___COORDS_SYS_H___
#define ___COORDS_SYS_H___

#include "SFML/Graphics.hpp"
#include "Core/Object.h"
#include "Math/Vector2.h"

class CoordsSys : public Object {
public:
    CoordsSys(uint32_t width, uint32_t height);
    ~CoordsSys() { };

    void SetSize(uint32_t width, uint32_t height);
    void SetPosition(float X, float Y);
    void SetScale(int32_t scale);

    void Move(const sf::Vector2f& offset);
    void Zoom(float factor);

    void SetBackgroundColor(sf::Color color);

    sf::Vector2f ToWorldCoords(const sf::Vector2i& screen_coords) const;
    sf::Vector2i ToScreenCoords(const sf::Vector2f& world_coords) const;

    void SetDrawGrid(bool draw_grid) { draw_grid_ = draw_grid; }

private:
    sf::Vector2f centre_ = sf::Vector2f(0, 0);
    int32_t scale_ = 10;

private:
    bool draw_grid_ = true;
    void DrawGrid(sf::RenderTexture& window);

private:
    sf::RenderTexture texture_;
    sf::Sprite sprite_;

    sf::Color background_color_ = sf::Color::White;

protected:
    virtual void Update() override;
    virtual void Draw(sf::RenderWindow& window) override;
};

#endif // ___COORDS_SYS_H___