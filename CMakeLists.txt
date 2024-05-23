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
# OPENCV
SET(OCV_LIB_NAME 
	"opencv_world490d.lib"
)
SET(OpenCV_DIR
	"E:/opencv/build/x64/vc16/bin"
)

find_package(OpenCV REQUIRED
COMPONENTS opencv_core
opencv_imgcodecs
opencv_highgui
)

# SBA

SET(SBA_INC_DIR "C:/dev/3DMMS/SBA/sba-1.6/")
SET(SBA_LIB_DIR "C:/dev/3DMMS/SBA/sba-1.6/")

# f2c is sometimes equivalent to libF77 & libI77; in that case, set HAVE_F2C to 0
SET(HAVE_F2C 1 CACHE BOOL "Do we have f2c or F77/I77?" )

# the directory where the lapack/blas/f2c libraries reside
SET(LAPACKBLAS_DIR "C:/dev/3DMMS/SBA/sba-1.6/" CACHE PATH "C:/dev/3DMMS/SBA/sba-1.6/")

# actual names for the lapack/blas/f2c libraries
SET(LAPACK_LIB liblapack CACHE STRING "liblapack.lib")
SET(BLAS_LIB libblas CACHE STRING "libblas.lib")
IF(HAVE_F2C)
  SET(F2C_LIB libf2c CACHE STRING "libf2c.lib")
ELSE(HAVE_F2C)
  SET(F77_LIB libF77 CACHE STRING "The name of the F77 library")
  SET(I77_LIB libI77 CACHE STRING "The name of the I77 library")
ENDIF(HAVE_F2C)

########################## NO CHANGES BEYOND THIS POINT ##########################

INCLUDE_DIRECTORIES(SBA_INC_DIR)

# sba library source files
ADD_LIBRARY(sba STATIC
  "${SBA_INC_DIR}/sba_levmar.c" 
  "${SBA_INC_DIR}/sba_levmar_wrap.c" 
  "${SBA_INC_DIR}/sba_lapack.c"
  "${SBA_INC_DIR}/sba_crsm.c" 
  "${SBA_INC_DIR}/sba_chkjac.c"
  "${SBA_INC_DIR}/sba.h" 
  "${SBA_INC_DIR}/sba_chkjac.h" 
  "${SBA_INC_DIR}/compiler.h"
)

LINK_DIRECTORIES(.. ${LAPACKBLAS_DIR})

SET(SPG_DIR
	"C:/dev/Silindokuhle15/Spring"
)

SET(ROOT_INC_DIR
	"${SPG_DIR}/Core/"
)

SET(SPG_DEP_DIR
	"${SPG_DIR}/Dependencies/"
)

SET(CSV_INC_DIR "c:/dev/3DMMS/Dependencies/CSV/")

include_directories(
	# INCLUDE EXTERNAL DEPENDENCIES
	"${SBA_INC_DIR}"

	# SPRING DEPENDENCIES INCLUDE
	"${SPG_DEP_DIR}/GLEW/include/"
	"${SPG_DEP_DIR}/GLM/"
	"${SPG_DEP_DIR}/imgui/"
	"${SPG_DEP_DIR}/imgui/backends"


	# SPRING INCLUDE 

	"${ROOT_INC_DIR}/"
	"${ROOT_INC_DIR}/Common/"
	"${ROOT_INC_DIR}/Engine/"
	"${ROOT_INC_DIR}/Event/"
	"${ROOT_INC_DIR}/Input/"
	"${ROOT_INC_DIR}/Rendering/"
	"${ROOT_INC_DIR}/SceneMgr/"
	"${ROOT_INC_DIR}/Viewing/"

	# HACK FOR THE UTILITY FOLDER WHICH IS NOT CURRENLTY PART OF SPRING

	"${SPG_DIR}/Editor/"

	"${CSV_INC_DIR}/"
)


# SET SOURCE FILES
SET( SOURCE_FILES
	# EUCSBADEMO FILES	
	#"${SBA_INC_DIR}/demo/eucsbademo.h" 
	#"${SBA_INC_DIR}/demo/eucsbademo.c" 
	"${SBA_INC_DIR}/demo/imgproj.c"
	"${SBA_INC_DIR}/demo/readparams.h"
	"${SBA_INC_DIR}/demo/readparams.c" 


	"3DMMS.h"
	"3DMMS.cpp"
	"UI.h"
	"UI.cpp"
	#"${CSV_INC_DIR}/csv.hpp"
	"${CSV_INC_DIR}/csv.h"
	"QuadrupedDynamics.h"
	"QuadrupedDynamics.cpp"
	"pch.h"
	"pch.cpp"
	
	

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
	#"${ROOT_INC_DIR}/Input/Mouse.h"
	#"${ROOT_INC_DIR}/Input/Mouse.cpp"

	# RENDERING
	#"${ROOT_INC_DIR}/Rendering/OpenGLFrameBuffer.h"
	#"${ROOT_INC_DIR}/Rendering/OpenGLFrameBuffer.cpp"

	# VIEWING
	#"${ROOT_INC_DIR}/Viewing/Camera.h"
	#"${ROOT_INC_DIR}/Viewing/Camera.cpp"

	"${SPG_DIR}/Editor/Utility/ObjectLoader.h"
	"${SPG_DIR}/Editor/Utility/ObjectLoader.cpp"
	"Dependencies/CSV/csv.h"  
)

SET(OCV_LIB_DIR
	"E:/opencv/build/x64/vc16/lib/"
)

# Add source to this project's executable.

link_directories(${OCV_LIB_DIR}
	${SBA_LIB_DIR}
	"E:/Tensorflow/"
)
add_executable (3DMMS ${SOURCE_FILES} )

find_package(OpenGL REQUIRED)
target_link_libraries(3DMMS
	${OPENGL_gl_LIBRARY}
	${OpenCV_LIBS} 
	"${OCV_LIB_DIR}${OCV_LIB_NAME}"
	sba
	${LAPACK_LIB} 
	${BLAS_LIB} 
	${F2C_LIB}
)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3DMMS PROPERTY CXX_STANDARD 20)

endif()

# TODO: Add tests and install targets if needed.
