set(Module_SRCS
  vtkBiomTableReader.cxx
  vtkChacoGraphReader.cxx
  vtkDelimitedTextReader.cxx
  vtkDIMACSGraphReader.cxx
  vtkDIMACSGraphWriter.cxx
  vtkFixedWidthTextReader.cxx
  vtkISIReader.cxx
  vtkMultiNewickTreeReader.cxx
  vtkNewickTreeReader.cxx
  vtkNewickTreeWriter.cxx
  vtkPhyloXMLTreeReader.cxx
  vtkPhyloXMLTreeWriter.cxx
  vtkRISReader.cxx
  vtkTulipReader.cxx
  vtkXGMLReader.cxx
  vtkXMLTreeReader.cxx
  )

vtk_module_library(vtkIOInfovis ${Module_SRCS})
target_link_libraries(vtkIOInfovis PUBLIC ${LIBXML2_LIBRARIES})
target_include_directories(vtkIOInfovis PUBLIC ${LIBXML2_INCLUDE_DIRS})
target_compile_options(vtkIOInfovis PUBLIC ${LIBXML2_CFLAGS})
