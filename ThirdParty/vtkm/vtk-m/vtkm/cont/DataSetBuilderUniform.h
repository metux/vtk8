//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//
//  Copyright 2015 National Technology & Engineering Solutions of Sandia, LLC (NTESS).
//  Copyright 2015 UT-Battelle, LLC.
//  Copyright 2015 Los Alamos National Security.
//
//  Under the terms of Contract DE-NA0003525 with NTESS,
//  the U.S. Government retains certain rights in this software.
//
//  Under the terms of Contract DE-AC52-06NA25396 with Los Alamos National
//  Laboratory (LANL), the U.S. Government retains certain rights in
//  this software.
//============================================================================
#ifndef vtk_m_cont_DataSetBuilderUniform_h
#define vtk_m_cont_DataSetBuilderUniform_h

#include <vtkm/cont/CoordinateSystem.h>
#include <vtkm/cont/DataSet.h>

namespace vtkm
{
namespace cont
{

class DataSetBuilderUniform
{
  using VecType = vtkm::Vec<vtkm::FloatDefault, 3>;

public:
  VTKM_CONT
  DataSetBuilderUniform() {}

  //1D uniform grid
  template <typename T>
  VTKM_CONT static vtkm::cont::DataSet Create(const vtkm::Id& dimension,
                                              const T& origin,
                                              const T& spacing,
                                              std::string coordNm = "coords",
                                              std::string cellNm = "cells")
  {
    return DataSetBuilderUniform::CreateDataSet(
      vtkm::Id3(dimension, 1, 1),
      VecType(static_cast<vtkm::FloatDefault>(origin), 0, 0),
      VecType(static_cast<vtkm::FloatDefault>(spacing), 1, 1),
      coordNm,
      cellNm);
  }

  VTKM_CONT
  static vtkm::cont::DataSet Create(const vtkm::Id& dimension,
                                    std::string coordNm = "coords",
                                    std::string cellNm = "cells")
  {
    return CreateDataSet(vtkm::Id3(dimension, 1, 1), VecType(0), VecType(1), coordNm, cellNm);
  }

  //2D uniform grids.
  template <typename T>
  VTKM_CONT static vtkm::cont::DataSet Create(const vtkm::Id2& dimensions,
                                              const vtkm::Vec<T, 2>& origin,
                                              const vtkm::Vec<T, 2>& spacing,
                                              std::string coordNm = "coords",
                                              std::string cellNm = "cells")
  {
    return DataSetBuilderUniform::CreateDataSet(vtkm::Id3(dimensions[0], dimensions[1], 1),
                                                VecType(static_cast<vtkm::FloatDefault>(origin[0]),
                                                        static_cast<vtkm::FloatDefault>(origin[1]),
                                                        0),
                                                VecType(static_cast<vtkm::FloatDefault>(spacing[0]),
                                                        static_cast<vtkm::FloatDefault>(spacing[1]),
                                                        1),
                                                coordNm,
                                                cellNm);
  }

  VTKM_CONT
  static vtkm::cont::DataSet Create(const vtkm::Id2& dimensions,
                                    std::string coordNm = "coords",
                                    std::string cellNm = "cells")
  {
    return CreateDataSet(
      vtkm::Id3(dimensions[0], dimensions[1], 1), VecType(0), VecType(1), coordNm, cellNm);
  }

  //3D uniform grids.
  template <typename T>
  VTKM_CONT static vtkm::cont::DataSet Create(const vtkm::Id3& dimensions,
                                              const vtkm::Vec<T, 3>& origin,
                                              const vtkm::Vec<T, 3>& spacing,
                                              std::string coordNm = "coords",
                                              std::string cellNm = "cells")
  {
    return DataSetBuilderUniform::CreateDataSet(
      vtkm::Id3(dimensions[0], dimensions[1], dimensions[2]),
      VecType(static_cast<vtkm::FloatDefault>(origin[0]),
              static_cast<vtkm::FloatDefault>(origin[1]),
              static_cast<vtkm::FloatDefault>(origin[2])),
      VecType(static_cast<vtkm::FloatDefault>(spacing[0]),
              static_cast<vtkm::FloatDefault>(spacing[1]),
              static_cast<vtkm::FloatDefault>(spacing[2])),
      coordNm,
      cellNm);
  }

  VTKM_CONT
  static vtkm::cont::DataSet Create(const vtkm::Id3& dimensions,
                                    std::string coordNm = "coords",
                                    std::string cellNm = "cells")
  {
    return CreateDataSet(vtkm::Id3(dimensions[0], dimensions[1], dimensions[2]),
                         VecType(0),
                         VecType(1),
                         coordNm,
                         cellNm);
  }

private:
  VTKM_CONT
  static vtkm::cont::DataSet CreateDataSet(const vtkm::Id3& dimensions,
                                           const vtkm::Vec<vtkm::FloatDefault, 3>& origin,
                                           const vtkm::Vec<vtkm::FloatDefault, 3>& spacing,
                                           std::string coordNm,
                                           std::string cellNm)
  {
    vtkm::Id dims[3];
    int ndims = 0;
    for (int i = 0; i < 3; ++i)
    {
      if (dimensions[i] > 1)
      {
        if (spacing[i] <= 0.0f)
        {
          throw vtkm::cont::ErrorBadValue("spacing must be > 0.0");
        }
        dims[ndims++] = dimensions[i];
      }
    }

    vtkm::cont::DataSet dataSet;
    vtkm::cont::ArrayHandleUniformPointCoordinates coords(dimensions, origin, spacing);
    vtkm::cont::CoordinateSystem cs(coordNm, coords);
    dataSet.AddCoordinateSystem(cs);

    if (ndims == 1)
    {
      vtkm::cont::CellSetStructured<1> cellSet(cellNm);
      cellSet.SetPointDimensions(dims[0]);
      dataSet.AddCellSet(cellSet);
    }
    else if (ndims == 2)
    {
      vtkm::cont::CellSetStructured<2> cellSet(cellNm);
      cellSet.SetPointDimensions(vtkm::Id2(dims[0], dims[1]));
      dataSet.AddCellSet(cellSet);
    }
    else if (ndims == 3)
    {
      vtkm::cont::CellSetStructured<3> cellSet(cellNm);
      cellSet.SetPointDimensions(vtkm::Id3(dims[0], dims[1], dims[2]));
      dataSet.AddCellSet(cellSet);
    }
    else
    {
      throw vtkm::cont::ErrorBadValue("Invalid cell set dimension");
    }

    return dataSet;
  }
};

} // namespace cont
} // namespace vtkm

#endif //vtk_m_cont_DataSetBuilderUniform_h
