0> Fill all src and include files with Doxygen comments, then edit Doxyfile parameters as written below.
1> doxygen <config-file> , or use -g before config-file to generate one
2> open index.html in browser
3> use application.c null.c and null.h in random-stuff repo as reference for generating doxygen doc

### EDITING DOXYGEN CONFIG FILE
###  Basic parameters in Doxyfile,
# 1. To include all src and include files in documentation,
#    EXTRACT_ALL            = YES
# 2. For graphs,
#  CALL_GRAPH             = YES
#  CALLER_GRAPH             = YES
#  Optional:
#  INCLUDE_GRAPH          = YES
#  INCLUDED_BY_GRAPH      = YES
# 3. INPUT = pwd OR keep it blank

### For more custom parameter in Doxyfile, search rohan in Doxyfile
