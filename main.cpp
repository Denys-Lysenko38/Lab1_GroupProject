#include <vector>
#include "student_b.h"

int main() {
    
    std::shared_ptr<InputData> inptB = std::make_shared<InputData>();

    calculateB(inptB);

    return 0;
}
