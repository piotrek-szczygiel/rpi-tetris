#pragma once
#include "Matrix.hpp"
#include "Shape.hpp"
#include <functional>

namespace Tetris {

class Piece {
public:
    using CollisionFunction = std::function<bool(const Piece&)>;

    Piece(ShapeType shape_type)
        : m_shape { shape_from_type(shape_type) }
    {
        m_x = static_cast<int>(static_cast<float>(WIDTH) / 2.0F
            - static_cast<float>(m_shape.grids[m_rotation].width) / 2.0F);
        m_y = VANISH - m_shape.grids[m_rotation].height - m_shape.grids[m_rotation].y;
    }

    int x() const { return m_x; }

    int y() const { return m_y; }

    const ShapeGrid& grid() const { return m_shape.grids[m_rotation]; }

    bool move(int x, int y, const CollisionFunction& collision_fun);
    bool rotate(bool right, const CollisionFunction& collision_fun);
    int fall(const CollisionFunction& collision_fun);
    void draw(int draw_x, int draw_y) const;

private:
    Shape m_shape;
    int m_x;
    int m_y;
    int m_rotation { 0 };

    bool collision(int x, int y, const CollisionFunction& collision_fun);
};

}
