#pragma once

#ifdef AURORA_ENABLE_GX
#include <webgpu/webgpu_cpp.h>
#include <cstdint>

namespace aurora::webgpu {
wgpu::Device get_device();
wgpu::Queue get_queue();
wgpu::TextureView get_present_source_view();
wgpu::TextureView get_depth_view();
wgpu::Sampler get_present_sampler();
wgpu::Sampler get_depth_sampler();
uint32_t get_present_width();
uint32_t get_present_height();
} // namespace aurora::webgpu
#endif
