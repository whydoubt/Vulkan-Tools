#!/bin/bash
# Update source for glslang, LunarGLASS, spirv-tools

set -e

GLSLANG_REVISION=$(cat $PWD/glslang_revision)
SPIRV_TOOLS_REVISION=$(cat $PWD/spirv-tools_revision)
echo "GLSLANG_REVISION=$GLSLANG_REVISION"
echo "SPIRV_TOOLS_REVISION=$SPIRV_TOOLS_REVISION"

BUILDDIR=$PWD
BASEDIR=$BUILDDIR/external

function create_glslang () {
   rm -rf $BASEDIR/glslang
   echo "Creating local glslang repository ($BASEDIR/glslang)."
   mkdir -p $BASEDIR/glslang
   cd $BASEDIR/glslang
   git clone https://github.com/KhronosGroup/glslang.git .
   git checkout $GLSLANG_REVISION
}

function update_glslang () {
   echo "Updating $BASEDIR/glslang"
   cd $BASEDIR/glslang
   git fetch --all
   git checkout $GLSLANG_REVISION
   # Special case for this particular revision:
   # Pull in a patch that fixes a compilation issue with g++ 5.3
   # See https://github.com/KhronosGroup/Vulkan-LoaderAndValidationLayers/issues/681
   if [ $GLSLANG_REVISION == "4678ca9dacfec7a084dbc69bbe568bdad6889f1b" ] ;
   then
      git checkout $GLSLANG_REVISION -B temp1610
      git cherry-pick 880bf36cacee1cfce7d5d94991eb18c9e2d59d39
   fi
}

function create_spirv-tools () {
   rm -rf $BASEDIR/spirv-tools
   echo "Creating local spirv-tools repository ($BASEDIR/spirv-tools)."
   mkdir -p $BASEDIR/spirv-tools
   cd $BASEDIR/spirv-tools
   git clone https://github.com/KhronosGroup/SPIRV-Tools.git .
   git checkout $SPIRV_TOOLS_REVISION
   mkdir -p $BASEDIR/spirv-tools/external/spirv-headers
   cd $BASEDIR/spirv-tools/external/spirv-headers
   git clone https://github.com/KhronosGroup/SPIRV-Headers .
}

function update_spirv-tools () {
   echo "Updating $BASEDIR/spirv-tools"
   cd $BASEDIR/spirv-tools
   git fetch --all
   git checkout $SPIRV_TOOLS_REVISION
   if [ ! -d "$BASEDIR/spirv-tools/external/spirv-headers" -o ! -d "$BASEDIR/spirv-tools/external/spirv-headers/.git" ]; then
      mkdir -p $BASEDIR/spirv-tools/external/spirv-headers
      cd $BASEDIR/spirv-tools/external/spirv-headers
      git clone https://github.com/KhronosGroup/SPIRV-Headers .
   else
      cd $BASEDIR/spirv-tools/external/spirv-headers
      git fetch --all
      git pull
   fi
}

function build_glslang () {
   echo "Building $BASEDIR/glslang"
   cd $BASEDIR/glslang
   mkdir -p build
   cd build
   cmake -D CMAKE_BUILD_TYPE=Release ..
   make
   make install
}

function build_spirv-tools () {
   echo "Building $BASEDIR/spirv-tools"
   cd $BASEDIR/spirv-tools
   mkdir -p build
   cd build
   cmake -D CMAKE_BUILD_TYPE=Release ..
   make -j $(nproc)
}

# If any options are provided, just compile those tools
# If no options are provided, build everything
INCLUDE_GLSLANG=false
INCLUDE_SPIRV_TOOLS=false

if [ "$#" == 0 ]; then
  echo "Building glslang, spirv-tools"
  INCLUDE_GLSLANG=true
  INCLUDE_SPIRV_TOOLS=true
else
  # Parse options
  while [[ $# > 0 ]]
  do
    option="$1"

    case $option in
        # options to specify build of glslang components
        -g|--glslang)
        INCLUDE_GLSLANG=true
        echo "Building glslang ($option)"
        ;;
        # options to specify build of spirv-tools components
        -s|--spirv-tools)
        INCLUDE_SPIRV_TOOLS=true
        echo "Building spirv-tools ($option)"
        ;;
        *)
        echo "Unrecognized option: $option"
        echo "Try the following:"
        echo " -g | --glslang      # enable glslang"
        echo " -s | --spirv-tools  # enable spirv-tools"
        exit 1
        ;;
    esac
    shift
  done
fi

if [ $INCLUDE_GLSLANG == "true" ]; then
  if [ ! -d "$BASEDIR/glslang" -o ! -d "$BASEDIR/glslang/.git" -o -d "$BASEDIR/glslang/.svn" ]; then
     create_glslang
  fi
  update_glslang
  build_glslang
fi


if [ $INCLUDE_SPIRV_TOOLS == "true" ]; then
    if [ ! -d "$BASEDIR/spirv-tools" -o ! -d "$BASEDIR/spirv-tools/.git" ]; then
       create_spirv-tools
    fi
    update_spirv-tools
    build_spirv-tools
fi
