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

#ifndef WIZTK_GRAPHICS_IMAGE_HPP_
#define WIZTK_GRAPHICS_IMAGE_HPP_

#include "wiztk/base/macros.hpp"

#include <memory>

namespace wiztk {
namespace graphics {

class Pixmap;

class Image {

 public:

  struct Private;

  typedef void *ReleaseContext;

  typedef void (*RasterReleaseProc)(const void *pixels, ReleaseContext);

  // TODO: use the rasterReleaseProc and releaseContext parameters
  static Image MakeFromRaster(const Pixmap &pixmap);

  Image();

  Image(const Image &other);

  Image(Image &&other) noexcept;

  Image &operator=(const Image &other);

  Image &operator=(Image &&other) noexcept;

  virtual ~Image();

 private:

  std::unique_ptr<Private> p_;

};

} // namespace graphics
} // namespace wiztk

#endif // WIZTK_GRAPHICS_IMAGE_HPP_
