set(TEST_SRC)

if(WIN32 AND VTK_USE_VIDEO_FOR_WINDOWS)
  list(APPEND TEST_SRC TestAVIWriter.cxx)
endif()

  list(APPEND TEST_SRC TestOggTheoraWriter.cxx)

vtk_add_test_cxx(${vtk-module}CxxTests tests
  NO_VALID
  ${TEST_SRC}
  )

vtk_test_cxx_executable(${vtk-module}CxxTests tests)
