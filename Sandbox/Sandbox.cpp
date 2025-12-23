#include "Sandbox.h"
#include "Core/SceneManager.h"
#include "SceneGraph/Scene.h"

#include <SceneGraph/GameObject.h>
#include "Commands.h"

#include "Input/InputManager.h"

#include "Shapes/Shapes.h"

#include "ShapeObject.h"
#include "Window/WindowManager.h"

#include <iostream>

void SB::SandBox::Load()
{
	auto& scene = Engine::SceneManager::GetInstance().CreateScene("Moving Camera Test");
	Engine::SceneManager::GetInstance().SetActiveScene(&scene);

	auto playerGo = std::make_shared<Engine::GameObject>("Player", &scene);
	scene.AddObject(playerGo);
	playerGo->SetPosition(300, 200);
	
	auto moveCommand = std::make_unique<SB::MoveCommand>(playerGo.get());
	Engine::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::move(moveCommand));

	auto shapeObject = std::make_unique<ShapeObject>(playerGo.get());
	playerGo->AddComponent(std::move(shapeObject));
}