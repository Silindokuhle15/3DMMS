# sba CMake file; see http://www.cmake.org and 
#                     http://www.insightsoftwareconsortium.org/wiki/index.php/CMake_Tutorial

PROJECT(SBA)
#CMAKE_MINIMUM_REQUIRED(VERSION 1.4)


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

INCLUDE_DIRECTORIES(.)
# sba library source files
ADD_LIBRARY(sba STATIC
  sba_levmar.c sba_levmar_wrap.c sba_lapack.c sba_crsm.c sba_chkjac.c
  sba.h sba_chkjac.h compiler.h
)

#ADD_SUBDIRECTORY(demo)
SUBDIRS(demo)

