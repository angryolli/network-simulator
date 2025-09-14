# LIBS directory

In this directory, you should place all the external libraries your project depends on.
Although, in principle, you can use git submodules (and place them under this directory),
for the sake of easily compiling your application, placing the source code of the
open source libraries is also fine. However, this approach is not applicable to
large dependencies, such as QT.

In some cases libraries are available from the distribution, for example using
apt with Ubuntu. In such case it does not need to be installed here.

# List of External Libs

1. [Project1](https://someproject.com/download)
2. [Project2](https://anotherproject.com/download)

> If you are using already compiled library, place it in this folder, and set the linker options appropriately.
> The include files of the dependent library should also be placed in this folder.
