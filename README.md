# My graphical library, written on C++.

In this repository you can find high-level library, that wraps several low-level ones, including SFML, OpenGL and (maybe) ncurses, and provides common interface to interact with all of them. All you need to choose implementation is to provide some template argument to Application class:

```c
int main() 
{
	// pre-work
	auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance("WindowName");
	// make some buttons, slidebars and other fancy windows
}
```

In directory files-dialog lies user-level code, and in kudry lies the library. You will find cues describing implementation in every subfolder of a library.