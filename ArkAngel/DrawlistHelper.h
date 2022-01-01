#pragma once
#include "il2cpp-appdata.h"
#include <chrono>
#include <unordered_map>
#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "Globals.h"
#include "Util.h"

void drawlist_AddLine(ImDrawList* drawList, Vector2i from, Vector2i to, ImVec4 color, float thickness = 1.0f)
{
	drawList->AddLine(ImVec2(from.x, from.y), ImVec2(to.x, to.y), ImGui::GetColorU32(color), thickness);
}
void drawlist_AddLineWorldSpace(ImDrawList* drawList, Vector2 from, Vector2 to, ImVec4 color, float thickness = 1.0f)
{
	Vector2i screenSpaceFrom = WorldToScreen(from);
	Vector2i screenSpaceTo = WorldToScreen(to);
	drawList->AddLine(ImVec2(screenSpaceFrom.x, screenSpaceFrom.y), ImVec2(screenSpaceTo.x, screenSpaceTo.y), ImGui::GetColorU32(color), thickness);
}

void drawlist_AddRect(ImDrawList* drawList, Vector2i position, Vector2i size, ImVec4 color, float thickness = 1.0f)
{
	Vector2i bottomRight = Vector2i{position.x + size.x, position.y + size.y};
	drawList->AddRect(ImVec2(position.x, position.y), ImVec2(bottomRight.x, bottomRight.y), ImGui::GetColorU32(color), thickness);
}
void drawlist_AddRectWorldSpace(ImDrawList* drawList, Vector2 position, Vector2 size, ImVec4 color, float thickness = 1.0f)
{
	Vector2i screenSpacePosition = WorldToScreen(position);
	Vector2i screenSpaceSize = ScaleToScreen(size);
	Vector2i bottomRight = Vector2i{ screenSpacePosition.x + screenSpaceSize.x, screenSpacePosition.y + screenSpaceSize.y };
	drawList->AddRect(ImVec2(screenSpacePosition.x, screenSpacePosition.y), ImVec2(bottomRight.x, bottomRight.y), ImGui::GetColorU32(color), thickness);
}

void drawlist_AddText(ImDrawList* drawList, const char* text, Vector2i position, ImVec4 color)
{
	drawList->AddText(ImVec2{ (float)position.x, (float)position.y }, ImGui::GetColorU32(color), text);
}
void drawlist_AddTextCentered(ImDrawList* drawList, const char* text, Vector2i centerPoint, ImVec4 color)
{
	ImVec2 textSize = ImGui::CalcTextSize(text);
	drawList->AddText(ImVec2{ centerPoint.x - textSize.x / 2, centerPoint.y - textSize.y / 2 }, ImGui::GetColorU32(color), text);
}