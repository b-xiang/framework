/*
 * Copyright 2017 - 2018 The WizTK Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WIZTK_GRAPHICS_SURFACE_PRIVATE_HPP_
#define WIZTK_GRAPHICS_SURFACE_PRIVATE_HPP_

#include "wiztk/graphics/surface.hpp"

#include "SkSurface.h"

namespace wiztk {
namespace graphics {

struct Surface::Private {

  Private(const Private &) = delete;
  Private &operator=(const Private &) = delete;

  static const Private &Get(const Surface &surface) {
    return *surface.p_;
  }

  Private() = default;

  explicit Private(const sk_sp<SkSurface> &native)
      : sk_surface_sp(native) {}

  ~Private() = default;

  sk_sp<SkSurface> sk_surface_sp;

};

} // namespace graphics
} // namespace wiztk

#endif // WIZTK_GRAPHICS_SURFACE_PRIVATE_HPP_
