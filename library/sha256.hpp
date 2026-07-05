/*
 * Copyright (C) 2026 Gleb Obitotsky <glebobitotsky@yandex.com>
 *
 * This file is part of bcn-crypto.
 *
 * bcn-crypto is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * CORPORATE & COMMERCIAL USE:
 * Using this code in proprietary or corporate applications without sharing
 * your source code is strictly prohibited under AGPL-3.0. You must purchase
 * a commercial license. Contact: glebobitotsky@yandex.com
 *
 * Version 2072026
 */

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

namespace bcrypto {

namespace sha256 {

inline constexpr size_t sha256_size = 32;
using Sha256Hash = std::array<uint8_t, sha256_size>;

[[nodiscard]] Sha256Hash sha256(std::span<const uint8_t> data);

}  // namespace sha256

}  // namespace bcrypto