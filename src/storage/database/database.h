//
// Created by jinhai on 23-5-27.
//

#pragma once

#include "common/types/internal_types.h"

namespace infinity {
class Database {
public:
    static inline SharedPtr<Database>
    Make() {
        return MakeShared<Database>();
    }
public:
    Database() = default;
};

}

