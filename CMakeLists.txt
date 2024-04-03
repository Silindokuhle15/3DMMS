# CMakeList.txt : CMake project for 3DMMS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.18)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("3DMMS")

# ADD HEADER DIRECTORIES

SET(LIB_NAME 
	"opencv_world490d.lib"
)

SET(OpenCV_DIR
	"E:/opencv/build/"
)

#find_package(OpenCV REQUIRED
#COMPONENTS opencv_core
#opencv_imgcodecs
#opencv_highgui
#)

SET(SPG_DIR
	"C:/dev/Silindokuhle15/Spring"
)

SET(ROOT_INC_DIR
	"${SPG_DIR}/Core/"
)

SET(SPG_DEP_DIR
	"${SPG_DIR}/Dependencies/"
)

include_directories(
	# SPRING DEPENDENCIES INCLUDE
	"${SPG_DEP_DIR}/GLEW/include/"
	"${SPG_DEP_DIR}/GLM/"
	"${SPG_DEP_DIR}/Lua/"
	"${SPG_DEP_DIR}/imgui/"
	"${SPG_DEP_DIR}/imgui/backends"
	"${SPG_DEP_DIR}/stbi_image/"


	# SPRING INCLUDE 

	"${ROOT_INC_DIR}/"
	"${ROOT_INC_DIR}/Application/"
	"${ROOT_INC_DIR}/Common/"
	"${ROOT_INC_DIR}/Engine/"
	"${ROOT_INC_DIR}/Event/"
	"${ROOT_INC_DIR}/Input/"
	"${ROOT_INC_DIR}/Materials/"
	"${ROOT_INC_DIR}/Physics/"
	"${ROOT_INC_DIR}/Rendering/"
	"${ROOT_INC_DIR}/SceneMgr/"
	"${ROOT_INC_DIR}/Scripting/"
	"${ROOT_INC_DIR}/Viewing/"

	# HACK FOR THE UTILITY FOLDER WHICH IS NOT CURRENLTY PART OF SPRING

	"${SPG_DIR}/Editor/"
)


# SET SOURCE FILES
SET( SOURCE_FILES
	"3DMMS.h"
	"3DMMS.cpp"
	"UI.h"
	"UI.cpp"


	# DEPENDENCIES
	"${SPG_DEP_DIR}/GLEW/include/GL/glew.h"
	"${SPG_DEP_DIR}/GLEW/src/glew.c"
	"${SPG_DEP_DIR}/ImGui/imgui.h"
	"${SPG_DEP_DIR}/ImGui/imconfig.h"
	"${SPG_DEP_DIR}/ImGui/imgui.cpp"
	"${SPG_DEP_DIR}/ImGui/imgui_draw.cpp"
	"${SPG_DEP_DIR}/ImGui/imgui_tables.cpp"
	"${SPG_DEP_DIR}/ImGui/imgui_widgets.cpp"
	"${SPG_DEP_DIR}/ImGui/imgui_internal.h"
	"${SPG_DEP_DIR}/ImGui/backends/imgui_impl_opengl3.h"
	"${SPG_DEP_DIR}/ImGui/backends/imgui_impl_opengl3_loader.h"
	"${SPG_DEP_DIR}/ImGui/backends/imgui_impl_opengl3.cpp"
	"${SPG_DEP_DIR}/ImGui/backends/imgui_impl_win32.h"
	"${SPG_DEP_DIR}/ImGui/backends/imgui_impl_win32.cpp"

	# MY LIBRARY INCLUDES

	# APPLICATION
	"${ROOT_INC_DIR}/Application/Square.h"
	"${ROOT_INC_DIR}/Application/Square.cpp"
	"${ROOT_INC_DIR}/Application/Grid.h"
	"${ROOT_INC_DIR}/Application/Grid.cpp"

	# COMMON
	"${ROOT_INC_DIR}/Common/Common.h"

	# ENGINE
	"${ROOT_INC_DIR}/Engine/Window.h"
	"${ROOT_INC_DIR}/Engine/Window.cpp"
	"${ROOT_INC_DIR}/Engine/Mesh.h"
	"${ROOT_INC_DIR}/Engine/Mesh.cpp"


	# EVENTS
	"${ROOT_INC_DIR}/Event/Event.h"
	"${ROOT_INC_DIR}/Event/Event.cpp"
	"${ROOT_INC_DIR}/SceneMgr/SceneEvent.h"
	"${ROOT_INC_DIR}/SceneMgr/SceneEvent.cpp"

	# INPUT
	"${ROOT_INC_DIR}/Input/Mouse.h"
	"${ROOT_INC_DIR}/Input/Mouse.cpp"

	# MATERIAL
	"${ROOT_INC_DIR}/Materials/Material.h"
	"${ROOT_INC_DIR}/Materials/Material.cpp"
	"${ROOT_INC_DIR}/Materials/Shader.h"
	"${ROOT_INC_DIR}/Materials/Shader.cpp"
	"${ROOT_INC_DIR}/Materials/Texture.h"
	"${ROOT_INC_DIR}/Materials/Texture.cpp"

	# RENDERING
	"${ROOT_INC_DIR}/Rendering/OpenGLFrameBuffer.h"
	"${ROOT_INC_DIR}/Rendering/OpenGLFrameBuffer.cpp"



	# VIEWING
	"${ROOT_INC_DIR}/Viewing/Camera.h"
	"${ROOT_INC_DIR}/Viewing/Camera.cpp"

	"${SPG_DIR}/Editor/Utility/ObjectLoader.h"
	"${SPG_DIR}/Editor/Utility/ObjectLoader.cpp"
)

SET( LIBS
	"E:/opencv/build/x64/vc16/lib/"
)


# Add source to this project's executable.

link_directories(${LIBS})
add_executable (3DMMS ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
target_link_libraries(3DMMS
	${OPENGL_gl_LIBRARY}
	#${OpenCV_LIBS} 
	#"${LIBS}${LIB_NAME}"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3DMMS PROPERTY CXX_STANDARD 20)

endif()

# TODO: Add tests and install targets if needed.
