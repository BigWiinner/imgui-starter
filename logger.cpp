#include "logger.h"

Logger* Logger::instance = nullptr;

Logger &Logger::GetInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return *instance;
}

void Logger::CreateGameLog() {
    ImGui::Begin("Game Log");

    const bool options = ImGui::Button("Options"); ImGui::SameLine();
    const bool clear = ImGui::Button("Clear"); ImGui::SameLine();
    const bool info = ImGui::Button("Test Info"); ImGui::SameLine();
    const bool warning = ImGui::Button("Test Warning"); ImGui::SameLine();
    const bool error = ImGui::Button("Test Error");

    if (options)
        {
            ImGui::BulletText("These are the options. Yay!");
        }
    if (clear)
        {

        }
    if (info) 
        {
            
        }
    if (warning) 
        {
            
        }
    if (error) 
        {
            
        }
    ImGui::End();
}