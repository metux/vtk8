Debianized VTK
==============

This is a debianzed VTK source tree, which can be directly built into a
Debian/Ubuntu package (eg. via dpkg-buildpackage) w/o any further patching.
All necessary patches are already applied.

The most important change against upstream is unbundling certain 3rdparty
libraries. Main reasons for NOT bundling 3rdparty libs (and also why 
upstream shouldn't do that) are:

* it makes the package unnecessarily fat
* slow and complex build, increases maintenance overhead (eg. 3rdparty
  upstream changes, eg. bugfixes have to be applied manually, ...)
* bad for security and bugfixes: distros usually provide bugfix/security
  updates pretty fast - bundled libs are obviously not updated automatically,
  so all packagers (in all distros) need to take extra care and port the
  fixes to the bundled libs - heavy increase in maintenance overhead
* risk of clashes between distro-provided and bundled libraries (eg. when
  another application imports both vtk and some of the bundled libs) !
  solving this problem requires a really strict isolation, including
  changing all symbol names of the 3rdparty libs (eg. via symbol
  versioning)

Bottom line: the easiest, safest and cleanes way is biting the bitter
apple and completely drop the bundled 3rdparty libs from the source tree,
importing only the dist-provieded libs.

As of now it's WIP, not all 3rdparty packages have been unbundled yet,
only those I've found in the official debian/ubuntu repos, yet missing:

* alglib
* libexodus
* tcl/tk
* libgl2ps
* libxdmf2


![VTK - The Visualization Toolkit](vtkBanner.gif)

Introduction
============

VTK is an open-source software system for image processing, 3D
graphics, volume rendering and visualization. VTK includes many
advanced algorithms (e.g., surface reconstruction, implicit modelling,
decimation) and rendering techniques (e.g., hardware-accelerated
volume rendering, LOD control).

VTK is used by academicians for teaching and research; by government
research institutions such as Los Alamos National Lab in the US or
CINECA in Italy; and by many commercial firms who use VTK to build or
extend products.

The origin of VTK is with the textbook "The Visualization Toolkit, an
Object-Oriented Approach to 3D Graphics" originally published by
Prentice Hall and now published by Kitware, Inc. (Third Edition ISBN
1-930934-07-6). VTK has grown (since its initial release in 1994) to a
world-wide user base in the commercial, academic, and research
communities.

Learning Resources
==================

* General information is available at the [VTK Homepage][].

* Community discussion takes place on the [VTK Mailing Lists][].

* Commercial [support][Kitware Support] and [training][Kitware Training]
  are available from [Kitware][].

* Doxygen-generated nightly reference documentation is
  available [online][Doxygen].

[VTK Homepage]: http://www.vtk.org
[Doxygen]: http://www.vtk.org/doc/nightly/html
[VTK Mailing Lists]: http://www.vtk.org/VTK/help/mailing.html
[Kitware]: http://www.kitware.com/
[Kitware Support]: http://www.kitware.com/products/support.html
[Kitware Training]: http://www.kitware.com/products/protraining.php

Reporting Bugs
==============

If you have found a bug:

1. If you have a patch, please read the [CONTRIBUTING.md][] document.

2. Otherwise, please join the one of the [VTK Mailing Lists][] and ask
   about the expected and observed behaviors to determine if it is
   really a bug.

3. Finally, if the issue is not resolved by the above steps, open
   an entry in the [VTK Issue Tracker][].

[VTK Issue Tracker]: https://gitlab.kitware.com/vtk/vtk/issues

Requirements
============

In general VTK tries to be as portable as possible; the specific configurations below are known to work and tested.

VTK supports the following C++11 compilers:
1. Microsoft Visual Studio 2013 or newer
2. gcc 4.8.3 or newer
3. Clang 3.3 or newer
4. Apple Clang 5.0 (from Xcode 5.0) or newer
5. Intel 14.0 or newer

VTK supports the following operating systems:
1. Windows Vista or newer
2. Mac OS X 10.7 or newer
3. Linux (ex: Ubuntu 12.04 or newer, Debian 4 or newer)

Contributing
============

See [CONTRIBUTING.md][] for instructions to contribute.

[CONTRIBUTING.md]: CONTRIBUTING.md

License
=======

VTK is distributed under the OSI-approved BSD 3-clause License.
See [Copyright.txt][] for details.

[Copyright.txt]: Copyright.txt
