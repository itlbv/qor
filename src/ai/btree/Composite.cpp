#include "Composite.h"

namespace btree {
    Composite::Composite(std::vector<std::unique_ptr<BTreeNode>> children_a)
            : children_(std::move(children_a)) {}
}