set(Module_SRCS
  vtkDatabaseToTableReader.cxx
  vtkRowQuery.cxx
  vtkRowQueryToTable.cxx
  vtkSQLDatabase.cxx
  #  vtkSQLDatabaseGraphSource.cxx
  vtkSQLDatabaseSchema.cxx
  vtkSQLDatabaseTableSource.cxx
  #vtkSQLGraphReader.cxx
  vtkSQLQuery.cxx
  vtkTableToDatabaseWriter.cxx
  )

set(SQLite_SRCS
  vtkSQLiteDatabase.cxx
  vtkSQLiteQuery.cxx
  vtkSQLiteToTableReader.cxx
  vtkTableToSQLiteWriter.cxx
  )

set_source_files_properties(
  vtkDatabaseToTableReader
  vtkRowQuery
  vtkSQLDatabase
  vtkSQLQuery
  vtkTableToDatabaseWriter
  ABSTRACT
  )

vtk_module_library(vtkIOSQL ${Module_SRCS} ${SQLite_SRCS})
target_link_libraries(vtkIOSQL PUBLIC ${SQLITE3_LIBRARIES})
target_include_directories(vtkIOSQL PUBLIC ${SQLITE3_INCLUDE_DIRS})
target_compile_options(vtkIOSQL PUBLIC ${SQLITE3_CFLAGS})
