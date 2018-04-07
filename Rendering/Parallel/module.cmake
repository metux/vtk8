vtk_module(vtkRenderingParallel
  TEST_DEPENDS
    vtkParallelMPI
    vtkFiltersParallelMPI
    vtkTestingRendering
    vtkImagingSources
    vtkRendering${VTK_RENDERING_BACKEND}
    vtkInteractionStyle
    vtkTestingCore
  KIT
    vtkParallel
  DEPENDS
    vtkCommonCore
    vtkRendering${VTK_RENDERING_BACKEND}
    vtkRenderingCore
  PRIVATE_DEPENDS
    vtkCommonDataModel
    vtkCommonMath
    vtkCommonSystem
    vtkFiltersParallel
    vtkIOImage
    vtkImagingCore
    vtkParallelCore
  )