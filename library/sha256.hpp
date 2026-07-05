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
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <expected>
#include <span>
#include <string_view>

namespace bcrypto::sha256 {

inline constexpr size_t sha256_size = 32;
using Sha256Hash = std::array<uint8_t, sha256_size>;

enum class Error : int32_t {
  InitializationFailed,
  HardwareError,
  BufferTooSmall,
  BadState,
  Unknown
};

[[nodiscard]] std::expected<Sha256Hash, Error> hash(
    std::span<const uint8_t> data) noexcept;

[[nodiscard]] inline std::expected<Sha256Hash, Error> hash(
    std::span<std::string_view> str) noexcept {
  return hash(std::span<const uint8_t>(
      reinterpret_cast<const uint8_t*>(str.data()), str.size()));
}

template <typename T>
concept ContiguousByteContainer = requires(T container) {
  { std::data(container) } -> std::contiguous_iterator;
  sizeof(*std::data(container)) == 1;
};

template <ContiguousByteContainer T>
[[nodiscard]] inline std::expected<Sha256Hash, Error> hash(
    const T& container) noexcept {
  return hash(std::span<const uint8_t>(
      reinterpret_cast<const uint8_t*>(std::data(container)),
      std::size(container)));
}

class Hasher {
 public:
  Hasher() noexcept;
  ~Hasher() noexcept;

  Hasher(const Hasher&) = delete;
  Hasher& operator=(const Hasher&) = delete;

  Hasher(Hasher&& other) noexcept;
  Hasher& operator=(Hasher&& other) noexcept;

  [[nodiscard]] std::expected<void, Error> init() noexcept;

  [[nodiscard]] std::expected<void, Error> update(
      std::span<const uint8_t> data) noexcept;

  [[nodiscard]] inline std::expected<void, Error> update(
      std::string_view str) noexcept {
    return update(std::span<const uint8_t>(
        reinterpret_cast<const uint8_t*>(str.data()), str.size()));
  }

  [[nodiscard]] std::expected<void, Error> finalize() noexcept;

 private:
  alignas(8) std::array<uint8_t, 64> b_ctx_storage{};
  bool b_is_active{false};
};

}  // namespace bcrypto::sha256
