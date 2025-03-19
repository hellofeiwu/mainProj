// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class MemoryPool {
public:
    MemoryPool(size_t size):objectSize(size) {
    }
    ~MemoryPool() {
        for (int* block:memoryBlocks) {
            delete[] block;
        }
    }

    void* allocate() {
        if (freeList.empty()) {
            int* block = new int[chunk_size*objectSize]; // ??????400??????
            memoryBlocks.push_back(block);
            for (int i = 0; i < chunk_size; i++) {
                freeList.push_back(block+i*objectSize); // ??4??????char????
                // ?????32??????size?4????????TestNd?placement new??
                // ????size??4?????????
            }
        }

        void* p= freeList.back();
        freeList.pop_back();
        return p;
    }

    void deallocate(void* p) {
        freeList.push_back(p);
    }

    void* allocateArr(int arrSize) {
        int* block = new int[arrSize*objectSize]; // ??????12????int???
        // ??????12*4=48???
        memoryBlocks.push_back(block);
        return block;
    }
    void deallocateArr(void* p) {
        memoryBlocks.erase(
            remove(memoryBlocks.begin(),memoryBlocks.end(),p),
            memoryBlocks.end()
        );
        delete[] p;
    }
private:
    int chunk_size = 100;
    vector<int*> memoryBlocks;
    vector<void*> freeList;
    size_t objectSize;
};

class TestNd {
public:
    TestNd(int data):_data(data) {
        cout << "in TestNd(int data), _data: "<<_data << endl;
    }
    ~TestNd() {
        cout << "in ~TestNd(), _data: "<<_data << endl;
    }
    // operator new
    void* operator new(size_t size0) { // ?????????????????
        // ??????????static?????????????????
        cout << "in operator new(size_t size0), size0: " << size0 << endl;
        void* p0 = malloc(size0);
        if (!p0) {
            throw bad_alloc();
        }
        return p0;
    }

    // placement new ??????????operator new???????????size???????
    // size????????p???????p??????????????
    void* operator new(size_t size1, void* p1) {
        cout << "in placement new(size_t size1, void* p1), size1: " << size1 
            << ", p1: " << p1 << endl;
        return p1;
    }

    // operator delete
    void operator delete(void* p2) {
        cout << "in operator delete(void* p2), p2: " <<p2<< endl;
        free(p2);
    }

    // placement delete
    void operator delete(void* p3, void* p4) {
        cout << "in placement delete(void* p3, void* p4), p3: " 
            << p3 <<", p4: "<<p4 << endl;
        ((TestNd*)p3)->~TestNd();
    }
private:
    int _data;
};

class TestNdArr {
public:
    TestNdArr(int size):_arraySize(size),_arrayDataP(nullptr) {
        cout << "in TestNdArr(int size), size: "<<_arraySize << endl;
        _arrayDataP = static_cast<TestNd*>(operator new[](sizeof(TestNd) * _arraySize)); //???????TestNd??size?????????
        //????_arrayDataP?????????????????TestNd? placement new ???????
        //????size?4
        for (int i = 0; i < _arraySize; i++) {
            new(&_arrayDataP[i]) TestNd(i);
        }
    }
    ~TestNdArr() {
        cout << "in ~TestNdArr()" << endl;
        for (int i = 0; i < _arraySize; i++) {
            _arrayDataP[i].~TestNd();
        }
        operator delete[](_arrayDataP);
    }

    // operator new[]
    void* operator new[](size_t size) {
        cout <<"in operator new[](size_t size), size: "<<size << endl;
        return ::operator new[](size); // ????????????????????
    }

    // placement new[]
    void* operator new[](size_t size1, void* p1) {
        cout << "in placement new[](size_t size1, void* p1), size1: " << size1
            << ", p1: " << p1 << endl;
        return p1;
    }

    // operator delete[]
    void operator delete[](void* p2) {
        cout << "in operator delete[](void* p2), p2: " << p2 << endl;
        ::operator delete[](p2);
    }

    TestNd& operator[](int i) {
        return _arrayDataP[i];
    }

private:
    int _arraySize;
    TestNd* _arrayDataP;
};

int main()
{
    void* ptr = TestNd::operator new(2);
    TestNd* t = new(ptr) TestNd(10); // ???new?? placement new

    ////TestNd::operator delete(t, nullptr);

    ////TestNd::operator delete(ptr);

    //delete t;

    //int size = 3;
    //TestNdArr* arr = new TestNdArr(size);
    //for (int i = 0; i < size; i++) {
    //    cout << "value at " << i << ", pointer: " << &(*arr)[i] << endl;
    //    // ??(*arr)[i]???????????operator[]??
    //}

    //delete arr;

    //MemoryPool memoryPool(sizeof(TestNd));

    //TestNd* tp = new(memoryPool.allocate()) TestNd(5);
    //tp->~TestNd();
    //memoryPool.deallocate(tp);

    //TestNd* arrTp = (TestNd*)memoryPool.allocateArr(3);
    //for (int i = 0; i < 3; i++) { // ???????????????????
    //    // ??c++???????????????????
    //    new(&arrTp[i]) TestNd(i);
    //}
    //for (int i = 0; i < 3; i++) {
    //    arrTp[i].~TestNd();
    //}
    //memoryPool.deallocateArr(arrTp);
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
