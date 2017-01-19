#include "OglCore.hh"
#include "WindowHandle.hh"
#include "node.hh"
#include "fileWatcher.hh"

#include "imgui/imgui.h"

#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

class Heart {
    public:
	class IGamelogic {
	    public:
		Heart* _lunaticPlatipus;
		std::string _scene;
		virtual void update() = 0;
	};
    private:
	WindowHandle _win;
	OglCore _renderer;
	Graph _scene;
	FileWatcher* _fw;
    public:
	static IGamelogic* _game;
	Heart();
	OglCore& getRenderer();
	void loadScene();
	void run();
};
#define SetGameClass(GameClass) Heart::IGamelogic* Heart::_game = new GameClass();