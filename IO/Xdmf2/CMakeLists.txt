set(Module_SRCS
  vtkSILBuilder.cxx
  vtkXdmfDataArray.cxx
  vtkXdmfHeavyData.cxx
  vtkXdmfReader.cxx
  vtkXdmfReaderInternal.cxx
  vtkXdmfWriter.cxx
  )

set_source_files_properties(
  vtkXdmfDataArray
  vtkXdmfHeavyData
  vtkXdmfReaderInternal
  WRAP_EXCLUDE
  )

set_source_files_properties(
  vtkXdmfHeavyData
  vtkXdmfReaderInternal
    PROPERTIES WRAP_EXCLUDE_PYTHON 1
  )

#set(${vtk-module}_NO_HeaderTest 1) # TODO: helper classes and reenable
vtk_module_library(vtkIOXdmf2 ${Module_SRCS})
target_link_libraries(vtkIOXdmf2 PUBLIC ${HDF5_LIBRARIES} ${LIBXML2_LIBRARIES})
target_include_directories(vtkIOXdmf2 PUBLIC ${HDF5_INCLUDE_DIRS} ${LIBXML2_INCLUDE_DIRS})
target_compile_options(vtkIOXdmf2 PUBLIC ${HDF5_CFLAGS} ${LIBXML2_CFLAGS})
