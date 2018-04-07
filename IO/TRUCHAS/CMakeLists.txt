set(Module_SRCS
  vtkTRUCHASReader.cxx
  )

vtk_module_library(vtkIOTRUCHAS ${Module_SRCS})
target_link_libraries(vtkIOTRUCHAS PUBLIC ${HDF5_LIBRARIES})
target_include_directories(vtkIOTRUCHAS PUBLIC ${HDF5_INCLUDE_DIRS})
target_compile_options(vtkIOTRUCHAS PUBLIC ${HDF5_CFLAGS})
