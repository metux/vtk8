vtk_module(vtkIOXMLParser
  GROUPS
    StandAlone
  KIT
    vtkIO
  DEPENDS
    vtkCommonCore
    vtkCommonDataModel
  PRIVATE_DEPENDS
    vtkIOCore
    vtksys
  )

list(APPEND vtkIOXMLParser_SYSTEM_INCLUDE_DIRS "${EXPAT_INCLUDE_DIRS}")
list(APPEND vtkIOXMLParser_SYSTEM_LIBRARY_DIRS "${EXPAT_LIBRARY_DIRS}")
list(APPEND vtkIOXMLParser_LIBRARIES "${EXPAT_LIBRARIES}")
