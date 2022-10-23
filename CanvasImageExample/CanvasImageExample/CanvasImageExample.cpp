#include "pch.h"
#include "CanvasImageExample.h"


BAKKESMOD_PLUGIN(CanvasImageExample, "write a plugin description here", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void CanvasImageExample::onLoad()
{
	_globalCvarManager = cvarManager;
	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
		RenderCanvas(canvas);
	});
	myImage = std::make_shared<ImageWrapper>(gameWrapper->GetDataFolder() /"myimage.png", true, false);

}

void CanvasImageExample::onUnload()
{
}

void CanvasImageExample::RenderCanvas(CanvasWrapper canvas) {
	myImage->LoadForCanvas();
	if (myImage->IsLoadedForCanvas()) {
		canvas.SetPosition(Vector2F{ 200.0f, 300.0f });
		canvas.DrawTexture(myImage.get(), 1); //the 1 represents the scale of the image
	}
}