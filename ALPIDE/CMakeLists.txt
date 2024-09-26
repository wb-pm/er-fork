# Create a library called "libERALPIDE" which includes the source files given in
# the array .
#? The extension is already found.  Any number of sources could be listed here.

set(INCLUDE_DIRECTORIES
${BASE_INCLUDE_DIRECTORIES}
${ROOT_INCLUDE_DIR}
${Boost_INCLUDE_DIRS}
${CMAKE_SOURCE_DIR}/data/
${CMAKE_SOURCE_DIR}/base/
${CMAKE_SOURCE_DIR}/ALPIDE/
${CMAKE_SOURCE_DIR}/ALPIDE/data
)

include_directories( ${INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${BASE_LINK_DIRECTORIES}
${FAIRROOT_LIBRARY_DIR}
) 

link_directories( ${LINK_DIRECTORIES})

set(SRCS 
ERALPIDE.cxx
ERALPIDEGeoPar.cxx
ERALPIDESetup.cxx
data/ERALPIDEPoint.cxx
data/ERALPIDEStep.cxx
data/ERALPIDEHit.cxx
)

CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

Set(LINKDEF ERALPIDELinkDef.h)
Set(LIBRARY_NAME ERALPIDE)
Set(DEPENDENCIES ERData ERBase Base Core)

GENERATE_LIBRARY()