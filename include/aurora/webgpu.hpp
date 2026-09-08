#pragma once

#include <webgpu/webgpu_cpp.h>
#include <cstdint>

struct SDL_Window;

namespace aurora::webgpu {

/// Creates an unconfigured WebGPU surface for an SDL window.
/// The SDL window must remain alive until the surface is released.
wgpu::Surface create_window_surface(const wgpu::Instance& instance, SDL_Window* window, const char* label = nullptr);

/// Selects a presentation mode from the surface's capabilities matching the current vsync mode.
wgpu::PresentMode select_present_mode(const wgpu::SurfaceCapabilities& capabilities) noexcept;

/// Returns the application's current vsync mode.
bool vsync_enabled() noexcept;

#ifdef AURORA_ENABLE_GX
wgpu::Device get_device();
wgpu::Queue get_queue();
wgpu::TextureView get_present_source_view();
wgpu::TextureView get_depth_view();
wgpu::Sampler get_present_sampler();
wgpu::Sampler get_depth_sampler();
uint32_t get_present_width();
uint32_t get_present_height();
#endif

} // namespace aurora::webgpu
