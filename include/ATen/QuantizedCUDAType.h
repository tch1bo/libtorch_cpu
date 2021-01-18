#pragma once

// @generated by aten/src/ATen/gen.py from TypeDerived.h

#include <c10/core/TensorOptions.h>
#include <c10/core/Scalar.h>
#include <c10/core/QScheme.h>
#include <c10/core/MemoryFormat.h>
#include <c10/util/ArrayRef.h>
#include <c10/util/intrusive_ptr.h>
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <ATen/Dimname.h>

#include <ATen/DeviceGuard.h>
#include <ATen/cuda/ATenCUDAGeneral.h>
#include <ATen/cuda/CUDADevice.h>
#include <ATen/cuda/CUDAContext.h>

namespace c10 {
struct Storage;
}

namespace at {

class Tensor;
using TensorList = ArrayRef<Tensor>;

class Context;
struct Generator;

struct Quantizer;
// This is temporary typedef to enable Quantizer in aten native function API
// we'll remove them when we are actually exposing Quantizer class
// to frontend
using ConstQuantizerPtr = const c10::intrusive_ptr<Quantizer>&;

namespace QuantizedCUDAType {
  Tensor as_strided(const Tensor & self, IntArrayRef size, IntArrayRef stride, c10::optional<int64_t> storage_offset);
  Tensor _empty_affine_quantized(IntArrayRef size, const TensorOptions & options, double scale, int64_t zero_point, c10::optional<MemoryFormat> memory_format);
  Tensor _empty_per_channel_affine_quantized(IntArrayRef size, const Tensor & scales, const Tensor & zero_points, int64_t axis, const TensorOptions & options, c10::optional<MemoryFormat> memory_format);
  Tensor empty_quantized(IntArrayRef size, const Tensor & qtensor);
  Tensor clone(const Tensor & self, c10::optional<MemoryFormat> memory_format);
  Tensor dequantize_self(const Tensor & self);
  double q_scale(const Tensor & self);
  int64_t q_zero_point(const Tensor & self);
  Tensor q_per_channel_scales(const Tensor & self);
  Tensor q_per_channel_zero_points(const Tensor & self);
  int64_t q_per_channel_axis(const Tensor & self);
  Tensor int_repr(const Tensor & self);
  QScheme qscheme(const Tensor & self);
  Tensor & set__source_Storage_storage_offset(Tensor & self, Storage source, int64_t storage_offset, IntArrayRef size, IntArrayRef stride);
  Tensor & set_quantizer_(Tensor & self, ConstQuantizerPtr quantizer);
  Tensor view(const Tensor & self, IntArrayRef size);
  Tensor unfold(const Tensor & self, int64_t dimension, int64_t size, int64_t step);
}

} // namespace at
