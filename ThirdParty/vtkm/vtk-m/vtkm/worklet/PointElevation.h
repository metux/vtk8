//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//
//  Copyright 2014 National Technology & Engineering Solutions of Sandia, LLC (NTESS).
//  Copyright 2014 UT-Battelle, LLC.
//  Copyright 2014 Los Alamos National Security.
//
//  Under the terms of Contract DE-NA0003525 with NTESS,
//  the U.S. Government retains certain rights in this software.
//
//  Under the terms of Contract DE-AC52-06NA25396 with Los Alamos National
//  Laboratory (LANL), the U.S. Government retains certain rights in
//  this software.
//============================================================================

#ifndef vtk_m_worklet_PointElevation_h
#define vtk_m_worklet_PointElevation_h

#include <vtkm/worklet/WorkletMapField.h>

#include <vtkm/Math.h>

namespace vtkm
{
namespace worklet
{

namespace internal
{

template <typename T>
VTKM_EXEC T clamp(const T& val, const T& min, const T& max)
{
  return vtkm::Min(max, vtkm::Max(min, val));
}
}

class PointElevation : public vtkm::worklet::WorkletMapField
{
public:
  typedef void ControlSignature(FieldIn<Vec3>, FieldOut<Scalar>);
  typedef _2 ExecutionSignature(_1);

  VTKM_CONT
  PointElevation()
    : LowPoint(0.0, 0.0, 0.0)
    , HighPoint(0.0, 0.0, 1.0)
    , RangeLow(0.0)
    , RangeHigh(1.0)
  {
  }

  VTKM_CONT
  void SetLowPoint(const vtkm::Vec<vtkm::Float64, 3>& point) { this->LowPoint = point; }

  VTKM_CONT
  void SetHighPoint(const vtkm::Vec<vtkm::Float64, 3>& point) { this->HighPoint = point; }

  VTKM_CONT
  void SetRange(vtkm::Float64 low, vtkm::Float64 high)
  {
    this->RangeLow = low;
    this->RangeHigh = high;
  }

  VTKM_EXEC
  vtkm::Float64 operator()(const vtkm::Vec<vtkm::Float64, 3>& vec) const
  {
    vtkm::Vec<vtkm::Float64, 3> direction = this->HighPoint - this->LowPoint;
    vtkm::Float64 lengthSqr = vtkm::dot(direction, direction);
    vtkm::Float64 rangeLength = this->RangeHigh - this->RangeLow;
    vtkm::Float64 s = vtkm::dot(vec - this->LowPoint, direction) / lengthSqr;
    s = internal::clamp(s, 0.0, 1.0);
    return this->RangeLow + (s * rangeLength);
  }

  template <typename T>
  VTKM_EXEC vtkm::Float64 operator()(const vtkm::Vec<T, 3>& vec) const
  {
    return (*this)(vtkm::make_Vec(static_cast<vtkm::Float64>(vec[0]),
                                  static_cast<vtkm::Float64>(vec[1]),
                                  static_cast<vtkm::Float64>(vec[2])));
  }

private:
  vtkm::Vec<vtkm::Float64, 3> LowPoint, HighPoint;
  vtkm::Float64 RangeLow, RangeHigh;
};
}
} // namespace vtkm::worklet

#endif // vtk_m_worklet_PointElevation_h
