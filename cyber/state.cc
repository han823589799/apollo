#include "state.h"

#include <atomic>

namespace apollo {
namespace cyber {

namespace {
std::atomic<State> g_cyber_state;
}

State GetState() {return g_cyber_state.load();}

void SetState(const State& state) {g_cyber_state.store(state);}
}  // namespace cyber 
}  // namespace apollo