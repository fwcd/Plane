# Shared C++ sources
Contains the entire (header-only) shared library including the API.

Note that this library is still in an early stage of development.

## Dependencies
* C++11 or newer

## Style Guide
* Opening braces are *always* on the same line as the statement
* Tabs are used to indent the code
* Headers contain both interface and implementation
* Pure interface classes are prefixed with I
* Class names use PascalCase, function/method/field/variable names use camelCase
* Inherit at most one implementation class (abstract or concrete) 