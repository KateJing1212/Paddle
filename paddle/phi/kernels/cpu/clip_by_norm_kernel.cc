// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/phi/kernels/clip_by_norm_kernel.h"

#include "paddle/phi/backends/cpu/cpu_context.h"
#include "paddle/phi/core/kernel_registry.h"
#include "paddle/phi/kernels/impl/clip_by_norm_kernel_impl.h"

namespace phi {

template <typename T, typename Context>
void ClipByNormKernel(const Context& dev_ctx,
                      const DenseTensor& in,
                      float max_norm,
                      DenseTensor* output) {
  return ClipByNormFunctor<T, Context>(dev_ctx, in, max_norm, output);
}

}  // namespace phi

PD_REGISTER_KERNEL(clip_by_norm,
                   CPU,
                   ALL_LAYOUT,
                   phi::ClipByNormKernel,
                   float,
                   phi::dtype::float16,
                   phi::dtype::bfloat16) {}
