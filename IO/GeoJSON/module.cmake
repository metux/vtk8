vtk_module(vtkIOGeoJSON
  TEST_DEPENDS
    vtkTestingCore
  KIT
    vtkIO
  DEPENDS
    vtkCommonDataModel
    vtkCommonExecutionModel
    vtkIOCore
  PRIVATE_DEPENDS
    vtkCommonCore
    vtkFiltersCore
  )