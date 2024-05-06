#ifndef LAZYBST_H
#define LAZYBST_H
#include "TreeNode.h"
#include "nqueue.h"
#include <stdexcept>
template <typename T>
class LazyBST
{
public:
    LazyBST();
    virtual ~LazyBST();
    int getSize();
    void insert(T d);
    void remove(T d);
    bool contains(T d);
    T getFromTemp(T temp);
    T getMin();
    T getMax();
    void printTreeInOrder();
    void printInBSTOrder();
    void rebalance();
    void updateDepths();

private:
    TreeNode<T> *m_root;
    int m_size;
    int m_rightSubtreeDepth;
    int m_leftSubtreeDepth;
    // void rebalance();
    void rebuild(T* sortedArray);
    TreeNode<T>* rebuildHelper(T *sortedArray, int start, int end);
    T *sortArray(TreeNode<T> *root);
    void nodeToArray(TreeNode<T>* node, T*& sortedArray, int &counter);
    // double checkSubtreeBalance(TreeNode<T> *subTreeRoot);
    // bool needsRebalance();
    void insertHelper(TreeNode<T> *&subTreeRoot, TreeNode<T> *newNode);
    bool containsHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *target);
    T getMinHelper(TreeNode<T> *subTreeRoot);
    T getMaxHelper(TreeNode<T> *subTreeRoot);
    void printTreeInOrderHelper(TreeNode<T> *subTreeRoot);
    void findTarget(T key, TreeNode<T> *&target, TreeNode<T> *&parent);
    TreeNode<T> *getSuccessor(TreeNode<T> *rightChild);
    void nullifySubtree(TreeNode<T>*& node);
    int calculateDepth(TreeNode<T>* node);
    T getHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *target);
};
template <typename T>
LazyBST<T>::LazyBST()
{
    m_root = NULL;
    m_size = 0;
    m_rightSubtreeDepth = 0;
    m_leftSubtreeDepth = 0;
}
template <typename T>
LazyBST<T>::~LazyBST()
{
    nullifySubtree(m_root);
    if (m_root != NULL)
    {
        delete m_root;
    }
}
template <typename T>
int LazyBST<T>::getSize()
{
    return m_size;
}

