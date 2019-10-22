#include "../State.hpp"
#include "Player.hpp"
#include <memory>
#include <raylib.h>

namespace Tetris {

class Tetris final : public State {
public:
    Tetris()
        : m_width { 320 }
        , m_height { 240 }
        , m_framebuffer { LoadRenderTexture(m_width, m_height) }
    {
    }

    ~Tetris() override { UnloadRenderTexture(m_framebuffer); }

    void update(std::shared_ptr<ControllerState> state) override;
    void draw() override;
    RenderTexture2D framebuffer() override;

private:
    int m_width;
    int m_height;
    RenderTexture2D m_framebuffer;

    Player m_player_1 {};
    Player m_player_2 {};
};

}
