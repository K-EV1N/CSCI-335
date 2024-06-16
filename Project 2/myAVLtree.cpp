#include "myAVLtree.hpp"


int height(AVLnode *t) {
    return t == nullptr ? -1 : t -> height; // returns the height of the node or -1 if it's a nullptr
}

/**
 * Internal method to insert into subtree.
 * x is the item to insert
 * t is the node that roots the subtree.
 * set the new root of the subtree.
*/
void insert(const int &x, AVLnode *&t) {
    if (t == nullptr) {
        t = new AVLnode(x, nullptr, nullptr);
    } else if (x <= t -> element) {
        insert(x, t -> left);
    } else if (t -> element < x) {
        insert(x, t -> right);
    }
    balance(t);
}

static const int ALLOWED_IMBALANCE = 1;

//Assume t is balanced or within one of being balanced
void balance(AVLnode *&t){
    if (t == nullptr) {
        return;
    }

    if (height(t -> left) - height(t -> right) > ALLOWED_IMBALANCE) {
        if (height(t -> left -> left) >= height(t -> left -> right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (height(t -> right) - height(t -> left) > ALLOWED_IMBALANCE) {
        if (height(t -> right -> right) >= height(t -> right -> left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }

    t -> height = std::max(height(t -> left), height(t -> right)) + 1; 
}

/**
 * rotate binary tree node with left child.
 * for AVL trees this is a single rotation for case 1
 * update heights, then set new root.
*/
void rotateWithLeftChild(AVLnode *&k2){
    AVLnode *k1 = k2 -> left;
    k2 -> left = k1 -> right;
    k1 -> right = k2;
    k2 -> height = std::max(height(k2 -> left), height(k2 -> right)) + 1;
    k1 -> height = std::max(height(k1 -> left), k2 -> height) + 1;
    k2 = k1;
}

/**
 * rotate binary tree node with right child.
 * for AVL trees this is a single rotation for case 4
 * update heights, then set new root.
*/
void rotateWithRightChild(AVLnode *&k2){
    AVLnode *k1 = k2 -> right;
    k2 -> right = k1 -> left;
    k1 -> left = k2;
    k2 -> height = std::max(height(k2 -> right), height(k2 -> left)) + 1;
    k1 -> height = std::max(height(k1 -> right), k2 -> height) + 1;
    k2 = k1;
}

/**
 * double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child.
 * for AVL trees, this is a double rotation for case 2
 * Update hrights, then set new root.
*/
void doubleWithLeftChild(AVLnode *&k3){
    rotateWithRightChild(k3 -> left);
    rotateWithLeftChild(k3);
}

/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
*/
void doubleWithRightChild(AVLnode *&k3) {
    rotateWithLeftChild(k3 -> right); 
    rotateWithRightChild(k3); 
}

/**
 * internal method to remove from a subtree
 * x is the item to remove
 * t is the node that roots the subtree
 * set the new root of the sub tree
*/
void remove(const int &x, AVLnode *&t){
    if (t == nullptr) {
        return;
    }

    if (x < t->element) {
        remove(x, t -> left);
    } else if (t -> element < x) {
        remove(x, t -> right); 
    } else if (t -> left != nullptr && t -> right != nullptr) {
        t -> element = findMinimum(t -> right) -> element;
        remove(t -> element, t -> right);
    } else {
        AVLnode *oldNode = t; 
        t = (t -> left != nullptr) ? t -> left : t -> right; 
        delete oldNode;
        oldNode = nullptr;
    }

    balance(t);
}

/**
 * internal method to find the smallest item in subtree t.
 * return node containing the smallest item
*/
AVLnode *findMinimum(AVLnode *t){
    if (t == nullptr){
        return nullptr;
    }
    if(t -> left == nullptr){
        return t;
    }
    return findMinimum(t -> left);
}

/**
 * internal method to find the largest item in a subtree t
 * return node containing the largest item
*/
AVLnode *findMaximum(AVLnode *t){
    if (t != nullptr) {
        while(t -> right != nullptr) {
            t = t -> right;
        }
    }
    return t;
}

void treeMedian(const std::vector<int> *instructions){
    std::vector<int> md;
    AVLnode *max = nullptr;
    AVLnode *min = nullptr; 
    int maxCount = 0;
    int minCount = 0;

    const auto time_begin = std::chrono::steady_clock::now();

    for (auto it = instructions -> begin(); it != instructions -> end(); ++it) { // loops through the instructions
        if (max == nullptr && *it != -1) { // checks to see if max is pointing to nullptr and if the value of 'it' doesn't equal to -1
            insert(*it, max); // insert the value of 'it' to the location of max
            maxCount += 1; // increments the maxCount by 1
        } else if (*it == -1) {
            AVLnode *rightMost = findMaximum(max);
            md.push_back(rightMost -> element); // finds the right most element and pushes it back into 'md'
            remove(rightMost -> element, max); // removes the value from the tree
            maxCount -= 1; // decrements the maxCount by 1 and assigns it to maxCount
            if (minCount > maxCount) {
                AVLnode *leftMost = findMinimum(min);
                auto copy = leftMost -> element; // assigns the left most element to 'copy'
                remove(copy, min); // removes the node holding the value
                insert(copy, max); // inserts the value stored in 'copy' 
                minCount -= 1; // decrements the minCount by 1 and assigns it to minCount
                maxCount += 1; // increments the maxCount by 1 and assigns it to maxCount
            }
        } else {
            if (*it <= findMaximum(max) -> element) {
                insert(*it, max);
                maxCount += 1;
                if (maxCount > minCount + 1) {
                    AVLnode *rightMost = findMaximum(max);
                    int copy2 = rightMost -> element; // assigns the right most element to 'copy2'
                    remove(copy2, max); // removes the node holding the value
                    insert(copy2, min); // inserts the value stored in 'copy2'
                    maxCount -= 1; // decrements the maxCount by 1 and assigns it to maxCount
                    minCount += 1; // increments the minCount by 1 and assigns it to minCount
                }
            } else if (*it > findMaximum(max) -> element) {
                insert(*it, min);
                minCount += 1; 
                if (minCount > maxCount){
                    AVLnode *leftMost = findMinimum(min);
                    auto copy3 = leftMost -> element; // assigns the left most element to 'copy3'
                    remove(copy3, min); // removes the node holding the value
                    insert(copy3, max); // inserts the value stored in 'copy3'
                    minCount -= 1; // decrements the minCount by 1 and assigns it to minCount
                    maxCount += 1; // increments the maxCount by 1 and assigns it to maxCount
                }
            }
        }
    }
    const auto time_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int duration_ = std::chrono::duration<double, std::micro>(time_end - time_begin).count();

    //std::cout << "Time to insert and pop medians for AVLtree: " << duration_ << " microseconds" << std::endl;

    for (auto m: md) {
        std::cout << m << " ";
    }
}