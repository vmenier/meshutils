import os, sys

path = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
if not path in sys.path:
    sys.path.insert(1, path)
del path

import _meshutils_module


# Arguments: 
#   - Inria (GMF) mesh 
#   - Inria solution (if any, otherwise '')
#   - Output base name -> will output out.su2

_meshutils_module.py_ConvertSU2toGMF('wedge.su2', '', 'out')





