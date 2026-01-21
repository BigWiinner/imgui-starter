/*
    Changes made to other classes:
    Applications.cpp : Added logger.Start() and uncommented calls to GetInstance, LogInfo, and LogGameEvent,
                       as well as added Logger::GetInstance().CreateGameLog() to RenderGame().

    Application:
        Logger works as a logger for ImGui which is used for debugging.
        Information is logged to both the window "Game Log" and to the file debug.txt
        Use functions LogInfo, LogWarning, and LogError to call general information,
        and LogGameEvent for game specific information
*/

#include "logger.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>

Logger* Logger::instance = nullptr;
bool Logger::open = true;
std::vector<message> Logger::logs = {};
int Logger::debugIndex = 0;

Logger &Logger::GetInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return *instance;
}

void Logger::Start() {
    std::ofstream file("debug.txt", std::ios::trunc);
    file.close();
}

void Logger::CreateGameLog() {
    ImGui::Begin("Game Log", &open);

    bool options = ImGui::Button("Options"); ImGui::SameLine();
    bool clear = ImGui::Button("Clear"); ImGui::SameLine();
    bool info = ImGui::Button("Test Info"); ImGui::SameLine();
    bool warning = ImGui::Button("Test Warning"); ImGui::SameLine();
    bool error = ImGui::Button("Test Error");
    bool command;

    if (options)
        {
            
        }
    if (clear)
        {
            Logger::logs.clear();
            Logger::debugIndex = 0;
            std::ofstream file("debug.txt", std::ios::trunc);
        }
    if (info) 
        {
            message txt = {"This is a test info message", 0};
            Logger::logs.push_back(txt);
        }
    if (warning) 
        {
            message txt = {"This is a test warning message", 1};
            Logger::logs.push_back(txt);
        }
    if (error) 
        {
            message txt = {"This is a test error message", 2};
            Logger::logs.push_back(txt);
        }

    for (int i = 0; i < Logger::logs.size(); i++) {
        if (i >= Logger::debugIndex) {
            ImGui::LogToFile(-1, "debug.txt");
        }
        if (Logger::logs[i].intensity == 1) {
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), "[WARN]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 2) {
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), "[ERROR]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 3) {
            ImGui::Text("[INFO] [GAME]"); ImGui::SameLine();
            ImGui::Text(Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 4) {
            ImGui::TextColored(ImVec4(1.0, 1.0, 0.0, 1.0), "[WARN] [GAME]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else if (Logger::logs[i].intensity == 5) {
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), "[ERROR] [GAME]"); ImGui::SameLine();
            ImGui::TextColored(ImVec4(1.0, 0.0, 0.0, 1.0), Logger::logs[i].msg);
        }
        else {
            ImGui::Text("[INFO]"); ImGui::SameLine();
            ImGui::Text(Logger::logs[i].msg);
        }
        if (i >= Logger::debugIndex) {
            ImGui::LogFinish();
            Logger::debugIndex++;
        }
    }

    float offset_y = ImGui::GetWindowHeight() - ImGui::GetFrameHeightWithSpacing() - ImGui::GetStyle().ItemInnerSpacing.y - 10.0f;
    ImGui::SetCursorPosY(offset_y);
    ImGui::BeginChild(" ");
    ImGui::Separator();
    static char buf[32];
    command = ImGui::InputText("Command", buf, IM_ARRAYSIZE(buf), ImGuiInputTextFlags_EnterReturnsTrue);
    if (command) {
        std::cout << buf << std::endl;
        buf[0] = '\0';
    }
    ImGui::EndChild();

    ImGui::End();
}

void Logger::LogInfo(const char* info) {
    message log = {info, 0};
    Logger::logs.push_back(log);
}

void Logger::LogWarning(const char* info) {
    message log = {info, 1};
    Logger::logs.push_back(log);
}

void Logger::LogError(const char* info) {
    message log = {info, 2};
    Logger::logs.push_back(log);
}

void Logger::LogGameEvent(const char* event, int intensity) {
    intensity += 3;
    message log = {event, intensity};
    Logger::logs.push_back(log);
}