#pragma once

#ifdef AURORA_ENABLE_GX

#include <cstdint>
#include <webgpu/webgpu_cpp.h>

namespace aurora::gfx {

struct CapturedFrame {
  wgpu::Texture colorTexture;
  wgpu::TextureView colorView;
  wgpu::Texture depthTexture;
  wgpu::TextureView depthView;
  uint32_t width = 0;
  uint32_t height = 0;
};

// Distinct tags keep simultaneous captures, such as left and right eyes,
// from aliasing the same cached textures.
bool begin_capture(uint32_t width, uint32_t height, uint32_t tag);
bool end_capture(CapturedFrame& frame);

void set_offscreen_uses_native_logical_size(bool enabled) noexcept;
bool offscreen_uses_native_logical_size() noexcept;

} // namespace aurora::gfx

#endif
