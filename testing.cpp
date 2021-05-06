// #include "SingleLinkList.h"
// #include "DoublyLinkList.h"
// #include "DynamicStack.h"
// #include "DynamicQueue.h"
// #include "StaticStack.h"
// #include "StaticQueue.h"
// #include "StaticCircularQueue.h"
// #include "BinarySearchTree.h"

#include "HashWithChaning.h"
#include <iostream>
using namespace std;


// ---------------------   Hash   --------------------- //


/**
 * You Provide your own hash Function to the class HashTable...
 * Because we don't know what type of data you use in
 * HashTable like int, string or char Type...
 *
 * This "myHashFunc" is only work if you create hash table
 * of integer like in this example...
**/
int myHashFunc(int key, int size)
{
    return key % size;
}


int main()
{

    auto ht = HashTable<int, 5>(myHashFunc);  // You need to provide your hash function...

    ht.insert(12);
    ht.insert(3);
    ht.insert(35);
    ht.insert(23);
    ht.insert(7);

    ht.printTable();

    if (ht.search(35))
        cout << "35 Found in the Table" << endl;
    else
        cout << "35 Not Found in the Table" << endl;

    ht.deletee(23);
    ht.deletee(12);

    cout << endl << endl;

    ht.printTable();

    system("pause");
    return 0;
}


// ---------------------   BST   --------------------- //



// int main()
// {
//     BST<int> intBst;

//     intBst.insert(3);
//     intBst.insert(1);
//     intBst.insert(2);
//     intBst.insert(5);
//     intBst.insert(4);

//     intBst.remove(3);

//     intBst.display();

//     cout << endl;

//     intBst.print2D();

//     system("pause");
//     return 0;
// }



// ---------------------  DoublyLinkList --------------------- //


// int main()
// {
//     DoublyLinkList<int> ll;

//     ll.insertAtEnd(1);
//     ll.insertAtEnd(2);
//     ll.insertAtEnd(3);
//     ll.insertAtEnd(4);
//     ll.insertAtEnd(5);

//     ll.deleteFromHead();
//     ll.reverse();
//     ll.deleteFromEnd();

//     ll.forEach([](auto value) { cout << value << endl; });

//     system("pause");
//     return 0;
// }


//---------------------------- SingleLinkList ----------------------------//



// int main()
// {
//     LinkList<int> ll;

//     ll.insertAtEnd(1);
//     ll.insertAtEnd(2);
//     ll.insertAtEnd(3);
//     ll.insertAtEnd(4);
//     ll.insertAtEnd(5);

//     ll.deleteFromHead();
//     ll.deleteFromEnd();

//     ll.reverse();

//     ll.forEach([](auto val) { cout << val << endl; });

//     cout << ll.size() << endl;

//     system("pause");
//     return 0;
// }



//--------------------------- CircularQueue ----------------------------//



// int main()
// {
//     CircularQueue<int, 6> que;

//     que.Enqueue(1);
//     que.Enqueue(2);
//     que.Enqueue(3);
//     que.Enqueue(4);
//     que.Enqueue(6);

//     auto res = que.Enqueue(5);

//     if (res.first)
//         cout << "Inserted: " << res.second << endl;
//     else
//         cout << "Not Inserted: " << res.second << endl;


//     que.Front() = 456;

//     cout << que.Back() << endl;

//     cout << que.Dequeue() << endl;
//     cout << que.Dequeue() << endl;
//     cout << que.Dequeue() << endl;

//     que.Enqueue(55);
//     res = que.Enqueue(67);

//     if (res.first)
//         cout << "Inserted: " << res.second << endl;
//     else
//         cout << "Not Inserted: " << res.second << endl;

//     system("pause");
//     return 0;
// }



//--------------------------- Queue ----------------------------//



// int main()
// {
//     Queue<int, 6> que;

//     que.Enqueue(1);
//     que.Enqueue(2);
//     que.Enqueue(3);
//     que.Enqueue(4);
//     que.Enqueue(6);

//     auto res = que.Enqueue(5);

//     if (res.first)
//         cout << "Inserted: " << res.second << endl;
//     else
//         cout << "Not Inserted: " << res.second << endl;


//     cout << que.Back() << endl;

//     cout << que.Dequeue() << endl;
//     cout << que.Dequeue() << endl;
//     cout << que.Dequeue() << endl;

//     cout << que.Peek(2) << endl;

//     system("pause");
//     return 0;
// }



//--------------------------- Stack ----------------------------//



// int main()
// {
//     Stack<int, 5> stack;

//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     stack.push(4);
//     stack.push(6);

//     auto res = stack.push(5);

//     if (res.first)
//         cout << "Inserted: " << res.second << endl;
//     else
//         cout << "Not Inserted: " << res.second << endl;


//     cout << stack.peek() << endl;

//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;
//     cout << stack.pop() << endl;

//     cout << stack.peek() << endl;

//     system("pause");
//     return 0;
// }