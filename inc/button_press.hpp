#ifndef BUTTON_PRESS_HPP
#define BUTTON_PRESS_HPP
#include <chrono>
#include <mutex>
#include <atomic>

namespace elev {
typedef std::chrono::time_point<std::chrono::system_clock> sysclk_t;

class ButtonPress {
    public:
        ButtonPress(sysclk_t time, std::atomic<int>* btn);
        ButtonPress() = delete;
        bool poll(void);
    private:
        sysclk_t pressed_at;
        std::atomic<int>* btn;
};

} //namespace elev

#endif //BUTTON_PRESS_HPP