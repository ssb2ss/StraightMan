#pragma once

class IScene
{
public:
	IScene();
	~IScene();

	void virtual Start() = 0;
};