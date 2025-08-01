#include <ios>
#include <vector>
#include <cstdint>

class MaxHeap
{
private:
    // Indices start from 0, so left child is 2 * id + 1, right is 2 * id + 2, and parent is (id - 1) / 2
    std::vector<uint64_t> heap;

    void pushUp(uint64_t index)
    {
        while (index > 0)
        {
            if (heap[index] > heap[(index - 1) / 2])
            {
                std::swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
            else
                return;
        }
    }

    void pushDown(uint64_t index)
    {
        uint64_t heapSize = heap.size();
        while (2 * index + 1 < heapSize)
        {
            // Right
            if (2 * index + 2 < heapSize && heap[2 * index + 1] < heap[2 * index + 2] && heap[index] < heap[2 * index + 2])
            {
                std::swap(heap[index], heap[2 * index + 2]);
                index = 2 * index + 2;
            } // Left
            else if (heap[index] < heap[2 * index + 1])
            {
                std::swap(heap[index], heap[2 * index + 1]);
                index = 2 * index + 1;
            }
            else
                return;
        }
    }

public:
    void insert(const uint64_t num)
    {
        heap.push_back(num);

        pushUp(heap.size() - 1);
    }

    uint64_t getMax()
    {
        if (heap.empty())
            throw std::runtime_error("Can't get max");

        return heap[0];
    }

    void delMax()
    {
        if (heap.empty())
            throw std::runtime_error("Can't del max");

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        pushDown(0);
    }

    bool empty() { return heap.empty(); }
};

uint64_t M, k;

int main()
{
    std::ios::sync_with_stdio(false);

    scanf("%lu%lu", &M, &k);

    /* Mythical table, a debugger's dream
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {

            printf("%3d ", j <= i ? i * j : 0);
        }
        printf("\n");
    }
    */

    MaxHeap heap;
    uint64_t diagonal = M;
    bool sqDiagonal = true;

    uint64_t multX, multY;

    while (k > 0)
    {
        uint64_t maxToPrint = diagonal * diagonal;

        if (!sqDiagonal || diagonal == 0)
        {
            uint64_t lastNum = UINT64_MAX;

            uint64_t currNum = 1;
            if (!heap.empty())
            {
                currNum = heap.getMax();
            }

            while (!heap.empty() && currNum > maxToPrint && k > 0)
            {
                if (lastNum != currNum)
                {
                    lastNum = currNum;
                    printf("%lu\n", currNum);
                    k -= 1;
                }

                heap.delMax();
                if (!heap.empty())
                {
                    currNum = heap.getMax();
                }
            }
        }

        if (k == 0)
            break;

        if (sqDiagonal)
        {
            multX = diagonal;
            multY = diagonal;
        }
        else
        {

            multX = diagonal - 1;
            multY = diagonal;
            diagonal -= 1;
        }

        while (multX >= 1 && multY <= M)
        {
            heap.insert(multX * multY);
            multX -= 1;
            multY += 1;
        }

        sqDiagonal = !sqDiagonal;
    }

    return 0;
}