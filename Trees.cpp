// Name: David Nguyen
// File: p11Trees.cpp
// Date: 04/013/20 - 05/22/20
// Description:Implement and test the following tree methods
//  - insert
//  - traverse
//  - inOrder
//  - preOrder
//  - postOrder
//  - minimum
//  - maximum
//  - displayTree()

#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *pLeftChild;
    Node *pRightChild;
    Node()
    {
        data = 0;
        pLeftChild = NULL;
        pRightChild =  NULL;
    }

    void displayNode()
    {
        cout << "{" << data << "}";
    }
};  // end of class Node

class Tree
{
private:
    Node *pRoot;
public:
    Tree() {pRoot = NULL;}

    Node *find(int key) // find node with given key
    {
        Node *pCurrent = pRoot;         // start at root
        while (pCurrent->data != key)   // while no match
        {
            if (key < pCurrent->data)   // go left
                pCurrent = pCurrent->pLeftChild;
            else                        // or go right
                pCurrent = pCurrent->pRightChild;
            if(pCurrent == NULL)        // if no child
                return NULL;            // didn't find it
        }

        return pCurrent;                // found it

    }

    void insert(int newData)
    {
        Node *pNewNode = new Node;      // make new node
        pNewNode->data = newData;       // insert data

        if(pRoot == NULL)               // no node in root
            pRoot = pNewNode;

        else                            // root Occupied
        {
            Node *pCurrent = pRoot;     // start at root
            Node *pParent;
            while (true)                // (exits internally)
            {
                pParent = pCurrent;
                if (newData < pCurrent->data)   // go left?
                {
                    pCurrent = pCurrent->pLeftChild;
                    if(pCurrent == NULL)        // if end of the line
                    {                           // insert on the left
                        pParent->pLeftChild = pNewNode;
                        return;
                    }
                } // end if go left
                else                            // go right?
                {
                    pCurrent = pCurrent->pRightChild;
                    if(pCurrent == NULL)
                    {
                        pParent->pRightChild = pNewNode;
                        return;
                    }
                } // end else go right

            } // end while
        } // end else not root

    } // end insert()

    void inOrder (Node *pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            inOrder(pLocalRoot->pLeftChild);    // left child
            cout << pLocalRoot->data << " ";    // display node
            inOrder(pLocalRoot->pRightChild);   // right child
        }
    }
    void preOrder(Node *pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            cout << pLocalRoot->data << " ";
            preOrder(pLocalRoot->pLeftChild);
            preOrder(pLocalRoot->pRightChild);
        }
    }

    void postOrder (Node *pLocalRoot)
    {
        if (pLocalRoot != NULL)
        {
            postOrder(pLocalRoot->pLeftChild);  // left child
            postOrder(pLocalRoot->pRightChild); // right child
            cout << pLocalRoot->data << " ";    // display node
        }
    }


    void minimum ()     // returns node with minimum value
    {
        Node *pCurrent, *pLast;
        pCurrent = pRoot;           // start at root
        while (pCurrent != NULL)    // until the bottom
        {
            pLast = pCurrent;       // remember node
            pCurrent = pCurrent->pLeftChild; // go to left child
        }
        cout << pLast->data << endl;
    }

    void maximum ()     // returns node with maximum value
    {
        Node *pCurrent, *pLast;
        pCurrent = pRoot;
        while (pCurrent != NULL)
        {
            pLast = pCurrent;
            pCurrent = pCurrent->pRightChild;
        }
        cout << pLast->data << endl;
    }
    void traverse (int traverseType)    // start traversal from main
    {
        if (traverseType == 1)
            inOrder(pRoot);
        if (traverseType == 2)
            preOrder(pRoot);
        if (traverseType == 3)
            postOrder(pRoot);

    }

    void displayTree()
    {
        stack <Node*> globalStack;
        globalStack.push(pRoot);
        int nBlanks = 32;
        bool isRowEmpty = false;
        cout << "..................................................................." << endl;
        while(isRowEmpty == false)
        {
            stack<Node*> localStack;
            isRowEmpty = true;
            for (int j = 0; j < nBlanks; j++)
                cout << ' ';
            while (globalStack.empty() == false )
            {
                Node* temp = globalStack.top();
                globalStack.pop();
                if(temp != NULL)
                {
                    cout << temp->data;
                    localStack.push(temp->pLeftChild);
                    localStack.push(temp->pRightChild);

                    if (temp->pLeftChild != NULL || temp->pRightChild != NULL)
                        isRowEmpty = false;
                }
                else
                    {
                    cout << "--";
                    localStack.push(NULL);
                    localStack.push(NULL);
                }
                    for (int j = 0; j < nBlanks * 2 - 2; j++)
                        cout << ' ';
                }

                cout << endl;
                nBlanks /= 2;

                while (localStack.empty() == false)
                {
                    globalStack.push( localStack.top());
                    localStack.pop();
                }
            }   // end while isRowEmpty is false

        cout << "..................................................................." << endl;
    } // end of display tree
};  // end of class tree

int main()
{
    Tree tree;
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(9);
    tree.insert(8);


    Node *found = tree.find(3);
    if (found != NULL)
        cout << "Found the node with key 3" << endl;
    else
        cout << "Could not find node with key 3"<< endl;

    cout << "tree inOrder(): ";
    tree.traverse(1);
    cout << endl;
    tree.displayTree();
    cout << "smallest value: ";
    tree.minimum();
    cout << "largest value: ";
    tree.maximum();



    return 0;
}






/* === OUTPUT ===
Final Test Run
/Users/davidnguyen/CLionProjects/generalPrograms/cmake-build-debug/generalPrograms
Found the node with key 3
tree inOrder(): 1 3 6 8 9
...................................................................
                                6
                1                              9
        --              3              8              --
...................................................................
smallest value: 1
largest value: 9

Process finished with exit code 0


Test Run 1
/Users/davidnguyen/CLionProjects/generalPrograms/cmake-build-debug/generalPrograms
Found the node with key 25

Process finished with exit code 0

*/

