#pragma once

class Scene;

class SceneManager
{
	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Clear();

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }

	Vector2D GetCameraPos() { return _cameraPos; }
	void SetCameraPos(Vector2D pos) { _cameraPos = pos; }
private:
	Scene* _scene;
	SceneType _sceneType = SceneType::None;
	Vector2D _cameraPos = { 400, 300 };
};

