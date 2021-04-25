//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_OOP_LISTNODE_H
#define LAB_02_OOP_LISTNODE_H

#include <memory>

namespace denis {
    template<typename T>
    class listNode {
    public:

        listNode();
        explicit listNode(const T &inData);
        explicit listNode(std::shared_ptr<listNode<T>> &inNode);

        void setData(const T &inData);

        void setNextNode(const std::shared_ptr<listNode<T>> &inNextNode);

        void setNextNode(const listNode<T> &inNode);

        const T &get() const;

        T &getData();

        std::shared_ptr<listNode<T>> getNextNode() const;

        void setNull();

        ~listNode() = default;

        bool operator == (const std::shared_ptr<listNode<T>>& cmpNode) const;
        bool operator != (const std::shared_ptr<listNode<T>>& cmpNode) const;

    private:
        T m_data;
        std::shared_ptr<listNode<T>> m_pNextNode;
    };
}

#endif //LAB_02_OOP_LISTNODE_H
