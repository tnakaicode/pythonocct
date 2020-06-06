# pyOCCT — Python bindings for OpenCASCADE

[![Documentation Status](https://readthedocs.org/projects/pyocct/badge/?version=latest)](http://pyocct.readthedocs.io/en/latest/?badge=latest)
[![Join the chat at https://gitter.im/pyOCCT/Lobby](https://badges.gitter.im/pyOCCT/Lobby.svg)](https://gitter.im/pyOCCT/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

![Workflow](https://github.com/LaughlinResearch/pyOCCT/workflows/Workflow/badge.svg)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/installer/conda.svg)](https://conda.anaconda.org/trelau/pyocct)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/platforms.svg)](https://anaconda.org/trelau/pyocct)
[![Anaconda-Server Badge](https://anaconda.org/trelau/pyocct/badges/downloads.svg)](https://anaconda.org/trelau/pyocct)

The **pyOCCT** project provides Python bindings to the OpenCASCADE 7.4.0 geometry kernel and SMESH
8.3.0 meshing library via pybind11. Together, this technology stack enables rapid CAD/CAE
application development in the popular Python programming language.

## Enabling technology

The `pyOCCT` core technology stack includes:

## Technology Stack

The pyOCCT core technology stack includes:

* [OpenCASCADE](https://www.opencascade.com): Open CASCADE Technology (OCCT) is an object-oriented
  C++ class library designed for rapid production of sophisticated domain-specific CAD/CAM/CAE
  applications.

* [Salome Platform](http://www.salome-platform.org): Open-source software that provides a generic
  pre- and post-processing platform for numerical simulation. It is based on an open and flexible
  architecture made of reusable components.
  
* [Netgen](https://ngsolve.org/): Advanced meshing capabilities including 3-D tetrahedral and 2-D
  unstructured quad-dominated surface meshing.
  
* [pybind11](https://github.com/pybind/pybind11): A lightweight header-only library that exposes
  C++ types in Python and vice versa, mainly to create Python bindings of existing C++ code.

## Getting started using conda

[Conda packages](https://anaconda.org/LaughlinResearch/dashboard/) are available for a number of
platforms and Python versions. Get started with:

    conda create -n pyocct python=3.7
    activate pyocct
    conda install -c conda-forge -c laughlinresearch pyocct

This will create an environment named "pyocct" and install `pyOCCT` and all necessary dependencies.
You can replace the "pyocct" environment name with anything you'd like.

To support minimal visualization the wxPython package is required and can be installed via conda by:

## Resources

More resources for using, developing, and navigating the pyOCCT project will be
made available, but for now the OpenCASCADE C++ documentation provides the most
complete set of information. The pyOCCT interface should be very similar to its
C++ counterpart. More resources will be available soon.
    conda activate pyocct
    conda install -c conda-forge wxpython

Navigate to the `examples/` folder and run from the active environment:

## Getting Started

[Anaconda Python](https://www.anaconda.com/) (or [Miniconda](https://conda.io/miniconda.html))
is recommended for package management and installation. It is recommended that
a designated environment be created and used for pyOCCT. An example of
creating this environment for Anaconda Python within an Anaconda command prompt
is:
    python import_step.py

and you should see the following image in the viewing tool if all the requirements are correctly
installed.

![compressor](./docs/source/resources/compressor.jpg)

Installation files can be cleaned up by:

    conda clean -a

    conda install -c trelau pyocct
  
To support minimal visualization the wxPython package is required and can be
installed via conda by:

    conda install -c conda-forge wxpython
  
At this point the ``OCCT`` package should be available:

## Building from sources

If you're looking to build from sources, you might notice that the `src/` folder only
contains binding source code for the SMESH modules. To build from sources, you must generate the
binding source code locally. This can be done using the
[pyOCCT_binder](https://github.com/LaughlinResearch/pyOCCT_binder) project which is available as a
git submodule in this repository within the `binder/` folder.

Clone this repository and use the `--recurse-submodules` command to initialize and download the
external `pyOCCT_binder` project:

    git clone --recurse-submodules https://github.com/LaughlinResearch/pyOCCT.git

The binder uses `clang` to parse the C++ header files of the libraries and generate the source
code. If you are familiar with `conda`, an environment can be created for this task by:

    python import_step.py
  
and you should see the following image in the viewing tool if all the
requirements are correctly installed.

    conda env create -f binder/environment.yml

If all the necessary dependencies are available, the binder can be run to generate the binding
sources:

    python binder/run.py -c binder/config.txt -o src/occt

At the moment, only the OpenCASCADE bindings are automatically generated. Eventually, the SMESH
bindings will be auto-generated as well. Be sure and check the output from the binding generation
process in the command prompt in case there are missing header files or other errors.

After the binding sources are generated:

    mkdir build
    cd build
    cmake ..

## Help Wanted

For now, contributions to the source code will be incorporated manually. There
is a (mostly) automated tool for generating the source but it is not yet
available. As new versions of OpenCASCADE are released, it may be better to
patch up the existing bindings rather than rerun the binding generation tool.
The automated process still requires a handful of manual patches to capture
edge cases. Although, if the header files of new OpenCASCADE releases are
significantly different or there is an architectural change in pyOCCT, it makes
sense to use the automated tool.

In addition to the items in the
[Design Considerations](http://pyocct.readthedocs.io/en/latest/dev.html#design-considerations)
section in the documentation, some areas that could use contributor support:

* Cross-platform support
* Leverage CI tools like AppVeyor and Travis-CI
* Conda packages
* Tests, examples, and benchmarks
* Better exception handling
Note that `PTHREAD_INCLUDE_DIR` will likely need defined manually since it cannot typically not be
automatically found by CMake.
