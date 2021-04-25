//
// Created by denis on 20.04.2021.
//

#ifndef LAB_02_OOP_SKELETONCONTAINER_H
#define LAB_02_OOP_SKELETONCONTAINER_H

namespace denis {
    class ISkeletonContainer {
    public:

        virtual ~ISkeletonContainer() = default;
        virtual bool isEmpty() = 0;
        virtual void clear() = 0;

    };
}

#endif //LAB_02_OOP_SKELETONCONTAINER_H
