#ifndef COMMON_H
#define COMMON_H

#define PI 3.14159265
#define MAX_KEYBOARD_KEY_NUM 348
#define MAX_MOUSE_BUTTON_NUM 7

#define SIZE_OF_ARRAY(a) (sizeof(a) / sizeof(a[0]))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "openGL/gl.h"
#include "openGL/glfw.h"
#include "openGL/callbacks.h"

#include "math/mat4.h"
#include "math/vec4.h"
#include "math/object.h"
#include "math/projectionMatrix.h"
#include "math/modelMatrix.h"

#include "file/fileToBuf.h"

#include "gfx/shader.h"
#include "gfx/window.h"
#include "gfx/camera.h"
#include "gfx/uniforms.h"
#include "gfx/model.h"

#include "system/init.h"
#include "system/update.h"
#include "system/render.h"
#include "system/close.h"
#include "system/input.h"
#include "system/error.h"

extern struct windowStruct window;

#endif