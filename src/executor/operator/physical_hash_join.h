//
// Created by JinHai on 2022/7/28.
//

#pragma once

#include "executor/physical_operator.h"

namespace infinity {

class PhysicalHashJoin : public PhysicalOperator {
public:
    explicit PhysicalHashJoin(uint64_t id)
        : PhysicalOperator(PhysicalOperatorType::kJoinHash, nullptr, nullptr, id) {}
    ~PhysicalHashJoin() = default;

    void Execute() override;
};

}