
###### USING THE PYTHON MODULE

### Installation

cd /path/to/meshutils_py
rm -f *.so
python setup.py build_ext --inplace

### Run example

cd ./example

python convert_inria_to_su2.py

and

python convert_su2_to_inria.py


###### USING THE MAKEFILE


cd /path/to/meshutils_py/meshutils

export ARCHI=linux64
(or export ARCHI=macintel if compiled on mac)

make

./meshutils

cd ../example

../meshutils/meshutils -O 2 -in wedge.su2 -out out



