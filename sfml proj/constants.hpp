// 22/6/24

#pragma once

constexpr int WinWidth = 800;
constexpr int WinHeight = 800;

constexpr float pointWidth = (WinWidth/3) - 5;
constexpr float pointHeight = (WinHeight/3) - 5;

enum GameState
{
    STARTMENU,
    RUNNING,
};
