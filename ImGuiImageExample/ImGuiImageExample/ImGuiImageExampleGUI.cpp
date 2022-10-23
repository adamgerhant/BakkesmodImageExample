#include "pch.h"
#include "ImGuiImageExample.h"

/* Plugin Settings Window code here
std::string ImGuiImageExample::GetPluginName() {
	return "ImGuiImageExample";
}

void ImGuiImageExample::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> ImGuiImageExample
void ImGuiImageExample::RenderSettings() {
	ImGui::TextUnformatted("ImGuiImageExample plugin settings");
}
*/


// Do ImGui rendering here
void ImGuiImageExample::Render()
{
	ImGuiWindowFlags WindowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;
	ImGui::SetNextWindowPos(ImVec2(200.0f, 300.0f));

	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, WindowFlags))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	if (shouldRenderImGui) {
		if (myImage->IsLoadedForImGui()) {
			if (ImTextureID myImageTexture = myImage -> GetImGuiTex()) {
				auto rect = myImage -> GetSizeF();
				ImGui::Image(myImageTexture, ImVec2(rect.X, rect.Y));
			}
		}
	}

	ImGui::End();

}

// Name of the menu that is used to toggle the window.
std::string ImGuiImageExample::GetMenuName()
{
	return "ImGuiImageExample";
}

// Title to give the menu
std::string ImGuiImageExample::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void ImGuiImageExample::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool ImGuiImageExample::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool ImGuiImageExample::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void ImGuiImageExample::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void ImGuiImageExample::OnClose()
{
	isWindowOpen_ = false;
}

