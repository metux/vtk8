if (VTK_OCULUS_OBJECT_FACTORY)
  set (_impl   IMPLEMENTS vtkRenderingOpenGL2)
endif()

vtk_module(vtkRenderingOculus
  BACKEND
    OpenGL2
  DEPENDS
    vtkCommonCore
    vtkRenderingOpenGL2
    vtkInteractionStyle
  ${_impl}
  TEST_DEPENDS
    vtkTestingCore
    vtkTestingRendering
    vtkInteractionWidgets
    vtkIOPLY
    vtkIOXML
)
