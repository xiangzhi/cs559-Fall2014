#pragma once

#include <windows.h>
#include <GL\glew.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <glm.hpp>


#include "DrawingTools.h"


//draw the skybox
//just four side of a box with a top 
//pass in the direction of the sun and intensity of light
void drawSkyBox(glm::vec3 sun, float light, glm::mat4 MVP);

