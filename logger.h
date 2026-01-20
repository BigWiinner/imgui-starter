#include "imgui/imgui.h"
#pragma once

class Logger {
        public:
            static Logger& GetInstance();
            void CreateGameLog();
        private:
            static Logger* instance;
};
