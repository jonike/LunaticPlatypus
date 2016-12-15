#pragma once

#include <vector>
#include "Camera.hh"
#include "Mesh.hh"

#include <iostream>

class Scene {
    private:
	char _sceneName[256];
	bool _mod;
    public:
	std::vector<FrameBuffer> _fb;
	std::vector<Mesh> _meshes;
	std::vector<Camera> _cameras;
	unsigned int _activeCamera;
	Scene() ;
	void update();
	void render();
	void bindGBuffer(unsigned int camera_);
};
