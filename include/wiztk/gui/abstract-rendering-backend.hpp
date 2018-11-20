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

#ifndef WIZTK_GUI_ABSTRACT_RENDERING_BACKEND_HPP_
#define WIZTK_GUI_ABSTRACT_RENDERING_BACKEND_HPP_

#include "wiztk/base/macros.hpp"

namespace wiztk {
namespace gui {

// Forward declarations:
class Surface;

/**
 * @ingroup gui
 * @brief The graphics backend used to render a wayland surface.
 *
 * A backend object represents the different GL APIs including:
 * - OpenGL ES 3.x
 * - OpenGL 4.x
 * - Vulkan
 */
class WIZTK_EXPORT AbstractRenderingBackend {

 public:

  WIZTK_DECLARE_NONCOPYABLE_AND_NONMOVALE(AbstractRenderingBackend);

  class Allocator {

   public:

    Allocator() = default;
    Allocator(const Allocator &) = default;
    Allocator(Allocator &&) = default;
    virtual ~Allocator() = default;
    Allocator &operator=(const Allocator &) = default;
    Allocator &operator=(Allocator &&) = default;

    // This allocator in abstract class returns nullptr
    virtual AbstractRenderingBackend *operator()() const {
      return nullptr;
    }

  };

  class Attribute {
   public:
    Attribute() = default;
    virtual ~Attribute() = default;
  };

  AbstractRenderingBackend();

  virtual ~AbstractRenderingBackend();

  virtual void SetViewportSize(int width, int height) = 0;

  virtual void Render(Surface *surface) = 0;

};

} // namespace graphics
} // namespace wiztk

#endif // WIZTK_GUI_ABSTRACT_RENDERING_BACKEND_HPP_
