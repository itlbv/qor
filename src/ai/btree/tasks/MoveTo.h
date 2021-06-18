#ifndef QOR_MOVETO_H
#define QOR_MOVETO_H

#include "../Node.h"

namespace btree {
    class MoveTo : public Node {
    public:
        Status run() override;
    };
}

#endif //QOR_MOVETO_H
