#include "run_once_action.hpp"

namespace rip
{

    bool RunOnceAction::isFinished()
    {
        return true;
    }

    void RunOnceAction::update() {}

    void RunOnceAction::setup()
    {
        runOnce();
    }

    void RunOnceAction::teardown() {}

    nlohmann::json RunOnceAction::save() const
    {
        return nlohmann::json();
    }

    void RunOnceAction::restore(const nlohmann::json& state) {}

}