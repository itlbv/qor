#ifndef QOR_BEHAVIORTREE_H
#define QOR_BEHAVIORTREE_H

namespace btree {
    enum Status {
        SUCCESS,
        FAILURE,
        RUNNING
    };

    void build();
}

#endif //QOR_BEHAVIORTREE_H
