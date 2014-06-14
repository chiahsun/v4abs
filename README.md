#################################
# How to build                 #
#################################
cd src
source source_env.sh  # change your environment variable here

make                  # build the object code, libarary, executables

make check            # execute the general c++ test or local check script

make clean            # clean up
