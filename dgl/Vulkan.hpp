/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2021 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DGL_VULKAN_HPP_INCLUDED
#define DGL_VULKAN_HPP_INCLUDED

#include "ImageBase.hpp"

#include <vulkan/vulkan_core.h>

START_NAMESPACE_DGL

// --------------------------------------------------------------------------------------------------------------------

/**
   Vulkan Graphics context.
 */
struct VulkanGraphicsContext : GraphicsContext
{
};

// --------------------------------------------------------------------------------------------------------------------

/**
   Vulkan Image class.

   TODO ...
 */
class VulkanImage : public ImageBase
{
public:
   /**
      Constructor for a null Image.
    */
    VulkanImage();

   /**
      Constructor using raw image data.
      @note @a rawData must remain valid for the lifetime of this Image.
    */
    VulkanImage(const char* rawData, uint width, uint height, ImageFormat format);

   /**
      Constructor using raw image data.
      @note @a rawData must remain valid for the lifetime of this Image.
    */
    VulkanImage(const char* rawData, const Size<uint>& size, ImageFormat format);

   /**
      Constructor using another image data.
    */
    VulkanImage(const VulkanImage& image);

   /**
      Destructor.
    */
    ~VulkanImage() override;

   /**
      Load image data from memory.
      @note @a rawData must remain valid for the lifetime of this Image.
    */
    void loadFromMemory(const char* rawData,
                        const Size<uint>& size,
                        ImageFormat format = kImageFormatBGRA) noexcept override;

   /**
      Draw this image at position @a pos using the graphics context @a context.
    */
    void drawAt(const GraphicsContext& context, const Point<int>& pos) override;

   /**
      TODO document this.
    */
    VulkanImage& operator=(const VulkanImage& image) noexcept;

    // FIXME this should not be needed
    inline void loadFromMemory(const char* rawData, uint w, uint h, ImageFormat format = kImageFormatBGRA)
    { loadFromMemory(rawData, Size<uint>(w, h), format); };
    inline void draw(const GraphicsContext& context)
    { drawAt(context, Point<int>(0, 0)); };
    inline void drawAt(const GraphicsContext& context, int x, int y)
    { drawAt(context, Point<int>(x, y)); };
};

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DGL

#endif
