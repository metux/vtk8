vtk_module(vtkIONetCDF
  GROUPS
    StandAlone
  TEST_DEPENDS
    vtkCommonExecutionModel
    vtkRendering${VTK_RENDERING_BACKEND}
    vtkTestingRendering
    vtkInteractionStyle
  KIT
    vtkIO
  DEPENDS
    vtkCommonCore
    vtkCommonExecutionModel
  PRIVATE_DEPENDS
    vtkCommonDataModel
    vtksys
  )
