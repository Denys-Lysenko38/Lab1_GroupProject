#include "shared_types.h"
#include <memory>
#include "student_b.h"

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
	return std::make_unique<Result>(Result{ 0,0 });
}
