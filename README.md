# SAF
Archive of Sets and Field software -- TriLabs I/O project from ca. 2000.  Not under active development.  See https://www.osti.gov/biblio/1230929

[Description from 2005/07/01]

SAF is being developed as part of the Data Models and Formats (DMF)
component of the Accelerated Strategic Computing Initiative
(ASCI). SAF represents a revolutionary approach to interoperation of
high performance, scientific computing applications based upon
rigorous, math oriented data modeling principles. Previous
technologies have required all applications to use the same data
structures and/or mesh objects to represent scientific data or lead to
an ever expanding set of incrementally different data structures
and/or mesh objects. SAF addresses this problem by providing a small
set of mathematical building blocks, sets, relations and fields, out
of which a wide variety of scientific data can be
characterized. Applications literally model their data by assembling
these building blocks. Sets and fields building blocks are at once,
both primitive and abstract: * They are primitive enough to model a
wide variety of scientific data. * They are abstract enough to model
the data in terms of what it represents in a mathematical or physical
sense independent of how it is represented in an implementation
sense. For example, while there are many ways to represent the airflow
over the wing of a supersonic aircraft in a computer program, there is
only one mathematical/physical interpretation: a field of 3D velocity
vectors over a 2D surface. This latter description is immutable. It is
independent of any particular representation or implementation
choices. Understanding this what versus how relationship, that is what
is represented versus how it is represented, is key to developing a
solution for large scale integration of scientific software.