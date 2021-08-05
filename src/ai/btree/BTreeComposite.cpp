#include "BTreeComposite.h"

BTreeComposite::BTreeComposite(std::vector<BTreeNode *> children_a) :
        children_(std::vector<std::unique_ptr<BTreeNode>>(children_a.begin(), children_a.end())) {}
