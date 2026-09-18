#pragma once

#include "shared_types.h"

#include <memory>

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data);