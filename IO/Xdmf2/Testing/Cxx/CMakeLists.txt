ExternalData_Expand_Arguments(VTKData _
  "DATA{${VTK_TEST_INPUT_DIR}/XDMF/,REGEX:.*}"
  )

vtk_add_test_cxx(${vtk-module}CxxTests tests
  TestTemporalXdmfReaderWriter.cxx,NO_VALID
  XdmfTestVTKIO.cxx,NO_VALID
  )
vtk_test_cxx_executable(${vtk-module}CxxTests tests)
target_link_libraries(${vtk-module}CxxTestsPUBLIC ${HDF5_LIBRARIES})
target_include_directories(${vtk-module}CxxTestsPUBLIC ${HDF5_INCLUDE_DIRS})
target_compile_options(${vtk-module}CxxTestsPUBLIC ${HDF5_CFLAGS})
