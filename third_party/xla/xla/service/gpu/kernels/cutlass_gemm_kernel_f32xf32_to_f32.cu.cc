/* Copyright 2023 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "cutlass/gemm/device/gemm_universal.h"
#include "xla/service/gpu/kernels/cutlass_gemm_adaptor.cu.h"

namespace xla::gpu::kernel::gemm_universal {

using GemmOperation =
    cutlass::gemm::device::GemmUniversal<float, cutlass::layout::RowMajor,
                                         float, cutlass::layout::RowMajor,
                                         float, cutlass::layout::RowMajor>;

XLA_GPU_DEFINE_CUTLASS_GEMM_TRAITS(F32xF32ToF32<Arch::kDefault>,
                                   GemmOperation);

template class Adaptor<F32xF32ToF32<Arch::kDefault>>;
template class DeviceKernel<F32xF32ToF32<Arch::kDefault>>;
}  // namespace xla::gpu::kernel::gemm_universal
