#include "../include/Input.h"

Input::Input() {

}

Input::~Input() {

}

void Input::registerInput(std::string alias, char key) {
	switch (key) {
	case 'a':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_a, alias));
		break;
	case 'b':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_b, alias));
		break;
	case 'c':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_c, alias));
		break;
	case 'd':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_d, alias));
		break;
	case 'e':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_e, alias));
		break;
	case 'f':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_f, alias));
		break;
	case 'g':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_g, alias));
		break;
	case 'h':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_h, alias));
		break;
	case 'i':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_i, alias));
		break;
	case 'j':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_j, alias));
		break;
	case 'k':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_k, alias));
		break;
	case 'l':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_l, alias));
		break;
	case 'm':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_m, alias));
		break;
	case 'n':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_n, alias));
		break;
	case 'o':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_o, alias));
		break;
	case 'p':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_p, alias));
		break;
	case 'q':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_q, alias));
		break;
	case 'r':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_r, alias));
		break;
	case 's':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_s, alias));
		break;
	case 't':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_t, alias));
		break;
	case 'u':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_u, alias));
		break;
	case 'v':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_v, alias));
		break;
	case 'w':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_w, alias));
		break;
	case 'x':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_x, alias));
		break;
	case 'y':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_y, alias));
		break;
	case 'z':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_z, alias));
		break;
	case '0':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_0, alias));
		break;
	case '1':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_1, alias));
		break;
	case '2':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_2, alias));
		break;
	case '3':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_3, alias));
		break;
	case '4':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_4, alias));
		break;
	case '5':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_5, alias));
		break;
	case '6':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_6, alias));
		break;
	case '7':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_7, alias));
		break;
	case '8':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_8, alias));
		break;
	case '9':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_9, alias));
		break;
	case ' ':
		inputBindings.insert(std::pair<SDL_Keycode, std::string>(SDLK_SPACE, alias));
		break;

	}
}

std::string Input::checkForInput() {
	SDL_Event e;
	std::map<SDL_Keycode, std::string>::iterator it;
	while (SDL_PollEvent(&e) != 0)
	{

		if (e.type == SDL_KEYDOWN)
		{
			
			it = inputBindings.find(e.key.keysym.sym);

			if (it != inputBindings.end()) {
				return it->second;
			}		
		}

		if( e.type == SDL_KEYUP){
			it = inputBindings.find(e.key.keysym.sym);
			if (it != inputBindings.end()) {
				return "-" + it->second;
			}
		}

	}
	return "";
}

std::string Input::checkForInputRelease() {
	return "";
}
