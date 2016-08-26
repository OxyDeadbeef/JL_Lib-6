#include "la_draw.h"

#ifdef LA_COMPUTER

#include "port.h"
#include <stdio.h>

void jlgr_resz(la_window_t* jlgr, uint16_t x, uint16_t y);

void la_print(const char* format, ...) {
	char temp[256];
	va_list arglist;

	// Write to temp
	va_start( arglist, format );
	vsprintf( temp, format, arglist );
	va_end( arglist );

//	la_file_append(LA_FILE_LOG, temp, strlen(temp)); // To File
	printf("%s\n", temp); // To Terminal
}

void la_port_input(la_window_t* window) {
	while(SDL_PollEvent(&window->sdl_event)) {
		uint8_t isNowDown = window->sdl_event.type == SDL_MOUSEBUTTONDOWN;
		uint8_t isNowUp = window->sdl_event.type == SDL_MOUSEBUTTONUP;

		// Keyboard
		if ( window->sdl_event.type == SDL_TEXTINPUT) {
//			int i;
//			for(i = 0; i < 32; i++)
//				window->main.ct.text_input[i] =
//					window->sdl_event.text.text[i];
//			window->main.ct.read_cursor = 0;

		// Keys
		}else if(window->sdl_event.type == SDL_KEYDOWN) {
			switch(window->sdl_event.key.keysym.scancode) {
				case SDL_SCANCODE_ESCAPE: {
					la_print("back due to escape");
					jl_mode_exit(window->jl);
					break;
				} case SDL_SCANCODE_F11: {
					jlgr_wm_togglefullscreen(window);
					break;
				} default: {
					break;
				}
			}

		// Move Mouse
		}else if(window->sdl_event.type == SDL_MOUSEMOTION) {
			float x = (float)window->sdl_event.motion.x /
				(float)window->wm.w;
			float y = (float)window->sdl_event.motion.y /
				(float)window->wm.h;
			if(window->wm.w == 0) x = 0.f;
			if(window->wm.h == 0) y = 0.f;
			// Set location of virtual mouse.
			al_safe_set_float(&window->mouse_x, x);
			al_safe_set_float(&window->mouse_y, y * window->wm.ar);

		// Click Mouse
		}else if ( isNowDown || isNowUp) {
//			if(window->sdl_event.button.button == SDL_BUTTON_LEFT)
//				window->main.ct.input.click = isNowDown;
//			else if(window->sdl_event.button.button == SDL_BUTTON_RIGHT)
//				window->main.ct.input.click_right = isNowDown;
//			else if(window->sdl_event.button.button == SDL_BUTTON_MIDDLE)
//				window->main.ct.input.click_middle = isNowDown;

		// Scroll Wheel
		}else if (window->sdl_event.wheel.type == SDL_MOUSEWHEEL) {
//			uint8_t flip = (window->sdl_event.wheel.direction ==
//				SDL_MOUSEWHEEL_FLIPPED) ? -1 : 1;
//			int32_t x = flip * window->sdl_event.wheel.x;
//			int32_t y = flip * window->sdl_event.wheel.y;
			if (window->sdl_event.wheel.y > 0) {
//				window->main.ct.input.scroll_up = (y > 0) ? y : -y;
			} else if(window->sdl_event.wheel.y < 0) {
//				window->main.ct.input.scroll_down = (y > 0) ? y : -y;
			}
			if (window->sdl_event.wheel.x > 0) {
//				window->main.ct.input.scroll_right = (x > 0) ? x : -x;
			} else if(window->sdl_event.wheel.x < 0) {
//				window->main.ct.input.scroll_left = (x > 0) ? x : -x;
			}

		// Resize or Close
		}else if (window->sdl_event.type==SDL_WINDOWEVENT) {
			switch(window->sdl_event.window.event) {
				case SDL_WINDOWEVENT_RESIZED: {
					jlgr_resz(window,
						window->sdl_event.window.data1,
						window->sdl_event.window.data2);
					break;
				} case SDL_WINDOWEVENT_CLOSE: {
					la_print("back due to close");
					jl_mode_exit(window->jl);
					break;
				} default: {
					break;
				}
			}
		}
	}
}

#endif