// template<typename T>
// double LazyBST<T>::checkSubtreeBalance(TreeNode<T> *subTreeRoot){
// //finish
//     return 0;
// }
// template <typename T>
// bool LazyBST<T>:: needsRebalance(){
// //finish
//     return false;
// }
template <typename T>
void LazyBST<T>::insert(T d)
{
    TreeNode<T> *newNode = new TreeNode<T>(d);
    insertHelper(m_root, newNode);
    ++m_size;
    updateDepths();
}
template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T> *&subTreeRoot, TreeNode<T> *newNode)
{
    if (subTreeRoot == NULL)
    {
        subTreeRoot = newNode;
    }
    else if (newNode->m_data < subTreeRoot->m_data)
    {
        insertHelper(subTreeRoot->m_left, newNode);
    }
    else
    {
        insertHelper(subTreeRoot->m_right, newNode);
    }
}
template <typename T>
void LazyBST<T>::remove(T d)
{
    // check if tree is empty
    TreeNode<T> *target = NULL;
    TreeNode<T> *parent = NULL;
    target = m_root;
    findTarget(d, target, parent);
    if (target == NULL)
    { // value doesn't exist
        return;
    }
    if (target->m_left == NULL && target->m_right == NULL)
    { // it's a leaf
        if (target == m_root)
        { // leaf we found is the root
            m_root = NULL;
        }
        else
        { // leaf isn't the root
            if (target == parent->m_left)
            {
                parent->m_left = NULL;
            }
            else
            {
                parent->m_right = NULL;
            }
        }
    }
    else if (target->m_left != NULL && target->m_right != NULL)
    { // 2 child case
        TreeNode<T> *suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value);
        target->m_data = value;
    }
    else
    {                       // 1 child case
        TreeNode<T> *child; // the thing to replace the target with
        // which side is the child on?
        if (target->m_left != NULL)
        { // child on left
            child = target->m_left;
        }
        else
        { // child is on the right
            child = target->m_right;
        }
        if (target == m_root)
        {
            m_root = child;
        }
        else
        { // the thing to delete isn't the root
            if (target == parent->m_left)
            {
                parent->m_left = child;
            }
            else
            {
                parent->m_right = child;
            }
        }
    }
    updateDepths();
    --m_size;
}
template <typename T>
bool LazyBST<T>::contains(T d)
{
    if (m_root == NULL)
    {
        return false;
    }
    TreeNode<T> *newNode = new TreeNode<T>(d);
    bool ret = containsHelper(m_root, newNode);
    delete newNode;
    return ret;
}
template <typename T>
bool LazyBST<T>::containsHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *target)
{
    if (subTreeRoot == NULL)
    {
        return false;
    }
    else if (target->m_data < subTreeRoot->m_data)
    {
        return containsHelper(subTreeRoot->m_left, target);
    }
    else if (target->m_data > subTreeRoot->m_data)
    {
        return containsHelper(subTreeRoot->m_right, target);
    }
    else
    {
        return true;
    }
}
template <typename T>
T LazyBST<T>::getMin()
{
    // what if the tree is empty?
    return getMinHelper(m_root);
}
template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T> *subTreeRoot)
{
    if (subTreeRoot->m_left == NULL)
    {
        return subTreeRoot->m_data;
    }
    else
    {
        return getMinHelper(subTreeRoot->m_left);
    }
}
template <typename T>
T LazyBST<T>::getMax()
{
    // what if the tree is empty?
    return getMaxHelper(m_root);
}
template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T> *subTreeRoot)
{
    if (subTreeRoot->m_right == NULL)
    {
        return subTreeRoot->m_data;
    }
    else
    {
        return getMaxHelper(subTreeRoot->m_right);
    }
}
template <typename T>
void LazyBST<T>::printTreeInOrder()
{
    if(m_root == NULL){
       // cout << "BST is empty" << endl;
        return;
    }
    printTreeInOrderHelper(m_root);
}
template <typename T>
void LazyBST<T>::printTreeInOrderHelper(TreeNode<T> *subTreeRoot)
{
    if (subTreeRoot->m_left != NULL)
    {
        printTreeInOrderHelper(subTreeRoot->m_left);
    }
    cout << subTreeRoot->m_data << endl << endl;
    if (subTreeRoot->m_right != NULL)
    {
        printTreeInOrderHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void LazyBST<T>::printInBSTOrder(){
    NQueue<TreeNode<T>*> queue(5);
    queue.add(m_root);
    while(!queue.isEmpty()){
        TreeNode<T>* currentNode = queue.peek();
        queue.remove();
        cout << currentNode->m_data << " ";

        if (currentNode->m_left!= nullptr){
            queue.add(currentNode->m_left);

        }

        if(currentNode->m_right != nullptr){
            queue.add(currentNode->m_right);
        }
    }
    cout << endl;
}

template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T> *&target, TreeNode<T> *&parent)
{
    while (target != NULL && target->m_data != key)
    {
        parent = target;
        if (key < target->m_data)
        {
            target = target->m_left;
        }
        else
        {
            target = target->m_right;
        }
    }
}
template <typename T>
TreeNode<T> *LazyBST<T>::getSuccessor(TreeNode<T> *rightChild)
{
    while (rightChild->m_left != NULL)
    {
        rightChild = rightChild->m_left;
    }
    return rightChild;
}

template <typename T>
void LazyBST<T>::rebalance(){
    //make ascending array
    //go left every time until you can't and then go back up to last branch and add right node
    T* sortedArray = sortArray(m_root);  //see about passing it by reference???
    // cout << endl;

    // for(int i = 0; i < m_size; i++){
    //     cout << sortedArray[i] << endl;
    // }
   // nullifySubtree(m_root);
    //m_root = nullptr;
    rebuild(sortedArray); //fix
}

template <typename T>
void LazyBST<T>::rebuild(T* sortedArray){
// The median value of the collection is chosen and inserted into a new LB-BST as the root/leaf
// The median value of everything less than the root/leaf is chosen and inserted into the tree is inserted as the root’s/leaf’s left child.
// The median value of everything greater than the root/leaf is chosen and inserted into the tree is inserted as the root’s/leaf’s right child.
// Steps 3 and 4 are repeated for each leaf until all N values have been added to the new LB-BST
   int size = getSize();
   m_root = rebuildHelper(sortedArray,0,size - 1);
}

template <typename T>
TreeNode<T> *LazyBST<T>::rebuildHelper(T *sortedArray, int start, int end)
{
    if (start > end) {
        return nullptr;
    }

    int middle = start + (end-start) / 2;
    TreeNode<T>* root = new TreeNode<T>(sortedArray[middle]);

    root->m_left = rebuildHelper(sortedArray,start, middle-1);
    root->m_right = rebuildHelper(sortedArray, middle+1, end);

    return root;
}

    template <typename T>
    T *LazyBST<T>::sortArray(TreeNode<T> * root)
    {
        int counter = 0;
        T *sortedArray = new T[getSize()];
        nodeToArray(root, sortedArray, counter);
        return sortedArray;
    }

    template <typename T>
    void LazyBST<T>::nodeToArray(TreeNode<T> * node, T * &sortedArray, int &counter)
    {
        if (node != nullptr)
        {
            nodeToArray(node->m_left, sortedArray, counter);
            sortedArray[counter] = node->m_data;
            //  cout << node-> m_data << endl;
            //  cout << "counter" << counter << endl;
            counter++;
            nodeToArray(node->m_right, sortedArray, counter);
        }
    }

    template <typename T>
    void LazyBST<T>::nullifySubtree(TreeNode<T>*& node)
    {
        if (node != nullptr)
        {
            nullifySubtree(node->m_left);
            nullifySubtree(node->m_right);
            delete node;
            node = nullptr;
        }
    }

    

    template <typename T>
    int LazyBST<T>::calculateDepth(TreeNode<T>* node){
        if (node == NULL){
            return 0;
        }

        int leftDepth = calculateDepth(node->m_left);
        int rightDepth = calculateDepth(node->m_right);

        node->m_leftSubtreeDepth = leftDepth;
        node->m_rightSubtreeDepth = rightDepth;

        int maxDepth = (rightDepth > leftDepth) ? rightDepth : leftDepth;

        return 1 + maxDepth;
    }

    template <typename T>
    void LazyBST<T>::updateDepths(){
        if(m_root != nullptr){
            int rootDepth = calculateDepth(m_root);

            m_leftSubtreeDepth = m_root->m_leftSubtreeDepth;
            //cout << "left: " << m_leftSubtreeDepth << endl;
            m_rightSubtreeDepth = m_root->m_rightSubtreeDepth;
            //cout << "right: " << m_rightSubtreeDepth << endl;
            if (m_leftSubtreeDepth > m_rightSubtreeDepth * 1.5 || m_rightSubtreeDepth > m_leftSubtreeDepth * 1.5){
                rebalance();
            }
        }
    }

    template <typename T>
    T LazyBST<T>::getFromTemp(T temp){
        TreeNode<T> *newNode = new TreeNode<T>(temp);
        T ret = getHelper(m_root, newNode);
        delete newNode;
        return ret;
    }

    template <typename T>
    T LazyBST<T>::getHelper(TreeNode<T> *subTreeRoot, TreeNode<T> *target)
    {
        if (subTreeRoot == NULL)
        {
            throw invalid_argument("data not found");
        }
        else if (target->m_data < subTreeRoot->m_data)
        {
            return getHelper(subTreeRoot->m_left, target);
        }
        else if (target->m_data > subTreeRoot->m_data)
        {
            return getHelper(subTreeRoot->m_right, target);
        }
        else
        {
            return subTreeRoot->m_data;
        }
    }

#endif